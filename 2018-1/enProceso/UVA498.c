#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long potencia(long long a,int b)
{
	int i,aux;

	if(b==0)
	{
		return 1;
	}

	if(b==1)
	{
		return a;
	}

	aux=a;

	for(i=0;i<b-1;i++)
	{
		a=a*aux;
	}

	return a;
}


int main()
{

	int a,b,num,c,negatividad,contador;
	int i=0;
	long long suma,factores[10000],equis[10000];
	int j=0;

	contador=0;

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
			suma=0;

			for(b=i-1;b>=0;b--)
			{
				suma=suma+factores[b]*potencia(equis[a],abs(i-b-1));
				/*printf("%lld*%lld!%d(%lld)",factores[b],equis[a],abs(i-b-1),potencia(equis[a],abs(i-b-1)));
				if(b!=0)
				{
					printf("+");
				}

				else
				{
					printf("=");
				}*/
			}

			printf("%lld",suma);

			if(a<j-1)
			{
				printf(" ");
			}

			/*if(a!=j-1)
			{
				printf(" ");
			}*/
		}

		printf("\n");
	}	


	return 0;
}