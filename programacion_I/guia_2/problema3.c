#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,promedio,contenedor,mediana,j;
	int suma=0;

	do
	{
		printf("por favor,escriba el numero de elementos que desea ingresar\n");
		scanf("%d",&n);
	}while(n<=0);

	int num[n];
	j=n/2;
	printf("escriba sus numeros\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}

	for(i=0;i<n-1;i++)
	{
		if(num[i]>num[i+1])
		{
			contenedor=num[i+1];
			num[i+1]=num[i];
			num[i]=contenedor;
			i=-1;
		}

	}

	for(i=0;i<n;i++)
	{
		suma=suma+num[i];
	}

	if(n%2==0)
	{
		mediana=num[j];
	}

	if(n%2==1)
	{
		mediana=(num[j]+num[j+1])/2;
	}

	promedio=suma/n;

	printf("el numero menor del conjunto es: %d\n",num[0]);
	printf("el numero mayor del conjunto es: %d\n",num[n-1]);
	printf("el promedio del conjunto es: %d\n",promedio);
	printf("la mediana del conjunto es: %d\n",mediana);

	return 0;
}
