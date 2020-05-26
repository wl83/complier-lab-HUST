#include "semantic.h"

void boolExp(struct ASTNode *T){
    struct opn opn1, opn2, result;
    int op;
    int rtn;
    if (T) {
        switch (T->kind)
        {
        case INT:
            T->width = 0;
            break;
        case FLOAT:
            T->width = 0;
            break;
        case ID:
            rtn = searchSymbolTable(T->type_id);
            if(rtn == -1)
                semantic_error(T->pos, T->type_id, "变量未定义");
            if(symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
            T->width = 0;
            break;
        case RELOP:
            T->ptr[0]->offset = T->offset;
            T->ptr[1]->offset = T->offset;
            Exp(T->ptr[0]);
            T->width = T->ptr[0]->width;
            Exp(T->ptr[1]);
            T->width = (T->width < T->ptr[0]->width) ? T->ptr[0]->width : T->width;
            break;
        case AND:
        case OR:
            if(T->kind == AND){
                strcpy(T->ptr[0]->Etrue, newLabel());
                strcpy(T->ptr[1]->Efalse, T->Efalse);
            }
            else {
                strcpy(T->ptr[0]->Etrue, T->Etrue);
                strcpy(T->ptr[0]->Efalse, newLabel());
            }
            strcpy(T->ptr[1]->Etrue, T->Etrue);
            strcpy(T->ptr[1]->Efalse, T->Efalse);
            T->ptr[0]->offset = T->offset;
            T->ptr[1]->offset = T->offset;
            boolExp(T->ptr[0]);
            T->width = T->ptr[0]->width;
            boolExp(T->ptr[1]);
            T->width = (T->width < T->ptr[1]->width) ? T->ptr[1]->width : T->width;
            break;
        case NOT:
            strcpy(T->ptr[0]->Etrue, T->Efalse);
            strcpy(T->ptr[0]->Efalse, T->Etrue);
            boolExp(T->ptr[0]);
            break;

        default:
            break;
        }
    }
}

void id_exp(struct ASTNode *T){
    int rtn, num, width;
    
    rtn = searchSymbolTable(T->type_id);
    if (rtn == -1)
        semantic_error(T->pos, T->type_id, "变量为定义");
    if (symbolTable.symbols[rtn].flag == 'F')
        semantic_error(T->pos, T->type_id, "是函数");
    else {
        T->place = rtn;
        T->type = symbolTable.symbols[rtn].type;
        T->offset = symbolTable.symbols[rtn].offset;
        T->width = 0;
    }
}

void int_exp(struct ASTNode *T){
    int rtn, num, width;
    T->place = fill_Temp(newLabel(), LEV, T->type, 'T', T->offset);
    T->type = INT;
    T->width = 4;
}

void float_exp(struct ASTNode *T){
    int rtn, num, width;
    T->place = fill_Temp(newLabel(), LEV, T->type, 'T', T->offset);
    T->type = FLOAT;
    T->width = 4;
}

void char_exp(struct ASTNode *T){
    int rtn, num, width;
    T->place = fill_Temp(newLabel(), LEV, T->type, 'T', T->offset);
    T->type = CHAR;
    T->width = 1;
}

void string_exp(struct ASTNode *T){
    int rtn, num, width;
    T->place = fill_Temp(newLabel(), LEV, T->type, 'T', T->offset);
    T->type = STRING;
    // T->width
}

void assignop_exp(struct ASTNode *T){
    int rtn, num, width;
    if (T->ptr[0]->kind != ID){
        semantic_error(T->pos, "", "赋值语句需要左值");
    }
    else {
        Exp(T->ptr[0]);
        T->ptr[1]->offset = T->offset;
        Exp(T->ptr[1]);
        T->type = T->ptr[0]->type;
        T->width = T->ptr[1]->width;
    }
}

void relop_exp(struct ASTNode *T){
    T->type = INT;
    T->ptr[0]->offset = T->offset;
    T->ptr[1]->offset = T->offset;
    Exp(T->ptr[0]);
    Exp(T->ptr[1]);
}

void args_exp(struct ASTNode *T){
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
    T->width = T->ptr[0]->width;
    if(T->ptr[1]){
        T->ptr[1]->offset = T->offset + T->ptr[0]->width;
        Exp(T->ptr[1]);
        T->width += T->ptr[1]->width;
    }
}

void op_exp(struct ASTNode *T){
    int rtn, num, width;
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
    T->ptr[1]->offset = T->offset + T->ptr[0]->width;
    Exp(T->ptr[1]);
    if(T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT){
        T->type = FLOAT;
        T->width = T->ptr[0]->width + T->ptr[1]->width + 4;
    }
    else{
        T->type = INT;
        T->width = T->ptr[0]->width + T->ptr[1]->width + 2;
    }
    T->place = fill_Temp(newLabel(), LEV, T->type, 'T', T->ptr[0]->width + T->ptr[1]->width);
    T->width = T->ptr[0]->width + T->ptr[1]->width + (T->type == INT ? 4 : 8);
}

void func_call_exp(struct ASTNode *T){
    int rtn, num, width;
    struct ASTNode *T0;
    rtn = searchSymbolTable(T->type_id);
    if (rtn == -1) {
        semantic_error(T->pos, T->type_id, "函数未定义");
        return;
    }
    if (symbolTable.symbols[rtn].flag != 'F'){
        semantic_error(T->pos, T->type_id, "不是一个函数");
        return;
    }
    T->type = symbolTable.symbols[rtn].type;
    width = T->type == INT ? 4 : 8;
    if(T->ptr[0]){
        T->ptr[0]->offset = T->offset;
        Exp(T->ptr[0]);
        T->width = T->ptr[0]->width;
    }
    else {
        T->width = width;
    }
    match_param(rtn, T->ptr[0]);
    T0 = T->ptr[0];
    T->place = fill_Temp(newLabel(), LEV, T->type, 'F', T->offset+T->width-width);
}

void not_exp(struct ASTNode *T){
    T->type = INT;
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
}

void unminus_exp(struct ASTNode *T){
    T->type = T->ptr[0]->type;
    T->ptr[0]->offset = T->offset;
    Exp(T->ptr[0]);
}

void exp_array(struct ASTNode *T){

}

void exp_struct_tag(struct ASTNode *T){

}
