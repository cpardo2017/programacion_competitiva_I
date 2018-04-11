#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{	
	int cantidad,i,j,d,limite,verificador;
	float pi,combinaciones,pares;

	for(;;)
	{
		scanf("%d",&cantidad);


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
				if(numeros[i]<numeros[j])
				{
					limite=numeros[i];
				}

				else
				{
					limite=numeros[j];
				}

				verificador=0;

				for(d=2;d<=limite;d++)
				{
					if(numeros[i]%d==0 && numeros[j]%d==0)
					{
						verificador=1;
						break;
					}
				}
				
				if(verificador==0)
				{
					pares++;
				}
			}
		}

		if(pares!=0)
		{
			pi=(6.0f*combinaciones)/pares;
			pi=sqrt(pi);
			printf("%*f\n",6,pi);	
		}
		
		else
		{
			printf("No estimate for this data set.\n");
		}	
	}

	return 0;
}