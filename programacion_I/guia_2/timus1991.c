#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int droides,escuadrones,i,resultado;
	scanf("%d %d",&escuadrones,&droides);
	int camiones[escuadrones];

	for(i=0;i<escuadrones;i++)
	{
		scanf("%d",&camiones[i]);
	}

	int bombas_no_usadas=0;
	int sobrevivientes=0;

	for(i=0;i<escuadrones;i++)
	{
		resultado=droides-camiones[i];

		if(resultado>=0)
		{
			sobrevivientes=sobrevivientes+resultado;
		}

		else
		{
			resultado=abs(resultado);
			bombas_no_usadas=bombas_no_usadas+resultado;
		}
	}

	printf("%d %d\n",bombas_no_usadas,sobrevivientes);



	return 0;
}