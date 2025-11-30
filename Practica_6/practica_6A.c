#include<stdio.h>
#include<stdlib.h>

#define MAX 5  

//-----------COLA CIRCULAR-----------//

typedef struct {   //Creación de la cola circular
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

// Inicializar cola
void Inicializar(ColaCircular *c) {
    c->frente=0;
    c->final=0;
    c->size=0;
    printf("Cola circular inicializada\n");
}
//Función que vacía la cola
int isEmpty(ColaCircular *c) {
    return c->size==0;
}

//Función que llena una cola
int isFull(ColaCircular *c) {
    return c->size==MAX;
}

//Función de encolar
void enqueue(ColaCircular *c, int valor) {
    if(isFull(c)){ //Si la cola ya esta llena
        printf("Cola llena, no se puede encolar %d\n", valor);
        return;
    } //Sino...
    c->datos[c->final]=valor;
    c->final=(c->final+ 1)%MAX;
    c->size++;
}
//Función de desencolar 
int dequeue(ColaCircular *c) {
    if(isEmpty(c)) {  //Si la cola esta vacía
        printf("Cola vacía, no se puede desencolar\n");
        return -1;
    } //Sino...
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}
//Función de ver el elemento al frente de la cola
int peek(ColaCircular *c) {
    if(isEmpty(c)) { //Si la cola esta vacia
        printf("Cola vacía\n");
        return -1;
    } //Sino...
    return c->datos[c->frente];
} 

//Función de imprimir la cola
void printQueue(ColaCircular *c) {
    printf("Cola: "); 
    if(isEmpty(c)) { //Si la cola esta vacia
        printf("(vacia)\n");
        return;
    } //Sino...
    int i=c->frente;
    for(int m=0; m<c->size; m++) {
        printf("%d ", c->datos[i]);
        i=(i+ 1)%MAX;
    } 
    printf("\nFrente = %d Final = %d Size = %d\n", c->frente, c->final, c->size);
}



//--------------PRUEBAS DE COLA CIRCULAR-----------------//
int main() {

    printf("-------Prueba de Cola Circular------\n");
    printf("\n");
    ColaCircular c;
    Inicializar(&c);
    printf("\n");

    //Encolar 5,10,15
    printf("Encolando 5, 10 y 15\nLlamando a enqueue\n");
    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    printQueue(&c);
    printf("\n");

    //Desencolar uno
    printf("Desencolando 1...\n");
    dequeue(&c);
    printQueue(&c);
    printf("\n");

    // Encolar 20,25 y 30
    printf("Encolando 20, 25 y 30\n");
    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30); 
    printQueue(&c);
    printf("\n");
    printf("\n");
}
/*
Preguntas (A)
1. ¿Por qué en la cola circular no se desperdician posiciones como en la cola lineal?
Porque al eliminar un elemento, la circular actualiza el tamano del arreglo de modo que
esta al pendiente de cualquier modificación y no se desperdician espacios.

2. ¿Qué pasa cuando el índice final llega al final del arreglo? 
Regresa al principio de la cola, y si hay espacio, inserta

3. ¿Qué sucede si intentas encolar cuando la cola está llena?
Un error de logica junto con anuncio de error.
*/