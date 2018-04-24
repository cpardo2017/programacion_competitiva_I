#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,k,i,autos,sobrantes,resultado;
	scanf("%d %d",&k,&n);
	sobrantes=0;

	if(n<0)
	{
		n=0;
	}


	for(i=0;i<n;i++)
	{
		scanf("%d",&autos);
		sobrantes=sobrantes+autos-k;
		if(sobrantes<0)
		{
			sobrantes=0;
		}
	}

	printf("%d\n",sobrantes);

	return 0;
}