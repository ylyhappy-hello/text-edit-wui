chap3: clean parsetest.o y.tab.o lex.yy.c errormsg.o util.o lex.yy.o symbol.o table.o absyn.o parse.o prabsyn.o globalVarTable.o parseAST.o
	cc -g parsetest.o y.tab.o lex.yy.o errormsg.o util.o symbol.o table.o absyn.o parse.o prabsyn.o globalVarTable.o parseAST.o -o chap3

parsetest.o: parsetest.c errormsg.h util.h
	cc -g -c parsetest.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.grm
	yacc -dv tiger.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: tiger.lex y.tab.h errormsg.h util.h
	flex tiger.lex

util.o: util.c util.h
	cc -g -c util.c

symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

absyn.o: absyn.c absyn.h util.h symbol.h symbol.c 
	cc -g -c absyn.c

table.o: table.c table.h
	cc -g -c table.c

parse.o: parse.c parse.h
	cc -g -c parse.c

prabsyn.o: prabsyn.c prabsyn.h util.h symbol.h absyn.h
	cc -g -c prabsyn.c

globalVarTable.o: globalVarTable.c globalVarTable.h
	cc -g -c globalVarTable.c

parseAST.o: parseAST.c parseAST.h
	cc -g -c parseAST.c

pre: lex.yy.c y.tab.c

clean: 
	rm -f *.a lex.yy.c y.tab.c y.tab.h *.o

t1:
	./chap3 test1/simp.txt

t2:
	./chap3 test1/calc1.txt

t3: chap3 
	./chap3 test1/calc22.txt

t4: chap3 
	./chap3 test1/stm12.txt

t5: chap3 
	./chap3 test1/stm33.txt

lib: chap3
	ar rcs libhushu.a *.o

re:
	cat *result
