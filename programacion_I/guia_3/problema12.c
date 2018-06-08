#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	char linea_de_texto_1[1000],linea_de_texto_2[1000],palabras1[1000][1000],palabras2[1000][1000],c;
	char *token;
	int i,j,k,l,aux;

	printf("ingrese dos lineas de texto\n");

	scanf("%[^\n]",linea_de_texto_1);

	c=fgetc(stdin);
	assert(c=='\n');

	token=strtok(linea_de_texto_1," ");
	i=0;

	while(token!=NULL)
	{
		strcpy(palabras1[i],token);
		i++;
		token=strtok(NULL," ");
	}

	scanf("%[^\n]",linea_de_texto_2);

	c=fgetc(stdin);
	assert(c=='\n');

	token=strtok(linea_de_texto_2," ");
	j=0;

	while(token!=NULL)
	{
		strcpy(palabras2[j],token);
		j++;
		token=strtok(NULL," ");
	}

	printf("las palabras comunes son:\n");

	for(k=0;k<i;k++)
	{
		aux=0;

		for(l=0;l<j;l++)
		{
			if(strcmp(palabras1[k],palabras2[l])==0)
			{
				if(aux==0)
				{
					printf("%s\n",palabras1[k]);
					aux=1;
				}
				strcpy(palabras2[l]," ");
			}
		}
	}

	return 0;
}