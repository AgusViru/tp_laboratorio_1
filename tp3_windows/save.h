/*
 * save.h
 *
 *  Created on: 8 jun. 2020
 *      Author: Ezequiel
 */

#ifndef SAVE_H_
#define SAVE_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
int save_EmployeesAsText(FILE* pFile,LinkedList* pArrayListEmployee);
int save_EmployeesAsBin(FILE* pArchivo,LinkedList* pArrayListEmployee);

#endif /* SAVE_H_ */
