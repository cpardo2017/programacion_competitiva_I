#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,j,contador;
	char invitado[1000000];

	scanf("%d",&n);

	contador=2;

	for(i=0;i<n;i++)
	{
		scanf("%s",invitado);
		j=0;

		contador++;

		while(invitado[j]!='\0')
		{

			if(invitado[j]=='+')
			{
				contador++;
				break;
			}

			j++;
		}
	}

	if(contador==13)
	{
		contador++;
	}

	printf("%d\n",contador*100);

	return 0;
}