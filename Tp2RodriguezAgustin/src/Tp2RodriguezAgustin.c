/*
 ============================================================================
 Name        : Tp2RodriguezAgustin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "empleado.h"
#define EMPLEADOS 1000
#define PROGRAMADOR 0
#define INGERNIERO 1
#define ARQUITECTO 2
int main(void) {
	setbuf(stdout,NULL);
	Empleado arrayEmpleadoMain[EMPLEADOS];
	    Empleado_init(arrayEmpleadoMain,EMPLEADOS);
	    int auxiliarIndiceMain;
	    int auxiliarIdMain;
	    float totalSueldosMain;
	    int mayorAlPromedioMain;
	    float promedioMain;
	    int opcion=0;
	    /*Empleado_alta_forzada(arrayEmpleadoMain,EMPLEADOS,"MARCELO","DOMINGUEZ",PROGRAMADOR,1200.50);
	    Empleado_alta_forzada(arrayEmpleadoMain,EMPLEADOS,"TITO","CARDOZO",INGERNIERO,1100.50);
	    Empleado_alta_forzada(arrayEmpleadoMain,EMPLEADOS,"JOSE","SOTO",ARQUITECTO,1300.50);
	    Empleado_alta_forzada(arrayEmpleadoMain,EMPLEADOS,"MANUEL","DIAZ",INGERNIERO,1800.21);*/
	    do
	    {
	        printf("\n1-Alta de Empleado: \n2-Modificar un empleado: \n3-Baja de un empleado: \n4-Informe: Ordenar por apellido y sector. \n5-Informe: Total salarios y promedios. \n0-Salir:");
	        scanf("%d",&opcion);
	        switch(opcion)
	        {
	            case 1:
	            if(Empleado_buscarLugarLibre(arrayEmpleadoMain,EMPLEADOS,&auxiliarIndiceMain)==0)
	            {
	                Empleado_altaDeEmpleado(arrayEmpleadoMain,EMPLEADOS,auxiliarIndiceMain);
	                printf("\nSe ha dado de alta satisfactoriamente.\n");
	            }
	            else
	            {
	                printf("\nNo se ha podido dar de alta.\n");
	            }
	            break;
	            case 2:
	            if(utn_getEntero(&auxiliarIdMain,5,"\nIngrese ID: \n","\nError. No es valida la ID. \n",0,999)==0 &&
	               Empleado_buscarEmpleadoPorId(arrayEmpleadoMain,EMPLEADOS,auxiliarIdMain,&auxiliarIndiceMain)==0)
	            {
	                Empleado_modificarEmpleado(arrayEmpleadoMain,EMPLEADOS,auxiliarIndiceMain,auxiliarIdMain);
	                printf("\nSe ha modificado satisfactoriamente. \n");
	            }
	            else
	            {
	                printf("\nError. No se ha podido modificar. \n");
	            }
	            break;
	            case 3:
	            if(utn_getEntero(&auxiliarIdMain,5,"\nIngrese ID: \n","\nError. No es una ID valida. \n",0,999)==0 &&
	                Empleado_buscarEmpleadoPorId(arrayEmpleadoMain,EMPLEADOS,auxiliarIdMain,&auxiliarIndiceMain)==0)
	            {
	                    Empleado_bajaEmpleado(arrayEmpleadoMain,EMPLEADOS,auxiliarIdMain);
	                    printf("\nSe ha dado de baja satisfactoriamente. \n");
	            }
	            else
	            {
	                    printf("\nError. No se ha podido dar de baja. \n");
	            }
	            break;
	            case 4:
	                Empleado_ordenarPorApellidoYSector(arrayEmpleadoMain,EMPLEADOS,1);
	                Empleado_mostrar(arrayEmpleadoMain,EMPLEADOS);
	                break;
	            case 5:
	                Empleado_totalYPromedioDeSalarios(arrayEmpleadoMain,EMPLEADOS,&totalSueldosMain,&mayorAlPromedioMain,&promedioMain);
	                printf("\nEl total es: %.2f\nLos salarios mayores al promedio son: %d\nEl promedio es: %.2f\n",
	                       totalSueldosMain,mayorAlPromedioMain,promedioMain);
	                break;
	        }
	    }while(opcion!=0);
	return EXIT_SUCCESS;
}
