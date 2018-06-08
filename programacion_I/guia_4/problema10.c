#include <stdio.h>
#include <stdlib.h>

void modificarMatriz(int n, int m, int mat1[n][m])
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mat1[i][j]==1)
			{
				mat1[i][j]=-1;
			}
		}
	}
}

int main()
{
	int n,m,i,j;

	printf("ingrese las dimensiones de la matriz(fila,columna)\n");
	scanf("%d %d",&n,&m);

	int matriz[n][m];

	printf("ingrese los numeros de su matriz de izquierda a derecha, arriba a abajo\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&matriz[i][j]);
		}
	}

	modificarMatriz(n,m,matriz);

	printf("la nueva matriz es:\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",matriz[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	return 0;
}