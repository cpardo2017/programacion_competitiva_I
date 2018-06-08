#include <stdio.h>
#include <stdlib.h>

int longitudPalabraMasLarga(int n, char crucigrama[n][n])
{
	int contador=0;
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(crucigrama[i][j]=='-')
			{
				break;
			}
		}

		if(j>contador)
		{
			contador=j;
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(crucigrama[j][i]=='-')
			{
				break;
			}
		}

		if(j>contador)
		{
			contador=j;
		}
	}

	return contador;
}

int main()
{
	int n,i;

	printf("ingrese la dimension de su matriz\n");
	scanf("%d",&n);

	char matriz[n][n];

	printf("ingrese su crucigrama\n");

	for(i=0;i<n;i++)
	{
		scanf("%s",matriz[i]);
	}

	printf("el tamaño de la palabra mas larga del crucigrama es: %d\n",longitudPalabraMasLarga(n,matriz));

	return 0;
	
}