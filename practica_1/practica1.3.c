#include <stdio.h>

int main() {
	int n;
	int a[10];
	int pos;

	printf("Ingresa cuantos elementos tendra tu arreglo, maximo 10: \n");
	scanf("%d", &n);
	pos=n;
	if( n<0) {
		printf("No se aceptan numeros negativos o igual 0, intenta de nuevo");
		return 0;
	}
	if( n<11) {
		printf("Dame los %d elementos de tu arreglo: \n", n);
		for(int i=0; i<n; i++) {
			printf("Elemento %d: ", i+1);
			scanf("%d", &a[i]);
		}
	
	printf("Ël arrglo invertido seria: \n");
	printf("[");
	for(int i=n-1; i>-1; i--){
	    printf("%d ", a[i]);
	}
	printf("]");
	return 0;
	}
}
