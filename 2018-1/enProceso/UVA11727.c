#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int cantidad,i,c,j,aux;

	int *salario;

	salario = (int*) malloc(sizeof(int)*3);

	salario[0] = 0;
	salario[1] = 0;
	salario[2] = 0;



	scanf("%d",&cantidad);

	for(i=0;i<cantidad;i++)
	{
		j=0;

		while((c=fgetc(stdin)!='\n'))
		{
				printf("%d\n",c);

			if(c>='0' && c<='9')
			{
				salario[j]=salario[j]*10+(c-'0');
			}

			else
			{
				j++;
			}
		}

		for(j=0;j<3;)
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

	}

	return 0;
}