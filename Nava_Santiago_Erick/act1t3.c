#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct coche{

    int anio;
    char modelo[50];
    char placas[10];
    int num_dueno;
};


int main(){

    struct coche auto1={2014, "A17", "E3SD-SQ",1};
    //mostrando los datos inicciales
    printf("Placas: %s\n", auto1.placas);
    printf("Dueno: %d\n", auto1.num_dueno);

    //suponiendo que se desea cambiar las placas
    struct coche *autotmp = &auto1;
    strcpy(autotmp->placas, "EEEE-123");
    (*autotmp).num_dueno=2;
    //comprobando el cambio a la estructura dle auto1
    printf("Placas: %s\n", auto1.placas);
    printf("Dueno: %d\n", auto1.num_dueno);


    return 0;
}