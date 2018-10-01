
typedef struct
{
    int id;
    char nombres[51];
    char apellido[51];
    float sueldo;
    int sector;
    int estado;

}eEmpleado;

void inicializar( eEmpleado empleado[], int cantidad);
int buscarEspacioLibre(eEmpleado empleado[], int cantidad);
int buscarEmpleadoPorId(eEmpleado empleado[], int cantidad, int identificacion);
void mostrarUnEmpleado(eEmpleado empleado);
void mostrarEmpleados(eEmpleado empleado[], int cantidad);
void listarPromTotal(eEmpleado empleado[], int cantidad);

void ingresoEmpleado(eEmpleado empleado[], int cantidad, int identificacion, char nombre[], char apellido[], float sueldo, int sector);
void ingresoDatos(eEmpleado empleado[],int espacioLibre, int auxId,char auxNombre[], char auxApellido[], float auxSueldo,int auxSector);
void modificarEmpleado(eEmpleado empleado[], int cantidad, int identificacion, char nombre[], char apellido[], float sueldo, int sector);
void bajaEmpleado(eEmpleado empleado[], int cantidad, int identificacion);
