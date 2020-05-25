#include "semantic.h"

extern int LEV; // 层号
extern int func_size; // 一个函数的活动记录大小

void ext_def_list(struct ASTNode *T){
    if (!T->ptr[0]){
        return;
    }
    // 语义分析之前先设置偏移地址
    T->ptr[0]->offset = T->offset;
    semantic_Analysis(T->ptr[0]); // 访问外部定义列表的第一个
    // 之后合并code

    // 可为空
    if (T->ptr[1]){
        T->ptr[1]->offset = T->ptr[0]->offset + T->ptr[0]->width;
        semantic_Analysis(T->ptr[1]); // 访问外部定义列表的剩余部分
    }
}

void ext_var_list(struct ASTNode *T){
    // 处理变量列表
    int rtn, num = 1;
    switch (T->kind)
    {
    case EXT_DEC_LIST:
        T->ptr[0]->type = T->type; // 向下传递类型
        T->ptr[0]->offset = T->offset; // 外部变量的偏移量向下传递
        T->ptr[1]->type = T->type;
        T->ptr[1]->offset = T->offset + T->width;
        T->ptr[1]->width = T->width;
        ext_var_list(T->ptr[0]);
        ext_var_list(T->ptr[1]);
        T->num = T->ptr[1]->num + 1;
        break;
    case ID:
        rtn = fillSymbolTable(T->type_id, newAlias(), LEV, T->type, 'V', T->offset); //最后一个变量名
        if (rtn == -1)
            semantic_error(T->pos, T->type_id, "变量重复定义");
        else
            T->place = rtn;
        T->num = 1;
        break;
    
    default:
        break;
    }
}

void ext_var_def(struct ASTNode *T){
    if (!strcmp(T->ptr[0]->type, "int")) {
        T->type = INT;
        T->ptr[1]->type = INT;
        T->ptr[1]->width = 4;
    }
    if (!strcmp(T->ptr[0]->type, "float")) {
        T->type = FLOAT;
        T->ptr[1]->type = FLOAT;
        T->ptr[1]->width = 8;
    }
    if (!strcmp(T->ptr[0]->type, "char")) {
        T->type = CHAR;
        T->ptr[1]->type = CHAR;
        T->ptr[1]->width = 1;
    }
    if (!strcmp(T->ptr[0]->type, "string")) {
        T->type = STRING;
        T->ptr[1]->type = STRING;
    }
    T->ptr[1]->offset = T->offset;
    // 处理外部变量说明中的标识符序列
    ext_var_list(T->ptr[1]);
    T->width = (T->ptr[1]->width) * T->ptr[1]->num;
}

void func_def(struct ASTNode *T){
    if (!strcmp(T->ptr[0]->type_id, "int")){
        T->ptr[1]->type = INT;
    }
    if (!strcmp(T->ptr[0]->type_id, "float")){
        T->ptr[1]->type = FLOAT;
    }
    if (!strcmp(T->ptr[0]->type_id, "char")){
        T->ptr[1]->type = CHAR;
    }
    if (!strcmp(T->ptr[0]->type_id, "string")){
        T->ptr[1]->type = STRING;
    }
    T->width = 0;                  //函数的宽度设置为0，不会对外部变量的地址分配产生影响
    T->offset = DX;                //设置局部变量在活动记录中的偏移量初值
    semantic_Analysis(T->ptr[1]);  //处理函数名和参数结点部分，这里不考虑用寄存器传递参数
    T->offset += T->ptr[1]->width; //用形参单元宽度修改函数局部变量的起始偏移量
    T->ptr[2]->offset = T->offset;
    strcpy(T->ptr[2]->Snext, newLabel()); //函数体语句执行结束后的位置属性
    semantic_Analysis(T->ptr[2]);
    //计算活动记录大小,这里offset属性存放的是活动记录大小，不是偏移
    symbolTable.symbols[T->ptr[1]->place].offset = T->offset + T->ptr[2]->width;
}

void func_dec(struct ASTNode *T){
    int rtn;
    rtn = fillSymbolTable(T->type_id, newAlias(), LEV, T->type, 'F', 0);

    if (rtn == -1){
        semantic_error(T->pos, "", "函数重复定义");
        return;
    }
    else{
        T->place = rtn;
    }
    T->offset = DX;
    if(T->ptr[0]){ // 判断是否有参数
        T->ptr[0]->offset = T->offset;
        semantic_Analysis(T->ptr[0]);
        T->width = T->ptr[0]->width;
        symbolTable.symbols[rtn].paramnum = T->ptr[0]->num;
    }
    else{
        symbolTable.symbols[rtn].paramnum = 0;
        T->width = 0;
    }
}

void ext_struct_def(struct ASTNode *T){
    T->ptr[0]->offset = T->offset;
    semantic_Analysis(T->ptr[0]);
}

void struct_def(struct ASTNode *T){
    int rtn;
    T->width = 0;
    T->type = STRUCT;
    T->offset = DX;
    rtn = fillSymbolTable(T->ptr[0]->type_id, newAlias(), LEV, T->ptr[0]->type, 'S', 0);
    if(rtn == -1){
        semantic_error(T->pos, "", "结构体定义重复");
        return;
    }
    else
        T->place = rtn;
    T->ptr[1]->offset = T->offset;
    semantic_Analysis(T->ptr[1]);
}

void struct_dec(struct ASTNode *T){
    T->ptr[0]->offset = T->offset;
    semantic_Analysis(T->ptr[0]);
    T->width = T->ptr[0]->width;
}

void array_dec(struct ASTNode *T){

}

void param_list(struct ASTNode *T){
    T->ptr[0]->offset = T->offset;
    semantic_Analysis(T->ptr[0]);
    if(T->ptr[1]){
        T->ptr[1]->offset = T->ptr[0]->width + T->offset;
        semantic_Analysis(T->ptr[1]);
        T->width = T->ptr[0]->width + T->ptr[1]->width;
        T->num = T->ptr[0]->num + T->ptr[1]->num;
    }
    else{
        T->num = T->ptr[0]->num;
        T->width = T->ptr[0]->width;
    }
}

void param_dec(struct ASTNode *T){
    int rtn;
    rtn = fillSymbolTable(T->ptr[1]->type_id, newAlias(), LEV, T->ptr[0]->type, 'P', T->offset);
    if(rtn == -1)
        semantic_error(T->pos, "", "参数重复定义");
    else
        T->ptr[1]->place = rtn;
    T->num = 1; // 参数个数计算的初始值
    T->width = T->ptr[0]->type == INT ? 4 : 8; //参数宽度
}

void comp_stm(struct ASTNode *T){
    LEV++;
    //设置层号加1，并且保存该层局部变量在符号表中的起始位置在symbol_scope_TX
    symbol_scope_TX.TX[symbol_scope_TX.top++] = symbolTable.index;
    T->width = 0;
    if(T->ptr[0]){
        T->ptr[0]->offset = T->offset;
        semantic_Analysis(T->ptr[0]);
        T->width += T->ptr[0]->width;
    }
    if(T->ptr[1]){
        T->ptr[1]->offset = T->offset + T->width;
        strcpy(T->ptr[1]->Snext, T->Snext);
        semantic_Analysis(T->ptr[1]);
        T->width += T->ptr[1]->width;
    }
    // 在退出一个符合语句前显示的符号表
    prn_symbol();
    LEV--;
    symbolTable.index = symbol_scope_TX.TX[--symbol_scope_TX.top];
}

void def_list(struct ASTNode *T){
    if(T->ptr[0]){
        T->ptr[0]->offset = T->offset;
        semantic_Analysis(T->ptr[0]);
        T->width = T->ptr[0]->width;
    }
    if(T->ptr[1]){
        T->ptr[1]->offset = T->offset + T->ptr[0]->width;
        semantic_Analysis(T->ptr[1]);
        T->width += T->ptr[1]->width;
    }
}

void var_def(struct ASTNode *T){
    int rtn, width, num;
    struct ASTNode *T0;
    if (!strcmp(T->ptr[0]->type_id, "int"))
    {
        T->ptr[1]->type = INT;
        width = 4;
    }
    if (!strcmp(T->ptr[0]->type_id, "float"))
    {
        T->ptr[1]->type = FLOAT;
        width = 8;
    }
    if (!strcmp(T->ptr[0]->type_id, "char"))
    {
        T->ptr[1]->type = CHAR;
        width = 1;
    }
    if (!strcmp(T->ptr[0]->type_id, "string"))
    {
        T->ptr[1]->type = STRING;
    }
    T0 = T->ptr[1];
    num = 0;
    T0->width = T->offset;
    T->width = 0;
    while(T0){ //处理所以DEC_LIST结点
        num++;
        T0->ptr[0]->type = T0->type;
        if(T0->ptr[1])
            T0->ptr[1]->type = T0->type;
        T0->ptr[0]->offset = T0->offset;
        if(T0->ptr[1])
            T0->ptr[1]->offset = T0->offset + width;
        
        if(T0->ptr[0]->kind == ID){
            rtn = fillSymbolTable(T0->ptr[0]->type_id, newAlias(), LEV, T0->ptr[0]->type_id, 'V', T->offset+T->width);
            if(rtn == -1){
                semantic_error(T0->pos, "", "变量重复定义");
            }
            else
                T0->ptr[0]->place = rtn;
            T->width += width;                
        }
        else if(T0->ptr[0]->kind == ASSIGNOP){
            rtn = fillSymbolTable(T0->ptr[0]->ptr[0]->type_id, newAlias(), LEV, T0->ptr[0]->type, 'V', T->offset+T->width);
            if(rtn == -1){
                semantic_error(T0->ptr[0]->ptr[0]->pos, "", "变量重复定义");
            }
            else{
                T0->ptr[0]->place = rtn;
                T0->ptr[0]->ptr[1]->offset = T->offset + T->width + width;
                Exp(T->ptr[0]->ptr[1]);
            }
            T->width += width + T0->ptr[0]->ptr[1]->width;
        }
        T0 = T0->ptr[1];
    }
}

void stm_list(struct ASTNode *T){
    if(!T->ptr[0]){
        T->width = 0;
        return;
    }
    if(T->ptr[1])
        strcpy(T->ptr[0]->Snext, newLabel());
    else
        strcpy(T->ptr[0]->Snext, T->Snext);
    T->ptr[0]->offset = T->offset;
    semantic_Analysis(T->ptr[0]);
    T->width = T->ptr[0]->width;
    if(T->ptr[1]){ //2条以上语句连接,S.next属性向下传递
        strcpy(T->ptr[1]->Snext, T->Snext);
        T->ptr[1]->offset = T->offset;
        semantic_Analysis(T->ptr[1]);

        if(T->ptr[1]->width > T->width)
            T->width = T->ptr[1]->width;
    }
}

void if_then(struct ASTNode *T){
    strcpy(T->ptr[0]->Etrue, newLabel());
    strcpy(T->ptr[0]->Efalse, T->Snext);
    T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
    boolExp(T->ptr[0]); // 处理判断条件
    T->width = T->ptr[0]->width;
    strcpy(T->ptr[1]->Snext, T->Snext);
    semantic_Analysis(T->ptr[1]); // 处理if子句
    if(T->width < T->ptr[1]->width)
        T->width = T->ptr[1]->width;
}

void if_then_else(struct ASTNode *T){
    strcpy(T->ptr[0]->Etrue, newLabel());
    strcpy(T->ptr[0]->Efalse, T->Snext);
    T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
    boolExp(T->ptr[0]); // 处理判断条件
    T->width = T->ptr[0]->width;
    strcpy(T->ptr[1]->Snext, T->Snext);
    semantic_Analysis(T->ptr[1]); // 处理if子句
    if(T->width < T->ptr[1]->width)
        T->width = T->ptr[1]->width;
    strcpy(T->ptr[2]->Snext, T->Snext);
    semantic_Analysis(T->ptr[2]); // 处理else子句
    if(T->width < T->ptr[2]->width)
        T->width = T->ptr[2]->width;
}

void while_dec(struct ASTNode *T){
    strcpy(T->ptr[0]->Etrue, newLabel());
    strcpy(T->ptr[0]->Efalse, T->Snext);
    T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
    boolExp(T->ptr[0]); // 处理循环条件
    T->width = T->ptr[0]->width;
    strcpy(T->ptr[1]->Snext, T->Snext);
    semantic_Analysis(T->ptr[1]); // 处理while语句
    if(T->width < T->ptr[1]->width)
        T->width = T->ptr[1]->width;
}

void exp_stmt(struct ASTNode *T){
    T->ptr[0]->offset = T->offset;
    semantic_Analysis(T->ptr[0]);
    T->width = T->ptr[0]->width;
}

void return_dec(struct ASTNode *T){
    int rtn, num;
    if(T->ptr[0]){
        T->ptr[0]->offset = T->offset;
        Exp(T->ptr[0]);
        num = symbolTable.index;
        do{
            num--;
        }while(symbolTable.symbols[num].flag != 'F');
        if(T->ptr[0]->type != symbolTable.symbols[num].type){
            semantic_error(T->pos, "", "返回值类型错误");
            T->width = 0;
            return;
        }
        T->width = T->ptr[0]->width;
    }
    else{
        T->width = 0;
    }
}