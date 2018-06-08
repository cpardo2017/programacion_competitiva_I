#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	char pinguino_emperador[100]="Emperor Penguin";
	char pequeno_pinguino[100]="Little Penguin";
	char pinguino_maraconi[100]="Macaroni Penguin";
	char pinguino[100];
	int n,i,c;
	int Emperor=0;
	int pequeno=0;
	int Macaron=0;

	scanf("%d",&n);

	c=fgetc(stdin);
	assert(c=='\n');

	for(i=0;i<n;i++)
	{
		scanf("%[^\n]",pinguino);
		c=fgetc(stdin);
		assert(c=='\n');

		if(strcmp(pinguino,pinguino_emperador)==0)
		{
			Emperor++;
		}

		if(strcmp(pinguino,pinguino_maraconi)==0)
		{
			Macaron++;
		}

		if(strcmp(pinguino,pequeno_pinguino)==0)
		{
			pequeno++;
		}
	}

	if(Emperor>pequeno && Emperor>Macaron)
	{
		printf("%s\n",pinguino_emperador);
	}

	if(pequeno>Emperor && pequeno>Macaron)
	{
		printf("%s\n",pequeno_pinguino);
	}

	if(Macaron>Emperor && Macaron>pequeno)
	{
		printf("%s\n",pinguino_maraconi);
	}

	if(Emperor>pequeno &&Emperor==Macaron)
	{
		printf("%s\n",pinguino_emperador);
		printf("%s\n",pinguino_maraconi);
	}

	if(pequeno>Emperor && pequeno==Macaron)
	{
		printf("%s\n",pequeno_pinguino);
		printf("%s\n",pinguino_maraconi);
	}

	if(Emperor>Macaron && Emperor==pequeno)
	{
		printf("%s\n",pinguino_emperador);
		printf("%s\n",pequeno_pinguino);
	}

	if(Emperor==pequeno && Emperor==Macaron)
	{
		printf("%s\n",pinguino_emperador);
		printf("%s\n",pequeno_pinguino);
		printf("%s\n",pinguino_maraconi);
	}

	return 0;
}