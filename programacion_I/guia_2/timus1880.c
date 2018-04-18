#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c,i,j,menor,utilizable;
	int comun=0;

	scanf("%d",&a);

	int concursante1[a];

	for(i=0;i<a;i++)
	{
		scanf("%d",&concursante1[i]);
	}

	scanf("%d",&b);

	int concursante2[b];

	for(i=0;i<b;i++)
	{
		scanf("%d",&concursante2[i]);
	}

	scanf("%d",&c);

	int concursante3[c];

	for(i=0;i<c;i++)
	{
		scanf("%d",&concursante3[i]);
	}


	if(a<b)
	{
		menor=a;
	}

	else
	{
		menor=b;
	}

	int comparante[menor];
	utilizable=0;

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(concursante1[i]==concursante2[j])
			{
				comparante[utilizable]=concursante1[i];
				utilizable++;
			}
		}
	}

	for(i=0;i<utilizable;i++)
	{
		for(j=0;j<c;j++)
		{
			if(comparante[i]==concursante3[j])
			{
				comun++;
			}
		}
	}

	printf("%d\n",comun);

	return 0;
}