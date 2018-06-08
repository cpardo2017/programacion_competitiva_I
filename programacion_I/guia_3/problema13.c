#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	char linea_de_texto1[100000],linea_de_texto2[100000],final[200000];
	int i,l,c;

	printf("ingrese dos lineas de texto\n");

	scanf("%[^\n]",linea_de_texto1);
	c=fgetc(stdin);
	assert(c=='\n');
	scanf("%[^\n]",linea_de_texto2);

	l=strlen(linea_de_texto1);

	i=0;

	while(l>=0)
	{
		if(linea_de_texto1[l]=='a' || linea_de_texto1[l]=='e' || linea_de_texto1[l]=='i' || linea_de_texto1[l]=='o' || linea_de_texto1[l]=='u')
		{
			final[i]=linea_de_texto1[l];
			i++;
		}

		if(linea_de_texto1[l]=='A' || linea_de_texto1[l]=='E' || linea_de_texto1[l]=='I' || linea_de_texto1[l]=='O' || linea_de_texto1[l]=='U')
		{
			final[i]=linea_de_texto1[l];
			i++;
		}

		l--;
	}

	l=strlen(linea_de_texto2);

	while(l>=0)
	{
		if(linea_de_texto2[l]=='a' || linea_de_texto2[l]=='e' || linea_de_texto2[l]=='i' || linea_de_texto2[l]=='o' || linea_de_texto2[l]=='u')
		{
			final[i]=linea_de_texto2[l];
			i++;
		}

		if(linea_de_texto2[l]=='A' || linea_de_texto2[l]=='E' || linea_de_texto2[l]=='I' || linea_de_texto2[l]=='O' || linea_de_texto2[l]=='U')
		{
			final[i]=linea_de_texto2[l];
			i++;
		}

		l--;
	}

	printf("las vocales invertidas y concatenadas son: %s\n",final);
	return 0;
}