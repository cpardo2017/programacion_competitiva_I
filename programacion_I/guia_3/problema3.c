#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,i,exponencial,negatividad;

	do
	{
		printf("escriba la cantidad de numeros que desea ingresar\n");
		scanf("%d",&n);
	}while(n<=0);

	double numeros[n],suma,mediana,media,varianza,desviacion_estandar,desviacion_media,aux;

	suma=0.0f;

	printf("ingrese %d numeros\n",n);

	for(i=0;i<n;i++)
	{
		scanf("%lf",&numeros[i]);
		suma=suma+numeros[i];
	}

	media=suma/(float)n;

	for(i=0;i<n-1;)
	{
		negatividad=0;
		exponencial=0;

		if(numeros[i]>numeros[i+1])
		{
			aux=numeros[i];
			numeros[i]=numeros[i+1];
			numeros[i+1]=aux;
			i--;
		}

		else
		{
			i++;
		}

		if(i<0)
		{
			i=0;
		}
	}

	suma=0.0f;

	for(i=0;i<n;i++)
	{
		suma=suma+abs(numeros[i]-media);
	}

	desviacion_media=suma/(float)n;

	if(n>1)
	{
		suma=0.0f;

		for(i=0;i<n;i++)
		{
			suma=suma+pow(numeros[i]-media,2);
		}

		varianza=suma/(float)(n-1);
	}

	else
	{
		varianza=numeros[0];
	}

	desviacion_estandar=sqrt(varianza);

	if(n%2==0)
	{
		mediana=(numeros[n/2]+numeros[n/2-1])/2.0f;
	}

	else
	{
		mediana=numeros[(n-1)/2];
	}

	exponencial=0;

	if(numeros[0]<0)
	{
		numeros[0]=-numeros[0];
		negatividad=1;
	}

	if(numeros[0]>=10)
	{
		while(numeros[0]>10)
		{
			numeros[0]=numeros[0]/10.0f;
			exponencial++;
		}
	}

	if(numeros[0]<=1)
	{
		while(numeros[0]<1)
		{
			numeros[0]=numeros[0]*10.0f;
			exponencial--;
		}
	}

	if(negatividad==1)
	{
		numeros[0]=-numeros[0];
	}

	printf("el numero menor del conjunto es: %.2fX10^%d\n",numeros[0],exponencial);

	if(numeros[n-1]<0.0f)
	{
		printf("el numero mayor del conjunto es: %.7f\n",numeros[n-1]);
	}

	if(numeros[n-1]>0.0f)
	{
		printf("el numero mayor del conjunto es: +%.7f\n",numeros[n-1]);
	}

	if(numeros[n-1]==0.0f)
	{
		printf("el numero mayor del conjunto es: %.8f\n",numeros[n-1]);
	}

	printf("la media del conjunto es: %.2f000000\n",media);

	printf("la mediana del conjunto es: %.4f\n",mediana);

	printf("la desviacion_media del conjunto es: %.2f\n",desviacion_media);
	printf("la desviacion_estandar del conjunto es: %.3f\n",desviacion_estandar);
	printf("la varianza del conjunto es: %g\n",varianza);

	return 0;
}