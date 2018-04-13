#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{

	int factores[50],equis[50],a,b,num,c;
	int i=0;
	float suma;
	int j=0;
	int verificador=0;

	for(;;)
	{

		i=0;
		j=0;
		num=0;

		while((c=fgetc(stdin))!='\n')
		{


			if(c>='0' && c<='9')
			{
				num=num*10+(c-'0');
			}

			else
			{
				factores[i]=num;
				num=0;
				i++;
			}

		
		while((c=fgetc(stdin))!='\n')
		{

			if(c==EOF)
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
				num=0;
				j++;
			}
		}

		if(verificador==1)
		{
			break;
		}

		for(a=0;a<j;a++)
		{	
			suma=0.0f;

			for(b=0;b<i;b++)
			{
				suma=suma+factores[b]*pow(equis[a],b);
			}

			printf("%f",suma);
		}

		printf("\n");


	}	

	
	}

	return 0;
}