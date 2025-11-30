#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int paso;
    int *arr0;
    int *arr2;
    printf("¿Qué paso desea realizar?\nPaso 1: Reservar memoria con Malloc\nPaso 2: Reservar memoria con Calloc\nPaso 3-5: Llenar un arreglo\nPaso: ");
    scanf("%d",&paso); //Se pregunta al usuario que paso desea hacer leyendo la opción con la variable "paso"
    
    //-----------RESERVACIÓN DE MEMORIA CON MALLOC----------//
    
    if( paso==1){ //Caso 1 si quiere el paso 1
    printf("¿Cuántos enteros quieres almacenar? ");
    scanf("%d", &n);
    arr0=(int*)malloc(n*sizeof(int)); //Reservación de la memoria con malloc
    
    if(arr0==NULL){ //Condición para confirmar de que se reservó de forma correcta la memoria
        printf("No se pudo reservar memoria de forma correcta");
        return 1; 
    }
    printf("Espacio reservado correctamente con malloc!\nValor basura:%d", arr0); //impresion del valor de malloc
    free(arr0); //liberación de memoria del arreglo
return 0;
} 
    //----------RESERVACIÓN DE MEMORIA CON CALLOC--------------//
  
    if(paso==2){ //Caso 2 al seleccionar el paso 2
    printf("¿Cuántos enteros quieres almacenar? ");
    scanf("%d", &n);
    arr0=(int*)calloc(n, sizeof(int));
    if(arr0==NULL){ //Condición para confirmar de que se reservó de forma correcta la memoria
        printf("No se pudo reservar memoria de forma correcta");
        return 1;
    }
    printf("Espacio reservado correctamente con calloc!\n");
    printf("Contenido del arreglo:\n");
    for(int i= 0; i<n; i++){
    printf("%d ", arr0[i]);
    }
    free(arr0); //liberación de memoria
    return 0;
} 
    
    //-------------RESERVACIÓN DE MEMORIA CON REALLOC--------------//

    if(paso==3){ //3er caso, este abarca los pasos 3 al 5 de la practica
    printf("¿Cuántos valores deseas ingresar? ");
    scanf("%d", &n);//Pide al usuario n cantidad de enteros o elementos que estara conformado su arreglo
    arr2=(int*)calloc(n, sizeof(int));  //Reservación de memoria con Calloc
    for(int i=0; i<n; i++){
        scanf("%d", &arr2[i]); //Guarda los elementos registrados en el arreglo
    }
    printf("Tu arreglo es: [");
    for(int i=0; i<n; i++){
    printf(" %d", arr2[i]);  //Imprime el arreglo obtenido
    }
    printf(" ]\n");
    int nuevo;
    printf("¿Cuántos enteros deseas agregar al arreglo? : ");
    scanf("%d", &nuevo); //Obtiene cuantos elementos mas desea agregar
    int*arr3 = realloc(arr2, (n+nuevo)*sizeof(int)); //Cambio de tamaño del arreglo
    if(arr3==NULL){  //Condicion para confirmar que se pudo redimensionar el arreglo
        printf("No se pudo redimensionar el tamaño del arreglo");
        free(arr2);
        return 1;
    }
    arr2 = arr3; //Los elementos del arreglo los sobrepone en un nuevo arreglo
    for(int i=0; i<nuevo; i++){
        scanf("%d", &arr2[n+i]);
    }
    printf("Tu nuevo arreglo es [ "); //Impresión del nuevo arreglo
    for(int i=0; i<n+nuevo; i++){
    printf(" %d", arr2[i]);
    }
    printf(" ]\n");
    free(arr2); //  liberación de memoria 
    printf("Memoria liberada"); 
    return 0;
    }
    return 0;
}

// SECCION DE PREGUNTAS:
/*
1. ¿Qué diferencia observaron entre los valores iniciales con malloc y calloc?
Los valores de malloc son valores basura de Memoria que fue ocupada por otros datos, mientas con calloc iniciaba con ceros teniendo una mayor "limpieza".


2. ¿Qué sucede si en realloc piden un tamaño más grande que el original? ¿y más
pequeño?
Este mismmo empieza a reserva memoria para el nuevo tamaño que se le solicita, y cuando es mas pequeño truncara el bloque de memoria que requeria, para el arreglo nuevo. 


3. ¿Qué pasa si olvidan llamar a free?
Se crea un desbordamiento de memoria y esta se consumira de una forma absurda y puede perjudicar al mismo dispositivo.
*/        
        