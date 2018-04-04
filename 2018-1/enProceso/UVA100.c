#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i,n,mayor,b;
	int j,k;

	int contador[100001];
	for(i=1;i<=100000;i++)
	{	
		contador[i]=1;
		n=i;
		while(n!=1)
		{
			contador[i]++;
			if(n%2==1)
			{	
				n=(3*n)+1;				
			}
			else
			{
				n=n/2;
			}
		}
	}

	while(scanf("%d %d",&j,&k)!=EOF)
	{	
		b=j;
		mayor=j;

		for(i=j;i<=k;i++)
		{
			if(contador[i]>=contador[mayor])
			{	
				mayor=i;
			}
		}

		printf("%d %d %d\n",b,k,contador[mayor]);

	}
		return 0;
}