#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num,octal[3],hexadecimal[3],resto,aux,i,j,k;
	unsigned char caracter;


	do
	{
		printf("escriba un numero entero entre 0 y 255\n");
		scanf("%d",&num);
	}while(num<0 || num>255);
	

	caracter=num;

	printf("el caracter es: %c\n",caracter);
	printf("el entero es: %d\n",num );

	aux=num;
	i=0;

	while(aux>=8)
	{
		resto=aux%8;
		octal[i]=resto;
		i++;
		aux=aux/8;
	}

	octal[i]=aux;
	i++;

	for(k=0;k<i/2;k++)
	{
		aux=octal[k];
		octal[k]=octal[i-k-1];
		octal[i-k-1]=aux;
	}

	aux=num;
	j=0;

	while(aux>=16)
	{
		resto=aux%16;
		hexadecimal[j]=resto;
		j++;
		aux=aux/16;
	}

	hexadecimal[j]=aux;
	j++;

	for(k=0;k<j/2;k++)
	{
		aux=hexadecimal[k];
		hexadecimal[k]=hexadecimal[j-k-1];
		hexadecimal[j-k-1]=aux;
	}

	printf("el numero octal es: ");

	for(k=0;k<i;k++)
	{
		printf("%d",octal[k]);
	}
	printf("\n");

	printf("el numero hexadecimal es: ");

	for(k=0;k<j;k++)
	{
		if(hexadecimal[k]<=9)
		{
			printf("%d",hexadecimal[k]);
		}

		else
		{
			switch(hexadecimal[k])
			{
				case 10: printf("A");
						break;
				case 11: printf("B");
						break;
				case 12: printf("C");
						break;
				case 13: printf("D");
						break;
				case 14: printf("E");
						break;
				case 15: printf("F");
						break;
			}
		}
	}

	printf("\n");
	return 0;
}