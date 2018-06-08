#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

void swap(int *a,int *b)
{
	int aux= *a;
	*a=*b;
	*b=aux;

	return;
}

void swapChar(char *a,char *b)
{
	int aux= *a;
	*a=*b;
	*b=aux;

	return;
}

int main()
{
	int torneos,i,c,j,num_equipos,num_partidos,goles1,goles2,a,b,victoria,derrota,empate,contenedor;
	char nombre_torneo[100],equipo1[30],equipo2[30],partido[1000],aux[100];
	char *token;


	scanf("%d",&torneos);

	for(i=0;i<torneos;i++)
	{
		scanf("%[^\n]",nombre_torneo);

		scanf("%d",&num_equipos);

		struct Equipo_del_torneo{

			char nombre[30];
			int puntos;
			int partidos_jugados;
			int partidos_ganados;
			int partidos_perdidos;
			int partidos_empatados;
			int diferencia_de_goles;
			int goles_marcados;
			int goles_contra;
		} equipo[num_equipos];

		for(j=0;j<num_equipos;j++)
		{
			equipo[j].partidos_ganados=0;
			equipo[j].partidos_empatados=0;
			equipo[j].partidos_perdidos=0;
			equipo[j].goles_marcados=0;
			equipo[j].goles_contra=0;
		}

		for(j=0;j<num_equipos;j++)
		{
			scanf("%s",equipo[j].nombre);
		}

		scanf("%d",&num_partidos);

		for(j=0;j<num_partidos;j++)
		{	
			goles1=0;
			goles2=0;

			scanf("%s",partido);
			token=strtok(partido,"#");
			strcpy(equipo1,token);
			token=strtok(NULL,"@");
			strcpy(aux,token);
			a=0;

			while(aux[a]!='\0')
			{	
				goles1=goles1*10+aux[a];
			}

			token=strtok(NULL,"#");
			strcpy(aux,token);
			a=0;

			while(aux[a]!='\0')
			{
				goles2=goles2*10+aux[a];
			}

			token=strtok(NULL,"#");
			strcpy(equipo2,token);


			victoria=0;
			derrota=0;
			empate=0;

			if(goles1>goles2)
			{
				victoria=1;
			}

			if(goles1<goles2)
			{
				derrota=1;
			}

			if(goles1==goles2)
			{
				empate=1;
			}

			for(a=0;a<num_equipos;a++)
			{
				if(strcmp(equipo[a].nombre,equipo1)==0)
				{
					break;
				}
			}

			for(b=0;b<num_equipos;b++)
			{
				if(strcmp(equipo[b].nombre,equipo2)==0)
				{
					break;
				}
			}


			equipo[a].goles_marcados+=goles1;
			equipo[a].goles_contra+=goles2;

			equipo[b].goles_marcados+=goles2;
			equipo[b].goles_contra+=goles1;

			if(victoria==1)
			{
				equipo[a].partidos_ganados++;
				equipo[b].partidos_perdidos++;
			}

			if(derrota==1)
			{
				equipo[a].partidos_perdidos++;
				equipo[b].partidos_ganados++;
			}

			if(empate==1)
			{
				equipo[a].partidos_empatados++;
				equipo[b].partidos_empatados++;
			}
		}

		for(j=0;j<num_equipos;j++)
		{
			equipo[j].puntos=equipo[j].partidos_ganados*3+equipo[j].partidos_empatados;
			equipo[j].diferencia_de_goles=equipo[j].goles_marcados-equipo[j].goles_contra;
			equipo[j].partidos_jugados=equipo[j].partidos_ganados+equipo[j].partidos_perdidos+equipo[j].partidos_empatados;
		}

		for(j=0;j<num_equipos-1;)
		{
			if(equipo[j].puntos<equipo[j+1].puntos)
			{
				swapChar(&equipo[j].nombre,&equipo[j+1].nombre);
				swap(&equipo[j].puntos,&equipo[j+1].puntos);
				swap(&equipo[j].partidos_ganados,&equipo[j+1].partidos_ganados);
				swap(&equipo[j].partidos_empatados,&equipo[j+1].partidos_empatados);
				swap(&equipo[j].partidos_perdidos,&equipo[j+1].partidos_perdidos);
				swap(&equipo[j].diferencia_de_goles,&equipo[j+1].diferencia_de_goles);
				swap(&equipo[j].goles_marcados,&equipo[j+1].goles_marcados);
				swap(&equipo[j].goles_contra,&equipo[j+1].goles_contra);
			}

			if(equipo[j].puntos==equipo[j+1].puntos)
			{
				if(equipo[j].partidos_ganados<equipo[j+1].partidos_ganados)
				{
					swapChar(&equipo[j].nombre,&equipo[j+1].nombre);
					swap(&equipo[j].puntos,&equipo[j+1].puntos);
					swap(&equipo[j].partidos_ganados,&equipo[j+1].partidos_ganados);
					swap(&equipo[j].partidos_empatados,&equipo[j+1].partidos_empatados);
					swap(&equipo[j].partidos_perdidos,&equipo[j+1].partidos_perdidos);
					swap(&equipo[j].diferencia_de_goles,&equipo[j+1].diferencia_de_goles);
					swap(&equipo[j].goles_marcados,&equipo[j+1].goles_marcados);
					swap(&equipo[j].goles_contra,&equipo[j+1].goles_contra);
				}

				if(equipo[j].partidos_ganados==equipo[j+1].partidos_ganados)
				{
					if(equipo[j].diferencia_de_goles<equipo[j+1].diferencia_de_goles)
					{
						swapChar(&equipo[j].nombre,&equipo[j+1].nombre);
						swap(&equipo[j].puntos,&equipo[j+1].puntos);
						swap(&equipo[j].partidos_ganados,&equipo[j+1].partidos_ganados);
						swap(&equipo[j].partidos_empatados,&equipo[j+1].partidos_empatados);
						swap(&equipo[j].partidos_perdidos,&equipo[j+1].partidos_perdidos);
						swap(&equipo[j].diferencia_de_goles,&equipo[j+1].diferencia_de_goles);
						swap(&equipo[j].goles_marcados,&equipo[j+1].goles_marcados);
						swap(&equipo[j].goles_contra,&equipo[j+1].goles_contra);
					}

					if(equipo[j].diferencia_de_goles==equipo[j+1].diferencia_de_goles)
					{
						if(equipo[j].goles_marcados<equipo[j+1].goles_marcados)
						{
							swapChar(&equipo[j].nombre,&equipo[j+1].nombre);
							swap(&equipo[j].puntos,&equipo[j+1].puntos);
							swap(&equipo[j].partidos_ganados,&equipo[j+1].partidos_ganados);
							swap(&equipo[j].partidos_empatados,&equipo[j+1].partidos_empatados);
							swap(&equipo[j].partidos_perdidos,&equipo[j+1].partidos_perdidos);
							swap(&equipo[j].diferencia_de_goles,&equipo[j+1].diferencia_de_goles);
							swap(&equipo[j].goles_marcados,&equipo[j+1].goles_marcados);
							swap(&equipo[j].goles_contra,&equipo[j+1].goles_contra);
						}

						if(equipo[j].goles_marcados==equipo[j+1].goles_marcados)
						{
							if(equipo[j].partidos_jugados>equipo[j+1].partidos_jugados)
							{
								swapChar(&equipo[j].nombre,&equipo[j+1].nombre);
								swap(&equipo[j].puntos,&equipo[j+1].puntos);
								swap(&equipo[j].partidos_ganados,&equipo[j+1].partidos_ganados);
								swap(&equipo[j].partidos_empatados,&equipo[j+1].partidos_empatados);
								swap(&equipo[j].partidos_perdidos,&equipo[j+1].partidos_perdidos);
								swap(&equipo[j].diferencia_de_goles,&equipo[j+1].diferencia_de_goles);
								swap(&equipo[j].goles_marcados,&equipo[j+1].goles_marcados);
								swap(&equipo[j].goles_contra,&equipo[j+1].goles_contra);
							}

							if(equipo[j].partidos_jugados==equipo[j+1].partidos_jugados)
							{
								if(strcmp(equipo[j].nombre,equipo[j+1].nombre)>0)
								{
									swapChar(&equipo[j].nombre,&equipo[j+1].nombre);
									swap(&equipo[j].puntos,&equipo[j+1].puntos);
									swap(&equipo[j].partidos_ganados,&equipo[j+1].partidos_ganados);
									swap(&equipo[j].partidos_empatados,&equipo[j+1].partidos_empatados);
									swap(&equipo[j].partidos_perdidos,&equipo[j+1].partidos_perdidos);
									swap(&equipo[j].diferencia_de_goles,&equipo[j+1].diferencia_de_goles);
									swap(&equipo[j].goles_marcados,&equipo[j+1].goles_marcados);
									swap(&equipo[j].goles_contra,&equipo[j+1].goles_contra);
								}
							}
						}
					}
				}
			}
		}

		printf("%s\n",nombre_torneo);

		for(j=0;j<num_equipos;j++)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",j+1,equipo[j].nombre,equipo[j].puntos,equipo[j].partidos_jugados,equipo[j].partidos_ganados,equipo[j].partidos_empatados,equipo[j].partidos_perdidos,equipo[j].diferencia_de_goles,equipo[j].goles_marcados,equipo[j].goles_contra );
		}
		printf("\n");

	}

	return 0;
}