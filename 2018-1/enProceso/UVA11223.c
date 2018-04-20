#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main ()
{
	int T,i,c,d;
	unsigned int factor;
	unsigned int suma=0;

	scanf("%d",&T);
	c=fgetc(stdin);
	assert(c=='\n');
	
	for(i=0;i<T;i++)
	{
		d=0;
		printf("Message #%d\n",i+1);
		while((c=fgetc(stdin))!='\n')
		{	
			d++;
			if(c!=' ')
			{
				factor=(unsigned int)pow(2,d);

				if(c=='-')
				{
					factor=2*factor;
				}

				suma=suma+factor;
			}

			if(c==' ') 
			{
			     switch(suma)
			     { 
			     	case 0: printf(" ");
							break;
					case 10: printf("A");
							break;
					case 32: printf("B");
							break;
					case 40: printf("C");
							break;
					case 16: printf("D");
							break;
					case 2: printf("E");
							break;
					case 38: printf("F");
							break;
					case 20:printf("G");
							break;
					case 30: printf("H");
							break;
					case 6: printf("I");
							break;
					case 58: printf("J");
							break;
					case 24: printf("K");
							break;
					case 34: printf("L");
							break;
					case 12: printf("M");
							break;
					case 8: printf("N");
							break;
					case 28: printf("O");
							break;
					case 42: printf("P");
							break;
					case 52: printf("Q");
							break;
					case 18: printf("R");
							break;
					case 14: printf("S");
							break;
					case 4: printf("T");
							break;
					case 22: printf("U");
							break;
					case 46: printf("V");
							break;
					case 26: printf("W");
							break;
					case 48: printf("X");
							break;
					case 56: printf("Y");
							break;
					case 36: printf("Z");
							break;
					case 124: printf("0");
							break;
					case 122: printf("1");
							break;
					case 118: printf("2");
							break;
					case 110: printf("3");
							break;
					case 94: printf("4");
							break;
					case 62: printf("5");
							break;
					case 64: printf("6");
							break;
					case 68: printf("7");
							break;
					case 76: printf("8");
							break;
					case 92: printf("9");
							break;
					case 210: printf(".");
							break;
					case 228: printf(",");
							break;
					case 150: printf("?");
							break;
					case 186: printf("'");
							break;
					case 232: printf("!");
							break;
					case 80: printf("/");
							break;
					case 88: printf("\(");
							break;
					case 216: printf(")");
							break;
					case 66: printf("&");
							break;
					case 96: printf("=");
							break;
					case 168: printf(";");
							break;
					case 82: printf("+");
							break;
					case 192: printf("-");
							break;
					case 214: printf("_");
							break;
					case 162: printf("\"");
							break;
					case 170: printf("@");
							break;
					case 140: printf(":");
							break;
				}

				suma=0;
				d=0; 
			}

		}

		switch(suma)
			     { 
			     	case 0: printf(" ");
							break;
					case 10: printf("A");
							break;
					case 32: printf("B");
							break;
					case 40: printf("C");
							break;
					case 16: printf("D");
							break;
					case 2: printf("E");
							break;
					case 38: printf("F");
							break;
					case 20:printf("G");
							break;
					case 30: printf("H");
							break;
					case 6: printf("I");
							break;
					case 58: printf("J");
							break;
					case 24: printf("K");
							break;
					case 34: printf("L");
							break;
					case 12: printf("M");
							break;
					case 8: printf("N");
							break;
					case 28: printf("O");
							break;
					case 42: printf("P");
							break;
					case 52: printf("Q");
							break;
					case 18: printf("R");
							break;
					case 14: printf("S");
							break;
					case 4: printf("T");
							break;
					case 22: printf("U");
							break;
					case 46: printf("V");
							break;
					case 26: printf("W");
							break;
					case 48: printf("X");
							break;
					case 56: printf("Y");
							break;
					case 36: printf("Z");
							break;
					case 124: printf("0");
							break;
					case 122: printf("1");
							break;
					case 118: printf("2");
							break;
					case 110: printf("3");
							break;
					case 94: printf("4");
							break;
					case 62: printf("5");
							break;
					case 64: printf("6");
							break;
					case 68: printf("7");
							break;
					case 76: printf("8");
							break;
					case 92: printf("9");
							break;
					case 210: printf(".");
							break;
					case 228: printf(",");
							break;
					case 150: printf("?");
							break;
					case 186: printf("'");
							break;
					case 232: printf("!");
							break;
					case 80: printf("/");
							break;
					case 216: printf(")");
							break;
					case 66: printf("&");
							break;
					case 96: printf("=");
							break;
					case 168: printf(";");
							break;
					case 82: printf("+");
							break;
					case 192: printf("-");
							break;
					case 214: printf("_");
							break;
					case 162: printf("''");
							break;
					case 170: printf("@");
							break;
				}

				printf("\n");
				if(i!=T-1)
				{
					printf("\n");
				}
				suma=0;

	}	

	return 0;
}