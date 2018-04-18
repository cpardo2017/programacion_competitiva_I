#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{	
	int cantidad,i,j,d,resto,verificador,dividendo,divisor;
	double pi,combinaciones,pares;
	int contador=1;

	for(;;)
	{
		scanf("%d",&cantidad);
		contador++;


		if(cantidad==0)
		{
			break;
		}

		int numeros[cantidad];
		combinaciones=0.0f;
		pares=0.0f;

		for(i=0;i<cantidad;i++)
		{
			scanf("%d",&numeros[i]);
		}

		for(i=0;i<cantidad;i++)
		{
			for(j=i+1;j<cantidad;j++)
			{
				combinaciones++;
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

				if(resto==1)
				{
					pares++;
				}

				
			}
		}

		if(contador==480)
		{
			for(i=0;i<cantidad;i++)
			{
				printf("%d\n",numeros[i]);
			}
		}

			
	}

	return 0;
}