#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){
    printf("Seleccione una opcion:\n");
    printf("1.Crear Personas\n");
    printf("2.Mostrar Personas\n");
    printf("3.Actualizar Persona\n");
    printf("4.Borrar Persona\n");
    printf("5.Salir\n");
    printf(">> ");
    int opc = validarIntRango(1,5);
    return opc;
}

void crearPersona1(Persona *personas, int *n){
    printf("Ingrese el nombre de la persona %d: ",*n);
    leerCadena(personas[*n].nombre,20);
    printf("Ingrese la edad de la persona %d: ",*n);
    personas[*n].edad = validarIntRango(1,80);
    printf("Ingrese el telefono de la persona %d (ingrese 6 digitos): ",*n);
    personas[*n].telefono = validarIntRango(100000,999999);
    printf("Cuantas direcciones desea ingresar: ");
    personas[*n].numDirecciones = validarIntRango(1,3);
    for (int i = 0; i < personas[*n].numDirecciones; i++)
    {
        printf("Direccion %d\n",i+1);
        printf("Ingrese la calle: ");
        leerCadena(personas[*n].direcciones[i].calle,40);
        printf("Ingrese el numero de la casa: ");
        personas[*n].direcciones[i].numero = validarIntRango(1,1000);
    }
    (*n)++;
}

void mostrarPersonas(Persona *personas, int *n){
    printf("#\t\tNombre\t\tEdad\t\tTelefono\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%d\n",i,
                                        personas[i].nombre,
                                        personas[i].edad,
                                        personas[i].telefono);
    }
    printf("Desea ver el detalle de una persona 1.Si/2.No: ");
    int opc = validarIntRango(1,2);

    if (opc == 1)
    {
        printf("Ingrese el numero de la persona: ");
        int num = validarIntRango(0,(*n) - 1);
        for (int i = 0; i < personas[num].numDirecciones; i++)
        {
            printf("Direccion %d\n", i);
            printf("Calle: %s Numero: %d\n",personas[num].direcciones[i].calle,
                                            personas[num].direcciones[i].numero);
        }
    }
}


Persona crearPersona2(){
    Persona persona;
    printf("Ingrese el nombre de la persona: ");
    leerCadena(persona.nombre,20);
    printf("Ingrese la edad de la persona: ");
    persona.edad = validarIntRango(1,80);
    printf("Ingrese el telefono de la persona (ingrese 6 digitos): ");
    persona.telefono = validarIntRango(100000,999999);
    return persona;
}

int validarIntRango(int a, int b){
    int n;
    int aux;
    do
    {
        aux = scanf("%d",&n);
        while((getchar())!='\n');
        if (aux != 1 || n < a || n > b)
        {
            printf("Error: El valor ingresado es incorrecto\n");
            printf("Vuelva a ingresarlo: ");
        }
    } while (aux != 1 || n < a || n > b);
}

void leerCadena(char *cadena, int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}