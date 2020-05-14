/*
 * empleado.c
 *
 *  Created on: 14 may. 2020
 *      Author: Agustin
 */


#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "empleado.h"
#define PROGRAMADOR 0
#define INGERNIERO 1
#define ARQUITECTO 2
static int generarId();
int Empleado_init(Empleado* arrayEmpleados, int cantidadElementos)
{
    int retorno=0;
    int i;
    if(arrayEmpleados !=NULL && cantidadElementos >0)
    {
        retorno=0;
        for(i=0; i<cantidadElementos; i++)
        {
            arrayEmpleados[i].isEmpty=1;
        }
    }
    return retorno;
}
int Empleado_mostrar(Empleado* arrayEmpleados, int cantidadElementos)
{
    int retorno;
    int i;
    if(arrayEmpleados!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayEmpleados[i].isEmpty != 1)
            {
                    printf("\nMostrar: - Apellido: %s - Nombre: %s - Salario: %.2f - Sector: %d - ID: %d - IsEmpty: %d \n\n",
                    arrayEmpleados[i].apellido, arrayEmpleados[i].nombre, arrayEmpleados[i].salario,
                    arrayEmpleados[i].sector, arrayEmpleados[i].id, arrayEmpleados[i].isEmpty);
                    retorno=0;
            }
        }
    }
    return retorno;
}
int Empleado_buscarEmpleadoPorId(Empleado* arrayEmpleados, int cantidadElementos, int id, int* indice)
{
    int retorno=-1;
    int i;
    if(arrayEmpleados!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayEmpleados[i].id == id && arrayEmpleados[i].isEmpty ==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
static int generarId()
{
    static int contadorId=0;
    return contadorId++;
}
int Empleado_buscarLugarLibre(Empleado* arrayEmpleado, int cantidadElementos, int* indice)
{
    int retorno=-1;
    int i;
    if(arrayEmpleado!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayEmpleado[i].isEmpty ==1)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int Empleado_altaDeEmpleado(Empleado* arrayEmpleados, int cantidadElementos, int indice)
{
    int retorno=-1;
    char auxiliarNombre[51];
    char auxiliarApellido[51];
    int auxilarSector;
    float auxiliarSalario;
    if(arrayEmpleados!=NULL && cantidadElementos>0)
    {
        if(utn_getLetras(auxiliarNombre,51,5,"\nIngrese Nombre: \n","\nNo es un nombre valido. \n")==0)
        {
            if(utn_getLetras(auxiliarApellido,51,5,"\nIngrese Apellido: \n","\nNo es un apellido valido. \n")==0)
            {
                if(utn_getEntero(&auxilarSector,5,"\nIngrese sector: \n","\nNo es un sector valido. \n",PROGRAMADOR,ARQUITECTO)==0)
                {
                    if(utn_getFloat(&auxiliarSalario,5,"\nIngrese salario: \n","\nNo es un salario valido. \n",0,99999)==0)
                    {
                        strncpy(arrayEmpleados[indice].nombre, auxiliarNombre,51);
                        strncpy(arrayEmpleados[indice].apellido, auxiliarApellido,51);
                        arrayEmpleados[indice].sector = auxilarSector;
                        arrayEmpleados[indice].salario = auxiliarSalario;
                        arrayEmpleados[indice].isEmpty=0;
                        arrayEmpleados[indice].id = generarId();
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}
int Empleado_modificarEmpleado(Empleado* arrayEmpleado, int cantidadElementos, int indice, int ID)
{
    int retorno=-1;
    char auxiliarNombre[51];
    char auxiliarApellido[51];
    int auxilarSector;
    float auxiliarSalario;
    if(arrayEmpleado!=NULL && cantidadElementos>0)
    {
        if(Empleado_buscarEmpleadoPorId(arrayEmpleado,cantidadElementos,ID,&indice)==0)
        {
            if(utn_getLetras(auxiliarNombre,51,5,"\nIngrese Nombre: \n","\nNo es un nombre valido. \n")==0)
            {
                if(utn_getLetras(auxiliarApellido,51,5,"\nIngrese Apellido: \n","\nNo es un apellido valido. \n")==0)
                {
                    if(utn_getEntero(&auxilarSector,5,"\nIngrese sector: \n","\nNo es un sector valido. \n",PROGRAMADOR,ARQUITECTO)==0)
                    {
                        if(utn_getFloat(&auxiliarSalario,5,"\nIngrese salario: \n","\nNo es un salario valido. \n",0,99999)==0)
                        {
                            strncpy(arrayEmpleado[indice].nombre,auxiliarNombre,51);
                            strncpy(arrayEmpleado[indice].apellido,auxiliarApellido,51);
                            arrayEmpleado[indice].sector = auxilarSector;
                            arrayEmpleado[indice].salario = auxiliarSalario;
                            retorno=0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
int Empleado_bajaEmpleado(Empleado* arrayEmpleado, int cantidadElementos, int ID)
{
    int retorno=-1;
    int i;
    if(arrayEmpleado!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayEmpleado[i].id == ID && arrayEmpleado[i].isEmpty == 0)
            {
                arrayEmpleado[i].isEmpty=1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int Empleado_ordenamientoDeEmpleados(Empleado* arrayEmpleados, int i, int j)
{
    int retorno=-1;
    Empleado campos[1];
    if(arrayEmpleados!=NULL && i!=j)
    {
        strcpy(campos[0].nombre,arrayEmpleados[i].nombre);
        strcpy(campos[0].apellido, arrayEmpleados[i].apellido);
        campos[0].salario = arrayEmpleados[i].salario;
        campos[0].sector=arrayEmpleados[i].sector;
        campos[0].id=arrayEmpleados[i].id;
        campos[0].isEmpty=arrayEmpleados[i].isEmpty;

        strcpy(arrayEmpleados[i].nombre,arrayEmpleados[j].nombre);
        strcpy(arrayEmpleados[i].apellido,arrayEmpleados[j].apellido);
        arrayEmpleados[i].salario=arrayEmpleados[j].salario;
        arrayEmpleados[i].sector=arrayEmpleados[j].sector;
        arrayEmpleados[i].id=arrayEmpleados[j].id;
        arrayEmpleados[i].isEmpty=arrayEmpleados[j].isEmpty;

        strcpy(arrayEmpleados[j].nombre, campos[0].nombre);
        strcpy(arrayEmpleados[j].apellido, campos[0].apellido);
        arrayEmpleados[j].salario=campos[0].salario;
        arrayEmpleados[j].sector=campos[0].sector;
        arrayEmpleados[j].id=campos[0].id;
        arrayEmpleados[j].isEmpty=campos[0].isEmpty;
    }
    return retorno;
}
int Empleado_ordenarPorApellidoYSector(Empleado* arrayEmpleado, int cantidadElementos,int ordenarAscendenteDescendente)
{
    int retorno=-1;
    int i;
    int flagNoEstaOrdenado=1;
    if(arrayEmpleado!=NULL && cantidadElementos>0)
    {
        while(flagNoEstaOrdenado==1)
        {
            flagNoEstaOrdenado=0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if(((strcmp(arrayEmpleado[i].apellido,arrayEmpleado[i+1].apellido)<0)&&ordenarAscendenteDescendente==0) ||
                   ((strcmp(arrayEmpleado[i].apellido,arrayEmpleado[i+1].apellido)>0)&&ordenarAscendenteDescendente==1))
                {
                    Empleado_ordenamientoDeEmpleados(arrayEmpleado,i,i+1);
                    flagNoEstaOrdenado=1;
                    retorno=0;
                }
                    else if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[i+1].apellido)==0&&(
                            (arrayEmpleado[i].sector<arrayEmpleado[i+1].sector && ordenarAscendenteDescendente==0)||
                            (arrayEmpleado[i].sector>arrayEmpleado[i+1].sector && ordenarAscendenteDescendente==1)))
                    {
                        Empleado_ordenamientoDeEmpleados(arrayEmpleado,i,i+1);
                        flagNoEstaOrdenado=1;
                        retorno=0;
                    }
            }
        }
    }
    return retorno;
}
int Empleado_totalYPromedioDeSalarios(Empleado* arrayEmpleados,int cantidadElementos, float* indiceAcumulador, int* indiceContador,float* indicePromedio)
{
    //int retorno=-1;
    int i;
    int auxiliarAcumulador=0;
    int auxiliarContador=0;
    if(arrayEmpleados!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayEmpleados[i].isEmpty==0)
            {
                auxiliarAcumulador=arrayEmpleados[i].salario;
                auxiliarAcumulador++;
                auxiliarContador++;
            }
        }
        *indiceAcumulador=auxiliarAcumulador;
        *indicePromedio=auxiliarAcumulador/auxiliarContador;
         auxiliarContador=0;
            for(i=0;i<cantidadElementos;i++)
            {
                if(arrayEmpleados[i].isEmpty==0 && arrayEmpleados[i].salario>*indicePromedio)
                {
                    auxiliarContador++;
                }
            }
        *indiceContador=auxiliarContador;
    }
    return 0;
}
void Empleado_alta_forzada(Empleado* empleado,int len,
                      char* nombre,char* apellido,
                      int sector ,float salario)
{
    int index;
    if(Empleado_buscarLugarLibre(empleado,len,&index)==0)
    {
        if(index>=0)
        {
            empleado[index].sector = sector;
            empleado[index].salario = salario;

            strncpy(empleado[index].nombre,nombre,51);
            strncpy(empleado[index].apellido,apellido,51);

            empleado[index].isEmpty=0;
            empleado[index].id = generarId();
        }
    }
}
