#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n,i;

	do
	{
		printf("escriba un numero no negativo\n");
		scanf("%d",&n);
	}while(n<0);

	int potencias[n+1];

	for(i=0;i<=n;i++)
	{
		if(i==0) potencias[i]=1;
		else
		{
			potencias[i]=potencias[i-1]*2;
		}
	}

	printf("las potencias de 2 son:\n");

	for(i=0;i<=n;i++)
	{
		printf("%d ",potencias[i]);
	}

	printf("\n");

	return 0;
}