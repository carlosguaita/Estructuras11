

typedef struct
{
    char calle[40];
    int numero;
}Direccion;

typedef struct 
{
    char nombre[20];
    int edad;
    int telefono;
    int numDirecciones;
    Direccion direcciones[3];
    int estado;
}Persona;

int menu();
void leerCadena(char *cadena, int n);
int validarIntRango(int a, int b);
void crearPersona1(Persona *personas, int *n);
Persona crearPersona2();
void mostrarPersonas(Persona *personas, int *n);