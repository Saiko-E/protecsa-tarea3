#include<stdio.h>
#include<stdlib.h>

//structura empleado
struct Empleado{
    int id;
    char nombre[50];
    float salario;
};

//estructura departamento
struct Departamento
{   
    int num_empleados;
    struct Empleado *empleados; //un atributo sera una lista de las estructuras, para el dinamico se usara el puntero
};

//funcion para inicializar la memoria dinamica
void iniDepa(struct Departamento *a, int n){
    a->num_empleados=n;
    a->empleados=(struct Empleado *)malloc(n*sizeof(struct Empleado));
};



int main(){
    //declaracion de departamento
    struct Departamento depa;
    //una lista con los nombres de los empleados
    char nombres[3][50]={
        {"Juan"},
        {"Carlos"},
        {"Fransisco"}
    };
    //inicializacion de la estructura
    iniDepa(&depa, sizeof(nombres) / sizeof(nombres[0]));
    //llenado de la estructura 
    for (int  i = 0; i < 3; i++)
    {
        depa.empleados[i].id = i+1;
        strcpy(depa.empleados[i].nombre, nombres[i]);
        depa.empleados[i].salario= 800.30 * (i+1);
    }
    //impresion
    printf("Departamento con %d empleados:\n", depa.num_empleados);
    for (int i = 0; i < depa.num_empleados; i++) {
        printf("ID: %d, Nombre: %s, Salario: %.2f\n", depa.empleados[i].id, depa.empleados[i].nombre, depa.empleados[i].salario);
    }

    free(depa.empleados);//liberar memoria
   return 0;
}