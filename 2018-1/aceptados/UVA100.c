#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i,n,mayor;
	int j,k,contenedor,verificador;

	int contador[100000];

	while(scanf("%d %d",&j,&k)!=EOF)
	{	
		verificador=0;

		if(j>k)
		{
			contenedor=k;
			k=j;
			j=contenedor;
			verificador=1;
		}

		for(i=j;i<=k;i++)
		{	
			contador[i-j]=1;
			n=i;
			while(n!=1)
			{
				contador[i-j]++;
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

		mayor=0;

		for(i=0;i<=k-j;i++)
		{
			if(contador[i]>=contador[mayor])
			{	
				mayor=i;
			}
		}

		if(verificador==0)
		{
			printf("%d %d %d\n",j,k,contador[mayor]);
		}
		else
		{
			printf("%d %d %d\n",k,j,contador[mayor]);
		}

	}
		return 0;
}