#include "semantic.h"

void semantic_error(int line, char *msg1, char *msg2){
    printf("在%d行, %s, %s\n", line, msg1, msg2);
}

void prn_symbol(){
    int i = 0;
    char *symbolsType;
    printf("  %6s  %6s   %6s   %6s  %4s  %6s\n", "变量名", "别名", "层号", "类型", "标记", "偏移量");
    for (i = 0; i < symbolTable.index; i++){
        if (symbolTable.symbols[i].type == INT) {
            symbolsType = "int";
        }
        if (symbolTable.symbols[i].type == FLOAT) {
            symbolsType = "float";
        }
        if (symbolTable.symbols[i].type == CHAR) {
            symbolsType = "char";
        }
        if (symbolTable.symbols[i].type == STRING) {
            symbolsType = "string";
        }
        printf("%6s %6s %6d  %6s %4c %6d\n", symbolTable.symbols[i].name, symbolTable.symbols[i].alias, symbolTable.symbols[i].level,
                                             symbolTable.symbols[i].type, symbolTable.symbols[i].flag, symbolTable.symbols[i].offset);

    }
}

int searchSymbolTable(char *name) {
    int i;
    for (i = symbolTable.index - 1; i >= 0; i--){
        if (!strcmp(symbolTable.symbols[i].name, name)){
            return i;
        }
    }
    return -1;
}

int fillSymbolTable(char *name, char *alias, int level, int type, char flag, int offset){
    int i;
    for (i = symbolTable.index - 1; symbolTable.symbols[i].level == level || (level == 0 && i >= 0); i--) {
        if (level == 0 && symbolTable.symbols[i].level == 1)
            continue;
        if (!strcmp(symbolTable.symbols[i].name, name))
            return -1;
    }
    strcpy(symbolTable.symbols[symbolTable.index].name, name);
    strcpy(symbolTable.symbols[symbolTable.index].alias, alias);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    symbolTable.symbols[symbolTable.index].offset = offset;
    return symbolTable.index++;
}

int fill_Temp(char *name, int level, int type, char flag, int offset){
    strcpy(symbolTable.symbols[symbolTable.index].name, "");
    strcpy(symbolTable.symbols[symbolTable.index].alias, name);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    symbolTable.symbols[symbolTable.index].offset = offset;
    return symbolTable.index++; //返回的是临时变量在符号表中的位置序号
}

int match_param(int i, struct ASTNode *T){
    int j, num;
    int type1, type2;
    num = symbolTable.symbols[i].paramnum;
    if (num == 0 && T == NULL)
        return 1;
    for (j = 1; j < num; j++){
        if (!T){
            semantic_error(T->pos, "", "函数调用的参数太少");
            return 0;
        }
        type1 = symbolTable.symbols[i + j].type;
        type2 = T->ptr[0]->type;
        if(type1 != type2) {
            semantic_error(T->pos, "", "参数类型不匹配");
            return 0;
        }
        T = T->ptr[1];
    }
    if(T->ptr[1]){
        semantic_error(T->pos, "", "函数调用的参数太多");
        return 0;
    }
    return 1;
}

void Exp(struct ASTNode *T){
    if(T) {
        switch (T->kind)
        {
        case ID: // todo
            id_exp(T);
            break;
        case INT:
            int_exp(T);
            break;
        case FLOAT: // todo
            float_exp(T);
            break;
        case CHAR: // todo
            char_exp(T);
            break;
        case STRING: // todo
            string_exp(T);
            break;
        case STRUCT_TAG: // todo ???
            exp_struct_tag(T);
            break;
        case ASSIGNOP: // todo
            assignop_exp(T);
            break;
        case AND:
        case OR:
        case RELOP: // todo
            relop_exp(T);
            break;
        case PLUSASSIGNOP:
        case MINUSASSIGNOP:
        case STARASSIGNOP:
        case DIVASSIGNOP:
        case MODASSIGNOP: // todo
            break;
        
        case AUTOPLUS:
        case AUTOMINUS: // todo
            break;

        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case MOD: // todo
            op_exp(T);
            break;

        case NOT: // todo 
            not_exp(T);
            break;

        case UMINUS: // todo
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
        
        default:
            break;
        }
    }
}

void semantic_Analysis(struct ASTNode *T){
    if (T) {
        switch (T->kind)
        {
        case EXT_DEF_LIST:
            ext_def_list(T);
            break;
        case EXT_VAR_DEF:
            ext_var_def(T);
            break;
        case EXT_STRUCT_DEF:
            ext_struct_def(T);
            break;
        case STRUCT_DEF:
            struct_def(T);
            break;
        case STRUCT_DEC:
            struct_dec(T);
            break;
        case ARRAY_DEC: // todo
            array_dec(T);
            break;
        case FUNC_DEF:
            func_def(T);
            break;
        case FUNC_DEC:
            func_dec(T);
            break;
        case PARAM_LIST:
            param_list(T);
            break;
        case PARAM_DEC:
            param_dec(T);
            break;
        case COMP_STM:
            comp_stm(T);
            break;
        case DEF_LIST:
            def_list(T);
            break;
        case VAR_DEF:
            var_def(T);
            break;
        case STM_LIST:
            stm_list(T);
            break;
        case IF_THEN:
            if_then(T);
            break;
        case IF_THEN_ELSE:
            if_then_else(T);
            break;
        case WHILE:
            while_dec(T);
            break;
        case EXP_STMT:
            exp_stmt(T);
            break;
        case RETURN:
            return_dec(T);
            break;
        case ID:
        case STRUCT_TAG:
        case INT:
        case FLOAT:
        case CHAR:
        case STRING:
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
        case AUTOMINUS:
        case AUTOPLUS:
        case UMINUS:
        case NOT:
        case FUNC_CALL:
        case EXP_ARRAY:
            Exp(T);
            break;
        
        default:
            printf("default\n");
            break;
        }
    }
}

void semantic_Analysis0(struct ASTNode *T){
    symbolTable.index = 0;
    fillSymbolTable("read", "", 0, INT, 'F', 4);
    symbolTable.symbols[0].paramnum = 0;
    fillSymbolTable("x", "", 1, INT, 'P', 4);
    fillSymbolTable("write", "", 0, INT, 'F', 4);
    symbolTable.symbols[1].paramnum = 1;
    symbol_scope_TX.TX[0] = 0;
    symbol_scope_TX.top = 1;
    T->offset = 0;
    semantic_Analysis(T);
    prn_symbol();
}