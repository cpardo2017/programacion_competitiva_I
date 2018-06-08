#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	int n,i,c,num,a,b,aux,d,j;
	int orden[1000000];
	char numeros[1000][1000];

	scanf("%d",&n);
	

	for(i=0;i<n;i++)
	{

		c=fgetc(stdin);
		assert(c=='\n');
		c=fgetc(stdin);
		assert(c=='\n');

		num=0;
		a=0;

		while((c=fgetc(stdin))!='\n')
		{
			if(c>='0' && c<='9')
			{
				num=num*10+(c-'0');
			}

			else
			{
				orden[a]=num;
				num=0;
				a++;
			}
		}

		orden[a]=num;
		num=0;
		a++;

		for(j=0;j<a;j++)
		{
			aux=orden[j]-1;
			scanf("%s",numeros[aux]);
		}

		for(j=0;j<a;j++)
		{
			printf("%s\n",numeros[j]);
		}
		if(i<n-1)
		{
			printf("\n");
		}
	}

	return 0;
}