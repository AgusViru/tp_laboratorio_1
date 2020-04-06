/*
 * funciones.c
 *
 *  Created on: 6 abr. 2020
 *      Author: Agustin
 */


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**\brief solicita al usuario dos numeros para sumarlos y el valor se guarda dentro de un puntero.
 *
 * \param un numero entero.
 * \param un numero entero.
 * \param un puntero de tipo float llamado resultado.
 * \return la suma de ambos numeros.
 *
 */
float suma(int numeroUno, int numeroDos, float* parametroResultado)
{
	int retorno=-1;
	int auxiliarResultado;
	auxiliarResultado= numeroUno+numeroDos;
	if(auxiliarResultado < 32000)
	{
		*parametroResultado=auxiliarResultado;
		retorno=0;
	}
	return retorno;
}
/**\brief solicita al usuario dos numeros para restarlos y el valor se guarda dentro de un puntero.
 *
 * \param un numero entero.
 * \param un numero entero.
 * \param un puntero de tipo float llamado resultado.
 * \return la resta de ambos numeros.
 *
 */
float resta(int numeroUno, int numeroDos, float* parametroResultado)
{
	int retorno=-1;
	int auxiliarResultado;
	auxiliarResultado= numeroUno-numeroDos;
	if(auxiliarResultado < 32000)
	{
		*parametroResultado=auxiliarResultado;
		retorno=0;
	}
	return retorno;
}
/**\brief solicita al usuario dos numeros para multiplicarlos y el valor se guarda dentro de un puntero.
 *
 * \param un numero entero.
 * \param un numero entero.
 * \param un puntero de tipo float llamado resultado.
 * \return la multiplicacion de ambos numeros.
 *
 */
float multiplicacion(int numeroUno, int numeroDos, float* parametroResultado)
{
	int retorno=-1;
	int auxiliarResultado;
	auxiliarResultado= numeroUno*numeroDos;
	if(auxiliarResultado < 32000)
	{
		*parametroResultado=auxiliarResultado;
		retorno=0;
	}
	return retorno;
}
/**\brief solicita al usuario dos numeros para dividirlos y el valor se guarda dentro de un puntero.
 *
 * \param un numero entero.
 * \param un numero entero.
 * \param un puntero de tipo float llamado resultado.
 * \return la division de ambos numeros.
 *
 */
float division(int numeroUno, int numeroDos, float* parametroResultado)
{
	int retorno=-1;
	int auxiliarResultado;

	if(numeroDos != 0)
	{
		auxiliarResultado= numeroUno/numeroDos;
		*parametroResultado=auxiliarResultado;
		retorno=0;
	}
	else
	{
		printf("\nError no es posible dividir por 0\n");
	}
	return retorno;
}
/**\brief solicita al usuario un numero para hacer el factorial y el valor se guarda dentro de un puntero.
 *
 * \param un numero entero.
 * \param un numero entero.
 * \param un puntero de tipo float llamado resultado.
 * \param un puntero de tipo float llamado resultadoDos.
 * \return el factorial de dos numeros.
 *
 */
float factorial(float primerNumero,float segundoNumero,float* resultado, float* resultadoDos)
{
    int retorno=-1;
    long auxiliarCalculo;
    long auxiliarCalculoDos;

    auxiliarCalculo = (long)primerNumero;
    auxiliarCalculoDos = (long)segundoNumero;
    while(primerNumero > 1 && segundoNumero>1)
    {
        primerNumero--;
        segundoNumero--;
        auxiliarCalculo = auxiliarCalculo * primerNumero;
        auxiliarCalculoDos = auxiliarCalculoDos * segundoNumero;
        retorno=0;
    }
        *resultado = auxiliarCalculo;
        *resultadoDos = auxiliarCalculoDos;
    return retorno;
}
