SRC = src/
INCL = lib/
inc = -I./lib

PROJECT = alloc.o debug-print.o Main.o

TARGET = alloc

CFLAGS = -Wall -ansi -g -pedantic 

LDLIBS = -lMLV

CC = colorgcc

all: $(TARGET) clean

$(TARGET) : $(PROJECT)
	@echo "Création de l'exécutable -> $@"
	@$(CC) $(PROJECT) $(LDLIBS) -o $@ -lm

%.o : $(SRC)%.c $(INCL)%.h
	@echo "Création de l'objet $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@

clean :
	@echo "Suppression des fichiers objets : "
	rm -f *.o

mrproper : clean
	rm -f $(TARGET)
