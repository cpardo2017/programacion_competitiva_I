#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int c,o,x,i,j,a,n,sobrevictoria,victoria,valor_de_victoria;
	int gato[3][3];
	int eje[3];
	scanf("%d",&n);

	for(a=0;a<n;a++)
	{

		o=0;
		victoria=0;
		valor_de_victoria=0;
		x=0;
		sobrevictoria=0;
		c=fgetc(stdin);
		assert(c=='\n');

		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				c=fgetc(stdin);
				gato[i][j]=c;

				if(gato[i][j]=='O')
				{
					o++;
				}

				if(gato[i][j]=='X')
				{
					x++;
				}
			}
			c=fgetc(stdin);
			assert(c=='\n');
		}

		if(o>x || x>o+1)
		{
			printf("no\n");
			continue;
		}

		for(i=0;i<3;i++)
		{
			if(gato[i][0]==gato[i][1] && gato[i][0]==gato[i][2] && gato[i][0]!='.')
			{
				if(victoria>0)
				{
					printf("no\n");
					sobrevictoria=1;
					break;
				}

				else
				{
					victoria++;
					valor_de_victoria=gato[i][0];
				}
			}
		}

		victoria=0;

		if(sobrevictoria==1)
		{
			continue;
		}

		for(i=0;i<3;i++)
		{
			if(gato[0][i]==gato[1][i] && gato[0][i]==gato[2][i] && gato[0][i]!='.')
			{
				if(victoria>0)
				{
					printf("no\n");
					sobrevictoria=1;
					break;
				}

				else
				{
					victoria++;
					valor_de_victoria=gato[0][i];
				}
			}
		}

		victoria=0;

		if(sobrevictoria==1)
		{
			continue;
		}


		if(gato[0][0]==gato[1][1] && gato[0][0]==gato[2][2] && gato[0][0]!='.')
		{
			if(victoria>0)
			{
				printf("no\n");
				sobrevictoria=1;
			}

			else
			{
				victoria++;
				valor_de_victoria=gato[0][0];
			}
		}

		victoria=0;

		if(sobrevictoria==1)
		{
			continue;
		}

		if(gato[0][2]==gato[1][1] && gato[0][2]==gato[2][0] && gato[0][2]!='.')
		{
			if(victoria>0)
			{
				printf("no\n");
				sobrevictoria=1;
			}

			else
			{
				victoria++;
				valor_de_victoria=gato[0][2];
			}
		}

		victoria=0;

		if(sobrevictoria==1)
		{
			continue;
		}

		if(valor_de_victoria=='O')
		{
			if(o!=x)
			{
				printf("no\n");
				continue;
			}
		}

		if(valor_de_victoria=='X')
		{
			if(x!=o+1)
			{
				printf("no\n");
				continue;
			}
		}

		printf("yes\n");

	}

	return 0;
}