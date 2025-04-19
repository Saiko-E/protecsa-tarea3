#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Producto{
    char nombre[50];
    float precio;
    int cantidad;

};


int main(){

    struct Producto productos[8]={
        {"Manzana",13.2,8},
        {"Cheetos", 15.3, 30},
        {"Vino",200, 7},
        {"Cafe", 22.56, 9 },
        {"agua", 5.90, 100},
        {"platano", 8.32, 22},
        {"paleta", 6, 10},
        {"refresco", 43.22, 50}
    };
    float total = 0;
    for (int i = 0; i<8; i++){
        total += productos[i].precio * productos[i].cantidad;
    }

    printf("Para comprar todos los productos necesitas $%.3f\n", total);



    return 0;
}