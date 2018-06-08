#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long mcd(long long n1, long long n2)
{
	long long mult=1;
	long long min,max;
	int i;

	if(n1<n2)
	{
		min=n1;
		max=n2;
	}

	else
	{
		min=n2;
		max=n1;
	}

	if(max%min==0)
	{
		return min;
	}

	for(i=2;i<=sqrt(min);i++)
	{
		if(n1%i==0 && n2%i==0)
		{
			n1=n1/i;
			n2=n2/i;

			mult=mult*i;
			i--;
		}
	}

	return mult;

}


int main()
{
	long long num1,num2;

	printf("escriba dos numeros\n");
	scanf("%lld %lld",&num1,&num2);
	printf("el maximo comun divisor es %lld\n",mcd(num1,num2));

	return 0;
}