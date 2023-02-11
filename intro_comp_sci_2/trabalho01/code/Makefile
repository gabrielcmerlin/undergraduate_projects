all: main.o arquivos.o buscar.o desalocar.o divisao_string.o ordenar.o
	gcc -o main *.o

main.o: main.c
	gcc -c main.c
arquivos.o: arquivos.c
	gcc -c arquivos.c
buscar.o: buscar.c
	gcc -c buscar.c
desalocar.o: desalocar.c
	gcc -c desalocar.c
divisao_string.o: divisao_string.c
	gcc -c divisao_string.c
ordenar.o: ordenar.c
	gcc -c ordenar.c

clean:
	rm main *.o

run:
	./main