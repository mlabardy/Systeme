#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/* Fonction qui écrit la chaîne de caractères s sur la sortie d’erreur. */
void debug_print(char *s);

/* Fonction qui écrit, sur la sortie d’erreur, la chaîne de caractères prompt suivie de la valeur de l’entier i et d’un retour à la ligne. */
void debug_println_int(char *prompt, int i);

/* Fonction qui écrit, sur la sortie d’erreur, la chaîne de caractères prompt suivie de la valeur du pointeur ptr et d’un retour à la ligne. */
void debug_println_ptr(char *prompt, void *ptr);
 
/* Fonction qui écrit, sur la sortie d’erreur, la chaîne de caractères message avant de terminer le programme avec exit() en retournant la valeur i. */
void fail_with(char *message, int i);

#endif
