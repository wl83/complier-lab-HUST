result: grammarTree.l grammarTree.h grammarTree.y
	bison -d grammarTree.y
	flex grammarTree.l
	gcc -o parser grammarTree.c grammarTree.tab.c lex.yy.c