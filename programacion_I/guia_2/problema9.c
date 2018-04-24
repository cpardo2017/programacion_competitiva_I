#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,i,j,a,b,diferencia,aux,dis,fila,columna,fila_menor,columna_menor,menor,distancia_menor;

	printf("ingrese el coeficiente de la matriz cuadrada\n");
	scanf("%d",&n);

	int original[n][n];
	int distancias[n][n];
	printf("ingrese los elementos de la matriz de izquierda a derecha y de arriba a abajo\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&original[i][j]);
		}
	}


 	for(a=0;a<n;a++)
 	{
 		for(b=0;b<n;b++)
 		{

 			if(a==0 && b==0)
 			{
 				menor=abs(original[a][b]-original[a][b+1]);
 				distancia_menor=1;
 			}

 			else
 			{
 				menor=abs(original[a][b]-original[0][0]);
 				distancia_menor=a+b;
 			}

 			for(i=0;i<n;i++)
 			{
 				for(j=0;j<n;j++)
 				{
 					if(a!=i || b!=j)
 					{
 						diferencia=abs(original[a][b]-original[i][j]);

						if(menor==diferencia)
						{
							dis=abs(i-a)+abs(j-b);
							if(dis<distancia_menor)
							{
								distancia_menor=dis;
							}							
						}

						if(menor>diferencia)
 						{
 							distancia_menor=abs(i-a)+abs(j-b);
 							menor=diferencia;
 							columna=b;
 							fila=a;
 							columna_menor=j;
 							fila_menor=i;
						}
 					}
 				}
 			}

 			distancias[a][b]=distancia_menor;
 		}
 	}
 	
 	printf("la matriz distancias es:\n");

 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			printf("%d ",distancias[i][j]);
 		}

 		printf("\n");
 	}

	return 0;
}