#include <stdio.h>
int main(void) {
	int a[5] = {2, 4, 6, 8, 10};
	int *p = a; // p apunta a a[0]
	printf("1) a[1] = %d\n", a[1]);  //Mostrara la posición 1, que es 4
	printf("2) *(a+3) = %d\n", *(a+3)); //Mostrara la posición 3 que es 8
	printf("3) *p++ = %d\n", *p++); //Mostrara la posición 0 que es 2
	printf("4) *++p = %d\n", *++p); //Mostrara la posición 2 que es 6
	printf("5) p[1] = %d\n", p[1]); //Mostrara la posición 3 que es 8
	printf("6) *(p+=2) = %d\n", *(p+=2)); //Mostrara la posición 4 que es 10
	printf("7) p - a = %ld\n", p - a); //Mostrara 4
	return 0;
}

