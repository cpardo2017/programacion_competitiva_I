#include <stdio.h>
#include <stdlib.h>

void ordenParcial(int* v1, int n,int cant)
{
	int i,j,aux;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(v1[i]<v1[j])
			{
				aux=v1[i];
				v1[i]=v1[j];
				v1[j]=aux;
			}
		}
	}

	for(i=0;i<cant-1;i++)
	{
		for(j=i+1;j<cant;j++)
		{
			if(v1[i]>v1[j])
			{
				aux=v1[i];
				v1[i]=v1[j];
				v1[j]=aux;
			}
		}
	}
}

int main()
{
	int n,i,limite;

	printf("ingrese los numeros que tendra su vector\n");
	scanf("%d",&n);

	int *vector;

	printf("ingrese los numeros de su vector\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&vector[i]);
	}

	do
	{
		printf("ingrese el limite de su ordenamiento, debe ser menor o igual al tamaño del vector\n");
		scanf("%d",&limite);

	}while(limite>n);

	ordenParcial(vector,n,limite);

	printf("el nuevo vector es\n");

	for(i=0;i<n;i++)
	{
		printf("%d ",vector[i]);
	}

	printf("\n");

	return 0;
}