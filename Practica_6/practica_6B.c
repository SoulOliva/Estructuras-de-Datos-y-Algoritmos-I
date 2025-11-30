#include <stdio.h>
#include<stdlib.h>
#define MAX 5

//---------COLA DOBLE---------//

typedef struct { //Creación de la Cola Doble
    int datos[MAX];
    int front;
    int size;
} Deque;

//Función de Inicializar
void InicializarD(Deque *d) {
    d->front=0;
    d->size=0;
    printf("Cola Doble inicializada\n");
}

//Función de Cola Doble vacia
int isEmptyD(Deque *d) {
    return d->size==0;
}

//Función de Cola Doble llena
int isFullD(Deque *d) {
    return d->size==MAX;
}

//Función para ver el final de la Cola
int getRear(Deque *d) {
    return (d->front + d->size - 1)%MAX;
}
//Función para insertar al frente en la Cola Doble
void insert_front(Deque *d, int valor) {
    if (isFullD(d)) {
        printf("Cola llena\n");
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;
}
//Función para insetar del otro lado de cola
void insert_rear(Deque *d, int valor) {
    if (isFullD(d)) {
        printf("Cola llena\n");
        return;
    }
    int rear = (d->front + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;
}
//Función para eleminnar lo que hay al frente de la cola
int delete_front(Deque *d) {
    if (isEmptyD(d)) {
        printf("Cola vacía\n");
        return -1;
    }
    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return valor;
}

//Función para eleminar lo que hay del otro lado de la cola
int delete_rear(Deque *d) {
    if (isEmptyD(d)) {
        printf("Cola vacía\n");
        return -1;
    }
    int rear=getRear(d);
    int valor=d->datos[rear];
    d->size--;
    return valor;
}
//Función para consultar lo que hay en frente
int peek_front(Deque *d) {
    if (isEmptyD(d)) {
        printf("Cola vacia\n");
        return -1;
    }
    return d->datos[d->front];
}
//Función para consultar lo que hay en el otro lado 
int peek_rear(Deque *d) {
    if (isEmptyD(d)) {
        printf("Cola vacía\n");
        return -1;
    }
    return d->datos[getRear(d)];
}
//Función para imprimir la cola
void printDeque(Deque *d) {
    printf("Deque: ");
    if (isEmptyD(d)) {
        printf("(vacio)\n");
        return;
    }
    int i = d->front;
    for (int cnt = 0; cnt < d->size; cnt++) {
        printf("%d ", d->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\nfront = %d rear = %d size = %d\n", d->front, getRear(d), d->size);
}
int main(){
printf("/----------Prueba de Cola Doble----------/\n");
    printf("\n");
    Deque d;
    InicializarD(&d);
    printf("\n");
    
    printf("Insertando 10, 15, 20, 30 y 40\nLlamando a Insert\n");
    insert_front(&d, 10);
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    insert_front(&d, 30);
    insert_rear(&d, 40);
    printDeque(&d);
    printf("\n");
    
    printf("Eliminando el frente y reverso\nLlamando a delete\n");
    delete_front(&d);
    delete_rear(&d);
    printDeque(&d);
    printf("\n");
    
    printf("Insertando en el frente 50 y atras 60\nLlamando a insert\n");
    insert_front(&d, 50);
    insert_rear(&d, 60);
    printDeque(&d);
    printf("\n");
    return 0;
}


//PREGUNTAS

/*
1. ¿Qué diferencia tiene el deque frente a la cola circular normal?
En la cola circular normal solo existe la insercciones por un lado, mientras que la doble permite insertar en ambos extremos de la cola.

2. ¿Qué operaciones permiten simular tanto FIFO como LIFO?
Insertar, eliminar, consultar el ultimo elemento, imprimir los elementos e incilar una estructura.

3. Investiga que aplicaciones prácticas tiene deque.
Se usan para acciones como el de navegacion para ir "atras" o "siguiente" en uso de ventanas, tambien se usa en la creación de listas de reproduccion de música, gestion de recursos de un procesador entre muchos mas.
 */