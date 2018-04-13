#include <stdlib.h>
#include <stdio.h>

int main()
{	
	int n,i,j,contador;

	scanf("%d",&n);

	char nombre[50][n],apellido[50][n],nacionalidad[50][n];

	for(i=0;i<n;i++)
	{
		j=0;

		while((nacionalidad[j][i]=fgetc(stdin))!=' ')
		{
			j++;
		}

		j=0;

		while((nombre[j][i]=fgetc(stdin))!=' ')
		{
			j++;
		}

		j=0;

		while((apellido[j][i]=fgetc(stdin))!='\n')
		{
			j++;
		}
	}

	printf("%c\n",apellido[1][0]);




	return 0;
}