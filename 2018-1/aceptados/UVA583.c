#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num,i,raiz,raiz_2,d,a;
	int negatividad=0;
	int verificador,verificador_2;
	
	for(;;)
	{
		scanf("%d",&num);

		if(num==0)
		{
			break;
		}

		printf("%d = ",num);

		if(num==1 || num==-1)
		{
			if(num==-1)
			{
				printf("%d x ",num);
				num=abs(num);
			}
			printf("%d\n",num);
		}


		if(num<0)
		{
			negatividad=1;
			num=abs(num);
			printf("-1 x ");
		}

		raiz=sqrt(num);

		for(i=2;i<=raiz;i++)
		{

			if(num%i==0)
			{
				num=num/i;
				printf("%d x ",i);
				i--;
				raiz=sqrt(num);
			}

		}

		printf("%d\n",num);
	}

	return 0;

}
