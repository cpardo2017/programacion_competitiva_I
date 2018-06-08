#include <stdlib.h>
#include <stdio.h>

int main()
{
	char string1[1000],string2[1000];
	int num1=0;
	int num2=0;
	int i=2;
	int negatividad;

	printf("ingrese una linea en el formato 2xN1 3xN2\n");

	scanf("%s",string1);
	scanf("%s",string2);

	negatividad=0;

	while(string1[i]!='\0')
	{
		if(string1[i]=='-')
		{
			negatividad=1;
			i++;
			continue;
		}

		num1=num1*10+(string1[i]-'0');
		i++;
	}

	if(negatividad==1)
	{
		num1=-num1;
	}

	i=2;

	negatividad=0;

	while(string2[i]!='\0')
	{
		if(string2[i]=='-')
		{
			negatividad=1;
			i++;
			continue;
		}

		num2=num2*10+(string2[i]-'0');
		i++;
	}

	if(negatividad==1)
	{
		num2=-num2;
	}

	printf("el numero menor es: ");

	if(num1<=num2)
	{
		printf("%d\n",num1);
	}

	else
	{
		printf("%d\n",num2);
	}

	return 0;
}