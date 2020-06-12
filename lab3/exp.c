#include "grammarTree.h"

extern int LEV;   //层号
extern int func_size; //函数的活动记录大小

extern struct symboltable symbolTable;
extern struct symbol_scope_begin symbol_scope_TX;

void Exp(struct ASTNode *T)
{ //处理基本表达式，参考文献[2]p82的思想
    int rtn, num, width;
    struct ASTNode *T0;
    struct opn opn1, opn2, result;
    if (T)
    {
        switch (T->kind)
        {
        case ID: //查符号表，获得符号表中的位置，类型送type
            id_exp(T);
            break;
        case STRUCT_TAG: // TODO
            exp_struct_tag(T);
            break;
        case INT:
            int_exp(T);
            break;
        case FLOAT:
            float_exp(T);
            break;
        case CHAR: // new
            char_exp(T);
            break;
        case STRING: // TODO
            string_exp(T);
            break;
        case ASSIGNOP:
            assignop_exp(T);
            break;
        case PLUSASSIGNOP:
        case MINUSASSIGNOP:
        case STARASSIGNOP:
        case DIVASSIGNOP:
        case MODASSIGNOP:
            other_assignop_exp(T);
            break;
        case AUTOMINUS_L: // TODO
        case AUTOMINUS_R:
        case AUTOPLUS_L:
        case AUTOPLUS_R:
            auto_op_exp(T);
            break;
        case AND:   //按算术表达式方式计算布尔值，未写完
        case OR:    //按算术表达式方式计算布尔值，未写完
        case RELOP: //按算术表达式方式计算布尔值，未写完
            relop_exp(T);
            break;
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case MOD:
            op_exp(T);
            break;
        case NOT: //未写完整
            not_exp(T);
            break;
        case UMINUS: //未写完整
            // uminus_exp(T);
            break;
        case FUNC_CALL: //根据T->type_id查出函数的定义，如果语言中增加了实验教材的read，write需要单独处理一下
            func_call_exp(T);
            break;
        case ARGS: //此处仅处理各实参表达式的求值的代码序列，不生成ARG的实参系列
            args_exp(T);
            break;
        case EXP_ARRAY: // TODO
            exp_array(T);
            break;
        }
    }
}

//布尔表达式
void boolExp(struct ASTNode *T)
{
    struct opn opn1, opn2, result;
    int op;
    int rtn;
    if (T)
    {
        switch (T->kind)
        {
            case INT:
                if (T->type_int != 0)
                    T->code = genGoto(T->Etrue);
                else
                    T->code = genGoto(T->Efalse);
                T->width = 0;
                break;
            case FLOAT:
                if (T->type_float != 0.0)
                    T->code = genGoto(T->Etrue);
                else
                    T->code = genGoto(T->Efalse);
                T->width = 0;
                break;
            case ID: //查符号表，获得符号表中的位置，类型送type
                rtn = searchSymbolTable(T->type_id);
                if (rtn == -1)
                    semantic_error(T->pos, T->type_id, "变量为定义");
                if (symbolTable.symbols[rtn].flag == 'F')
                    semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
                else
                {
                    opn1.kind = ID;
                    strcpy(opn1.id, symbolTable.symbols[rtn].alias);
                    opn1.offset = symbolTable.symbols[rtn].offset;
                    opn2.kind = INT;
                    opn2.const_int = 0;
                    result.kind = ID;
                    strcpy(result.id, T->Etrue);
                    T->code = genIR(NEQ, opn1, opn2, result);
                    T->code = merge(2, T->code, genGoto(T->Efalse));
                }
                T->width = 0;
                break;
            case RELOP: //处理关系运算表达式,2个操作数都按基本表达式处理
                T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
                Exp(T->ptr[0]);
                T->width = T->ptr[0]->width;
                Exp(T->ptr[1]);
                if (T->width < T->ptr[1]->width)
                    T->width = T->ptr[1]->width;
                opn1.kind = ID;
                strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
                opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;
                opn2.kind = ID;
                strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
                opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;
                result.kind = ID;
                strcpy(result.id, T->Etrue);
                if (strcmp(T->type_id, "<") == 0)
                    op = JLT;
                else if (strcmp(T->type_id, "<=") == 0)
                    op = JLE;
                else if (strcmp(T->type_id, ">") == 0)
                    op = JGT;
                else if (strcmp(T->type_id, ">=") == 0)
                    op = JGE;
                else if (strcmp(T->type_id, "==") == 0)
                    op = EQ;
                else if (strcmp(T->type_id, "!=") == 0)
                    op = NEQ;
                T->code = genIR(op, opn1, opn2, result);
                T->code = merge(4, T->ptr[0]->code, T->ptr[1]->code, T->code, genGoto(T->Efalse));
                break;
            case AND:
            case OR:
                if (T->kind == AND)
                {
                    strcpy(T->ptr[0]->Etrue, newLabel());
                    strcpy(T->ptr[0]->Efalse, T->Efalse);
                }
                else
                {
                    strcpy(T->ptr[0]->Etrue, T->Etrue);
                    strcpy(T->ptr[0]->Efalse, newLabel());
                }
                strcpy(T->ptr[1]->Etrue, T->Etrue);
                strcpy(T->ptr[1]->Efalse, T->Efalse);
                T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
                boolExp(T->ptr[0]);
                T->width = T->ptr[0]->width;
                boolExp(T->ptr[1]);
                if (T->width < T->ptr[1]->width)
                    T->width = T->ptr[1]->width;
                if (T->kind == AND)
                    T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Etrue), T->ptr[1]->code);
                else
                    T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Efalse), T->ptr[1]->code);
                break;
            case NOT:
                strcpy(T->ptr[0]->Etrue, T->Efalse);
                strcpy(T->ptr[0]->Efalse, T->Etrue);
                boolExp(T->ptr[0]);
                T->code = T->ptr[0]->code;
                break;
            default:
                break;
        }
    }
}


void id_exp(struct ASTNode *T)
{
    int rtn, num, width;

    rtn = searchSymbolTable(T->type_id);
    if (rtn == -1)
        semantic_error(T->pos, T->type_id, "变量未定义");
    if (symbolTable.symbols[rtn].flag == 'F')
        semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
    else
    {
        T->place = rtn; //结点保存变量在符号表中的位置
        T->code = NULL; //标识符不需要生成TAC
        T->type = symbolTable.symbols[rtn].type;
        T->offset = symbolTable.symbols[rtn].offset;
        T->width = 0; //未再使用新单元
    }
}

void int_exp(struct ASTNode *T){
    struct opn opn1, opn2, result;
    T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为整常量生成一个临时变量
    T->type = INT;
    opn1.kind = INT;
    opn1.const_int = T->type_int;
    result.kind = ID;
    strcpy(result.id, symbolTable.symbols[T->place].alias);
    result.offset = symbolTable.symbols[T->place].offset;
    T->code = genIR(ASSIGNOP, opn1, opn2, result);
    T->width = 4;
}

void float_exp(struct ASTNode *T)
{
    int rtn, num, width;
    struct opn opn1, opn2, result;
    T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为浮点常量生成一个临时变量
    T->type = FLOAT;
    opn1.kind = FLOAT;
    opn1.const_float = T->type_float;
    result.kind = ID;
    strcpy(result.id, symbolTable.symbols[T->place].alias);
    result.offset = symbolTable.symbols[T->place].offset;
    T->code = genIR(ASSIGNOP, opn1, opn2, result);
    T->width = 4;
}

void char_exp(struct ASTNode *T)
{
    int rtn, num, width;
    struct opn opn1, opn2, result;
    T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为整常量生成一个临时变量
    T->type = CHAR;
    opn1.kind = CHAR;
    opn1.const_char = T->type_char[1];
    result.kind = ID;
    strcpy(result.id, symbolTable.symbols[T->place].alias);
    result.offset = symbolTable.symbols[T->place].offset;
    T->code = genIR(ASSIGNOP, opn1, opn2, result);
    T->width = 1;
}

void string_exp(struct ASTNode *T)
{
    int rtn, num, width;
    struct opn opn1, opn2, result;
    T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为整常量生成一个临时变量
    T->type = STRING;
    opn1.kind = STRING;
    // strcpy(opn1.const_string, T->type_string);
    opn1.const_string = T->type_string;
    result.kind = ID;
    strcpy(result.id, symbolTable.symbols[T->place].alias);
    result.offset = symbolTable.symbols[T->place].offset;
    T->code = genIR(ASSIGNOP, opn1, opn2, result);
    // T->width = 1;
}

void assignop_exp(struct ASTNode *T)
{
    int rtn, num, width;
    struct opn opn1, opn2, result;
    if (T->ptr[0]->kind != ID)
    {
        semantic_error(T->pos, "", "赋值语句需要左值");
    }
    else
    {
        Exp(T->ptr[0]); //处理左值，例中仅为变量
        T->ptr[1]->offset = T->offset;
        Exp(T->ptr[1]);
        T->type = T->ptr[0]->type;
        T->width = T->ptr[1]->width;
        T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);

        opn1.kind = ID;
        strcpy(opn1.id, symbolTable.symbols[T->ptr[1]->place].alias); //右值一定是个变量或临时变量
        opn1.offset = symbolTable.symbols[T->ptr[1]->place].offset;
        result.kind = ID;
        strcpy(result.id, symbolTable.symbols[T->ptr[0]->place].alias);
        result.offset = symbolTable.symbols[T->ptr[0]->place].offset;
        T->code = merge(2, T->code, genIR(ASSIGNOP, opn1, opn2, result));
    }
}

void other_assignop_exp(struct ASTNode *T) {
    int rtn, num, width;
    struct opn opn1, opn2, result;
    struct opn result2;
    if (T->ptr[0]->kind != ID)
    {
        semantic_error(T->pos, "", "赋值语句需要左值");
    }
    else{
        T->ptr[0]->offset = T->offset;
        Exp(T->ptr[0]);
        T->ptr[1]->offset = T->offset + T->ptr[0]->width;
        Exp(T->ptr[1]);
        T->type = T->ptr[0]->type;
        T->width = T->ptr[1]->width;
        T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);

        opn1.kind = ID;
        strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias); //右值一定是个变量或临时变量
        opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;

        opn2.kind = ID;
        strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
        opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;
        
        result.kind = ID;
        strcpy(result.id, newTemp());
        if (T->kind == PLUSASSIGNOP)
            T->code = merge(2, T->code, genIR(PLUS, opn1, opn2, result));
        else if(T->kind == MINUSASSIGNOP)
            T->code = merge(2, T->code, genIR(MINUS, opn1, opn2, result));
        else if(T->kind == STARASSIGNOP)
            T->code = merge(2, T->code, genIR(STAR, opn1, opn2, result));
        else if(T->kind == DIVASSIGNOP)
            T->code = merge(2, T->code, genIR(DIV, opn1, opn2, result));
        else
            T->code = merge(2, T->code, genIR(MOD, opn1, opn2, result));

        result2.kind = ID;
        strcpy(result2.id, symbolTable.symbols[T->ptr[0]->place].alias);
        result2.type = T->type;
        result2.offset = symbolTable.symbols[T->ptr[0]->place].offset;
        T->code = merge(2, T->code, genIR(ASSIGNOP, result, opn2, result2));
    }
}

void auto_op_exp(struct ASTNode *T) {
    int rtn, num, width;
    struct opn opn1, opn2, result;
    struct opn result2;
    if (T->ptr[0]->kind != ID){
        semantic_error(T->pos, "", "赋值语句需要左值");
    }
    else {
        T->ptr[0]->offset = T->offset;
        Exp(T->ptr[0]);
        T->type = T->ptr[0]->type;
        T->width = T->ptr[0]->width;

        opn1.kind = INT;
        opn1.const_int = 1;
        result.kind = ID;
        strcpy(result.id, newTemp());
        T->code = merge(2, T->code, genIR(ASSIGNOP, opn1, opn2, result));

        opn1.kind = ID;
        strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
        result2.kind = ID;
        strcpy(result2.id, newTemp());
        if (T->kind == AUTOPLUS_L || T->kind == AUTOPLUS_R)
            T->code = merge(2, T->code, genIR(PLUS, opn1, result, result2));
        else if(T->kind == AUTOMINUS_L || T->kind == AUTOMINUS_R)
            T->code = merge(2, T->code, genIR(MINUS, opn1, result, result2));

        T->code = merge(2, T->code, genIR(ASSIGNOP, result2, opn2, opn1));
    }
}

void relop_exp(struct ASTNode *T)
{
    T->type = INT;
    T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
    Exp(T->ptr[0]);
    Exp(T->ptr[1]);
}

void args_exp(struct ASTNode *T)
{
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
    T->width = T->ptr[0]->width;
    T->code = T->ptr[0]->code;
    if (T->ptr[1]) {
        T->ptr[1]->offset = T->offset + T->ptr[0]->width;
        Exp(T->ptr[1]);
        T->width += T->ptr[1]->width;
        T->code = merge(2, T->code, T->ptr[1]->code);
    }
}

// 算数运算：加减乘除
void op_exp(struct ASTNode *T)
{
    int rtn, num, width;
    struct opn opn1, opn2, result;
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
    T->ptr[1]->offset = T->offset + T->ptr[0]->width;
    Exp(T->ptr[1]);
    //判断T->ptr[0]，T->ptr[1]类型是否正确，可能根据运算符生成不同形式的代码，给T的type赋值
    //下面的类型属性计算，没有考虑错误处理情况
    if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
        T->type = FLOAT, T->width = T->ptr[0]->width + T->ptr[1]->width + 4;
    else
        T->type = INT, T->width = T->ptr[0]->width + T->ptr[1]->width + 2;
    T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->ptr[0]->width + T->ptr[1]->width);
    
    opn1.kind = ID;
    strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
    opn1.type = T->ptr[0]->type;
    opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;

    opn2.kind = ID;
    strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
    opn2.type = T->ptr[1]->type;
    opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;

    result.kind = ID;
    strcpy(result.id, symbolTable.symbols[T->place].alias);
    result.type = T->type;
    result.offset = symbolTable.symbols[T->place].offset;

    T->code = merge(3, T->ptr[0]->code, T->ptr[1]->code, genIR(T->kind, opn1, opn2, result));
    if (T->type == INT) {
        T->width = T->ptr[0]->width + T->ptr[1]->width + 4;
    }
    else if(T->type == FLOAT) {
        T->width = T->ptr[0]->width + T->ptr[1]->width + 8;
    }
    else if(T->type == CHAR) {
        T->width = T->ptr[0]->width + T->ptr[1]->width + 1;
    }
}

void func_call_exp(struct ASTNode *T)
{
    int rtn, num, width;
    int count = 0, param_num;
    struct ASTNode *T0;
    struct ASTNode *T1;
    struct opn opn1, opn2, result;
    rtn = searchSymbolTable(T->type_id);
    if (rtn == -1)
    {
        semantic_error(T->pos, T->type_id, "函数未定义");
        return;
    }
    if (symbolTable.symbols[rtn].flag != 'F')
    {
        semantic_error(T->pos, T->type_id, "不是一个函数");
        return;
    }
    T->type = symbolTable.symbols[rtn].type;
    // 存放函数返回值的单数字节数
    if(T->type == INT) {
        width = 4;
    }
    else if(T->type == FLOAT) {
        width = 8;
    }
    else if(T->type == CHAR) {
        width = 1;
    }
    if (T->ptr[0]) {
        T->ptr[0]->offset = T->offset;
        Exp(T->ptr[0]);                      //处理所有实参表达式求值，及类型
        T->width = T->ptr[0]->width + width; //累加上计算实参使用临时变量的单元数
        T->code = T->ptr[0]->code;
    }
    else{
        T->width = width;
        T->code = NULL;
    }
    T1 = T->ptr[0];
    while(T1 != NULL) {
        count++;
        T1 = T1->ptr[1];
    }
    param_num = symbolTable.symbols[rtn].paramnum;
    if (count > param_num) {
        semantic_error(T->pos, "", "函数参数数量太多");
    }
    else if(count < param_num) {
        semantic_error(T->pos, "", "函数参数数量太少");
    }
    else
        match_param(rtn, T->ptr[0]); //处理所以参数的匹配
    //处理参数列表的中间代码
    T0 = T->ptr[0];
    while (T0){
        result.kind = ID;
        strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
        result.offset = symbolTable.symbols[T0->ptr[0]->place].offset;
        T->code = merge(2, T->code, genIR(ARG, opn1, opn2, result));
        T0 = T0->ptr[1];
    }
    T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->width - width);
    opn1.kind = ID;
    strcpy(opn1.id, T->type_id); //保存函数名
    opn1.offset = rtn;           //这里offset用以保存函数定义入口,在目标代码生成时，能获取相应信息
    result.kind = ID;
    strcpy(result.id, symbolTable.symbols[T->place].alias);
    result.offset = symbolTable.symbols[T->place].offset;
    T->code = merge(2, T->code, genIR(CALL, opn1, opn2, result)); //生成函数调用中间代码
}

void not_exp(struct ASTNode *T)
{
    T->type = INT;
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
}

void unminus_exp(struct ASTNode *T)
{
    T->type = T->ptr[0]->type;
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
}

void exp_array(struct ASTNode *T)
{

}

void exp_struct_tag(struct ASTNode *T)
{

}