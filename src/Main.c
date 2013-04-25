#include "Main.h"

int main(int argc, char * argv[]) {
	int i = 0;
	char *ptr = NULL;
	char *string = NULL;
	int fd = -1;
	Header* p;
	char *tab = NULL;
	char size = sizeof(char)*7;
	name_file(&i);
	/*debug_println_ptr("dedans address ", &address);*/
	fd = open_file("t");
	if (fd != -1){
		ptr = (char*)mmap_file();
		string = (char*)mymalloc(size);
		if (string == NULL) {
			perror("Erreur d'allocation");
		}
		strcpy(string, "coucou ");

		/*p = (void*)string - sizeof(Header);
		printf("%s\n", string);
		printf("string:%d  size:%d  address:%d\n", (int)string, p->size, address);*/
		tab = (char*)mymalloc(size);
		if (tab == NULL) {
			perror("Erreur d'allocation");
		}
		strcpy(tab, "coucou ");
		p = (void*)string - sizeof(Header);
		
		/* printf("string -> %s | tab -> %s | poniteur address %d string address %d file %d\n", string, tab, (int)p, (int)string, (int)ptr); */
		printf("\n p->size %d\n", p->size);
		/*debug_println_ptr("dehors address ", &address);*/
		myfree(string);
		string = NULL;
		/*printf("string -> %s | tab -> %s\n", string, tab);*/
		
	}
	else
		printf("Erreur %d\n", fd);
	exit(EXIT_SUCCESS);
}