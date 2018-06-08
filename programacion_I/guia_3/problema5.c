#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main()
{
	int numero,aux,i,resto,j,igualdad;
	unsigned char caracter;
	int binario[32]={0};
	int byte1[8]={0};
	int byte2[8]={0};
	int byte3[8]={0};
	int byte4[8]={0};
	int byte_char[8]={0};

	printf("escriba un numero\n");

	scanf("%d",&numero);

	aux=fgetc(stdin);
	assert(aux=='\n');

	printf("escriba un caracter\n");

	scanf("%c",&caracter);

	aux=numero;
	i=0;

	if(aux<0)
	{
		binario[31]=1;
		aux=abs(aux);
	}

	while(aux>=2)
	{
		resto=aux%2;
		binario[i]=resto;
		aux=aux/2;
		i++;
	}

	binario[i]=aux;

	for(j=0;j<16;j++)
	{
		aux=binario[j];
		binario[j]=binario[31-j];
		binario[31-j]=aux;
	}

	for(j=0;j<32;j++)
	{
		if(j<8)
		{
			byte1[j]=binario[j];
			continue;
		}

		if(j<16)
		{
			byte2[j-8]=binario[j];
			continue;
		}

		if(j<24)
		{
			byte3[j-16]=binario[j];
			continue;
		}

		byte4[j-24]=binario[j];
	}

	aux=caracter;
	i=0;

	while(aux>=2)
	{
		resto=aux%2;
		byte_char[i]=resto;
		aux=aux/2;
		i++;
	}

	byte_char[i]=aux;

	for(j=0;j<4;j++)
	{
		aux=byte_char[j];
		byte_char[j]=byte_char[7-j];
		byte_char[7-j]=aux;
	}

	igualdad=1;

	for(j=0;j<8;j++)
	{
		if(byte_char[j]!=byte1[j])
		{
			igualdad=0;
			break;
		}
	}

	if(igualdad==1)
	{
		printf("contenido\n");
		return 0;
	}

	igualdad=1;

	for(j=0;j<8;j++)
	{
		if(byte_char[j]!=byte2[j])
		{
			igualdad=0;
			break;
		}
	}

	if(igualdad==1)
	{
		printf("contenido\n");
		return 0;
	}

	igualdad=1;

	for(j=0;j<8;j++)
	{
		if(byte_char[j]!=byte3[j])
		{
			igualdad=0;
			break;
		}
	}

	if(igualdad==1)
	{
		printf("contenido\n");
		return 0;
	}

	igualdad=1;

	for(j=0;j<8;j++)
	{
		if(byte_char[j]!=byte4[j])
		{
			igualdad=0;
			break;
		}
	}

	if(igualdad==1)
	{
		printf("contenido\n");
		return 0;
	}

	for(j=0;j<32;j++)
	{
		if(j<8)
		{
			binario[j]=byte_char[j];
			continue;
		}

		if(j<16)
		{
			binario[j]=byte_char[j-8];
			continue;
		}

		if(j<24)
		{
			binario[j]=byte_char[j-16];
			continue;
		}

		binario[j]=byte_char[j-24];
	}

	numero=0;

	for(j=0;j<32;j++)
	{
		numero=numero+binario[j]*(int)pow(2,31-j);
	}

	printf("%d\n",numero);

	return 0;
}