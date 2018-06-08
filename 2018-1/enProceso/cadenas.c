#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n,i,j;

	scanf("%d",&n);
	char cadena[n][128];

	for(i=0;i<n;i++)
	{
		scanf("%s",cadena[i]);
	}

	scanf("%d",&j);

	for(i=0;i<n;i++)
	{
		if(i==j-1)
		{
			printf("%s\n",cadena[i]);
			break;
		}
	}

	return 0;
}