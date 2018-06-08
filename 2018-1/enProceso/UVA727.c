#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(char *a,char *b)
{
	int aux= *a;
	*a=*b;
	*b=aux;
	return;
}

int main()
{
	int n,i,c,j,k,aux,a;
	char caracter[1000000];

	scanf("%d",&n);
	c=fgetc(stdin);
	assert(c=='\n');

	for(i=0;i<n;i++)
	{	
		j=0;
		aux=0;

		while(aux<2)
		{
			c=fgetc(stdin);
			if(c=='\n')
			{
				aux++;
			}

			else
			{
				caracter[j]=c;
				aux=0;
				j++;
			}

		}

		for(k=0;k<j;k++)
		{
			if(caracter[k]=='*' || caracter[k]=='/')
			{

				a=0;

				if(caracter[k+1]=='(')
				{
					aux=1;
					c=k+1;
				}

				else
				{
					c=k;
					aux=0;
					a=1;
					
				}
					while((aux>0 || (caracter[c+1]!='+' && caracter[c+1]!='-' && caracter[c+1]!=')' && caracter[c+1]!='*' && caracter[c+1]!='/')) && c!=j-1)
					{
						c++;

						if(caracter[c]=='(')
						{
							aux++;
						}

						if(caracter[c]==')')
						{
							aux--;
						}
					}

					for(aux=k;aux<c;aux++)
					{
						swap(&caracter[aux],&caracter[aux+1]);
						//printf("%s\n",caracter);
					}

					if(caracter[aux]=='*')
					{
						caracter[aux]='@';
					}

					if(caracter[aux]=='/')
					{
						caracter[aux]='#';
					}

					/*if(a==1)
					{
						k=c-1;
					}*/
			}
		}

		for(k=0;k<=j;k++)
		{
			if(caracter[k]=='+' || caracter[k]=='-')
			{
				a=0;

				if(caracter[k+1]=='(')
				{

					aux=1;
					c=k+1;
				}

				else
				{
					aux=0;
					c=k;
					a=1;
				}

					while((aux>0 || (caracter[c+1]!='+' &&  caracter[c+1]!='-'&& caracter[c+1]!=')')) && c!=j-1)
					{
						c++;

						if(caracter[c]=='(')
						{
							aux++;
						}

						if(caracter[c]==')')
						{
							aux--;
						}
					}

					for(aux=k;aux<c;aux++)
					{
						swap(&caracter[aux],&caracter[aux+1]);
						//printf("%s\n",caracter);
					}

					if(caracter[aux]=='+')
					{
						caracter[aux]='&';
					}

					if(caracter[aux]=='-')
					{
						caracter[aux]='%';
					}

				/*if(a==1)
				{
					k=c-1;
				}*/
			}
			
		}

		for(k=0;k<j;k++)
		{
			if(caracter[k]!='(' && caracter[k]!=')')
			{
				if(caracter[k]=='@')
				{
					caracter[k]='*';
				}

				if(caracter[k]=='#')
				{
					caracter[k]='/';
				}

				if(caracter[k]=='&')
				{
					caracter[k]='+';
				}

				if(caracter[k]=='%')
				{
					caracter[k]='-';
				}

				printf("%c",caracter[k]);

			}
		}
		printf("\n");
		printf("\n");

	}

	return 0;
}