#include <stdio.h>

int main(void){
    int n;
    int a[10];

    printf("Ingresa cuantos elementos tendra tu arreglo, maximo 10\n");
    scanf("%d", &n);
    if( n<0) {
    printf("No se aceptan numeros negativos o igual a 0, intenta de nuevo");
    return 0;
    }
    if( n<11){
    printf("Dame los %d elementos de tu arreglo por favol\n", n);
    for(int i=0; i<n; i++){
       printf("Elemento %d: \n", i+1);
       scanf("%d", &a[i]);
    }
    
  
printf("Los elementos del arreglo son: \n");
printf("[ ");
  for (int i=0; i<n; i++){
      printf("%d ", a[i]); 
     }
printf(" ]");
printf("\n");
  
} else {
  printf("Estas ingresando mas de 10, vuelve a intentarlo\n");
}
return 0;
}