/*
 * empleado.h
 *
 *  Created on: 14 may. 2020
 *      Author: Agustin
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_


typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;
}Empleado;

int Empleado_init(Empleado* arrayEmpleados, int cantidadElementos);
int Empleado_mostrar(Empleado* arrayEmpleados, int cantidadElementos);
int Empleado_buscarEmpleadoPorId(Empleado* arrayEmpleados, int cantidadElementos, int id, int* indice);
int Empleado_buscarLugarLibre(Empleado* arrayEmpleado, int cantidadElementos, int* indice);

int Empleado_altaDeEmpleado(Empleado* arrayEmpleados, int cantidadElementos, int indice);
int Empleado_modificarEmpleado(Empleado* arrayEmpleado, int cantidadElementos, int indice, int ID);
int Empleado_bajaEmpleado(Empleado* arrayEmpleado, int cantidadElementos, int ID);

int Empleado_ordenamientoDeEmpleados(Empleado* arrayEmpleados, int i, int j);
int Empleado_ordenarPorApellidoYSector(Empleado* arrayEmpleado, int cantidadElementos,int ordenarAscendenteDescendente);
int Empleado_totalYPromedioDeSalarios(Empleado* arrayEmpleados,int cantidadElementos, float* indiceAcumulador, int* indiceContador,float* indicePromedio);

void Empleado_alta_forzada(Empleado* empleado,int len,
                      char* nombre,char* apellido,
                      int sector ,float salario);
#endif /* EMPLEADO_H_ */
