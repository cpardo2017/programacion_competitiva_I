#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

char eliminar(int a,int n, char str[n+2])
{
	int i,j;
	char eliminado[n];

	i=0;
	j=0;

	while(str[i]!='\0')
	{
		if(i!=a && i!=a+1)
		{
			eliminado[j]=str[i];
			j++;
		}

		i++;
	}

	eliminado[i]='\0';

	return eliminado;
}

int main()
{
	int n,i,j,k,c,verdadero,longitud,aux;
	char cadena[128];

	scanf("%d",&n);
	c=fgetc(stdin);
	assert(c=='\n');

	for(i=0;i<n;i++)
	{	
		scanf("%s",cadena);

		longitud=strlen(cadena);

		if(longitud%2==1)
		{
			printf("No\n");
			continue;
		}

		/*k=0;

		do
		{
			c=fgetc(stdin);
			cadena[k]=c;
			k++;
		}while(cadena[k-1]=='\n');*/

		j=0;

		verdadero=1;
		aux=longitud;

		while(aux>2)
		{
			if((cadena[j]=='(' && cadena[j+1]==')') || (cadena[j]=='[' && cadena[j+1]==']'))
			{
				strcpy(cadena,eliminar(j,aux-2,cadena));
				j--;
				aux=aux-2;
				continue;
			}

			if(cadena[j]=='(' && cadena[j+1]==']')
			{
				verdadero=0;
				break;
			}

			if(cadena[j]=='[' && cadena[j+1]==')')
			{
				verdadero=0;
				break;
			}

			j++;

			if(j>longitud)
			{
				j=0;
			}
		}

		if((cadena[0]=='(' && cadena[1]==')') || (cadena[0]=='[' && cadena[1]==']'))
		{
			verdadero=1;
		}

		else
		{
			verdadero=0;
		}

		if(verdadero==1)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}
	
	}

	return 0;
}