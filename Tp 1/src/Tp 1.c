/*
 ============================================================================
 Name        : Tp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(void) {
	setbuf(stdout, NULL);
	float auxiliarResultadoMain;
	float auxiliarRetorno;
	float numeroUno;
	float numeroDos;
	int opcion;
	float resultadoFactorial;
	float resultadoFactorialDos;
	int opcionMenu;
	char continuarMenu='s';
	do
	{
		printf("\nIngrese una opcion..\n");
		fflush(stdin);
		printf("\n1-Elegir 1er operando\n2-Elegir 2do operando\n3-Calcular todas las operaciones\n4-Informar resultados\n0- Salir\n\n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
			printf("\nIngrese su primer numero: ");
			scanf("%f",&numeroUno);
			break;

			case 2:
			printf("\nIngrese su segundo numero: ");
			scanf("%f",&numeroDos);
			break;

			case 3:
			do
			{
				system("cls");
				printf("\n1-Calcular Suma\n");
				printf("2-Calcular Resta\n");
				printf("3-Calcular la division\n");
				printf("4-Calcular la multiplicacion\n");
				printf("5-Calcular factorial\n");
				printf("6-Salir\n");
				scanf("%d",&opcionMenu);
				switch(opcionMenu)
				{
					case 1:
					auxiliarRetorno=suma(numeroUno,numeroDos,&auxiliarResultadoMain);
					if(auxiliarRetorno==0)
					{
						printf("\nLa suma es de: %.2f\n", auxiliarResultadoMain);
					}
					system("pause");
					break;

					case 2:
					auxiliarRetorno= resta(numeroUno,numeroDos,&auxiliarResultadoMain);
					if(auxiliarRetorno==0)
					{
						printf("\nLa resta es de: %.2f\n", auxiliarResultadoMain);
					}
					system("pause");
					break;

					case 3:
					fflush(stdin);
					auxiliarRetorno= division(numeroUno,numeroDos,&auxiliarResultadoMain);
					if(auxiliarRetorno==0)
					{
						printf("\nLa division es de: %.2f\n", auxiliarResultadoMain);
					}
					break;

					case 4:
					auxiliarRetorno= multiplicacion(numeroUno,numeroDos,&auxiliarResultadoMain);
					if(auxiliarRetorno==0)
					{
						printf("\nLa multiplicacion es de: %.2f\n", auxiliarResultadoMain);
					}
					system("pause");
					break;

					case 5:
					auxiliarRetorno = factorial(numeroUno,numeroDos,&resultadoFactorial,&resultadoFactorialDos);
					printf("\nEl factorial de %.2f es: %.2f y el factorial de %.2f es: %.2f\n", numeroUno,resultadoFactorial,numeroDos,resultadoFactorialDos);
					break;

					case 6:
					continuarMenu='n';
					break;

					default:
					printf("\nError. Opcion invalida\n");
					system("pause");
				}
			}while(continuarMenu=='s');
			break;

		case 4:
		fflush(stdin);
		auxiliarRetorno = suma(numeroUno, numeroDos, &auxiliarResultadoMain);
		printf("\nLa suma es: %.2f\n", auxiliarResultadoMain);
		auxiliarRetorno = resta(numeroUno, numeroDos, &auxiliarResultadoMain);
		printf("\nLa resta es: %.2f\n", auxiliarResultadoMain);
		auxiliarRetorno = multiplicacion(numeroUno, numeroDos, &auxiliarResultadoMain);
		printf("\nLa multiplicacion: %.2f\n", auxiliarResultadoMain);
		auxiliarRetorno = division(numeroUno, numeroDos, &auxiliarResultadoMain);
		if(numeroDos !=0)
		{
			printf("\nLa division es: %.2f\n", auxiliarResultadoMain);
		}
		auxiliarRetorno = factorial(numeroUno,numeroDos,&resultadoFactorial,&resultadoFactorialDos);
		printf("\nEl factorial de %.2f es: %.2f y el factorial de %.2f es: %.2f\n", numeroUno,resultadoFactorial,numeroDos,resultadoFactorialDos);

		break;
	}

}while(opcion!=0);
return 0;
}
