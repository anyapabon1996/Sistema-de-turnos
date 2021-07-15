#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "EjMedico.h"
#define T_E 11
#define T_D 33
#define T_P 165

int main()
{
    int indice_pacientes = 0, opcion, contador;

    char specialty[15], nombre_doctor[15], apellido_doctor[15];

    especializacion medicos[T_E];

    doctores expertos[T_D];

    paciente doliente[T_P];

    memset(nombre_doctor,0,sizeof(nombre_doctor));
    memset(nombre_doctor,0,sizeof(apellido_doctor));

    strcpy (medicos[0].especialidad, "ALERGOLOGIA");
    strcpy (medicos[1].especialidad, "CARDIOLOGIA");
    strcpy (medicos[2].especialidad, "ENDOCRINOLOGIA");
    strcpy (medicos[3].especialidad, "GERIATRIA");
    strcpy (medicos[4].especialidad, "PEDIATRIA");
    strcpy (medicos[5].especialidad, "NEFROLOGIA");
    strcpy (medicos[6].especialidad, "NEUMOLOGIA");
    strcpy (medicos[7].especialidad, "NEUROLOGIA");
    strcpy (medicos[8].especialidad, "OFTALMOLOGIA");
    strcpy (medicos[9].especialidad, "TRAUMATOLOGIA");
    strcpy (medicos[10].especialidad, "NUTRIOLOGIA");

    for (int i=0; i<T_E; i++) //inicializa en 0 el array.
    {
        for (int j=0; j<15; j++) medicos[i].turnos[j] = 0;
    }

    ordena_cadena_struct(medicos,T_E);

    strcpy(expertos[0].nombre, "JOSE");
    strcpy(expertos[0].apellido, "ROJAS");
    strcpy(expertos[0].area, "ALERGOLOGIA");

    strcpy(expertos[1].nombre, "MARIA");
    strcpy(expertos[1].apellido, "PABON");
    strcpy(expertos[1].area, "ALERGOLOGIA");

    strcpy(expertos[2].nombre, "CARLA");
    strcpy(expertos[2].apellido, "COLMENARES");
    strcpy(expertos[2].area, "ALERGOLOGIA");

    strcpy(expertos[3].nombre, "CARLA");
    strcpy(expertos[3].apellido, "CASTILLO");
    strcpy(expertos[3].area, "CARDIOLOGIA");

    strcpy(expertos[4].nombre, "ANA");
    strcpy(expertos[4].apellido, "PAZ");
    strcpy(expertos[4].area, "CARDIOLOGIA");

    strcpy(expertos[5].nombre, "JULIAN");
    strcpy(expertos[5].apellido, "MATOS");
    strcpy(expertos[5].area, "CARDIOLOGIA");

    strcpy(expertos[6].nombre, "MOISES");
    strcpy(expertos[6].apellido, "RAMIREZ");
    strcpy(expertos[6].area, "ENDOCRINOLOGIA");

    strcpy(expertos[7].nombre, "PEDRO");
    strcpy(expertos[7].apellido, "CALDERON");
    strcpy(expertos[7].area, "ENDOCRINOLOGIA");

    strcpy(expertos[8].nombre, "LUIS");
    strcpy(expertos[8].apellido, "FONSEKA");
    strcpy(expertos[8].area, "ENDOCRINOLOGIA");

    strcpy(expertos[9].nombre, "LUISA");
    strcpy(expertos[9].apellido, "APONTE");
    strcpy(expertos[9].area, "GERIATRIA");

    strcpy(expertos[10].nombre, "MARTA");
    strcpy(expertos[10].apellido, "GOMEZ");
    strcpy(expertos[10].area, "GERIATRIA");

    strcpy(expertos[11].nombre, "ANDREA");
    strcpy(expertos[11].apellido, "GONZALES");
    strcpy(expertos[11].area, "GERIATRIA");

    strcpy(expertos[12].nombre, "JUAN");
    strcpy(expertos[12].apellido, "TORRES");
    strcpy(expertos[12].area, "PEDIATRIA");

    strcpy(expertos[13].nombre, "JUANA");
    strcpy(expertos[13].apellido, "PEREZ");
    strcpy(expertos[13].area, "PEDIATRIA");

    strcpy(expertos[14].nombre, "STEVEN");
    strcpy(expertos[14].apellido, "ROLLERS");
    strcpy(expertos[14].area, "PEDIATRIA");

    strcpy(expertos[15].nombre, "MIRANDA");
    strcpy(expertos[15].apellido, "PALACIOS");
    strcpy(expertos[15].area, "NEFROLOGIA");

    strcpy(expertos[16].nombre, "PAULA");
    strcpy(expertos[16].apellido, "PONTE");
    strcpy(expertos[16].area, "NEFROLOGIA");

    strcpy(expertos[17].nombre, "PAOLA");
    strcpy(expertos[17].apellido, "GIL");
    strcpy(expertos[17].area, "NEFROLOGIA");

    strcpy(expertos[18].nombre, "PATRICIA");
    strcpy(expertos[18].apellido, "FERNANDEZ");
    strcpy(expertos[18].area, "NEUMOLOGIA");

    strcpy(expertos[19].nombre, "BEATRIZ");
    strcpy(expertos[19].apellido, "PINZON");
    strcpy(expertos[19].area, "NEUMOLOGIA");

    strcpy(expertos[20].nombre, "MARCELA");
    strcpy(expertos[20].apellido, "VALENCIA");
    strcpy(expertos[20].area, "NEUMOLOGIA");

    strcpy(expertos[21].nombre, "MARIO");
    strcpy(expertos[21].apellido, "CALDERON");
    strcpy(expertos[21].area, "NEUROLOGIA");

    strcpy(expertos[22].nombre, "DANIEL");
    strcpy(expertos[22].apellido, "VALENCIA");
    strcpy(expertos[22].area, "NEUROLOGIA");

    strcpy(expertos[23].nombre, "ARMANDO");
    strcpy(expertos[23].apellido, "MENDOZA");
    strcpy(expertos[23].area, "NEUROLOGIA");

    strcpy(expertos[24].nombre, "PEDRO");
    strcpy(expertos[24].apellido, "ORTEGA");
    strcpy(expertos[24].area, "OFTALMOLOGIA");

    strcpy(expertos[25].nombre, "AURA");
    strcpy(expertos[25].apellido, "LOZANO");
    strcpy(expertos[25].area, "OFTALMOLOGIA");

    strcpy(expertos[26].nombre, "HARRY");
    strcpy(expertos[26].apellido, "POTTER");
    strcpy(expertos[26].area, "OFTALMOLOGIA");

    strcpy(expertos[27].nombre, "MONICA");
    strcpy(expertos[27].apellido, "VILLAMIZAR");
    strcpy(expertos[27].area, "TRAUMATOLOGIA");

    strcpy(expertos[28].nombre, "ANGELICA");
    strcpy(expertos[28].apellido, "SUAREX");
    strcpy(expertos[28].area, "TRAUMATOLOGIA");

    strcpy(expertos[29].nombre, "LORD");
    strcpy(expertos[29].apellido, "VOLDEMORT");
    strcpy(expertos[29].area, "TRAUMATOLOGIA");

    strcpy(expertos[30].nombre, "LORENZ");
    strcpy(expertos[30].apellido, "FORCE");
    strcpy(expertos[30].area, "NUTRIOLOGIA");

    strcpy(expertos[31].nombre, "MATH");
    strcpy(expertos[31].apellido, "FORCE");
    strcpy(expertos[31].area, "NUTRIOLOGIA");

    strcpy(expertos[32].nombre, "LAB");
    strcpy(expertos[32].apellido, "FORCE");
    strcpy(expertos[32].area, "NUTRIOLOGIA");


    for (int i=0; i<33; i++) //inicializa en 0 sus cantidad de pacientes.
    {
        for (int j=0; j<5; j++) expertos[i].cant_pacientes[j] =0;
    }

    ordena_cadena_doctores(expertos);

    do
    {
        printf("=============================================================================================");
        printf("\n\t\t\tIngrese opci%cn a realziar \n\n%s\n%s\n%s\n\nOpcion: ",162,
               "1. Buscar turno por especialidad.",
               "2. Buscar turno por doctor.",
               "0. Salir.");

        scanf("%d", &opcion);
        fflush(stdin);

        while (opcion!=1 && opcion!=2 &&opcion!=0)
        {
            printf("\nInv%clido. Solo hay tres opciones posibles: ",160);
            scanf("%d", &opcion);
            fflush(stdin);
        }

        switch(opcion)
        {
        case 1:
            printf("\nEspecialidad: ");
            scanf("%s", specialty);
            fflush(stdin);

            cadena_mayuscula(specialty);

            busca_turno(specialty,medicos,expertos,doliente,&indice_pacientes);

            break;

        case 2:
            printf("\nNombre doctor: ");
            gets(nombre_doctor);
            fflush(stdin);

            printf("\nApellido doctor: ");
            scanf("%s", apellido_doctor);
            fflush(stdin);

            printf("\nEspecialidad: ");
            scanf("%s", specialty);
            fflush(stdin);

            cadena_mayuscula(nombre_doctor);

            cadena_mayuscula(apellido_doctor);

            cadena_mayuscula(specialty);

            busca_por_doctor(nombre_doctor,apellido_doctor,specialty, medicos, expertos, doliente, &indice_pacientes);

            break;

        case 0:
            break;
        }


    } while (opcion!=0);

    printf("\n\n\t\tCANTIDAD DE PACIENTES POR DOCTOR\nDoctor\t\t\tCantidad de Pacientes\n\n\r");

    for (int i=0; i<T_D; i++)
    {
        contador=0;

        printf("%s %s.",expertos[i].nombre, expertos[i].apellido);

        for (int j=0; j<5; j++)
        {
            if (expertos[i].cant_pacientes[j]!=0) contador+=1;
            else break;
        }

        printf("\t\t\t   %d\n\n\r", contador);
    }

    printf("\n\n\t\tCANTIDAD DE PACIENTES POR ESPECIALIDAD\nEspecialidad\t\t\tCantidad\n\n\r");

    for (int i=0; i<T_E; i++)
    {
        contador=0;

        printf("%s.", medicos[i].especialidad);

        for (int j=0; j<15; j++)
        {
            if (medicos[i].turnos[j]!=0) contador+=1;
            else break;
        }

        printf("\t\t\t   %d\n\n\r", contador);
    }

    printf("\n\nLISTADO DE PACIENTES POR ESPECIALIDAD Y MEDICO\n\nPaciente\t\t\tEspecialidad\t\t\tM%cdico\n\r",130);

    for (int i=0; i<indice_pacientes; i++) printf("%s       \t\t\t%s     \t\t\t%s\n\n", doliente[i].nombre, doliente[i].rama, doliente[i].medico_designado);


    printf("\n\n\t\tCANTIDAD DE TURNOS DISPONIBLES\n\nEspecialidad\t\t\tDisponibilidad de turnos\n\r");

    for(int i=0; i<T_E; i++)
    {
        contador=0;

        printf("%s", medicos[i].especialidad);

        for (int j=14; j>=0; j--)
        {
            if (medicos[i].turnos[j]!=1) contador+=1;
        }
        printf("\t\t\t      %d\n\n", contador);
    }

    printf("\n\nCantidad de turnos otorgados: %d", indice_pacientes);
    printf("\n\nCantidad de turnos disponibles: %d", T_P-indice_pacientes);

    getchar();

    printf("%s", doliente[0].nombre);
    printf("\n%d", doliente[0].edad);

    return 0;
}

