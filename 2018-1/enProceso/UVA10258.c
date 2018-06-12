
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tablilla
{
	int num_participante;
	int existencia;
	int problemas_resueltos;
	int tiempo;
	int tiempo_problema[9];
	int existencia_problema[9];
} estructura;

int main()
{
	int i,n,c,a,num,t,salir,j,b,aux,comprobador,problema;
	char estado,k;

	scanf("%d",&n);
	k=fgetc(stdin);
	n++;
	printf("error\n");

	for(i=0;i<n;i++)
	{	
		salir=0;
		a=0;

		estructura participante[1000000]={0,0,0,0,0,0};

		for(;;)
		{
			num=0;
			t=0;

			while((c=fgetc(stdin))!=' ')
			{
				if(c=='\n')
				{
					salir=1;
					break;
				}
				num=num*10+(c-'0');
			}

			if(salir==1)
			{
				struct tablilla Par[a];
				b=0;

				for(j=0;j<a;j++)
				{
					if(participante[j].existencia==1)
					{
						Par[b].num_participante=j+1;
						Par[b].problemas_resueltos=participante[j].problemas_resueltos;
						Par[b].tiempo=participante[j].tiempo;
						b++;
					}
				}

				for(j=0;j<b-1;)
				{
					comprobador=1;

					if(Par[j].problemas_resueltos<Par[j+1].problemas_resueltos)
					{
						aux=Par[j].problemas_resueltos;
						Par[j].problemas_resueltos=Par[j+1].problemas_resueltos;
						Par[j+1].problemas_resueltos=aux;

						aux=Par[j].tiempo;
						Par[j].tiempo=Par[j+1].tiempo;
						Par[j+1].tiempo=aux;

						aux=Par[j].num_participante;
						Par[j].num_participante=Par[j+1].num_participante;
						Par[j+1].num_participante=aux;

						j--;

						comprobador=0;
					}

					if(Par[j].problemas_resueltos==Par[j+1].problemas_resueltos)
					{
						if(Par[j].tiempo>Par[j+1].tiempo)
						{
							aux=Par[j].problemas_resueltos;
							Par[j].problemas_resueltos=Par[j+1].problemas_resueltos;
							Par[j+1].problemas_resueltos=aux;

							aux=Par[j].tiempo;
							Par[j].tiempo=Par[j+1].tiempo;
							Par[j+1].tiempo=aux;

							aux=Par[j].num_participante;
							Par[j].num_participante=Par[j+1].num_participante;
							Par[j+1].num_participante=aux;

							j--;

							comprobador=0;

						}
					}

					if(comprobador==1)
					{
						j++;
					}

					if(j<0)
					{
						j=0;
					}

				}

				for(j=0;j<b;j++)
				{
					printf("%d %d %d\n",Par[j].num_participante,Par[j].problemas_resueltos,Par[j].tiempo);
				}
				
				break;
			}

			if(participante[num-1].existencia!=1)
			{
				participante[num-1].existencia=1;
				a++;
			}

			problema=fgetc(stdin);

			scanf("%c",&k);

			while((c=fgetc(stdin))!=' ')
			{
				t=t*10+(c-'0');
			}

			scanf("%c",&estado);

			if(participante[num-1].existencia_problema[problema-1]==0)
			{

				if(estado=='C')
				{
					participante[num-1].tiempo=participante[num-1].tiempo+t+participante[num-1].tiempo_problema[problema-1];
					participante[num-1].problemas_resueltos++;
					participante[num-1].existencia_problema[problema-1]=1;
				}

				if(estado=='I')
				{
					participante[num-1].tiempo_problema[problema-1]=participante[num-1].tiempo_problema[problema-1]+20;
				}
			}

			k=fgetc(stdin);
			assert(k=='\n');

		}

		if(i!=0)
		{
			printf("\n");
		}

	}

	return 0;
}