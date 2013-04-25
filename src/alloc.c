#include "alloc.h"

static int address = 0;
static int fd = -1;
/*static char *ptr = (char*)-1;*/

void name_file(int *i) {
	char fileName[20];
	pid_t pid = getpid();
	sprintf(fileName, "%s%d", "memory-", pid);
	debug_print(fileName);
	debug_print("\n");
}

int multiple_of_eight(int nb) {
	if (nb%8 == 0) {
		return nb;
	}
	else {
		return multiple_of_eight(nb+1);
	}
}

int open_file(char *fileName) {
	int result = -1;
	fd = open(fileName, O_RDWR|O_CREAT|O_EXCL, 0600);
	if (-1 == fd) { 
		perror("Error opening the file"); 
		return -1; 
	}
	result = lseek(fd, FILE_SIZE-1, SEEK_SET);
	if (-1 == result) {
		perror("Error calling lseek() to 'stretch' the file");
		return -1;
    }
    result = write(fd, "", 1);
	    if (-1 == result) {
		perror("Error writing last byte of the file");
		return -1;
    }printf("fd %d\n", fd);
	return fd;
}

void *mmap_file(void) {
	void *ptr = NULL;
	ptr = mmap(0, FILE_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if ((void*) -1 == ptr) {
		perror("Error mmaping a file"); 
		return (void*)-1; 
	}
	address = (int)ptr+24;
	return ptr;
}

void *mymalloc(size_t size) {
	char *ptr;
	int newA;
	Header *h;
	h = (Header*)(address-16);
	h->size = size;
	h->init = 1;
	h->freed = 0;
	h->next = NULL;
	ptr = (char*)(address);
	address += size;
	newA = multiple_of_eight(address);
	if (newA != address) {
		address = newA+16;
	}printf("adress -> %d\n", (int)h);
	return ptr;
}

void myfree(void *ptr) {
	int i=0;
	char *tmp = (char*)ptr;
	/*int pointeur = (int)ptr;
	Header *p = NULL;
	p = (int)ptr - sizeof(Header);
	printf("free adress -> %d of header %d\n", (int)ptr, (int)p);*/
	/*if (ptr != NULL) {
		p->freed = 1;
		while (i < p->size) {
			tmp[i] = '\0';
			i++;
		}
	}*/
}
 
void *mycalloc(size_t size) {
	int i;
	char *ptr;
	ptr = (char*)mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if ((void*) -1 == ptr) {
		perror("Error trying to mmapping the file"); 
		return NULL; 
	}
	for (i=0 ; i<size ; i++) {
		ptr[i] = 0;
	}
	return ptr;
}

void init_child() {
	
}

int fork() {
	int tmp;
	tmp = syscall(SYS_fork);
	if(0 == tmp) {
		debug_print("Creating new process\n");
		init_child();
	}
	return tmp;
}