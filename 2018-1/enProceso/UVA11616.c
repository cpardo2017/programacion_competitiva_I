#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char num_romano[1000000];
	int num_real,c,i,aux,j;

	for(;;)
	{
		aux=0;
		num_real=0;
		j=0;

		while((c=fgetc(stdin))!='\n')
		{
			if(c==EOF)
			{
				aux=2;
				break;
			}
	
			if(c>='0' && c<='9')
			{
				num_real=num_real*10+(c-'0');
				aux=1;
				continue;
			}

			/*else
			{
				aux=3;
			}*/

			num_romano[j]=c;
			j++;
		}

		/*if(aux=0)
		{
			printf("0\n");
			continue;
		}*/

		if(aux==2)
		{
			break;
		}

		if(aux==0)
		{
			num_real=0;

			for(i=0;i<j;i++)
			{
				if(num_romano[i]=='M')
				{
					num_real+=1000;
					continue;
				}

				if(num_romano[i]=='D')
				{
					num_real+=500;
					continue;
				}

				if(num_romano[i]=='C')
				{
					if(num_romano[i+1]=='M' && i+1<j)
					{
						num_real+=900;
						i++;
						continue;
					}

					if(num_romano[i+1]=='D' && i+1<j)
					{
						num_real+=400;
						i++;
						continue;
					}

					num_real+=100;
					continue;
				}

				if(num_romano[i]=='L')
				{
					num_real+=50;
					continue;
				}

				if(num_romano[i]=='X')
				{
					if(num_romano[i+1]=='C' && i+1<j)
					{
						num_real+=90;
						i++;
						continue;
					}

					if(num_romano[i+1]=='L' && i+1<j)
					{
						num_real+=40;
						i++;
						continue;
					}

					num_real+=10;
					continue;
				}

				if(num_romano[i]=='V')
				{
					num_real+=5;
					continue;
				}

				if(num_romano[i]=='I')
				{
					if(num_romano[i+1]=='X' && i+1<j)
					{
						num_real+=9;
						i++;
						continue;
					}

					if(num_romano[i+1]=='V' && i+1<j)
					{
						num_real+=4;
						i++;
						continue;
					}

					num_real++;
					continue;
				}
			}

			if(num_real!=0)
			{
				printf("%d\n",num_real);
			}

			else
			{
				printf("\n");
			}
			continue;
		}


		if(aux==1)
		{
			i=0;

			while(num_real>=1000)
			{
				num_romano[i]='M';
				i++;
				num_real-=1000;
			}

			while(num_real>=500)
			{
				if(num_real>=900)
				{
					num_romano[i]='C';
					num_romano[i+1]='M';
					i+=2;
					num_real-=900;
					continue;
				}

				num_romano[i]='D';
				i++;
				num_real-=500;
			}

			while(num_real>=100)
			{
				if(num_real>=400)
				{
					num_romano[i]='C';
					num_romano[i+1]='D';
					i+=2;
					num_real-=400;
					continue;
				}

				num_romano[i]='C';
				i++;
				num_real-=100;
			}

			while(num_real>=50)
			{
				if(num_real>=90)
				{
					num_romano[i]='X';
					num_romano[i+1]='C';
					i+=2;
					num_real-=90;
					continue;
				}

				num_romano[i]='L';
				i++;
				num_real-=50;
			}

			while(num_real>=10)
			{
				if(num_real>=40)
				{
					num_romano[i]='X';
					num_romano[i+1]='L';
					i+=2;
					num_real-=40;
					continue;
				}

				num_romano[i]='X';
				i++;
				num_real-=10;
			}

			while(num_real>=5)
			{
				if(num_real>=9)
				{
					num_romano[i]='I';
					num_romano[i+1]='X';
					i+=2;
					num_real-=9;
					continue;
				}

				num_romano[i]='V';
				i++;
				num_real-=5;
			}

			while(num_real>=1)
			{
				if(num_real>=4)
				{
					num_romano[i]='I';
					num_romano[i+1]='V';
					i+=2;
					num_real-=4;
					continue;
				}

				num_romano[i]='I';
				i++;
				num_real--;
			}

			num_romano[i]='\0';

			printf("%s\n",num_romano);
			continue;
		}

		printf("\n");
		return 0;
	}
}