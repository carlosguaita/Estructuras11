#include <stdio.h>
#include <string.h>
#include "funciones.h"


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
        leerCadena(personas[*n].direccion[i].calle,40);
        printf("Ingrese el numero de la casa:");
        personas[*n].direccion[i].numero = validarIntRango(1,1000);
    }
    (*n)++;
}

void mostrarPersonas(Persona *personas, int *n){
    printf("#\t\tNombre\t\tEdad\t\tTelefono\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%d\n",i+1,personas[i].nombre,personas[i].edad,personas[i].telefono);
        for (int j = 0; j < 3; j++)
        {
            if (strlen(personas[i].direccion[j].calle) > 0)
            {
                printf("\tDireccion %d: %s %d\n",j+1,personas[i].direccion[j].calle,personas[i].direccion[j].numero);
            }
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