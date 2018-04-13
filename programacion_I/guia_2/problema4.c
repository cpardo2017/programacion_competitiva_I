#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num,i,j,raiz;
	int verificador=0;
	do
	{
		printf("ingrese un numero mayor que 1\n");
		scanf("%d",&num);
	}while(num<=1);	
	
	raiz=sqrt(num);

	for(i=2;i<=raiz;i++)
	{
		if(num%i==0 && num!=i)
		{
			verificador=1;
			break;
		}
	}

	if(verificador==0)
	{
		printf("primo\n");
	}

	else
	{
		printf("compuesto\n");
	}

	return 0;
}