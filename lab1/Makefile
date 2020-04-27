result: grammarTree.l grammarTree.h grammarTree.y
	bison -d grammarTree.y
	flex grammarTree.l
	gcc grammarTree.tab.c lex.yy.c grammarTree.c -o parser