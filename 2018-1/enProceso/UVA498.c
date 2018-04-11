#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{

	float factores[50],equis[50],a,b,suma,c;
	int i=0;
	float num=0.0f;
	int j=0;
	int verificador=0;

	for(;;)
	{

		while(scanf(c=fgetc(stelin))!='\n')
		{

			if(c>'0' && c<'9')
			{
				num=num*10+(c-'0');
			}

			else
			{
				factores[i]=num;
				num=0.0f;
				i++;
			}
		}

		while(scanf(c=fgetc(stelin))!='\n')
		{

			if(c=='EOF')
			{
				verificador=1;
				break;
			}

			if(c>'0' && c<'9')
			{
				num=num*10+(c-'0');
			}

			else
			{
				equis[j]=num;
				num=0.0f;
				j++;
			}
		}

		for(a=0.0f;a<j;a++)
		{	
			suma=0.0f;

			for(b=0.0f;b<i;b++)
			{
				suma=suma+factores[b]*pow(equis[a],b);
			}

			printf("%f",suma);
		}

		printf("\n");


	}	

	return 0;
}