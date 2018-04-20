#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{	
	int cantidad,i,c,j,aux;
	int salario[3];

	/*int *salario;

	salario = (int*) malloc(sizeof(int)*3);*/


	scanf("%d",&cantidad);
	c=fgetc(stdin);
	assert(c=='\n');

	for(i=0;i<cantidad;i++)
	{
		j=0;
		salario[0] = 0;
		salario[1] = 0;
		salario[2] = 0;


		while((c=fgetc(stdin))!='\n')
		{

			if(c>='0' && c<='9')
			{
				salario[j]=salario[j]*10+(c-'0');

			}

			else
			{
				j++;

			}

			
		}

		for(j=0;j<2;)
		{
			if(salario[j]>salario[j+1])
			{
				aux=salario[j];
				salario[j]=salario[j+1];
				salario[j+1]=aux;
				j--;
			}

			else
			{
				j++;
			}

			if(j<0)
			{
				j=0;
			}
		}

		printf("Case %d: %d\n",i+1,salario[1]);

	}

	return 0;
}