#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int n,i;
	
	do
	{	
		printf("por favor,escriba un numero mayor que cero\n");
		scanf("%d",&n);
	}while(n<=0);
	int num[n];

	for(i=0;i<n;i++)
	{
		if(i==0 || i==1)
		{
			num[i]=1;
		}

		if(i>=2)
		{
			num[i]=num[i-1]+num[i-2];
		}
	}

	printf("la susecion de fibonacci es:\n");

	for(i=0;i<n;i++)
	{	
		printf("%d ",num[i]);
	}

	printf("\n");

	return 0;
}	