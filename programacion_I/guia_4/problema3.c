#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long mcm(long long n1, long long n2)
{
	long long max,min,mult;
	int i,j;

	if(n1<n2)
	{
		max=n2;
		min=n1;
	}

	else
	{
		max=n1;
		min=n2;
	}

	if(max%min==0)
	{
		return max;
	}

	j=0;
	mult=1;

	for(i=2;i<=sqrt(max);i++)
	{
		if(n1%i==0 || n2%i==0)
		{
			if(n1%i==0 && n1!=1)
			{
				n1=n1/i;
			}

			if(n2%i==0 && n2!=1)
			{
				n2=n2/i;
			}

			mult=mult*i;
			i--;
		}
	}

	mult=mult*n1*n2;

	return mult;
}

int main()
{
	long long num1,num2;

	printf("escriba dos numeros\n");
	scanf("%lld %lld",&num1,&num2);

	printf("el minimo comun multiplo entre los dos numeros es %lld\n",mcm(num1,num2));

	return 0;
}