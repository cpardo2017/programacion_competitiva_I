#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int compare(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int n,j,i,c,aux;

	for(;;)
	{
		scanf("%d",&n);

		if(n==0)
		{
			break;
		}

		int edades[n];
		aux=0;

		for(j=0;j<n;j++)
		{
			scanf("%d",&edades[j]);
		}

		qsort(edades,n,sizeof(int),compare);

		for(j=0;j<n;j++)
		{
			printf("%d",edades[j]);
			if(j<n-1)
			{
				printf(" ");
			}
		}

		printf("\n");

	}

	return 0;
}