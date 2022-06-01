all: TrabalhoED2

TrabalhoED2: intervalos.o contagemInterseccoes.o main.o
	gcc -o TrabalhoED2 intervalos.o contagemInterseccoes.o main.o

intervalos.o: intervalos.c
	gcc -o intervalos.o -c intervalos.c

contagemInterseccoes.o: contagemInterseccoes.c
	gcc -o contagemInterseccoes.o -c contagemInterseccoes.c 
main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe

run: 
	./TrabalhoED2
