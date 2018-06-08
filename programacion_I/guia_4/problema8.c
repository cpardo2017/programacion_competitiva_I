#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int caracteresComunes(char* cadena1,char* cadena2)
{
	int contador=0;
	int i,j,aux;
	int permitir[1000000]={0};

	i=0;

	while(cadena1[i]!='\0')
	{
		j=0;
		aux=0;

		while(cadena2[j]!='\0')
		{
			if(cadena1[i]==cadena2[j] && permitir[j]==0)
			{
				if(aux==0)
				{
					contador++;
					aux=1;
					permitir[j]=1;
				}

				else
				{
					permitir[j]=1;
				}
			}
			j++;
		}
		i++;
	}
	return contador;
}

int main()
{
	char vector1[1000000];
	char vector2[1000000];
	int c;

	printf("escriba las dos cadenas de caracteres que desea comparar\n");
	scanf("%s",vector1);
	scanf("%s",vector2);

	printf("el numero de caracteres comunes es: %d\n",caracteresComunes(vector1,vector2));

	return 0;
}