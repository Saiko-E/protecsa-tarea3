#include<stdio.h>
#include<string.h>
#include <stdlib.h>


//Considerando el código que vimos en clase

typedef struct Paciente{
    char nombre[50];
    int edad;
    char diagnostico[200];
    int prioridad;
    struct Paciente *siguiente; //Puntero al siguiente nodo de la lista
} Paciente;

//Función para insertar un elemento al INICIO de la lista
Paciente* insertarInicio(Paciente *inicio, char nombre[], int edad, char diagnostico[], int prioridad){
    //Memoria para el nuevo nodo
    Paciente *nuevo = (Paciente *)malloc(sizeof(Paciente));

    if(nuevo == NULL){
        printf("Error: no se puede asignar memoria.\n");
        exit(1);
    }

    //Guardamos la copia de los valores nuevos
    strcpy(nuevo->nombre, nombre);
    nuevo->edad= edad;
    strcpy(nuevo->diagnostico, diagnostico);
    nuevo->prioridad =prioridad;

    nuevo->siguiente = inicio;
    return nuevo;
}

//Hay que imprimir la lista de pacientes
void imprimirListaPacientes(Paciente *inicio){
    Paciente *actual= inicio;
    printf("Pacientes:\n");

    while (actual != NULL){
        printf("Nombre: %s\n", actual->nombre);
        printf("Edad %d\n", actual->edad);
        printf("Diagnóstico: %s\n", actual->diagnostico);
        printf("Prioridad: %d\n", actual->prioridad);
        printf("------------------\n");

        actual=actual->siguiente; //Avanza al sig paciente
    }

}

//Eliminar paciente por nombre
Paciente* eliminarPaciente(Paciente *inicio, const char *nombre){
    Paciente *actual= inicio;
    Paciente *anterior= NULL;

    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) { //strcmp compara dos cadenas
            // Encontramos al paciente que queremos eliminar
            if (anterior == NULL) {
                // El paciente a eliminar es el primero
                inicio = actual->siguiente;
            } else {
                // El paciente está en medio o al final
                anterior->siguiente = actual->siguiente;
            }

            printf("Paciente %s eliminado.\n", actual->nombre);
            free(actual); // Liberamemoria
            return inicio; // Retorna el nuevo inicio 
        }

        anterior = actual;            // Guardamos el nodo anterior
        actual = actual->siguiente;    // Avanzamos al siguiente nodo
    }

    printf("Paciente %s no encontrado.\n", nombre);
    return inicio;

}

int main() {
    Paciente *inicio = NULL; // Lista inicialmente vacía

    // Añadimos 10 pacientes con diferentes prioridades
    inicio = insertarInicio(inicio, "Juan", 30, "Gripe", 2);
    inicio = insertarInicio(inicio, "María", 25, "Dolor de cabeza", 3);
    inicio = insertarInicio(inicio, "Carlos", 40, "Fractura", 1);
    inicio = insertarInicio(inicio, "Ana", 50, "Cáncer", 1);
    inicio = insertarInicio(inicio, "Luis", 60, "Artritis", 2);
    inicio = insertarInicio(inicio, "Sofía", 33, "Resfriado", 3);
    inicio = insertarInicio(inicio, "Pedro", 28, "Tos persistente", 2);
    inicio = insertarInicio(inicio, "Laura", 35, "Asma", 1);
    inicio = insertarInicio(inicio, "Ricardo", 55, "Hipertensión", 2);
    inicio = insertarInicio(inicio, "Elena", 45, "Diabetes", 3);

    // Imprimir la lista original
    printf("Lista de pacientes antes de eliminar:\n");
    imprimirListaPacientes(inicio);

    // Eliminar 2 pacientes (por nombre)
    inicio = eliminarPaciente(inicio, "María");
    inicio = eliminarPaciente(inicio, "Ricardo");

    // Imprimir la lista actualizada
    printf("\nLista de pacientes después de eliminar:\n");
    imprimirListaPacientes(inicio);

    // Liberamos la memoria de todos los pacientes restantes
    Paciente *temporal;
    while (inicio != NULL) {
        temporal = inicio;
        inicio = inicio->siguiente;
        free(temporal);
    }

    return 0;
}
