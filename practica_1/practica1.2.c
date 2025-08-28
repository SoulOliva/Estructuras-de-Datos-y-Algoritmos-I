#include <stdio.h>

int main() {
	int n;
	int a[10];
	int suma=0;
	int resta=0;
	float promedio=0;
	int val_max;
	int val_min;
	int pos_max;
	int pos_min;
	
	printf("Ingresa cuantos elementos tendra tu arreglo, maximo 10: \n");
	scanf("%d", &n);
	if( n<0) {
		printf("No se aceptan numeros negativos o igual 0, intenta de nuevo");
		return 0;
	}
	if( n<11) {
		printf("Dame los %d elementos de tu arreglo: \n", n);
		for(int i=0; i<n; i++) {
			printf("Elemento %d: ", i+1);
			scanf("%d", &a[i]);
            suma+=a[i];
            promedio= (float)suma/n;
		}
		resta=a[0];
        for(int i=1; i<n; i++) {
        resta-=a[i];
        }
        val_max=a[0];
        val_min=a[0];
        pos_max=0;
        pos_min=0;
	    for(int i=1; i<n; i++){
	        if(a[i] > val_max){ 
	           val_max=a[i];
	           pos_max=i;
	           }
	        if(a[i] < val_min){ 
	           val_min=a[i];
	           pos_min=i;
	           }
	    }
	    
		
		printf("La suma es: %d\n", suma);
		printf("La resta es: %d\n", resta);
		printf("El promedio es: %f\n", promedio);
		printf("El valor minimo es: %d", val_min);
		printf(" y se encuntra en la posicion %d\n", pos_min);
		printf("El valor maximo es: %d", val_max);
     	printf(" y se encuntra en la posicion %d\n", pos_max);
		return 0;
    } else {
      printf("Estas ingresando mas de 10 valores, no es valido, vuelve a intentarlo\n");
      }
      return 0;
}
