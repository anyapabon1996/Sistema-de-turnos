#include "EjMedico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T_E 11
#define T_D 33
#define T_P 165

int hay_turno (especializacion *arreglo, char la_especialidad[15])
{
    int bandera=0;

    for (int i =0; i<T_E; i++) //busca si hay disponibilidad y llena ese espacio con 1.
    {
        if (strcmp(la_especialidad,arreglo[i].especialidad)==0)
        {
            for (int j=0; j<15; j++)

                if (arreglo[i].turnos[j]==0)
                {
                    bandera = 1; //quiere decir que quedan turnos.

                    arreglo[i].turnos[j]=1; //aqui llena el espacio disponible.

                    return bandera;
                }
        }
    }

    return bandera;
}

void cadena_mayuscula (char cadena[])
{
    int dim;

    dim = sizeof(cadena)/sizeof(char);

    for (int i=0; i<15; i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
}

void ordena_cadena_struct (especializacion vector_a_ordenar[], int dim)
{
    especializacion auxiliar;

    for (int i=0; i<dim-1; i++)
    {
       for (int j = i+1; j<dim; j++)
       {
           if (strcmp(vector_a_ordenar[i].especialidad, vector_a_ordenar[j].especialidad) > 0)
           {
               auxiliar = vector_a_ordenar[i];

               vector_a_ordenar[i] = vector_a_ordenar [j];

               vector_a_ordenar[j] = auxiliar;
           }
       }
    }
}

void llena_paciente (paciente enfermizo[], char name[], char last_name[], int **ptr, char specialty[])
{

    for (int i=0; i< sizeof(name); i++) //agrega un espacio.
        {
            if (name[i+1]==0)
            {
                name[i+1] = 32;

                break;
            }
        }


        strcpy(enfermizo[**ptr].medico_designado, strcat(name, last_name));
        do
        {
            printf("\nIngrese el nombre del paciente: ");
            scanf("%s", enfermizo[**ptr].nombre);
            fflush(stdin);
        } while (isalpha(enfermizo[**ptr].nombre[0])==0);

        do
        {
            printf("\nApellido: ");
            scanf("%s", enfermizo[**ptr].apellido);
            fflush(stdin);
        } while (isalpha(enfermizo[**ptr].apellido[0])==0);

        do
        {
            printf("\nEdad: ");
            scanf("%d", &enfermizo[**ptr].edad);
            fflush(stdin);
        } while (enfermizo[**ptr].edad<0);

        printf("\nSexo (ingrese solo \"m\" o \"f\" (sea en may%cscula o min%cscula): ", 163, 163);
        scanf("%c", &enfermizo[**ptr].sexo);
        fflush(stdin);

        enfermizo[**ptr].sexo = toupper(enfermizo[**ptr].sexo);

        printf("\nDNI: ");
        scanf("%d", &enfermizo[**ptr].dni);
        fflush(stdin);

        printf("\nIngrese d%ca, luego mes y por %cltimo a%co de nacimiento: ", 161, 163, 164);
        scanf("%d%d%d", &enfermizo[**ptr].nacimiento.dia, &enfermizo[**ptr].nacimiento.mes, &enfermizo[**ptr].nacimiento.anio);
        fflush(stdin);

        strcpy(enfermizo[**ptr].rama, specialty);

        **ptr+=1;

}

void ordena_cadena_doctores (doctores arreglo[]) //ordena segun nombre y especialidad
{
    doctores auxiliar;

    int bandera=1;

    while (bandera)
    {
        bandera = 0;

        for (int i=0; i<T_D-1; i++)
        {
            if (strcmp(arreglo[i].nombre,arreglo[i+1].nombre) > 0)
            {
                if ((strcmp(arreglo[i].area, arreglo[i+1].area)==0))
                {
                    bandera = 1;

                    auxiliar = arreglo[i];

                    arreglo[i] = arreglo[i+1];

                    arreglo[i+1] = auxiliar;
                }
            }

            if ((strcmp(arreglo[i].area, arreglo[i+1].area)>0))
            {
                bandera = 1;

                auxiliar = arreglo[i];

                arreglo[i] = arreglo[i+1];

                arreglo[i+1] = auxiliar;
            }
        }
    }
}

void busca_turno (char especialidad[15], especializacion *aBuscar, doctores *disponibles, paciente *aquejado, int *pp)
{
    int indice, bandera=0, indice_doctor, bandera_doc[3], control=0, index;

    char nombre[20], apellido[20];

    memset(nombre,0,20);
    memset(apellido,0,20);

    for (int i=0; i<3; i++) bandera_doc[i]=0;

    bandera = hay_turno(aBuscar,especialidad);

    if (bandera==1)
    {
        for (int i=0; i<T_D; i+=3)
        {
            if (strcmp(disponibles[i].area, especialidad)==0)
            //determina la posicion de los doctores con la especialidad.
            {
                indice_doctor=i;

            break;
            }
        }

        for (int i=0; i<3; i++)//determina qué doctores tienen espeacio para atender.
        {
            for (int j=0; j<5; j++)
            {
                if (disponibles[indice_doctor+i].cant_pacientes[j]==0)
                {
                    bandera_doc[i]=1;

                    break;
                }
            }
        }

        for (int i=0; i<3; i++)//dice los nombre de los doctores disponibles
            //para que el paciente escoja.
        {
            if (bandera_doc[i]==1)
            {
                printf("El doctor %s %s tiene disponibilidad\n", disponibles[indice_doctor+i].nombre, disponibles[indice_doctor+i].apellido);
            }
        }

        do//pide nombre y apellido del doctor de manera controlada.
        {
        printf("\nIngrese el nombre y apellido del doctor: ");
        gets(nombre);
        fflush(stdin);

        gets(apellido);
        fflush(stdin);

        cadena_mayuscula(nombre);

        cadena_mayuscula(apellido);

        for (int i=0; i<3; i++)//control que el nombre y apellido coincidan.
        {
            if ((strcmp(disponibles[indice_doctor+i].nombre,nombre)==0) && (strcmp(disponibles[indice_doctor+i].apellido,apellido)==0))
            {
                control=1;

                index=i;//me ayuda a ubicar al doctor.

                break;
            }
        }

        if (control!=1) printf("\n\t¡¡¡INGRESE EL NOMBRE Y APELLIDO DE MANERA IDENTICA!!!");

        }while (control!=1);

        for (int i=0; i<5; i++)//llena con un 1 un espacio del array del doctor.
        {
            if (disponibles[indice_doctor+index].cant_pacientes[i]==0)
            {
                disponibles[indice_doctor+index].cant_pacientes[i]=1;

                break;
            }
        }

        llena_paciente(aquejado, nombre, apellido, &pp, disponibles[indice_doctor+index].area);
    }
    else
    {
        printf("\n*******Turnos completos. Llame ma%cana*******",164);
    }

}

void busca_por_doctor (char nombre[], char apellido[], char especialidad[15], especializacion *vector, doctores *medico, paciente *aquejado, int *lp)
{
    int indice_doctor, cupos[5], indice_medio, izq=0, der=T_D-1, bandera=0, bandera_auxiliar=0, indice_vector, indiceB, indiceC;

    for (int i=0; i < T_E; i++) //busca en que posicion esta la especialidad buscada.
    {
        if (strcmp(vector[i].especialidad, especialidad)==0)
        {
            indice_vector=i;

            break;
        }
    }

    while (izq <= der)//determina el indice del doctor en el array.
    {
        indice_medio = (izq+der)/2;

        if ((strcmp(especialidad, medico[indice_medio].area)==0))
        {
            indice_doctor = indice_medio;

            break;
        }
        else if (strcmp(especialidad, medico[indice_medio].area) < 0) der=indice_medio-1;

        else izq = indice_medio+1;
    }

    if (strcmp(nombre, medico[indice_doctor+1].nombre)==0) indice_doctor=indice_doctor+1; //estos tres determinan cual es el verdadero doctro entre los tres posibles
    else if (strcmp(nombre, medico[indice_doctor+2].nombre)==0) indice_doctor=indice_doctor+2;
    else if (strcmp(nombre, medico[indice_doctor-1].nombre)==0) indice_doctor=indice_doctor-1;
    else if (strcmp(nombre, medico[indice_doctor-2].nombre)==0) indice_doctor=indice_doctor-2;

    for (int i=0; i<5; i++) //determina si dicho doctor tiene disponibilidad.
    {
        if (medico[indice_doctor].cant_pacientes[i]==0)
        {
            bandera=1;

            medico[indice_doctor].cant_pacientes[i]=1; //llena un espacio de los turnos disponibles.

            break;
        }
    }

    if (bandera)
    {
        printf("\nEl m%cdico tiene disponibilidad.", 130);

        for (int i=0; i<15; i++) //llena un espacio del vector de especialidades.
        {
            if (vector[indice_vector].turnos[i]==0)
            {
                vector[indice_vector].turnos[i]=1;

                break;
            }
        }


        llena_paciente(aquejado, nombre, apellido, &lp, especialidad);
    }

    else
    {
        printf("\nEl m%cdico no tiene disponibilidad", 130);

     if ((strcmp(medico[indice_doctor+1].area, especialidad)==0) && (strcmp(medico[indice_doctor+2].area,especialidad)==0))
     {
         indiceB = indice_doctor+1;
         indiceC = indice_doctor+2;
     }
     else if ((strcmp(medico[indice_doctor+1].area, especialidad)==0) && (strcmp(medico[indice_doctor-1].area,especialidad)==0))
     {
         indiceB = indice_doctor+1;
         indiceC = indice_doctor-1;
     }
     else //estos tres buscan los los otros dos doctores de la misma especialidad.
     {
         indiceB = indice_doctor-1;
         indiceC = indice_doctor-2;
     }

     for (int i=0; i<5; i++)//determina si tienen espacio los doctores.
     {
         if (medico[indiceB].cant_pacientes[i]==0) bandera=1;

         if (medico[indiceC].cant_pacientes[i]==0) bandera_auxiliar=1;
     }

     if (bandera) printf("\n%s %s tiene turno.", medico[indiceB].nombre, medico[indiceB].apellido);

     if (bandera_auxiliar) printf("\n%s %s tiene turno.", medico[indiceC].nombre, medico[indiceC].apellido);

     if (bandera==0 && bandera_auxiliar==0)
     {
         printf("\n\n\tNO HAY TURNOS. LLAME EL DIA QUE SIGUE.");

        //break; // **********************COMO HAGO******
     }

     bandera=hay_turno(vector, especialidad);

     do
     {
     printf("\nIngrese el nombre y apellido del doctor selecionado (de manera id%cntica): ",130);
     scanf("%s%s", nombre, apellido);
     fflush(stdin);

     if (strcmp(nombre, medico[indiceB].nombre==0) || (strcmp(nombre, medico[indiceC].nombre==0)))
         {
             if (strcmp(apellido, medico[indiceB].apellido==0) || (strcmp(apellido, medico[indiceC].apellido==0))) bandera=1;
         }
     } while(bandera!=1);

     llena_paciente(&aquejado, nombre, apellido, &lp, especialidad);

    }
}




