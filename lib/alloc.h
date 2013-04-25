#ifndef ALLOC_H
#define ALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include "debug-print.h"

#define MAX_PAGE_NUMBER 5
#define NAME_SIZE 13
#define FILE_SIZE 80


typedef struct header {
	size_t size;
	char init;
	int freed;
	struct header *next;
} Header;

void name_file(int *i);

int multiple_of_eight(int nb);

int open_file(char *fileName);

void *mmap_file(void);

void *mymalloc(size_t size);

void myfree(void *ptr);

void *mycalloc(size_t size);

#endif