#include<stdio.h>
#include<string.h>

//Estructura producto
struct Producto{
    char nombre[30];
    float precio;
    int cantidad;
};

//Creo una función para calcular el valor del inventario
float valorInventario(struct Producto productos[], int tamanioarreglo){
    float total=0;
    for(int i=0; i<tamanioarreglo; i++){
        total+= productos[i].cantidad*productos[i].precio; //Uso indices para acceder a los valores del arreglo
    }
    printf("El valor total del inventario es de $%.2f \n", total);
    return total;

}


int main(){
    // Asigno valores al inventario
    struct Producto almacen[6]={
        {"Lápiz HB", 5.0, 150},
        {"Cuaderno A5", 23.50, 85},
        {"Cargador USB-C", 150.0, 32},
        {"Auriculares Bluetooth", 320.0, 40},
        {"Bocina portátil", 600.0, 12},
        {"Mouse inalámbrico", 220.0, 54}
    };

    //Llamo a la función, usando los parámetros de la estructura y tamaño del arreglo
    valorInventario(almacen, 6);


    return 0;
}