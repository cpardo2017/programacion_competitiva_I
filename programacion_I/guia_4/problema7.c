#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int determinante(int n,int m1[][n])
{
	int i,j,k,aux;

	if(n!=2 && n!=3 && n!=4)
	{
		return INT_MIN;
	}

	if(n==2)
	{
		return (m1[0][0]*m1[1][1]-m1[0][1]*m1[1][0]);
	}

	if(n>2)
	{
		int det=0;
		n--;
		int m2[n][n];

		for(i=0;i<n+1;i++)
		{
			for(j=0;j<n;j++)
			{
				aux=0;

				for(k=0;k<n+1;k++)
				{
					if(k!=i)
					{
						m2[j][k-aux]=m1[j+1][k];
					}

					else
					{
						aux=1;
					}
				}
			}

			if(i==0 || i%2==0)
			{
				det+=m1[0][i]*determinante(n,m2);
			}

			else
			{
				det-=m1[0][i]*determinante(n,m2);
			}
		}

		return det;
	}
}

int main()
{
	int n,i,j;

	printf("introduzca la dimension de su matriz\n");
	scanf("%d",&n);

	int matriz[n][n];

	printf("introduzca los numeros de su matriz(de izquierda a derecha, de arriba abajo)\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&matriz[i][j]);
		}
	}

	printf("el determinante de la matriz es: %d\n",determinante(n,matriz));

	return 0;
}