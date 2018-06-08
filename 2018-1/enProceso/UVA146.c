#include <stdio.h>
#include <stdlib.h>

int repetitividad(char a)
{
	int ascii;
	ascii=a;

	switch(ascii)
	{
		case 97: return 0;
		case 98: return 1;
		case 99: return 2;
		case 100: return 3;
		case 101: return 4;
		case 102: return 5;
		case 103: return 6;
		case 104: return 7;
		case 105: return 8;
		case 106: return 9;
		case 107: return 10;
		case 108: return 11;
		case 109: return 12;
		case 110: return 13;
		case 111: return 14;
		case 112: return 15;
		case 113: return 16;
		case 114: return 17;
		case 115: return 18;
		case 116: return 19;
		case 117: return 20;
		case 118: return 21;
		case 119: return 22;
		case 120: return 23;
		case 121: return 24;
		case 122: return 25;
	}
} 

int main()
{
	char codigo[50],letra;
	int cantidad[26],i,j,aux,cantidad2[26],flag;

	for(;;)
	{
		i=0;
		for(j=0;j<26;j++)
		{
			cantidad[j]=0;
			cantidad2[j]=0;
		}

		do
		{	
			scanf("%c",&codigo[i]);
			aux=repetitividad(codigo[i]);
			cantidad[aux]++;
			i++;
		}while(codigo[i-1]!='\n');
		i--;

		if(codigo[0]=='#')
		{
			break;
		}

		do
		{
			flag=0;
			codigo[i-1]++;
			if(codigo[i-1]>'z')
			{
				codigo[i-2]++;
				codigo[i-1]='a';
			}

			for(j=i-2;j>0;j--)
			{
				if(codigo[j]>'z')
				{
					codigo[j-1]++;
					codigo[j]='a';
				}
			}

			for(j=0;j<i;j++)
			{
				aux=repetitividad(codigo[j]);
				cantidad2[aux]++;
			}

			for(j=0;j<26;j++)
			{
				if(cantidad[j]!=cantidad2[j])
				{
					flag=1;
					break;
				}
			}
			
			for(j=0;j<i;j++)
			{
				printf("%c",codigo[j]);
			}
			printf("\n");
			

			if(flag==0)
			{
				break;
			}


		}while(flag==1 && codigo[0]<='z');

		if(codigo[0]>'z')
		{
			printf("No Successor\n");
		}

		else
		{
			for(j=0;j<i;j++)
			{
				printf("%c",codigo[j]);
			}
			printf("\n");
		}

		
	}

	return 0;
}