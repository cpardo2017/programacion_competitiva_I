#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{	
	int casos,largo,num_cadenas,i,j,k,aux;
	
	scanf("%d",&casos);

	for(i=0;i<casos;i++)
	{
		scanf("%d %d",&largo,&num_cadenas);

		char cadena[num_cadenas][largo],contenedor[largo];
		int desorden[num_cadenas];

		for(j=0;j<num_cadenas;j++)
		{
			desorden[j]=0;

			for(k=0;k<largo;k++)
			{
				scanf("%c",&cadena[j][k]);
				aux=cadena[j][k]*(unsigned int)pow(2,largo-k);
				desorden[j]=desorden[j]+aux;
			}
		}

		/*for(j=0;j<num_cadenas;)
		{
			if(desorden[j]>desorden[j+1])
			{
				strcpy(contenedor,cadena[j][0]);
				strcpy(cadena[j][0],cadena[j+1][0]);
				strcpy(cadena[j+1][0],contenedor);
				j--;
			}

			else
			{
				j++;
			}

			if(j<0)
			{
				j=0;
			}
		}

		for(j=0;j<num_cadenas;j++)
		{
			printf("%s\n",cadena[j][]);
		}*/

		printf("\n");
	}

	return 0;
}