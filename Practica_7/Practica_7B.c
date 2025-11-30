#include <stdio.h>
#include <stdlib.h>

struct Nodo {
int dato;
struct Nodo *siguiente;
};

//--------------LISTA CIRCULAR------------------//

//Función para insertar al inicio en la lista circular
void insertarCircularInicio(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
  
    if(nuevo==NULL){
        printf("No se pudo reservar memoria\n");
        return;
    }
    nuevo->dato=valor;
    if(*cabeza==NULL){
        *cabeza=nuevo;
        *ultimo=nuevo;
        nuevo->siguiente=nuevo;
        return;
    }
    nuevo->siguiente=*cabeza;
    *cabeza=nuevo;
    (*ultimo)->siguiente=*cabeza;
}
    
//Función para recorrer la lista cirular
void recorrerCircular(struct Nodo *cabeza) {
    if(cabeza==NULL){
    printf("Lista vacia");
    return;
    }
    struct Nodo *temp=cabeza;
    do{
        printf("%d -> ", temp->dato);
        temp=temp->siguiente;
    } while(temp!=cabeza);
    printf("Vuelve al inicio");

}

//Función para eliminar en la lista circular
void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza==NULL)
        return;

    struct Nodo *temp = *cabeza;
    struct Nodo *prev = *ultimo;

    //En el caso de que el valor a eliminar este en la cabeza
    if (temp->dato==valor) {

        // Si solo hay un nodo
        if (*cabeza == *ultimo) {
            free(temp);
            *cabeza=NULL;
            *ultimo=NULL;
            return;
        }
        //Moviendo el nodo
        prev->siguiente=temp->siguiente;
        *cabeza=temp->siguiente;
        free(temp);
        return;
    }

    //Buscando el valor
    
    prev=(*cabeza);
    temp=(*cabeza)->siguiente;
    

    while(temp!= *cabeza && temp->dato!=valor) {
        prev=temp;
        temp=temp->siguiente;
    }

    if(temp==*cabeza) {
       printf("Valor no encontrado, vuelve intentarlo con otro valor\n");
       return;
    }

    prev->siguiente=temp->siguiente;

    if(temp==*ultimo)
    *ultimo=prev;
    free(temp);
}



int main() {
	struct Nodo *cabeza=NULL;  //Inicialización de estructuras
	struct Nodo *cabezaC=NULL;
	struct Nodo *ultimoC=NULL;
	int n; 
	int valor;
	printf("//---------------------LISTA DOBLEMENTE LIGADA CIRCULAR--------------------//\n");
	printf("Cuántos valores deseas insertar en la lista circular? ");
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		printf("\nInserta valor: ");
		scanf("%d", &valor);

        //Llamado de funciones
		insertarCircularInicio(&cabezaC, &ultimoC, valor);
		recorrerCircular(cabezaC);
    }
    //Mostrar la lista
	printf("\nContenido actual: [");
	recorrerCircular(cabezaC);
	printf(" ]\n");
    printf("\n");
    //Eliminacion de un valor	
	printf("Qué valor deseas eliminar de la circular? ");
	scanf("%d", &valor);
	eliminarCircular(&cabezaC, &ultimoC, valor);
	printf("Lista después de eliminar: [");
	recorrerCircular(cabezaC);
    printf("]\n");
	return 0;
}
/*
PREGUNTAS

1. ¿Qué ventaja tiene la lista circular frente a la simple?
Que esta puede ser de dimensiones indefindas, de modo que puede crecer o decrecer su capacidad y usando eficientemente
su memoria no desperdiciando lugares

2. ¿Qué error puede causar un bucle infinito en una lista circular? Al no definir de una forma correcta ciclos for o 
condiciones dentro de las operaciones.

3. ¿Qué estructuras o programas del mundo real se basan en listas circulares?
En el uso de Buffers para poder almecenar temporalmente datos procesarlos en operaciones, como la reproduccion de
contenido multimedia, gestion de turnos en videojuegos o gestion de un sistema para un registro entre muchos mas.