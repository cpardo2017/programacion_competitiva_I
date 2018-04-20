#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{	
	int cantidad,i,j,d,resto,verificador,dividendo,divisor,a;
	double pi,combinaciones,pares;
	int contador=0;


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

				if(numeros[i]==1 || numeros[j]==1)
				{
					pares++;
					continue;
				}

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



		if(pares>0)
		{
			pi=(6*combinaciones)/pares;
			pi=sqrt(pi);
			printf("%lf\n",pi);
		}

		else
		{
			printf("No estimate for this data set.\n");
		}


			
	}


	return 0;
}
