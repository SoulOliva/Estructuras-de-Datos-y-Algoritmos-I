#include <stdio.h>
#include <string.h>

#define TAM 5       // tamaño máximo de la videoteca
#define NUM_DIR 2   // máximo de directores por película

// Definición de la estructura película
typedef struct {
    char nombre[30];
    char genero[20];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][30];
} Pelicula;

int main(void) {
    Pelicula videoteca[TAM];
    int numPeliculas;


    printf("Ingresa el numero de peliculas que deseas (max %d): ", TAM);
    scanf("%d", &numPeliculas);

    if (numPeliculas <= 0 || numPeliculas > TAM) {
        printf("Error, vuelve a intentarlo.\n");
        return 1;
    }

    for (int i = 0; i < numPeliculas; i++) {
        printf("\n=== Película %d ===\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", videoteca[i].nombre);

        printf("Genero: ");
        scanf(" %[^\n]", videoteca[i].genero);

        printf("Anio: ");
        scanf("%d", &videoteca[i].anio);

        printf("Número de directores (1-%d): ", NUM_DIR);
        scanf("%d", &videoteca[i].numDirectores);

        
        if (videoteca[i].numDirectores <= 0 || videoteca[i].numDirectores > NUM_DIR) {
            printf("Error, el numero de directores es mayor a 2.\n");
            return 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Nombre del director %d: ", j + 1);
            scanf(" %[^\n]", videoteca[i].directores[j]);
        }
    }

    
    printf("\n####### Contenido de la videoteca #######\n");
    for (int i = numPeliculas - 1; i >= 0; i--) {
        printf("Pelicula: %s\n", videoteca[i].nombre);
        printf("Genero: %s\n", videoteca[i].genero);
        printf("Anio: %d\n", videoteca[i].anio);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
        printf("\n");
    }

    
    int opcionBusqueda;
    printf("=== Búsqueda de películas ===\n");
    printf("1) Por nombre\n2) Por año\n3) Por director\nElige: ");
    scanf("%d", &opcionBusqueda);

    if (opcionBusqueda == 1) {
        char buscarNombre[30];
        printf("Nombre a buscar: ");
        scanf(" %[^\n]", buscarNombre);
        for (int i = 0; i < numPeliculas; i++) {
            if (strcmp(videoteca[i].nombre, buscarNombre) == 0) {
                printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
            }
        }
    } 
    else if (opcionBusqueda == 2) {
        int buscarAnio;
        printf("Año a buscar: ");
        scanf("%d", &buscarAnio);
        for (int i = 0; i < numPeliculas; i++) {
            if (videoteca[i].anio == buscarAnio) {
                printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
            }
        }
    } 
    else if (opcionBusqueda == 3) {
        char buscarDirector[30];
        printf("Director a buscar: ");
        scanf(" %[^\n]", buscarDirector);
        for (int i = 0; i < numPeliculas; i++) {
            for (int j = 0; j < videoteca[i].numDirectores; j++) {
                if (strcmp(videoteca[i].directores[j], buscarDirector) == 0) {
                    printf("Película de %s: %s (%d)\n", buscarDirector, videoteca[i].nombre, videoteca[i].anio);
                }
            }
        }
    } 
    else {
        printf("Opción inválida.\n");
    }


    char generoContar[20];
    printf("\n=== Contar películas por género ===\n");
    printf("Genero a contar: ");
    scanf(" %[^\n]", generoContar);

    int contador = 0;
    for (int i = 0; i < numPeliculas; i++) {
        if (strcmp(videoteca[i].genero, generoContar) == 0) {
            contador++;
        }
    }
    printf("Hay %d película(s) del género '%s'.\n", contador, generoContar);

    return 0;
}
