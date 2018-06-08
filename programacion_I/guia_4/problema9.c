#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palindromo(char* cadena1)
{
	int largo=strlen(cadena1);
	char* cadena2=malloc(largo*sizeof(char));
	int i,j;

	for(j=0,i=largo-1;i>=0;i--,j++)
	{
		if(cadena1[i]<='Z' && cadena1[i]>='A')
		{
			cadena1[i]+=32;
		}

		cadena2[j]=cadena1[i];
	}

	if(strcmp(cadena1,cadena2)==0)
	{
		return 1;
	}

	else
	{
		return 0;
	}

}

int main()
{
	char aux;
	char* cadena=malloc(100*sizeof(char));
	printf("ingrese una palabra\n");
	scanf("%s",cadena);

	aux=palindromo(cadena);

	if(aux==1)
	{
		printf("la palabra es un palindromo\n");
	}

	else
	{
		printf("la palabra no es un palindromo\n");
	}

	return 0;
}