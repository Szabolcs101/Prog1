#include <stdio.h>


void funct(char* p, int x){

	printf("p is \"%s\" and x is \"%d\n", p, x);
}


int main(){


	char* first = "Hello";
	char* last = "World";

	printf("%s %s\n", first, last);


	funct("József",42);
	funct("Árpád", 63);
	 return 0;

}