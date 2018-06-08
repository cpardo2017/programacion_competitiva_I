#include <stdio.h>
#include <stdlib.h>

int main()
{
	char i;
	int estado=0;

	printf("ingrese un caracter\n");

	scanf("%c",&i);

	if(i>='a' && i<='z')
	{
		estado=1;
	}

	if(i>='A' && i<='Z')
	{
		estado=2;
	}

	if(i>='0' && i<='9')
	{
		estado=3;
	}

	switch(estado)
	{
		case 0: printf("otro\n");
				break;
		case 1: printf("minuscula\n");
				break;
		case 2: printf("mayuscula\n");
				break;
		case 3: printf("numero\n");
				break;
	}

	return 0;
}