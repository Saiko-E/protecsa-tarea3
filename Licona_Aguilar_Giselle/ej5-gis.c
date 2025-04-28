#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Libro{
    char nombre[50];
    char autor[50];
    float precio;
};

struct Biblioteca{
    char nombreGenero[40];
    int numLibros;
    struct Libro* libro;

};

int main(){
    struct Biblioteca psicologia;
    psicologia.numLibros=20;

    /* Asignar memoria dinámica con malloc */
    psicologia.libro=malloc(psicologia.numLibros*sizeof(struct Libro));

    /*Siempre se verifica la asignación de memoria*/
    if (psicologia.libro == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }

    //Asigno valores de biblioteca
    strcpy(psicologia.nombreGenero, "Superación personal");

    //Asigno valores de los libros con una función
    for (int i=0; i<psicologia.numLibros; i++){
        snprintf(psicologia.libro[i].nombre, sizeof(psicologia.libro[i].nombre), "NombreLibro %d", 1 +i);
        snprintf(psicologia.libro[i].autor, sizeof(psicologia.libro[i].autor), "NombreAutor %d", i+1);
        psicologia.libro[i].precio= 320.50+i;

    }
    

    printf("Libros del género: %s\n", psicologia.nombreGenero);
    for (int i=0; i<psicologia.numLibros; i++){
        printf("Nombre: %s\nAutor: %s\nPrecio: %.2f\n", 
            psicologia.libro[i].nombre, 
            psicologia.libro[i].autor, 
            psicologia.libro[i].precio);

        printf("---------------\n");
     
    }

    free(psicologia.libro);
    return 0;
}