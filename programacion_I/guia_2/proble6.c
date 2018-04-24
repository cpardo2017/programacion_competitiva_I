#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int nivel,i,j;

	do{

		printf("ingrese hasta que nivel de triangulo de pascal quiere ver\n");
		scanf("%d",&nivel);
	}while(nivel<=0);
	printf("\n");

	int vector[nivel+1];
	int copia[nivel+1];

	copia[0]=1;
	copia[1]=1;

	printf("1\n");
	printf("%d ",copia[0]);
	printf("%d\n",copia[1]);

	for(i=2;i<=nivel;i++)
	{
		vector[0]=1;
		for(j=1;j<i;j++)
		{
			vector[j]=copia[j]+copia[j-1];
		}

		vector[i]=1;

		for(j=0;j<=i;j++)
		{
			copia[j]=vector[j];
			printf("%d ",vector[j]);
		}

		printf("\n");
	}



	return 0;
}