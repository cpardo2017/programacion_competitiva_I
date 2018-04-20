#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	int n,i,c,num,a,b,aux;
	int orden[20];
	double numeros[20];

	scanf("%d",&n);
	c=fgetc(stdin);
	assert(c=='\n');


	for(i=0;i<n;i++)
	{
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

		for(b=0;b<a;b++)
		{
			aux=orden[b]-1;
			scanf("%lf",&numeros[aux]);
		}
		c=fgetc(stdin);
		assert(c=='\n');

		for(b=0;b<a;b++)
		{
			printf("%lf\n",numeros[b]);
		}

		printf("\n");

	}

	return 0;
}