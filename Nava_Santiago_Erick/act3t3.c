#include<stdio.h>
#include<stdlib.h>
#include<time.h>



//declaracion de la estructura con las coordenadas
struct Punto{
    double x;
    double y;
};

//funcion del tipo estructura, aqui asigna los valores aleatorio 
//entre el 10 y el -10
struct Punto numeros(struct Punto a){
    srand(time(NULL));  //semilla 

    a.x = -10 + ((double)rand() / RAND_MAX) *(20);  //valor de x
    a.y = -10 + ((double)rand() / RAND_MAX) *(20);  //valor de y

    return a;       //retorna la estructura
}

//main
int main(){
    printf("Programa para generar una funcion con coordenadas al azar \n");
    struct Punto coordenadas;                       //declara una estructura
    coordenadas = numeros(coordenadas);             //usa la funcion
    printf("Coordenada x=%.2f\n",coordenadas.x);    //imprime x
    printf("Coordenada y=%.2f\n",coordenadas.y);    //imprime y
    return 0;
}