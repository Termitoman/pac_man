#Mettre des variables pour pouvoir changer le compilateur ou les options facilement
cc = gcc
OPT = -Wall
SRC = plateau.c  affichage2.c joueur.c fantome.c main2.c
OBJ = $(SRC:.c=.o) 
MAIN = test
#$ veut dire que ce qui suit est à interpréter et pas à mettre comme ça



all : $(MAIN)
	@echo $(MAIN) has been compiled!

$(MAIN) : $(OBJ)
	$(cc) $^ -o $@

%.o : %.c
	$(cc) $(OPT) -c $^ -o $@

clean : 
	$(RM) $(OBJ) *~ $(MAIN)

clean2 : 
	$(RM) $(OBJ) *~
