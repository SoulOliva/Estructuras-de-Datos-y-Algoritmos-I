#include <stdio.h>
#include <stdlib.h>

//Estructura del nodo

typedef struct Nodo{
    int valor;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;
int *inicio=NULL;

//Declaraciones de las funciones

//Funcion para insertar al inicio
void insertarInicio(struct Nodo **inicio, int valor) {
    Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
    if(nuevo==NULL) {
    printf("No se pudo asignar memoria de forma correcta");
    return;
    }
    nuevo->anterior=NULL;
    nuevo->valor=valor;
    nuevo->siguiente=*inicio;

    if(*inicio!=NULL)
        (*inicio)->anterior=nuevo;
    *inicio=nuevo;
}

//Funcion para insertar al final
void insertarFinal(Nodo **inicio, int valor) {
    Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
    if(nuevo==NULL) {
        printf("No se pudo asignar memoria de forma correcta");
        return;
    }
    nuevo->valor=valor;
    nuevo->siguiente=NULL;

    if(*inicio==NULL) {
       nuevo->anterior=NULL;
       *inicio=nuevo;
       return;
    }

    Nodo *temp=*inicio;
    while(temp->siguiente!=NULL)
    temp=temp->siguiente;

    temp->siguiente=nuevo;
    nuevo->anterior=temp;
}

//Funcion para recorrer hacia adelante en la lista
void recorrerAdelante(struct Nodo *inicio) {
    printf("Lista hacia adelante: [ ");
    Nodo *temp=inicio;

    while(temp!=NULL){
        printf("%d ", temp->valor);
        temp=temp->siguiente;
    }
    printf("]");
    printf("\n");
}

//Funcion para recorrer hacia atrás en la lista
void recorrerAtras(Nodo *inicio) {
    if(inicio==NULL) {
        printf("Lista vacía");
        return;
    }
    Nodo *temp=inicio;
    while(temp->siguiente!=NULL)
        temp=temp->siguiente;

    printf("Lista  hacia atrás: [");
    while (temp!=NULL){
        printf("%d ",temp->valor);
        temp=temp->anterior;
    }
    printf("]");
    printf("\n");
}

//Funcion para eliminar un nodo 
void eliminar(Nodo **inicio, int valor) {
    Nodo *temp = *inicio;

    //Busca el nodo a eliminar...
    while(temp!=NULL && temp->valor!=valor)
        temp=temp->siguiente;

    if (temp==NULL) {
        printf("Valor no encontrado, intenta otra vez con otro elemento\n");
        return;
    }

    //Si el elemento a eliminar esta en el inicio...
    if(temp==*inicio) {
        *inicio=temp->siguiente;
        if(*inicio!=NULL)
          (*inicio)->anterior=NULL;
        free(temp);
        return;
    }

    //Si el elemento a eliminar esta en el final
    if(temp->siguiente==NULL) {
        temp->anterior->siguiente = NULL;
        free(temp);
        return;
    }

    //Si el elemento esta en la lista, movera a los nodos que estaban antes y despues del nodo eliminado                      
    temp->anterior->siguiente=temp->siguiente;
    temp->siguiente->anterior=temp->anterior;
    free(temp);
}

//Funcion para iberar toda la lista
void liberar(Nodo *inicio) {
    Nodo *temp = inicio;
    while(temp!=NULL) {
        Nodo *sig=temp->siguiente;
        free(temp);
        temp = sig;
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    Nodo *inicio=NULL;
    int n;
    int valor;
    
    printf("/-----------------LISTA DOBLEMENTE LIGADA---------------------/\n");
    
    printf("¿Cuantos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }

//Llamado de funciones
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    printf("\n¿Cuantos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);
    return 0;
}

/* PREGUNTAS:

1. ¿Por qué es más fácil eliminar un nodo intermedio en una lista doblemente
ligada que en una lista simple? Porque en la lista simple solo podemos ir en una dirección mientras que 
la doblemente ligada podemos ir hacia ambos teniendo esta libertad de manupular la lista

2. ¿Qué sucede si se olvida actualizar alguno de los punteros anterior o
siguiente? Los punteros se quedaran estancados en algun nodo de modo que no podra siquiera recorrer la lista

3. ¿En qué escenarios prácticos se usa una lista doblemente ligada? Navegadores web, repreduccion de musica, historial de busqueda, la creacion 
y destruccion de objetos comunes en un videojuego entre otras mas.
*/