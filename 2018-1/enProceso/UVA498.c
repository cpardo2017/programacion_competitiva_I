#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{

	int factores[50],equis[50],a,b,num,c,negatividad;
	int i=0;
	unsigned long long int suma;
	int j=0;

	for(;;)
	{

		i=0;
		j=0;
		num=0;
		negatividad=0;

		while((c=fgetc(stdin))!='\n')
		{

			if(c=='-')
			{
				negatividad=1;
			}

			if(c>='0' && c<='9')
			{
				num=num*10+(c-'0');
			}

			if((c<'0' || c>'9') && c!='-')
			{	
				if(negatividad==1)
				{
					num=-num;
				}

				factores[i]=num;
				num=0;
				i++;
				negatividad=0;
			}

		}

		if(negatividad==1)
		{
			num=-num;
		}

		factores[i]=num;
		num=0;
		i++;
		negatividad=0;

		
		while((c=fgetc(stdin))!='\n')
		{
			if(c=='-')
			{
				negatividad=1;
			}

			if(c>='0' && c<='9')
			{
				num=num*10+(c-'0');
			}

			if((c<'0' || c>'9') && c!='-')
			{
				if(negatividad==1)
				{
					num=-num;
				}

				equis[j]=num;
				num=0;
				j++;
				negatividad=0;
			}
		}

		if(negatividad==1)
		{
			num=-num;
		}

		equis[j]=num;
		num=0;
		j++;
		negatividad=0;




		for(a=0;a<j;a++)
		{	
			suma=0.0f;

			for(b=i-1;b>=0;b--)
			{
				suma=suma+factores[b]*(unsigned int)pow(equis[a],abs(i-b-1));
				printf("%d*%d!%d",factores[b],equis[a],abs(i-b-1));
				if(b!=0)
				{
					printf("+");
				}

				else
				{
					printf("=");
				}
			}

			printf("%lld\n",suma);

			/*if(a!=j-1)
			{
				printf(" ");
			}*/
		}

		printf("\n");


	}	


	return 0;
}