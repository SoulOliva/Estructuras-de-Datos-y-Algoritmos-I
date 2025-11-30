#include<stdio.h>
#include<stdlib.h>
#define MAX 5 //Se define como 5 el número máximo de elementos

//---------------DEFINCIÓN DE ESTRUCTURAS Y FUNCIONES DE STACK Y QUEUE---------------//

//ESTRUCTURA DE PILA//

typedef struct {
	int elements[5];
	int top;
} Stack;

//ESTRUCTURA DE COLA//
typedef struct Queue {
    int datos[MAX];
    int front;
    int back;
} Queue;

//FUNCIÓN DE INICIALIZAR PILA
void EmptyStack(Stack *p) {
	p->top=-1;
	printf("Pila inicializada vacia\n");
}

//FUNCIÓN DE INSERTAR ELEMENTOS EN UNA PILA
int PushStack(Stack *p, int value) {
	if(p->top==9) {
		printf("La pila esta llena\n");
		return 0;
	}
	p->top++;
	p->elements[p->top]= value;
	return 1;
}

//FUNCION DE QUITAR ELEMENTOS DE LA PILA

int PopStack(Stack *p) {
	if(p->top==-1) {
		printf("No hay mas elementos que eliminar, la pila esta vacia");
		return 0;
	}
	int value=p->elements[p->top];
	p->top--;
	return value;
}

//FUNCIÓN DE MOSTRAR EL ESTADO DE LA PILA

int StackStatus(Stack *p) {
	if(p->top==-1) {
		printf("La pila esta vacia");
		return 1;
	} else {
		printf("Estado actual de la pila:\n");
		for(int i = 0; i <= p->top; i++) {
			printf("%d ", p->elements[i]);
		}
		printf("\n");
	}
	return 0;
}


//FUNCIÓN DE INICIALIZAR COLA
void EmptyQueue(Queue *q) {
    q->front=0;
    q->back=-1;
    printf("Cola vacia\n");
}

//FUNCIÓN DE AGREGAR ELEMENTOS DE UNA COLA

void Enqueue(Queue *q, int dato) {
    if (q->back==MAX-1) {
        printf("Cola llena\n");
        return;
    }

    q->back++;
    q->datos[q->back] = dato;
}

//FUNCIÓN DE QUITAR ELEMENTOS DE UNA COLA

int Dequeue(Queue *q) {
    if(q->front>q->back) {
       printf("Cola vacía\n");
       return -1;
    }

    int valor=q->datos[q->front];
    q->front++;
    return valor;
}

//FUNCIÓN DE MOSTRAR EL ESTADO DE LA COLA

void QueueStatus(Queue *q) {
    if (q->front > q->back) {
        printf("Cola vacía\n");
        return;
    }

    printf("Cola actual: ");
    for (int i=q->front; i<= q->back; i++) {
        printf("%d ", q->datos[i]);
    }
    printf("\n");
}

//----------INICIO DEL PROGRAMA(MAIN)-------------//

int main() {
	int n;     //CREACION DE VARIABLES Y NOMBRAMIENTO DE ESTRUCTURAS
	int n2;
	int opcion;
	Stack pila;
	Queue cola;
	printf("¿Qué acción desea realizar?\n1)Crear una pila, hacer push y pop en la misma\n2)Crear una cola, encolar y desencolar\nOpción...");
	scanf("%d", &opcion); 
	if(opcion>3){ //SI "OPCION" NO ESTA DENTRO DE LOS VALORES SEÑALADOS
	    printf("Opcion no valida, vuelve a intentarlo");
	    return 1;
	}
    
    //----------PROCESO DE PILA(STACK)-------------//
    
	if(opcion==1) { //SI "Opcion" es 1, hará...
		EmptyStack(&pila); //Crea una pila
		printf("¿Cuántos elementos deseas apilar?(Maximo 5)\n");
		scanf("%d", &n); //pide al usuario cuantos elementos desea insertar
		if(n<5) {
			for(int i=0; i<n; i++) { //Proceso para llenar la pila
				int valor;
				printf("Dame el elemento %d: ", i+1);
				scanf("%d", &valor);

				if(PushStack(&pila, valor))
					printf("Contenido: ");

				for(int i=0; i<= pila.top; i++) {
					printf("%d ", pila.elements[i]);
				}
				printf("\n");
			}
		} else { //Si quiere ingresar mas de 5 elementos
			printf("El número de elementos que deseas ingresar es mayor a 5");
			return 1;
		} //Llamado de Pop en la pila
		printf("Inicio de función de Pop...\nCuantos elementos deseas eliminar de la pila (Maximo 5): ");
		scanf("%d", &n2);
		if(n2<5) {
			for (int i=0; i<n2; i++) {

				PopStack(&pila);
				printf("--------Quitado elemento de la pila---------\n", i);
				StackStatus(&pila); //Muestra el estado de la pila tras la operación
			}
		}
		return 0;

	}
	
	
	
	 //-----------PROCESO DE COLA(QUEUE)------------//
	if(opcion==2) {
		EmptyQueue(&cola); //Crea una cola
		int m;
		int z;
		printf("¿Cuántos elementos deseas encolar?(maximo 5 elementos): ");
		scanf("%d",&m); //Pide al usuario cuantos elementos desea ingresar en el arreglo(cola)
		if(m<6 && m>0) { //Proceso para llenar la cola
			for(int i=0; i<m; i++) {
				int dato;
				printf("Elemento %d:  \n",i+1);
				scanf("%d", &dato);
				Enqueue(&cola, dato); //Llama la función para encolar
			}
			QueueStatus(&cola); //Muestra la cola
		printf("Cuantos elementos de la cola deseas desencolar: ");
		scanf("%d", &z); //Pide al usuario cuantos elementos desea desencolar
		if(z<6 && z>0){ //Proceso para desencolar
	    	for(int i=0; i<z; i++) {
				int dato;
				Dequeue(&cola); //Llama a la función para quitar z elementos desde el ultimo que se ingreso
			}
			printf("Quitando elementos de la cola...\n");
			QueueStatus(&cola); //Muestra el estado del arreglo
		
			return 1;
		}
		if(m>5) { //Si desea encolar mas datos
			printf("No puedes encolar mas de 5 datos");
			return 0;
		}
	}

}
	return 0;
}


//--------------SECCIÓN DE PREGUNTAS---------------//
/*
1. ¿Qué diferencias notaron entre el orden de salida de la pila y de la cola?
En que una es de tipo LIFO(Last in, First out) mientras que la otra es FIFO(First in, First out).


2. ¿Qué sucede si intentan hacer pop en una pila vacía o dequeue en una cola vacía?
Esta tendra que arrojar un error, porque no hay elementos en la estructura y es un error de lógica.


3. ¿Qué sucede si intentan insertar más elementos que la capacidad máxima?
Podria ocurrir un desborde de memoria porque ya hay una memoria reservada y esta no puede ser reservada.
*/