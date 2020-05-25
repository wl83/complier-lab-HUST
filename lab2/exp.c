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
    
}