#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int byte1[8]={0};
	int byte2[8]={0};
	int byte3[8]={0};
	int byte4[8]={0};
	int numeros[4]={0};
	char caracteres[4];
	unsigned int num,resto,aux,i,j,k,l;

	printf("ingrese un numero entero\n");

	scanf("%d",&num);
	i=0;

	while(num>=2 && i<8)
	{
		resto=num%2;
		byte1[i]=resto;
		i++;
		num=num/2;
	}

	i=0;

	while(num>=2 && i<8)
	{
		resto=num%2;
		byte2[i]=resto;
		i++;
		num=num/2;
	}

	i=0;

	while(num>=2 && i<8)
	{
		resto=num%2;
		byte3[i]=resto;
		i++;
		num=num/2;
	}

	i=0;

	while(num>=2 && i<8)
	{
		resto=num%2;
		byte4[i]=resto;
		i++;
		num=num/2;
	}

	for(j=0;j<4;j++)
	{
		aux=byte1[j];
		byte1[j]=byte1[7-j];
		byte1[7-j]=aux;

		aux=byte2[j];
		byte2[j]=byte2[7-j];
		byte2[7-j]=aux;

		aux=byte3[j];
		byte3[j]=byte3[7-j];
		byte3[7-j]=aux;

		aux=byte4[j];
		byte4[j]=byte4[7-j];
		byte4[7-j]=aux;
	}

	for(i=0;i<8;i++)
	{
		numeros[0]+=byte1[i]*pow(2,7-i);
	}

	for(i=0;i<8;i++)
	{
		numeros[1]+=byte2[i]*pow(2,7-i);
	}

	for(i=0;i<8;i++)
	{
		numeros[2]+=byte3[i]*pow(2,7-i);
	}

	for(i=0;i<8;i++)
	{
		numeros[3]+=byte4[i]*pow(2,7-i);
	}

	for(i=0;i<4;i++)
	{
		caracteres[i]=numeros[i];
		printf("numero %d: %d caracter %d: %c\n",i+1,numeros[i],i+1,caracteres[i]);
	}



	return 0;
}