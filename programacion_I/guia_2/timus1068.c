#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N,i;
	int suma=0;

	scanf("%d",&N);

	if(N>=1)
	{
		for(i=1;i<=N;i++)
		{
			suma=suma+i;
		}
	}

	else
	{
		for(i=1;i>=N;i--)
		{
			suma=suma+i;
		}
	}

	printf("%d\n",suma);

	return 0;
}