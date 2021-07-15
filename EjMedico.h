#ifndef EJMEDICO_H_INCLUDED
#define EJMEDICO_H_INCLUDED

struct fecha
{
    int dia, mes, anio;
};

typedef struct especialidades
{
     char especialidad [20];
     int turnos[15];

} especializacion;

typedef struct doctor
{
    char nombre[15];
    char apellido[15];
    char area[20];
    int cant_pacientes[5];

} doctores;

typedef struct convaleciente
{
    char nombre[20];
    char apellido[20];
    char sexo;
    int edad;
    int dni;
    struct fecha nacimiento;
    char rama[15];
    char medico_designado[30];

} paciente;

int hay_turno (especializacion *arreglo, char la_especialidad[]);

void cadena_mayuscula (char cadena[]);

void ordena_cadena_struct (especializacion vector_a_ordenar[], int dim);

void llena_paciente (paciente enfermizo[], char name[], char last_name[], int **ptr, char specialty[]);

void busca_turno (char especialidad[], especializacion *aBuscar, doctores *disponibles, paciente *aquejado, int *pp);

void ordena_cadena_doctores (doctores arreglo[]);

void busca_por_doctor (char nombre[], char apellido[], char especialidad[], especializacion *vector, doctores *medico, paciente *aquejado, int *lp);


#endif // EJMEDICO_H_INCLUDED
