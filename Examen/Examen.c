#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, nuevos, total;
	float *cal;
	float suma=0;
	float promedio;
	int respuesta;

	printf("Cuantos estudiantes desea ingresar? ");
	scanf("%d", &n);
	cal=(float*)malloc(n*sizeof(float));
	if (cal==NULL) {
		printf("No se pudo asignar memoria\n");
		return 1;
	}
	for (int i=0; i<n; i++) {
		printf("Calificaciones del estudiante %d: ",i+1);
		scanf("%f", &cal[i]);
	}
	suma=0;
	for(int i=0; i<n; i++) {
		suma+=cal[i];
	}
	promedio=suma/n;
	printf("Calificaciones registradas: \n");
	for (int i=0; i<n; i++) {
		printf("Estudiante %d: %.2f\n", i+1, cal[i]);
	}
	printf("Promedio general: %.2f\n", promedio);

	printf("Desea agregar mas estudiantes? 0 = No  1 = Si : ");
	scanf(" %d", &respuesta);

	if (respuesta==1) {
		printf("Cuantos estudiantes adicionales desea registrar? ");
		scanf("%d", &nuevos);
		total=n+nuevos;
		
		cal=(float*) realloc(cal, total*sizeof(float));
		if(cal==NULL) {
		  printf("No se pudo reasignar memoria\n");
		  return 1;
		}

		for(int i=n; i<total; i++) {
			printf("Calificacion del estudiante %d: ", i + 1);
			scanf("%f", &cal[i]);
		}

		suma=0;
		for(int i=0; i<total; i++) {
			suma+=cal[i];
		}
		promedio=suma/total;

		printf("Calificaciones:\n");
		for(int i=0; i<total; i++) {
			printf("Estudiante %d: %.2f\n", i+1, cal[i]);
		}
		printf("Promedio general: %.2f\n", promedio);
    }else{
    
    return 0;
    
    }
	free(cal);
	
	return 0;
}