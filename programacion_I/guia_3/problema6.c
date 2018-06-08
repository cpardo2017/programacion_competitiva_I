#include <stdlib.h>
#include <stdio.h>

int main()
{
	int c,suma;

	suma=0.0f;

	printf("ingrese un numero en coma flotante\n");
	
	while((c=fgetc(stdin))!='\n')
	{
		if(c!='-' && c!='.')
		{
			suma=suma+(c-'0');
		}
	}

	printf("la suma de sus digitos son: %d\n",suma);

	return 0;
}