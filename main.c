#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    Persona ps[5];

    int cont=0, opc1 = 0, opc2 = 0;


    do{

        opc1 = menu();

        switch (opc1)
        {
        case 1:
            crearPersona1(ps,&cont);
            break;
        case 2:
            mostrarPersonas(ps,&cont);
            break;
        default:
            break;
        }
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        opc2 = validarIntRango(1,2);
    }while (opc2 == 1);
    

    return 0;
}