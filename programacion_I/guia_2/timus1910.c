#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n,i,fuerza_mayor,centro;

	scanf("%d",&n);

	int secciones[n],fuerza_total[n-2];

	for(i=0;i<n;i++)
	{
		scanf("%d",&secciones[i]);
	}

	for(i=0;i<n-2;i++)
	{
		fuerza_total[i]=secciones[i]+secciones[i+1]+secciones[i+2];
	}

	fuerza_mayor=0;

	for(i=0;i<n-2;i++)
	{
		if(fuerza_total[i]>fuerza_mayor)
		{
			fuerza_mayor=fuerza_total[i];
			centro=i+2;
		}
	}

	printf("%d %d\n",fuerza_mayor,centro);	

	return 0;
}