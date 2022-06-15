all: TrabalhoED2 Teste_Empirico

TrabalhoED2: genoma.o intervalos.o ctrl_F.o main.o
	gcc -o TrabalhoED2 genoma.o intervalos.o ctrl_F.o main.o

Teste_Empirico: genoma.o intervalos.o ctrl_F.o main_teste_empirico.o
	gcc -o Teste_Empirico genoma.o intervalos.o ctrl_F.o main_teste_empirico.o

genoma.o: genoma.c
	gcc -o genoma.o -c genoma.c

intervalos.o: intervalos.c
	gcc -o intervalos.o -c intervalos.c

ctrl_F.o: ctrl_F.c
	gcc -o ctrl_F.o -c ctrl_F.c

main_teste_empirico.o: main_teste_empirico.c
	gcc -o main_teste_empirico.o -c main_teste_empirico.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe ./*.txt
	clear

run: TrabalhoED2
	./TrabalhoED2

teste: Teste_Empirico
	./Teste_Empirico
