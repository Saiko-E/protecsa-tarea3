#include<stdio.h>
#include<string.h>

struct Coche{
    char marca[20];
    char color[15];
    int cilindros;
};

void cambioCilindros(struct Coche *p, int valueCilindros){
    p->cilindros=valueCilindros;
};

int main(){
    struct Coche uno;
/*Asigno valores SIN punteros */
    strcpy(uno.marca, "Volkswagen");
    strcpy(uno.color, "Rojo");
    uno.cilindros=4;

    printf("________________________________\n");
    printf("Marca: %s\nColor: %s\nCilindros: %d\n", uno.marca, uno.color, uno.cilindros);

    struct Coche dos={"Ford", "Azul", 4};
    struct Coche *ptro=&dos;

/*Asigno valores CON punteros*/
    printf("_________________________________\n");
    printf("Marca: %s\n", ptro->marca);
    printf("Color: %s\n", ptro->color);
    printf("Cilindros: %d\n",ptro->cilindros);

/*Modifico una varible asignada con una función pasando puntero*/
    cambioCilindros(&dos,8);

    printf("______________Cambio cilindro con puntero___________________\n");
    printf("Marca: %s\n", ptro->marca);
    printf("Color: %s\n", ptro->color);
    printf("Cilindros: %d\n",ptro->cilindros);



    return 0;
}