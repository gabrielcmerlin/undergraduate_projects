all: hash_table.o aluno.o entrada_saida.o main.o
	gcc *.o -o exec -std=c99 -Wall -Werror -lm

hash_table.o: aluno.o hash_table.h
	gcc -c hash_table.c

aluno.o: aluno.h
	gcc -c aluno.c

entrada_saida.o: aluno.o hash_table.o entrada_saida.h
	gcc -c entrada_saida.c

main.o:
	gcc -c main.c

clean:
	rm *.o exec

run:
	./exec

valgrind:
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./exec