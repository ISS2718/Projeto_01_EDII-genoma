# Gera executalvel de todos os programas 
all: TrabalhoED2 Teste_Empirico Teste_Empirico_CTRL_F



# Roda o programa TrabalhoED2
run: TrabalhoED2
	./TrabalhoED2

# Roda o programa Teste_Empirico
teste: Teste_Empirico
	./Teste_Empirico

# Roda o programa Teste_Empirico_CTRL_F
teste_CTRL_F: Teste_Empirico_CTRL_F
	./Teste_Empirico_CTRL_F



# Gera executalvel soh o TrabalhoED2
TrabalhoED2: genoma.o intervalos.o ctrl_F.o main.o
	gcc -o TrabalhoED2 objdir/genoma.o objdir/intervalos.o objdir/ctrl_F.o objdir/main.o

# Gera executalvel soh o Teste_Empirico
Teste_Empirico: genoma.o intervalos.o ctrl_F.o main_teste_empirico.o
	gcc -o Teste_Empirico objdir/genoma.o objdir/intervalos.o objdir/ctrl_F.o objdir/main_teste_empirico.o

# Gera executalvel soh o Teste_Empirico_CTRL_F
Teste_Empirico_CTRL_F: genoma.o intervalos.o ctrl_F.o main_teste_CTRL_F.o
	gcc -o Teste_Empirico_CTRL_F objdir/genoma.o objdir/intervalos.o objdir/ctrl_F.o objdir/main_teste_CTRL_F.o

# Preh Compila genoma.c	
genoma.o: genoma.c
	gcc -o objdir/genoma.o -c genoma.c

# Preh Compila intervalos.c	
intervalos.o: intervalos.c
	gcc -o objdir/intervalos.o -c intervalos.c

# Preh Compila ctrl_F.c
ctrl_F.o: ctrl_F.c
	gcc -o objdir/ctrl_F.o -c ctrl_F.c

# Preh Compila main.c
main.o: main.c
	gcc -o objdir/main.o -c main.c

# Preh Compila main_teste_empirico.c
main_teste_empirico.o: main_teste_empirico.c
	gcc -o objdir/main_teste_empirico.o -c main_teste_empirico.c

# Preh Compila main_teste_CTRL_F.c
main_teste_CTRL_F.o: main_teste_CTRL_F.c	
	gcc -o objdir/main_teste_CTRL_F.o -c main_teste_CTRL_F.c

# Exclui todos os arquivos .o; .exe; .txt na pasta raiz; limpa o terminal;
clear:
	rm objdir/*.o *.exe ./*.txt
	clear
