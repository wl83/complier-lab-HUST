#include "grammarTree.h"

// semantic.c
void semantic_error(int line, char *msg1, char *msg2);
void prn_symbol();
int searchSymbolTable(char *name);
int fillSymbolTable(char *name, char *alias, int level, int type, char flag, int offset);
int fill_Temp(char *name, int level, int type, char flag, int offset);
int match_param(int i, struct ASTNode *T);
void Exp(struct ASTNode *T);
void semantic_Analysis(struct ASTNode *T);
void semantic_Analysis0(struct ASTNode *T);

// code.c
char *strcat0(char *s1, char *s2);
char *newAlias();
char *newLabel();
char *newTemp();
struct codenode *genIR(int op, struct opn opn1, struct opn opn2, struct opn result);
struct codenode *genLabel(char *label);
struct codenode *genGoto(char *label);
struct codenode *merge(int num, ...);
void prnIR(struct codenode *head);

// exp.c
void boolExp(struct ASTNode *T);
void id_exp(struct ASTNode *T);
void int_exp(struct ASTNode *T);
void float_exp(struct ASTNode *T);
void char_exp(struct ASTNode *T);
void string_exp(struct ASTNode *T);
void assignop_exp(struct ASTNode *T);
void relop_exp(struct ASTNode *T);
void args_exp(struct ASTNode *T);
void op_exp(struct ASTNode *T);
void func_call_exp(struct ASTNode *T);
void not_exp(struct ASTNode *T);
void unminus_exp(struct ASTNode *T);
void exp_array(struct ASTNode *T);
void exp_struct_tag(struct ASTNode *T);

// semantic_case.c
void ext_def_list(struct ASTNode *T);
void ext_var_list(struct ASTNode *T);
void ext_var_def(struct ASTNode *T);
void func_def(struct ASTNode *T);
void func_dec(struct ASTNode *T);
void ext_struct_def(struct ASTNode *T);
void struct_def(struct ASTNode *T);
void struct_dec(struct ASTNode *T);
void array_dec(struct ASTNode *T);
void param_list(struct ASTNode *T);
void param_dec(struct ASTNode *T);
void comp_stm(struct ASTNode *T);
void def_list(struct ASTNode *T);
void var_def(struct ASTNode *T);
void stm_list(struct ASTNode *T);
void if_then(struct ASTNode *T);
void if_then_else(struct ASTNode *T);
void while_dec(struct ASTNode *T);
void exp_stmt(struct ASTNode *T);
void return_dec(struct ASTNode *T);
void for_dec(struct ASTNode *T);
void switch_dec(struct ASTNode *T);
void case_dec(struct ASTNode *T);