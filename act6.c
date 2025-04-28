#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


struct Libro{
    char titulo[50];
    char autor[50];
    int anio;
    bool disponible;
};

struct Biblioteca
{
    int id;
    int num_libros;
    struct Libro *libros;
};


void iniBiblioteca(int i, struct Biblioteca *a, int n){
    a->id=i;
    a->num_libros =n;
    a->libros=(struct Libro *)malloc(n * sizeof(a));
    if(a->libros==NULL){
        printf("Error en la asignacion de memoriea\n");
        exit(1);
    }
}

void agregar(struct Biblioteca *a, char *titulo,char *autor, int anio, bool disponible){
    //realloc para aumentar la memoria dinamica asignada
    a->libros = (struct Libro *)realloc(a->libros, (a->num_libros + 1) * sizeof(struct Libro));
    if( a->libros == NULL){
        printf("Error en la asignacion de memoria\n");
        exit(1);
    }
    //insersion de los datos 
    struct Libro *b = &a->libros[a->num_libros];
    strcpy(b->titulo, titulo);
    strcpy(b->autor,autor);
    b->anio=anio;
    b->disponible=disponible;

    //aumentando el numero de libros 
    a->num_libros++;

}

void borrar(struct Biblioteca *a, char *titulo){
    bool tmp = false;
    for (int i = 0 ; i < a->num_libros; i ++){
        if(strcmp(a->libros[i].titulo,titulo) == 0){
            for (int j = i ; j < a->num_libros - 1; j ++){
                a->libros[j] = a->libros[j + 1];
            }
            a->num_libros--;
            a->libros=(struct Libro *)realloc(a->libros, a->num_libros*sizeof(struct Libro));

            if (a->libros == NULL && a->num_libros > 0) {
                printf("Error al reasignar memoria\n");
                exit(1);
            }
            tmp = true;
            break;
        }
    }
    if (!tmp){
        printf("El libro no se encuenctra\n");
    }
}

void mostrar(struct Biblioteca *a){
    for (int i = 0; i< a->num_libros; i ++){
        struct Libro *tmp = &a->libros[i];
        printf("Libro %d: %s, %s (%d) [%s]\n",
            i+1,
            tmp->titulo,
            tmp->autor,
            tmp->anio,
            tmp->disponible ? "Disponible" : "No disponible"
        );
    }

}

int main(){
    //declaracion
    struct Biblioteca biblio;

    //incializacion
    iniBiblioteca(1,&biblio,0);

    //impresion vacia
    mostrar(&biblio);

    //agregando los 7 libros
    agregar(&biblio, "Cien años de soledad", "Gabriel García Márquez", 1967, true);
    agregar(&biblio, "Ficciones", "Jorge Luis Borges", 1944, true);
    agregar(&biblio, "El viejo y el mar", "Ernest Hemingway", 1951, true);
    agregar(&biblio, "No tengo boca y debo gritar", "Harlan Ellison", 1967, false);
    agregar(&biblio,"Sorgo rojo", "Mo yan", 1986, true);
    agregar(&biblio,"La clase de griego", "Han Kang", 2023, false);
    agregar(&biblio,"Tokio blues", "Haruki Murakami", 1987, true);

    //mostrando los 7 titulos 
    printf("\n\n======'MOSTRANDO LOS 7 TITULOS -======\n");
    mostrar(&biblio);

    //Borrando tres titulos tres titulos
    printf("\n\n======'MOSTRANDO TRAS BORRAR TITULOS -======\n");
    borrar(&biblio,"El viejo y el mar");
    borrar(&biblio,"La clase de griego");
    borrar(&biblio,"No tengo boca y debo gritar");
    mostrar(&biblio);
    return 0;
}