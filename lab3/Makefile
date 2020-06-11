result: grammarTree.l grammarTree.h grammarTree.y
	bison -d grammarTree.y
	flex grammarTree.l
	gcc -g -o parser grammarTree.c grammarTree.tab.c lex.yy.c semantic_analysis.c semantic_case.c code.c exp.c