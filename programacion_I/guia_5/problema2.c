#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int crearEnteroAleatorio(int limite)
{
	int numero;
	srand(time(NULL));
	numero=1+rand()%(limite);

	return numero;
}

void crearNombreAleatorio(char *nombre,int n)
{
	int limite_de_letras,i,letra;
	srand(time(NULL));
	limite_de_letras=1+rand()%(n);

	for(i=0;i<limite_de_letras;i++)
	{
		letra=rand()%(26);

		nombre[i]=(letra+'a');
	}

	nombre[0]=nombre[0]-32;
}

Fanatico* crearFanaticos(int numFanaticos)
{
	Fanatico* pt;
	int i;

	pt=(Fanatico*)malloc(numFanaticos*sizeof(Fanatico));

	for(i=0;i<numFanaticos;i++)
	{
		crearNombreAleatorio(pt[i].nombre,100);
		pt[i].edad=crearEnteroAleatorio(256);
		pt[i].agresividad=(double)crearEnteroAleatorio(1000);
	}

	return pt;
}

void liberarFanaticos(Fanatico *fans)
{
	free(fans);
}

Staff* crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc)
{
	Staff* pt;
	int asistentes=numDT+numPrepArq+numPrepFis+numAsis+numFisio+numDoc;
	int i,j;
	int roles[6];
	char clase[6][100];

	roles[0]=numDT;
	roles[1]=numPrepArq;
	roles[2]=numPrepFis;
	roles[3]=numAsis;
	roles[4]=numFisio;
	roles[5]=numDoc;

	clase[0]="DT";
	clase[1]="Preparador Arqueros";
	calse[2]="Preparador Fisico";
	clase[3]="Asistente";
	clase[4]="Fisioterapeuta";
	clase[5]="Doctor";

	pt=(Staff*)malloc(asistentes*sizeof(Staff));

	for(i=0;i<asistentes;i++)
	{
		crearNombreAleatorio(pt[i].nombre,100);
		pt[i].edad=crearEnteroAleatorio(256);
		pt[i].experiencia=crearEnteroAleatorio(256);
	}

	i=0;

	while(i<asistentes);
	{
		srand(time(NULL));
		j=rand()%(6);

		if(roles[j]>0)
		{
			strcpy(pt[i].rol,clase[j]);
			i++;
			roles[j]--;
		}
	}

	return pt;
}

void liberarStaff(Staff* staff)
{
	free(staff);
}

Jugador* crearJugadores(int numArq, int numDef, int numCelt, int numDel)
{
	Jugador* pt;
	int num_jugadores=numArq+numDef+numCelt+numDel;
	int i,j;

	roles[0]=numArq;
	roles[1]=numDef;
	roles[2]=numCelt;
	roles[3]=numDel;

	clase[0]="Arquero";
	clase[1]="Defensa";
	calse[2]="Centro";
	clase[3]="Delantero";

	pt=(Jugador*)malloc(num_jugadores*sizeof(Jugador));

	for(i=0;i<num_jugadores;i++)
	{
		crearNombreAleatorio(pt[i].nombre,100);
		pt[i].edad=crearEnteroAleatorio(256);
		pt[i].regate=(float)crearEnteroAleatorio(1000);
		pt[i].defensa=(float)crearEnteroAleatorio(1000);
		pt[i].reflejos=(float)crearEnteroAleatorio(1000);
		pt[i].velocidad=(float)crearEnteroAleatorio(1000);
		pt[i].dureza=(float)crearEnteroAleatorio(1000);
		pt[i].resistencia=(float)crearEnteroAleatorio(1000);
	}

	i=0;

	while(i<num_jugadores);
	{
		srand(time(NULL));
		j=rand()%(4);

		if(roles[j]>0)
		{
			strcpy(pt[i].posicion,clase[j]);
			i++;
			roles[j]--;
		}
	}

	return pt;
}

void liberarJugadores(Jugador* jugadores)
{
	free(jugadores);
}

Equipo* crearEquipos(int numEquipos)
{
	Equipo* pt;
	int i,j;

	pt=(Equipo*)malloc(numEquipos*sizeof(Equipo));

	for(i=0;i<numEquipos;i++)
	{
		crearNombreAleatorio(pt[i].nombre,100);
		pt[i].anyofundacion=crearEnteroAleatorio(2018);
		pt[i].numFanaticos=crearEnteroAleatorio(10);

		for(j=0;j<4;j++)
		{
			pt[i].numJugadores[j]=crearEnteroAleatorio(10);
		}

		for(j=0;j<6;j++)
		{
			pt[i].numStaff[j]=crearEnteroAleatorio(10);
		}

		pt[i].staff=crearStaff(pt[i].numStaff[0],pt[i].numStaff[1],pt[i].numStaff[2],pt[i].numStaff[3],pt[i].numStaff[4],pt[i].numStaff[5]);
		pt[i].jugadores=crearJugadore(pt[i].numJugadores[0],pt[i].numJugadores[1],pt[i].numJugadores[2],pt[i].numJugadores[3]);
		pt[i].fanaticos=crearFanaticos(pt[i].numFanaticos);
	}

	return pt;
}

void liberarEquipos(Equipo* equipos, int numEquipos)
{
	int i;

	for(i=0;i<numEquipos;i++)
	{
		liberarJugadores(equipos[i].jugadores);
		liberarStaff(equipos[i].staff);
		liberarFanaticos(equipos[i].fanaticos);
	}

	free(equipos);
}

int main()
{
	return 0;
}