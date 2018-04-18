#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n,i,j,h;

	do
	{
		printf("ingrese un numero mayor o igual a 3\n");
		scanf("%d",&n);
	}while(n<3);

	int num[n];

	printf("ahora ingrese %d numeros\n",n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}

	printf("las posibles combinaciones de 3 numeros sin repeticion son:\n");

	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			for(h=j+1;h<n;h++)
			{
				printf("(%d,%d,%d)\n",num[i],num[j],num[h]);
			}
		}
	}


	return 0;	
}