#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int verificador=0;
	long long raiz,i,num;

	scanf("%lld",&num);

	raiz=sqrt(num);

	for(i=2;i<=raiz;i++)
	{
		if(num%i==0)
		{
			verificador=1;
			break;
		}
	}

	if(verificador==0)
	{
		printf("el numero es primo\n");
	}

	else
	{
		printf("el numero no es primo\n");
	}

	return 0;
}