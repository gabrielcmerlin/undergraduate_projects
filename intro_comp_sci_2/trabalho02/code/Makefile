all: main.o entrada_saida.o aluno.o ordenacao.o
	gcc -o main *.o

main.o: main.c entrada_saida.h aluno.h ordenacao.h
	gcc -c main.c
entrada_saida.o: main.c entrada_saida.h aluno.h ordenacao.h
	gcc -c entrada_saida.c
aluno.o: main.c entrada_saida.h aluno.h ordenacao.h
	gcc -c aluno.c
ordenacao.o: main.c entrada_saida.h aluno.h ordenacao.h
	gcc -c ordenacao.c

clean:
	rm *.o main

run:
	./main
valgrind:
	valgrind ./main