#include <stdlib.h>
#include <stdio.h>

int main()
{

	long long aux,binario[27],octal[9],hexadecimal[7],resto;
	int i,j,k,l,a;

    long long num[5]={29,131,2048,121817,4000000001};

	for(a=0;a<5;a++)
	{
		aux=num[a];
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

		for(l=0;l<i/2;l++)
		{
			aux=octal[l];
			octal[l]=octal[i-l-1];
			octal[i-l-1]=aux;
		}

		aux=num[a];
		j=0;

		while(aux>=2)
		{
			resto=aux%2;
			binario[j]=resto;
			j++;
			aux=aux/2;
		}
		
		binario[j]=aux;
		j++;
		
		for(l=0;l<j/2;l++)
		{
			aux=binario[l];
			binario[l]=binario[j-l-1];
			binario[j-l-1]=aux;
		}

		aux=num[a];
		k=0;

		while(aux>=16)
		{
			resto=aux%16;
			hexadecimal[k]=resto;
			k++;
			aux=aux/16;
		}

		hexadecimal[k]=aux;
		k++;

		for(l=0;l<k/2;l++)
		{
			aux=hexadecimal[l];
			hexadecimal[l]=hexadecimal[k-l-1];
			hexadecimal[k-l-1]=aux;
		}

		printf("numero en base 10: %lld\n",num[a]);
		printf("el numero en binario es: ");

		for(l=0;l<j;l++)
		{
			printf("%lld",binario[l]);
		}
		
		printf("\n");
		printf("el numero en octal es: ");

		for(l=0;l<i;l++)
		{
			printf("%lld",octal[l]);
		}
		
		printf("\n");
		printf("el numero en hexadecimal es: ");
		
		for(l=0;l<k;l++)
		{
			if(hexadecimal[l]<=9)
			{
				printf("%lld",hexadecimal[l]);
			}

			else
			{
				switch(hexadecimal[l])
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
		printf("\n");
	}
	return 0;
}