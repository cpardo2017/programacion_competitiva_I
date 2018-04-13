#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int n,i,j,contenedor,a,b;

	do
	{
		printf("imprima la cantidad de numeros que desee ingresar\n");
		scanf("%d",&n);
	}while(n<=0);

	int num[n];
	int num_pares[n];
	int num_impares[n];

	printf("ingrese los numeros\n");

	for(i=0,j=0;i+j<n;)
	{
		scanf("%d",&contenedor);
		if(contenedor%2==0)
		{
			num_pares[i]=contenedor;
			i++;
		}

		else
		{
			num_impares[j]=contenedor;
			j++;
		}
	}

	

	for(a=0;a<i;)
	{
		if(num_pares[a]>num_pares[a+1])
		{
			contenedor=num_pares[a];
			num_pares[a]=num_pares[a+1];
			num_pares[a+1]=contenedor; 
			a--;
		}
		else
		{
			a++;
		}

		if(a<0)
		{
			a=0;
		}
	}

	for(a=0;a<j;)
	{
		if(num_impares[a]<num_impares[a+1])
		{
			contenedor=num_impares[a];
			num_impares[a]=num_impares[a+1];
			num_impares[a+1]=contenedor; 
			a--;
		}
		else
		{
			a++;
		}

		if(a<0)
		{
			a=0;
		}
	}
	
	printf("los numeros pares son:\n");
	for(a=0;a<i;a++)
	{
		printf("%d ",num_pares[a]);
	}
	printf("\n");

	printf("los numeros impares son\n");

	for(a=0;a<j;a++)
	{
		printf("%d ",num_impares[a]);
	}

	printf("\n");

	printf("%d %d\n",i,j);

	return 0;
}