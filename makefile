all: TrabalhoED2

TrabalhoED2: genoma.o intervalos.o ctrl_F.o main.o
	gcc -o TrabalhoED2 genoma.o intervalos.o ctrl_F.o main.o

genoma.o: genoma.c
	gcc -o genoma.o -c genoma.c

intervalos.o: intervalos.c
	gcc -o intervalos.o -c intervalos.c

ctrl_F.o: ctrl_F.c
	gcc -o ctrl_F.o -c ctrl_F.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe ./*.txt
	clear

run: 
	./TrabalhoED2
