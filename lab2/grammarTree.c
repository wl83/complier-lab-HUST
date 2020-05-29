#include "grammarTree.h"
#include "grammarTree.tab.h"
#define OFFSET 3

symbolTable myTable = {{0}, 0};
symbol_scope_TX myScope = {{0}, 0};

struct ASTNode * mknode(int num,int kind,int pos,...){
    struct ASTNode *T=(struct ASTNode *)calloc(sizeof(struct ASTNode),1);
    int i=0;
    T->kind=kind;
    T->pos=pos;
    va_list pArgs;
    va_start(pArgs, pos);
    for(i=0;i<num;i++)
        T->ptr[i]= va_arg(pArgs, struct ASTNode *);
    while (i<4) T->ptr[i++]=NULL;
    va_end(pArgs);
    return T;
}


void display(struct ASTNode *T,int indent)
{//对抽象语法树的先根遍历
  int i=1;
  struct ASTNode *T0;
  if (T)
	{
	switch (T->kind) {
    case EXT_DEF_LIST:  
        display(T->ptr[0],indent);    //显示该外部定义（外部变量和函数）列表中的第一个
        display(T->ptr[1],indent);    //显示该外部定义列表中的其它外部定义
        break;
    case EXT_VAR_DEF:   
        printf("%*c外部变量定义：(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);        //显示外部变量类型
        printf("%*c变量名：\n",indent+OFFSET,' ');
        display(T->ptr[1],indent+OFFSET*2);        //显示变量列表
        break;
    case TYPE:          
        printf("%*c类型： %s\n",indent,' ',T->type_id);
        break;
    case EXT_DEC_LIST:  
        if(T->ptr[0]->ptr[0] != NULL)
        {
            printf("%*c数组名：%s\n", indent, ' ', T->ptr[0]->type_id);
            printf("%*c数组大小：\n", indent, ' ');
        }
        display(T->ptr[0],indent);     //依次显示外部变量名，
        display(T->ptr[1],indent);     //后续还有相同的，仅显示语法树此处理代码可以和类似代码合并
        break;
    case FUNC_DEF:      
        printf("%*c函数定义：(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);      //显示函数返回类型
        display(T->ptr[1],indent+OFFSET);      //显示函数名和参数
        display(T->ptr[2],indent+OFFSET);      //显示函数体
        break;
    case FUNC_DEC:      
        printf("%*c函数名：%s\n",indent,' ',T->type_id);
        if (T->ptr[0]) {
            printf("%*c函数形参：\n",indent,' ');
            display(T->ptr[0],indent+OFFSET);  //显示函数参数列表
        }
        else printf("%*c无参函数\n",indent+OFFSET,' ');
        break;
    case PARAM_LIST:    
        display(T->ptr[0],indent);     //依次显示全部参数类型和名称，
        display(T->ptr[1],indent);
        break;
    case PARAM_DEC:     
        printf("%*c类型：%s, 参数名：%s\n",indent,' ',T->ptr[0]->type==INT?"int":"float",T->ptr[1]->type_id);
        break;
    case EXP_STMT:      
        printf("%*c表达式语句：(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);
        break;
    case RETURN:        
        printf("%*c返回语句：(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);
        break;
    case COMP_STM:      
        printf("%*c复合语句：(%d)\n",indent,' ',T->pos);
        printf("%*c复合语句的变量定义部分：\n",indent+OFFSET,' ');
        // if(T->ptr[0] == NULL)
        //     printf("\n\n NULL!! \n\n");
        display(T->ptr[0],indent+OFFSET*2);      //显示定义部分
        printf("%*c复合语句的语句部分：\n",indent+OFFSET,' ');
        display(T->ptr[1],indent+OFFSET*2);      //显示语句部分
        break;
    case STM_LIST:      
        display(T->ptr[0],indent);      //显示第一条语句
        display(T->ptr[1],indent);        //显示剩下语句
        break;
    case WHILE:         
        printf("%*c循环语句(WHILE)：(%d)\n",indent,' ',T->pos);
        printf("%*c循环条件(WHILE)：\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //显示循环条件
        printf("%*c循环体(WHILE)：(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1],indent+OFFSET*2);      //显示循环体
        break;
    case FOR:
        printf("%*c循环语句(FOR)：(%d)\n",indent,' ',T->pos);
        printf("%*c循环条件(FOR)：\n", indent+OFFSET, ' ');
        display(T->ptr[0], indent+OFFSET*2);
        printf("%*c循环体(FOR)：(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1], indent+OFFSET*2);
        break;
    case SWITCH_STMT:
        printf("%*cSWITCH语句：(%d)\n", indent, ' ', T->pos);
        display(T->ptr[0], indent+OFFSET);
        display(T->ptr[1], indent+OFFSET);
        break;
    case CASE_STMT:
        printf("%*cCASE语句：(%d)\n", indent, ' ', T->pos);
        display(T->ptr[0], indent+OFFSET);
        display(T->ptr[1], indent+OFFSET);
        break;
    case FOR_DEC:
        display(T->ptr[0], indent+OFFSET*2);
        display(T->ptr[1], indent+OFFSET*2);
        display(T->ptr[2], indent+OFFSET*2);
        break;
    case CONTINUE:
        printf("%*cCONTINUE语句：(%d)\n", indent, ' ', T->pos);
        break;
    case BREAK:
        printf("%*cBREAK语句：(%d)\n", indent, ' ', T->pos);
        break;
    case IF_THEN:       
        printf("%*c条件语句(IF_THEN)：(%d)\n",indent,' ',T->pos);
        printf("%*c条件：\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //显示条件
        printf("%*cIF子句：(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1],indent+OFFSET*2);      //显示if子句
        break;
    case IF_THEN_ELSE:  
        printf("%*c条件语句(IF_THEN_ELSE)：(%d)\n",indent,' ',T->pos);
        printf("%*c条件：\n",indent+OFFSET,' ');
        display(T->ptr[0],indent+OFFSET*2);      //显示条件
        printf("%*cIF子句：(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[1],indent+OFFSET*2);      //显示if子句
        printf("%*cELSE子句：(%d)\n",indent+OFFSET,' ',T->pos);
        display(T->ptr[2],indent+OFFSET*2);      //显示else子句
        break;
    case DEF_LIST:     
        display(T->ptr[0],indent);    //显示该局部变量定义列表中的第一个
        display(T->ptr[1],indent);    //显示其它局部变量定义
        break;
    case VAR_DEF:       
        printf("%*c局部变量定义：(%d)\n",indent,' ',T->pos);
        display(T->ptr[0],indent+OFFSET);   //显示变量类型
        display(T->ptr[1],indent+OFFSET);   //显示该定义的全部变量名
        break;
    case DEC_LIST:      
        printf("%*c变量名：\n",indent,' ');
        T0=T;
        while (T0) {
            if (T0->ptr[0]->kind==ID)
                printf("%*c %s\n",indent+OFFSET*2,' ',T0->ptr[0]->type_id);
            else if (T0->ptr[0]->kind==ASSIGNOP)
            {
                printf("%*c %s ASSIGNOP\n ",indent+OFFSET*2,' ',T0->ptr[0]->ptr[0]->type_id);
                display(T0->ptr[0]->ptr[1],indent+strlen(T0->ptr[0]->ptr[0]->type_id)+7);        //显示初始化表达式
            }
            T0=T0->ptr[1];
        }
        break;
    case ARRAY_LIST:
        display(T->ptr[0], indent);
        display(T->ptr[1], indent);
        break;
    case ARRAY_ID:
        printf("%*c数组名： %s\n",indent,' ',T->type_id);
        printf("%*c访问下标：\n", indent, ' ');
        display(T->ptr[0], indent+OFFSET);
        break;
    case STRUCT_DEF:
        printf("%*c结构定义：(%d)\n", indent, ' ',T->pos);
        display(T->ptr[0], indent+OFFSET);
        display(T->ptr[1], indent+OFFSET);
        break;
    case STRUCT_TAG:
        printf("%*c结构名：%s\n", indent, ' ', T->struct_name);
        break;
    case ID:	        
        printf("%*cID： %s\n",indent,' ',T->type_id);
        break;
    case INT:	     
        printf("%*cINT：%d\n",indent,' ',T->type_int);
        break;
    case FLOAT:	        
        printf("%*cFLAOT：%f\n",indent,' ',T->type_float);
        break;
    case CHAR:
        printf("%*cCHAR: %s\n", indent, ' ', T->type_char);
        break;
    case STRING:
        printf("%*cSTRING: %s\n", indent, ' ', T->type_string);
        break;
	case ASSIGNOP:
    case PLUSASSIGNOP:
    case MINUSASSIGNOP:
    case STARASSIGNOP:
    case DIVASSIGNOP:
    case MODASSIGNOP:
    case AND:
    case OR:
    case RELOP:
    case PLUS:
    case AUTOPLUS:
    case AUTOMINUS:
    case MINUS:
    case STAR:
    case DIV:
    case MOD:
        printf("%*c%s\n",indent,' ',T->type_id);
        display(T->ptr[0],indent+OFFSET);
        display(T->ptr[1],indent+OFFSET);
        break;
    case EXP_ELE:
        printf("%*c结构体访问：\n", indent, ' ');
        display(T->ptr[0], indent+OFFSET);
        printf("%*c访问成员变量：%s\n", indent+OFFSET, ' ',T->type_id);
        break;
    case NOT:
    case UMINUS:    
        printf("%*c%s\n",indent,' ',T->type_id);
        display(T->ptr[0],indent+OFFSET);
        break;
    case FUNC_CALL: 
        printf("%*c函数调用：(%d)\n",indent,' ',T->pos);
        printf("%*c函数名：%s\n",indent+OFFSET,' ',T->type_id);
        display(T->ptr[0],indent+OFFSET);
        break;
    case ARGS:      
        i=1;
        while (T) {  //ARGS表示实际参数表达式序列结点，其第一棵子树为其一个实际参数表达式，第二棵子树为剩下的
            struct ASTNode *T0=T->ptr[0];
            printf("%*c第%d个实际参数表达式：\n",indent,' ',i++);
            display(T0,indent+OFFSET);
            T=T->ptr[1];
        }
//      printf("%*c第%d个实际参数表达式：\n",indent,' ',i);
  //    display(T,indent+OFFSET);
        printf("\n");
        break;
        }
    }
}

int searchSymbolTable(char *name) {
    int i,flag=0;
    for(i=myTable.index-1;i>=0;i--){
        if (myTable.symbols[i].level==0)
            flag=1;
        if (flag && myTable.symbols[i].level==1)
            continue;   //跳过前面函数的形式参数表项
        if (!strcmp(myTable.symbols[i].name, name))  
            return i;
    }
    return -1;
}

void semantic_error(int line, char *msg1, char *msg2){
    //这里可以只收集错误信息，最后一次显示
    printf("ERROR! 第%d行, %s %s\n",line, msg1, msg2);
}

void prn_symbol(){ //显示符号表
    int i = 0;
    printf("%6s %6s %6s  %6s %4s %6s\n","变量名","别 名","层 号","类  型","标记","偏移量");
    for(i = 0;i < myTable.index;i++)
        printf("%6s %6s %6d  %6s %4c %6d\n",myTable.symbols[i].name,\
                myTable.symbols[i].alias,myTable.symbols[i].level,\
                myTable.symbols[i].type==INT ? "int" : (myTable.symbols[i].type==FLOAT ? "float" : (myTable.symbols[i].type==CHAR ? "char" : (myTable.symbols[i].type==STRING ? "string" : "void"))),\
                myTable.symbols[i].flag,myTable.symbols[i].offset);
}

void DisplaySymbolTable()
{
    int i;
    printf("\t\t\n***Symbol Table***\n");
    printf("---------------------------------------------------\n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\n","Index","Name","Level","Type","Flag","Param_num");
    printf("---------------------------------------------------\n");
    for(i = 0;i < myTable.index; i++){
        printf("%d\t",i);
        printf("%s\t",myTable.symbols[i].name);
        printf("%d\t",myTable.symbols[i].level);
        if(myTable.symbols[i].type==INT)
               printf("%s\t","int");
        else if(myTable.symbols[i].type==FLOAT)
            printf("%s\t","float");
        else if(myTable.symbols[i].type==CHAR)
            printf("%s\t","char");
        else if(myTable.symbols[i].type==STRING)
            printf("%s\t","string");
        else if(myTable.symbols[i].type==STRUCT)
            printf("%s\t", "struct");
        else
            printf("%s\t","void");
            
        printf("%c\t",myTable.symbols[i].flag);
        if(myTable.symbols[i].flag=='F')
            printf("%d\n",myTable.symbols[i].paramnum);
        else
            printf("\n");
    }
    printf("---------------------------------------------------\n");
    printf("\n");
}

int fillSymbolTable(char *name, char *alias, int level, int type, char flag, int offset)
{ // 首先根据name查符号表，不能重复定义 重复定义返回-1

    int i;
    /*符号查重，考虑外部变量声明前有函数定义，
    其形参名还在符号表中，这时的外部变量与前函数的形参重名是允许的*/
    for (i = myTable.index - 1; myTable.symbols[i].level == level || (level == 0 && i >= 0); i--)
    {
        if (level == 0 && myTable.symbols[i].level == 1)
            continue; //外部变量和形参不必比较重名
        if (!strcmp(myTable.symbols[i].name, name))
            return -1;
    }
    //填写符号表内容
    strcpy(myTable.symbols[myTable.index].name, name);
    strcpy(myTable.symbols[myTable.index].alias, alias);
    myTable.symbols[myTable.index].level = level;
    myTable.symbols[myTable.index].type = type;
    myTable.symbols[myTable.index].flag = flag;
    myTable.symbols[myTable.index].offset = offset;
    return myTable.index++; //返回的是符号在符号表中的位置序号，中间代码生成时可用序号取到符号别名
}

//填写临时变量到符号表，返回临时变量在符号表中的位置
int fill_Temp(char *name, int level, int type, char flag, int offset)
{
    strcpy(myTable.symbols[myTable.index].name, "");
    strcpy(myTable.symbols[myTable.index].alias, name);
    myTable.symbols[myTable.index].level = level;
    myTable.symbols[myTable.index].type = type;
    myTable.symbols[myTable.index].flag = flag;
    myTable.symbols[myTable.index].offset = offset;
    return myTable.index++; //返回的是临时变量在符号表中的位置序号
}

int match_param(int i, struct ASTNode *T)
{ // 匹配函数参数
    int j, num = myTable.symbols[i].paramnum;
    int type1, type2;
    if (num == 0 && T == NULL)
        return 1;
    for (j = 1; j < num; j++)
    {
        if (!T)
        {
            semantic_error(T->pos, "", "函数调用参数太少");
            return 0;
        }
        type1 = myTable.symbols[i + j].type; //形参类型
        type2 = T->ptr[0]->type;
        if (type1 != type2)
        {
            semantic_error(T->pos, "", "参数类型不匹配");
            return 0;
        }
        T = T->ptr[1];
    }
    if (T->ptr[1])
    { //num个参数已经匹配完，还有实参表达式
        semantic_error(T->pos, "", "函数调用参数太多");
        return 0;
    }
    return 1;
}

int i, j, t, counter = 0;
int rtn, flag1, flag2, num;
int mem, stru_dec = 0;

int semantic_Analysis(struct ASTNode *T, int type, int level, char flag, int command){
    int type1, type2;
    if(T) {
        switch (T->kind)
        {
        case EXT_DEF_LIST:
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case EXT_VAR_DEF:
            type = semantic_Analysis(T->ptr[0], type, level, flag, command);
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case EXT_STRUCT_DEF:
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            break;
        case STRUCT_DEF:
            rtn = searchSymbolTable(T->ptr[0]->type_id);
            if(rtn != -1){
                if(myTable.symbols[rtn].flag == 'S'){
                    semantic_error(T->pos, "", "结构体名重复定义");
                }
            }
            strcpy(myTable.symbols[myTable.index].name, T->ptr[0]->type_id);
            myTable.symbols[myTable.index].level = level;
            myTable.symbols[myTable.index].flag = 'S';
            myTable.symbols[myTable.index].type = STRUCT;
            myTable.index++;
            flag = 'M';
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case STRUCT_DEC:
            rtn = searchSymbolTable(T->ptr[0]->type_id);
            if(rtn == -1){
                semantic_error(T->pos, T->type_id, "结构体未定义");
            }
            else{
                stru_dec = 1;
            }
            break;
        case TYPE:
            return T->type;
        case EXT_DEC_LIST:
            flag = 'V';
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case ID:
            i = 0;
            while(myTable.symbols[i].level != level && i < myTable.index)
                i++;
            if(command == 0){ //定义变量
                while(i < myTable.index){
                    if(strcmp(myTable.symbols[i].name,T->type_id)==0 && myTable.symbols[i].flag==flag){
                        if(flag=='V')
                            semantic_error(T->pos, T->type_id, "全局变量重复定义");
                        else if(flag=='F')
                            semantic_error(T->pos, T->type_id, "函数名重复定义");
                        else if(flag=='T')
                            semantic_error(T->pos, T->type_id, "局部变量重复定义");
                        else if(flag=='M')
                            semantic_error(T->pos, "", "成员变量重复定义");
                        else
                            semantic_error(T->pos, "", "函数参数定义重复");
                        return 0;
                    }
                    i++;
                }
                strcpy(myTable.symbols[myTable.index].name, T->type_id);
                myTable.symbols[myTable.index].level = level;
                myTable.symbols[myTable.index].flag = flag;
                myTable.symbols[myTable.index].type = type;
                myTable.index++;
            }
            else{ // 使用变量
                i = myTable.index - 1;
                while(i >= 0){
                    if(myTable.symbols[i].level <= level && !strcmp(myTable.symbols[i].name, T->type_id) && (myTable.symbols[i].flag == 'T' || myTable.symbols[i].flag == 'V' || myTable.symbols[i].flag == 'P'))
                        return myTable.symbols[i].type;
                    i--;
                }
                if(i < 0){
                    semantic_error(T->pos, T->type_id, "变量未定义");
                }
            }
            break;
        case FUNC_DEF:
            type = semantic_Analysis(T->ptr[0], type, level+1, flag, command);
            if (type != VOID)
                flag1 = 1;
            semantic_Analysis(T->ptr[1], type, 1, flag, command);
            semantic_Analysis(T->ptr[2], type, 1, flag, command);
            num = myTable.index;
            do{
                num--;
            }while (myTable.symbols[num].flag == 'P');
            myTable.index = num+1;
            if(flag1 && !flag2){
                semantic_error(T->pos, T->type_id, "函数没有返回值");
            }   
            flag1 = 0;
            flag2 = 0;
            break;
        case FUNC_DEC:
            rtn = searchSymbolTable(T->type_id);
            if(rtn != -1){
                if(myTable.symbols[rtn].flag == 'F'){
                    semantic_error(T->pos, T->type_id, "函数名重复定义");
                }
            }
            strcpy(myTable.symbols[myTable.index].name, T->type_id);
            myTable.symbols[myTable.index].flag = 'F';
            myTable.symbols[myTable.index].level = 0;
            myTable.symbols[myTable.index].type = type;
            myTable.index++;
            counter = 0;
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            myTable.symbols[myTable.index - counter - 1].paramnum = counter;
            break;
        case PARAM_LIST:
            counter++;
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case PARAM_DEC:
            flag = 'P';
            type = semantic_Analysis(T->ptr[0], type, level+1, flag, command);
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case COMP_STM:
            flag = 'T';
            command = 0;
            myScope.TX[myScope.top++] = myTable.index;
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            command = 1;
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            DisplaySymbolTable();
            myTable.index = myScope.TX[--myScope.top];
            break;
        case STM_LIST:
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            semantic_Analysis(T->ptr[1], type, level, flag, command);
            break;
        case DEF_LIST:
            semantic_Analysis(T->ptr[0],type,level,flag,command);
            semantic_Analysis(T->ptr[1],type,level,flag,command);
            break;
        case VAR_DEF:
            type = semantic_Analysis(T->ptr[0],type,level+1,flag,command);
            semantic_Analysis(T->ptr[1],type,level,flag,command);
            break;
        case DEC_LIST:
            if(stru_dec){
                type = STRUCT;
                stru_dec = 0;
            }
            semantic_Analysis(T->ptr[0],type,level,flag,command);
            semantic_Analysis(T->ptr[1],type,level,flag,command);
            break;
        case EXP_STMT:
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            break;
        case RETURN:
            flag2 = 1;
            if(flag1){
                if(!T->ptr[0]){
                    semantic_error(T->pos, "", "缺少返回值");
                    break;
                }
            }
            type = semantic_Analysis(T->ptr[0], type, level, flag, command);
            num = myTable.index;
            do{
                num--;
            }while (myTable.symbols[num].flag != 'F');
            if( !(!flag1 && !T->ptr[0]) && type != myTable.symbols[num].type){
                semantic_error(T->pos, "", "返回值类型错误");
            }
            break;
        case IF_THEN:
        case WHILE:
        case FOR:
        case SWITCH_STMT:
        case CASE_STMT:
            semantic_Analysis(T->ptr[0],type,level,flag,command);
            semantic_Analysis(T->ptr[1],type,level,flag,command);
            break;
        case IF_THEN_ELSE:
            semantic_Analysis(T->ptr[0],type,level,flag,command);
            semantic_Analysis(T->ptr[1],type,level,flag,command);
            semantic_Analysis(T->ptr[2],type,level,flag,command);
            break;
        case DEFAULT_STMT:
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            break;
        case ASSIGNOP:
        case PLUSASSIGNOP:
        case MINUSASSIGNOP:
        case STARASSIGNOP:
        case DIVASSIGNOP:
        case MODASSIGNOP:
        case AND:
        case OR:
        case RELOP:
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case MOD:
            if(T->ptr[0]->kind != ID) {
                semantic_error(T->pos, "", "赋值表达式需要左值");
            }
            else{
                type1 = semantic_Analysis(T->ptr[0], type, level, flag, command);
                type2 = semantic_Analysis(T->ptr[1], type, level, flag, command);
                if(type1 == type2)
                    return type1;
            }
            break;
        case AUTOPLUS_L:
        case AUTOPLUS_R:
        case AUTOMINUS_L:
        case AUTOMINUS_R:
            if(T->ptr[0]->kind != ID){
                semantic_error(T->pos, "", "自增表达式需要左值");
                break;
            }
        case UMINUS:
        case NOT:
            semantic_Analysis(T->ptr[0], type, level, flag, command);
            break;
        case INT:
            return INT;
        case CHAR:
            return CHAR;
        case FLOAT:
            return FLOAT;
        case STRING:
            return STRING;
        case FUNC_CALL:
            rtn = searchSymbolTable(T->type_id);
            if(rtn != -1){
                if(myTable.symbols[rtn].flag != 'F'){
                    semantic_error(T->pos, T->type_id, "不是函数");
                    return 0;
                }
                type = myTable.symbols[rtn+1].type;
                counter = 0;
                semantic_Analysis(T->ptr[0], type, level, flag, command);
                if(myTable.symbols[rtn].paramnum != counter)
                    semantic_error(T->pos, "", "参数数量不匹配");
            }
            else{
                semantic_error(T->pos, T->type_id, "函数未定义");
                return 0;
            }
            break;
        case ARGS:
            counter++;
            t = semantic_Analysis(T->ptr[0], type, level, flag, command);
            if(type != t){
                semantic_error(T->pos, "", "函数调用参数类型不匹配");
            }
            type = myTable.symbols[j+counter+1].type;
            semantic_Analysis(T->ptr[1], type, level, flag, command);       
            break;


        default:
            break;
        }
    }
}

void semantic_Analysis0(struct ASTNode *T){
    myTable.index = 0;
    fillSymbolTable("read", "", 0, INT, 'F', 4);
    myTable.symbols[0].paramnum = 0; //read的形参个数
    fillSymbolTable("x", "", 1, INT, 'P', 12);
    fillSymbolTable("write", "", 0, INT, 'F', 4);
    myTable.symbols[2].paramnum = 1;
    myScope.TX[0] = 0; //外部变量在符号表中的起始序号为0
    myScope.top = 0;
    T->offset = 0; // 外部变量在数据区的偏移量
    semantic_Analysis(T, 0, 0, ' ', 0);
    DisplaySymbolTable();
}
