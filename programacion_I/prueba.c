#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

double operacion(char op, double v1, double v2)
{
	if(op=='+')
	{
		return v1+v2;
	}

	if(op=='-')
	{
		return v1-v2;
	}

	if(op=='*')
	{
		return v1*v2;
	}

	if(op=='/')
	{
		return v1/v2;
	}
}

long long mcm(long long n1, long long n2)
{
	long long max,min,mult;
	int i,j;

	if(n1<n2)
	{
		max=n2;
		min=n1;
	}

	else
	{
		max=n1;
		min=n2;
	}

	if(max%min==0)
	{
		return max;
	}

	j=0;
	mult=1;

	for(i=2;i<=sqrt(max);i++)
	{
		if(n1%i==0 || n2%i==0)
		{
			if(n1%i==0 && n1!=1)
			{
				n1=n1/i;
			}

			if(n2%i==0 && n2!=1)
			{
				n2=n2/i;
			}

			mult=mult*i;
			i--;
		}
	}

	mult=mult*n1*n2;

	return mult;
}

long long mcd(long long n1, long long n2)
{
	long long mult=1;
	long long min,max;
	int i;

	if(n1<n2)
	{
		min=n1;
		max=n2;
	}

	else
	{
		min=n2;
		max=n1;
	}

	if(max%min==0)
	{
		return min;
	}

	for(i=2;i<=sqrt(min);i++)
	{
		if(n1%i==0 && n2%i==0)
		{
			n1=n1/i;
			n2=n2/i;

			mult=mult*i;
			i--;
		}
	}

	return mult;

}

int main()
{
	char opcion1[1000000],caracter;
	int opcion2,c,num1,num2,aux,negatividad,b,a;

	for(;;)
	{
		do
		{
			printf("eliga una de las siguientes opciones\noperacion\nmcm\nmcd\nsalir\n");
			scanf("%s",opcion1);

			if(strcmp(opcion1,"mcd")!=0 && strcmp(opcion1,"mcm")!=0 && strcmp(opcion1,"operacion")!=0 && strcmp(opcion1,"salir")!=0)
			{
				system("clear");
			}

		}while(strcmp(opcion1,"mcd")!=0 && strcmp(opcion1,"mcm")!=0 && strcmp(opcion1,"operacion")!=0 && strcmp(opcion1,"salir")!=0);

		if(strcmp(opcion1,"salir")==0)
		{
			break;
		}

		if(strcmp(opcion1,"operacion")==0)
		{
			do
			{

				aux=0;
				opcion2=0;

				printf(" 1: ingresar operacion\n 2: volver al menu principal\n");
				scanf("%d",&opcion2);

				if(opcion2!=1 && opcion2!=2)
				{
					aux=1;
				}

				if(opcion2==2)
				{
					system("clear");
					break;
				}

				if(opcion2==1)
				{

					negatividad=0;
					num1=0;
					num2=0;
					b=0;

					printf("ingrese la operacion deseada en una linea y separada por espacios\n");

					c=fgetc(stdin);
					assert(c=='\n');

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c=='-' && negatividad==0)
							{
								negatividad=1;
							}

							if(c=='-' && negatividad==1)
							{
								aux=1;
							}

							if(c>='0' && c<='9')
							{
								
								num1=num1*10+(c-'0');
							}

							else
							{
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							if(negatividad==1)
							{
								num1=-num1;
							}

							break;
						}
					}

					b=0;

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c=='+' || c=='-' || c=='*' || c=='/')
							{
								caracter=c;
							}

							else
							{	
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							break;
						}
					}

					negatividad=0;
					b=0;
					a=0;

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c=='-' && negatividad==0)
							{
								negatividad=1;
							}

							if(c=='-' && negatividad==1)
							{
								aux=1;
							}

							if(c>='0' && c<='9')
							{
								num2=num2*10+(c-'0');
							}

			 				else
							{
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							a=1;

							if(negatividad==1)
							{
								num2=-num2;
							}
							
							break;
						}
					}

					if(a==1)
					{
						while((c=fgetc(stdin))!='\n')
						{
							if(c!=' ')
							{
								aux=1;
							}
						}
					}

					if(aux!=0)
					{
						system("clear");
					}

				}

				if(aux==0)
				{
					printf(" el resultado es: %g\n\n",operacion(caracter,num1,num2));
				}

			}while(aux==1);

		}

		if(strcmp(opcion1,"mcm")==0)
		{
			do
			{	
				aux=0;
				opcion2=0;

				printf(" 1: ingresar numeros\n 2: volver al menu principal\n");
				scanf("%d",&opcion2);

				if(opcion2!=1 && opcion2!=2)
				{
					aux=1;
				}

				if(opcion2==2)
				{
					system("clear");
					break;
				}

				if(opcion2==1)
				{
					num1=0;
					num2=0;
					b=0;

					printf("ingrese los numeros positivos\n");

					c=fgetc(stdin);
					assert(c=='\n');

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c>='0' && c<='9')
							{
								
								num1=num1*10+(c-'0');
							}

							else
							{
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							break;
						}
					}

					b=0;
					a=0;

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c>='0' && c<='9')
							{
								num2=num2*10+(c-'0');
							}

			 				else
							{
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							a=1;
							break;
						}
					}

					if(a==1)
					{
						while((c=fgetc(stdin))!='\n')
						{
							if(c!=' ')
							{
								aux=1;
							}
						}
					}

					if(aux!=0)
					{
						system("clear");
					}

				}

				if(aux==0)
				{
					printf("%lld\n\n",mcm(num1,num2));
				}

			}while(aux==1);
		}

		if(strcmp(opcion1,"mcd")==0)
		{
			do
			{	
				aux=0;
				opcion2=0;

				printf(" 1: ingresar numeros\n 2: volver al menu principal\n");
				scanf("%d",&opcion2);

				if(opcion2!=1 && opcion2!=2)
				{
					aux=1;
				}

				if(opcion2==2)
				{
					system("clear");
					break;
				}

				if(opcion2==1)
				{
					num1=0;
					num2=0;
					b=0;

					printf("ingrese los numeros positivos\n");

					c=fgetc(stdin);
					assert(c=='\n');

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c>='0' && c<='9')
							{
								
								num1=num1*10+(c-'0');
							}

							else
							{
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							break;
						}
					}

					b=0;
					a=0;

					while((c=fgetc(stdin))!='\n')
					{
						if(c!=' ')
						{
							b=1;

							if(c>='0' && c<='9')
							{
								num2=num2*10+(c-'0');
							}

			 				else
							{
								aux=1;
							}
						}

						if(c==' ' && b==1)
						{
							a=1;
							break;
						}
					}

					if(a==1)
					{
						while((c=fgetc(stdin))!='\n')
						{
							if(c!=' ')
							{
								aux=1;
							}
						}
					}

					if(aux!=0)
					{
						system("clear");
					}
				}

				if(aux==0)
				{
					printf("%lld\n\n",mcm(num1,num2));
				}

			}while(aux==1);
		}
	}

	return 0;
}
