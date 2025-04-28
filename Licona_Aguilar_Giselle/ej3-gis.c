#include<stdio.h>
#include<stdlib.h> // Librería para usar rand() y srand() para un valor diferente cada vez que corra el cod
#include <time.h>   // time()


//Estructura punto
struct Punto{
    int x;
    int y;
};

//Función que genera valores aleatorios para x y y
void generarCoordenadas(struct Punto *ptr){
    ptr->x = rand() % 100; /*rand da un valor aleatorio que se divide porque puede ser muy grande y así controlo que de un valor entre 0 y 99*/
    ptr->y = rand() % 100;

    printf("Los valores son x: %d y y:%d\n", ptr->x, ptr->y);
}


int main(){
    struct Punto punto;
    srand(time(NULL));  // Garantiza diferentes secuencias aleatorias
    //Uso la dirección de memoria (puntero) de la estructura que creé
    generarCoordenadas(&punto);

    return 0;
}