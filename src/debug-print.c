#include "debug-print.h"


void fail_with(char *message, int i) {
	int nb;
	nb = write(STDERR_FILENO, message, strlen(message));
	if (-1 == nb) {
		perror("write\n");
		exit(EXIT_FAILURE);
	}
	exit(i);
}

void debug_print(char *s) {
	int nb;
	nb = write(STDERR_FILENO, s, strlen(s));
	if (-1 == nb) {
		fail_with("Error : write\n", errno);
	}
}

void debug_println_int(char *prompt, int i) {
	char tmp[20]; 
	sprintf(tmp, "%s %d", prompt, i);
	debug_print(tmp);
	debug_print("\n");
}

void debug_println_ptr(char *prompt, void *ptr) {
	char tmp[20]; 
	sprintf(tmp, "%s %p", prompt, ptr);
	debug_print(tmp);
	debug_print("\n");
}

/*
void debug_println_int(char *prompt, int i) qui écrit, sur la sortie d’erreur, la chaîne de caractères prompt suivie de la valeur de l’entier i et d’un retour à la ligne ;
void debug_println_ptr(char *prompt, void *ptr) qui écrit, sur la sortie d’erreur, la chaîne de caractères prompt suivie de la valeur du pointeur ptr et d’un retour à la ligne ;
void fail_with(char *message, int i) qui écrit, sur la sortie d’erreur, la chaîne de caractères message avant de terminer le programme avec exit() en retournant la valeur i.
*/
