#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Empleado{
    char nombre[20];
    char puesto[20];
    float salario;
};

struct Departamento{
    char nombreDepartamento[40];
    int numEMpleados;
    struct Empleado* empleado;

};

int main(){
    struct Departamento sales;
    sales.numEMpleados=5;

    /* Asignar memoria dinámica con malloc para el num de empleados que asigné a la estructura sales (correspondiente a un departamento.) */
    sales.empleado=(struct Empleado*)malloc(sales.numEMpleados*sizeof(struct Empleado));

    /*Siempre se verifica la asignación de memoria*/
    if (sales.empleado == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }

    //Asigno valores de departamento
    strcpy(sales.nombreDepartamento, "Ventas");

    //Asigno valores de empleados dentro de departamento
    strcpy(sales.empleado[0].nombre, "Daniel");
    strcpy(sales.empleado[0].puesto, "Vendedor");
    sales.empleado[0].salario=13000;

    strcpy(sales.empleado[1].nombre, "Lucas");
    strcpy(sales.empleado[1].puesto, "Gerente de ventas");
    sales.empleado[1].salario=15000;

    strcpy(sales.empleado[2].nombre, "Rosa");
    strcpy(sales.empleado[2].puesto, "Coordinadora de ventas");
    sales.empleado[2].salario=15000;

    strcpy(sales.empleado[3].nombre, "Karla");
    strcpy(sales.empleado[3].puesto, "Vendedora");
    sales.empleado[3].salario=13000;

    strcpy(sales.empleado[4].nombre, "Antonio");
    strcpy(sales.empleado[4].puesto, "Secretario");
    sales.empleado[4].salario=10000;

    //Este no sale porque la memoria solo la resesrvé para 5
    strcpy(sales.empleado[5].nombre, "Prueba");
    strcpy(sales.empleado[5].puesto, "anexo uno más");
    sales.empleado[5].salario=13000;

    printf("Empleados del departamento: %s\n", sales.nombreDepartamento);
    for (int i=0; i<sales.numEMpleados; i++){
        printf("Nombre: %s | Puesto: %s | Salario: %.2f\n\n", sales.empleado[i].nombre, sales.empleado[i].puesto, sales.empleado[i].salario);
    }

    free(sales.empleado);
    return 0;
}