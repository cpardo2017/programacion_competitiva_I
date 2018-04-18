#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n,i,c,num,a,b,aux;
	int orden[20];
	float numeros[20];

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		num=0;
		a=0;

		while((c=fgetc(stdin)!='\n'))
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

		for(b=0;b<=a;b++)
		{
			scanf("%f",&numeros[b]);
		}

		for(c=0;c<=a;c++)
		{
			printf("%f\n",numeros[orden[c]] );
		}


	}

	return 0;
}