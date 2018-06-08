#include <stdlib.h>
#include <stdio.h>

int main()
{
	unsigned char cadena[50000];
	int i=0;
	int aux;

	printf("ingrese una cadena de caracteres\n");

	scanf("%s",cadena);

	while(cadena[i]!='\0')
	{
		aux=1;

		if(cadena[i]>='A' && cadena[i]<='Z')
		{
			cadena[i]=cadena[i]+32;
			aux=0;
		}

		if(cadena[i]>='a' && cadena[i]<='z' && aux)
		{
			cadena[i]=cadena[i]-32;
		}

		i++;
	}

	printf("la nueva cadena es: %s\n",cadena);

	return 0;
}