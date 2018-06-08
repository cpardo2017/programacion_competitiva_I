#include <stdio.h>
#include <stdlib.h>

int main()
{
	char linea_de_texto[1000000];
	int palabras,caracteres,espacios,mayusculas,minusculas;

	printf("ingrese una linea de texto\n");

	scanf("%[^\n]",linea_de_texto);

	int i=0;
	caracteres=0;
	espacios=0;
	minusculas=0;
	mayusculas=0;

	while(linea_de_texto[i]!='\0')
	{
		caracteres++;

		if(linea_de_texto[i]>='A' && linea_de_texto[i]<='Z')
		{
			mayusculas++;
		}

		if(linea_de_texto[i]>='a' && linea_de_texto[i]<='z')
		{
			minusculas++;
		}

		if(linea_de_texto[i]==' ')
		{
			espacios++;
		}

		i++;
	}

	printf("N° de caracteres: %d\n",caracteres);
	printf("N° de palabras: %d\n",espacios+1);
	printf("N° de mayusculas: %d\n",mayusculas);
	printf("N° de minusculas: %d\n",minusculas);


	return 0;
}