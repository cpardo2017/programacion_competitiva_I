#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main()
{	
	int casos,largo,num_cadenas,i,j,k,aux,c;
	
	scanf("%d",&casos);
	c=fgetc(stdin);
	assert(c=='\n');

	for(i=0;i<casos;i++)
	{
		c=fgetc(stdin);
		assert(c=='\n');
		
		largo=0;

		while((c=fgetc(stdin))!=' ')
		{
			largo=largo*10+(c-'0');
		}

		num_cadenas=0;

		while((c=fgetc(stdin))!='\n')
		{
			num_cadenas=num_cadenas*10+(c-'0');
		}


		char cadena[num_cadenas][largo],contenedor[largo];
		int desorden[num_cadenas];

		for(j=0;j<num_cadenas;j++)
		{
			scanf("%s",cadena[j]);
		}

		for(j=0;j<num_cadenas;j++)
		{
			desorden[j]=0;

			for(k=0;k<largo;k++)
			{
				for(c=k+1;c<largo;c++)
				{
					if(cadena[j][k]>cadena[j][c])
					{
						desorden[j]++;
					}
				}
			}
		}

		for(j=0;j<num_cadenas-1;)
		{

			if(desorden[j]>desorden[j+1])
			{

				strcpy(contenedor,cadena[j]);
				strcpy(cadena[j],cadena[j+1]);
				strcpy(cadena[j+1],contenedor);

				aux=desorden[j];
				desorden[j]=desorden[j+1];
				desorden[j+1]=aux;
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
			printf("%s\n",cadena[j]);
		}

		printf("\n");
	}

	return 0;
}