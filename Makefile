# Makefile

CC = gcc
CFLAGS = -Wall -g # Flags para compilação.
# LDLIBS = -lSDL2 -lSDL2_gfx -lm

objects = Main.o Hash.o
arq = Main.c Hash.c

# Regra default
all: Main

# Remove arquivos temporários
clean:
	-rm -f *~ *.o

# Remove tudo o que não for código-fonte original
purge: clean
	-rm -f Main

Main: $(objects)
	$(CC) $(CFLAGS) $(arq) -o Cadastramentos #$(LDLIBS)