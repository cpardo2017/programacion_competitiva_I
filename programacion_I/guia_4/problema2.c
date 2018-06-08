#include <stdlib.h>
#include <stdio.h>

double operacion(char op, double v1, double v2)
{
	if(op=='+')
	{
		return v1+v2;
	}

	if(op=='-')
	{
		return v1-v2;
	}

	if(op=='*')
	{
		return v1*v2;
	}

	if(op=='/')
	{
		return v1/v2;
	}
}

int main()
{
	double num1,num2;
	char simbolo;

	printf("escriba la operacion de dos numeros que desee realizar\n");

	scanf("%lf %c %lf",&num1,&simbolo,&num2);

	printf("el resultado es %g\n",operacion(simbolo,num1,num2));

	return 0;
}