#include<stdio.h>
#include<stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};
//Funcion para insertar 
void insert(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato= valor;
    //Si la lista esta vacia
    if(*inicio==NULL){
        *inicio=nuevo;
        nuevo->siguiente=nuevo;
        nuevo->anterior=nuevo;
        return;
    }
    //Manejando el ultimo nodo
    struct Nodo *ultimo=(*inicio)->anterior;
    nuevo->siguiente=*inicio; //Recorriendo los demas nodos para la insercción
    nuevo->anterior=ultimo;
    ultimo->siguiente=nuevo;
    (*inicio)->anterior=nuevo;
}

//Función para recorrer hacia adelante
void recorrer(struct Nodo* inicio){
    if(inicio==NULL){
        printf("Lista vacia\n");
        return;
    } //Impresión de los datos de la lista
    struct Nodo *actual=inicio;
    do{
        printf("%d -> ",actual->dato);
        actual=actual->siguiente;
    } while (actual != inicio);
    printf("inicio\n");
}

//Función para eliminar en la lista
void eliminar(struct Nodo **inicio, int valor){
    if(*inicio==NULL){
    printf("Lista vacia\n");
    return;
    }
    struct Nodo *actual=*inicio;
    //Buscando el valor a eliminar
    do {
        if (actual->dato==valor)
            break;
        actual=actual->siguiente;
    } while(actual != *inicio);

    // Si no se encontró
    if (actual->dato != valor) {
        printf("Valor no encontrado, vuelve a intentarlo\n");
        return;
    }

    //Cuando solo hay nodo
    if (actual->siguiente == actual) {
        free(actual);
        *inicio = NULL;
        return;
    }

    //Reacomdar los nodos para tener una secuencia correcta
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    //Si se elimina el primer nodo...
    if (actual == *inicio){
        *inicio = actual->siguiente;

    free(actual);
    }
}


int main() {
    struct Nodo *inicio = NULL;
    int n;
    int valor;
    printf("/-------------------LISTA DOBLEMENTE LIGADA CIRCULAR-----------------/\n");
    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        //Llamado de funciones
        insert(&inicio, valor);
    }
    printf("Lista circular: ");
    recorrer(inicio);

    printf("Valor a eliminar: ");
    scanf("%d", &valor);

    eliminar(&inicio, valor);

    printf("Lista al eliminar: ");
    recorrer(inicio);
    return 0;
}


/*
1. ¿Qué diferencia hay entre una lista doblemente ligada y una circular
doblemente ligada? Una termina en NULL, mientras que la otra esta unida a si misma, conectada con el inicio.

2. ¿Qué errores pueden causar ciclos infinitos al recorrer una lista circular? No actualizar un apuntador de un nodo o 
dejar condiciones sin concluir.

3. ¿Qué tipo de aplicaciones reales usan este tipo de listas (por ejemplo,
reproductores multimedia, navegación en historial, juegos)?
En juegos como revisar el inventario o items guardados, reproducciones de playlist o creación de loops infinitos.
*/