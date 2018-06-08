#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main()
{	
	int n,i,j,k,contador,igualdad,aux,c,mayor;

	scanf("%d",&n);
	char nombre[n][1000],salto[1000],contenedor[50];
	int repetitividad[n],suma[n];
	char *token;
	c=fgetc(stdin);
	assert(c=='\n');

	for(i=0;i<n;i++)
	{
		repetitividad[i]=0;
	}

	for(i=0;i<n;i++)
	{
		scanf("%[^\n]",salto);
		c=fgetc(stdin);
		assert(c=='\n');
		token=strtok(salto," ");
		strcpy(nombre[i],token);
	}

	for(i=0;i<n-1;)
	{
		if(strcmp(nombre[i],nombre[i+1])>0)
		{
			strcpy(contenedor,nombre[i]);
			strcpy(nombre[i],nombre[i+1]);
			strcpy(nombre[i+1],contenedor);
			i--;
		}

		else
		{
			i++;
		}

		if(i<0)
		{
			i=0;
		}

	}

	for(i=0;i<n;i++)
	{
		if(repetitividad[i]==1)
		{
			continue;
		}

		contador=1;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(nombre[i],nombre[j])==0 && repetitividad[j]==0)
			{
				contador++;
				repetitividad[j]=1;
			}
		}

		printf("%s ",nombre[i]);
		printf("%d\n",contador);
	}

	return 0;

}