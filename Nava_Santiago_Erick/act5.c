#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Libro{
    char titulo[50];
    char autor[50];
    int anio ;
};


int main(){
    ////longitud del librero
    int n = 4;
    //generacion del arreglo
    struct Libro *libros=(struct Libro *)malloc(n*sizeof(struct Libro));
    //coprobacion de memoria
    if (libros == NULL){
        printf("Error de memoria\n");
    }

    //AUTORES
    char autores[4][50]={
        {"Gabriel García Márquez"},
        {"Ernest Hemingway"},
        {"Harlan Ellison"},
        {"Mo Yan"}
    };
    //TITULOS
    char titulos[4][50]={
        {"Cien años de soledad"},
        {"El viejo y el mar"},
        {"No tengo boca y debo gritar"},
        {"Sorgo rojo"}
    };
    //anios
    int anios[4]={1967,1951,1967,1986};
    //asignacion de valores
    for(int i = 0; i < n; i++){
        strcpy(libros[i].titulo, titulos[i]);
        strcpy(libros[i].autor, autores[i]);
        libros[i].anio=anios[i];
    }
    //impresion de valores
    printf("LIBROS:\n");
    for(int i = 0; i<n; i++){
        printf("Libro %d: %s, %s (%d)\n",i+1,
            libros[i].titulo,
            libros[i].autor,
            libros[i].anio
        );
    }
    //liberacion de memoria
    free(libros);
    return 0;
}