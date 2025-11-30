#include <stdio.h>
#include <stdlib.h>

struct Nodo {
int dato;
struct Nodo *siguiente;
};

struct Nodo *cabeza=NULL;


//------------LISTA SIMPLE------------//

//Función para insertar un dato
void insertInicio(struct Nodo **cabeza, int valor){
    struct Nodo *nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato=valor;
    
    if(nuevo==NULL){
    printf("No se pudo reservar memoria\n");
    return;
}
nuevo->dato=valor;
nuevo->siguiente= *cabeza;
*cabeza= nuevo;
}


//Función para recorrer la lista simple
void recorrer(struct Nodo *cabeza){
    struct Nodo *temp=cabeza;
    while(temp!=NULL){
        printf("%d->",temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

//Función para eliminar un nodo de la lista
void eliminar(struct Nodo **cabeza, int valor){
    if(*cabeza==NULL){ //Cuando no hay direccion de algun nodo en "cabeza"
        printf("La lista está vacía\n");
        return;
    }

    struct Nodo *temp=*cabeza;
    struct Nodo *prev=NULL;

    //Si el valor esta en la cabeza
    if(temp->dato==valor){
        *cabeza=temp->siguiente;
        free(temp);
        return;
    }

    //Buscar el valor en la lista
    while(temp!=NULL && temp->dato!=valor){
        prev=temp;
        temp=temp->siguiente;
    }

    if(temp==NULL){ //Si llega al final de la lista
        printf("Valor no encontrado\n");
        return;
    }
    
    //Une el lista donde se hizo el "corte" del nodo, con el nodo anterior y posterior del eliminado
    prev->siguiente=temp->siguiente;
    free(temp);
}

// Liberar memoria en lista simple
void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while(cabeza!=NULL){
        temp=cabeza;
        cabeza=cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabeza=NULL;  //Inicialización de estructuras
    struct Nodo *cabezaC=NULL;
    struct Nodo *ultimoC=NULL;
    int n, valor;

    printf("---------Lista Simple--------\n");
    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i=0; i < n; i++) { //Recolección de valores
        printf("Inserta valor: ");
        scanf("%d", &valor);

        insertInicio(&cabeza, valor);//Llamado de función para insertar
        recorrer(cabeza); //Llamado para recorrer en la lista los nodos
    }

    printf("\nContenido actual de la lista: "); //Impresion de la lista 
    recorrer(cabeza);

    printf("¿Qué valor deseas eliminar? ");
    scanf("%d", &valor);

    eliminar(&cabeza, valor); //Llamado de la funcion para eliminar

    printf("Lista después de eliminar:\n");//Muestra el estado de la lista al eliminar
    recorrer(cabeza);
    liberar(cabeza); //Liberar memoria
    return 0;
}


/*
Preguntas de LISTA SIMPLE:
1. ¿Por qué las listas enlazadas no requieren tamaño fijo como los arreglos? 
Porque usan memoria dinamica de modo que pueden crecer o decrecer tanto como el programa lo indique
2. ¿Qué diferencia hay entre mover la cabeza y modificar los punteros internos? 
En que uno deja a un lado a los nodos anteriores para avanzar, mientras que el otro crea una conexion entre todos los nodos de la lista

*/