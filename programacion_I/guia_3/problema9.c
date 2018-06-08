#include <stdio.h>
#include <stdlib.h>

int main()
{
	char caracteres[10000],negatividad;
	int numero;
	int i=0;

	printf("ingrese un numero en coma flotante\n");

	scanf("%s",caracteres);

	negatividad=0;

	while(caracteres[i]!='\0' && caracteres[i]!='.')
	{
		if(caracteres[i]=='-')
		{
			negatividad=1;
			i++;
			continue;
		}

		numero=numero*10+(caracteres[i]-'0');
		i++;
	}

	if(negatividad==1)
	{
		numero=-numero;
	}

	printf("el numero entero redondeado es: %d\n",numero);

	return 0;
}