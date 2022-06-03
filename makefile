all: TrabalhoED2

TrabalhoED2: intervalos.o ctrl_F.o main.o
	gcc -o TrabalhoED2 intervalos.o ctrl_F.o main.o

intervalos.o: intervalos.c
	gcc -o intervalos.o -c intervalos.c

ctrl_F.o: ctrl_F.c
	gcc -o ctrl_F.o -c ctrl_F.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe

run: 
	./TrabalhoED2
