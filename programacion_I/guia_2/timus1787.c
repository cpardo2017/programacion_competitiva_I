#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,k,i,autos,suma,resultado;
	scanf("%d %d",&k,&n);
	suma=0;

	for(i=0;i<n;i++)
	{
		scanf("%d",&autos);
		suma=suma+autos;

	}

	resultado=suma-n*k;
	if(resultado<0)
	{
		resultado=0;
	}
	printf("%d",resultado);

	return 0;
}