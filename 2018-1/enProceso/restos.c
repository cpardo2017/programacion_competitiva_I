#include <stdlib.h>
#include <stdio.h>

int main()
{
	int numeros[38],dividendo,divisor,resto,i,j;

	for(i=0;i<28;i++)
	{
		scanf("%d",&numeros[i]);
	}

	for(i=0;i<38;i++)
	{
		for(j=i+1;j<38;j++)
		{
			resto=0;

			if(numeros[i]<numeros[j])
			{
				dividendo=numeros[j];
				divisor=numeros[i];
			}

			else
			{
				dividendo=numeros[i];
				divisor=numeros[j];
			}

			do
			{
				resto=dividendo%divisor;
				dividendo=divisor;
				divisor=resto;					
			}while(resto!=0 && resto!=1);

			printf("%d %d\n",numeros[i],numeros[j]);

			if(resto==1)
			{
			printf("no hay factores comunes\n");
			}

			if(resto==0)
			{
			printf(" hay factores comunes\n");
			}
		}


	}

	return 0;
}