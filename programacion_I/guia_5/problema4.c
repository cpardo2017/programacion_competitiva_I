#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

const char nameTable[15][100]=
{
	"David",
	"Ivonne",
	"Leonardo",
	"Ignacio",
	"Denilson",
	"Diego",
	"Felipe",
	"Pablo",
	"Alegandro",
	"Javiera",
	"Milenko",
	"Joaquin",
	"Sergio",
	"Carlos",
	"Jorge"
};

typedef struct 
{
	char nombre[100];
	int edad;
	double agresividad;
} Fanatico;


typedef struct 
{
	char nombre[100];
	int edad;
	char posicion[100];
	float regate;
	float defensa;
	float reflejos;
	float velocidad;
	float dureza;
	float resistencia;
} Jugador;

typedef struct 
{
	char nombre[100];
	int edad;
	char rol[100];
	int experiencia;
} Staff;

typedef struct 
{
	char nombre[100];
	int anyoFundacion;
	Staff *staff;
	int numStaff[6];
	Jugador *jugadores;
	int numJugadores[4];
	Fanatico *fanaticos;
	int numFanaticos;
} Equipo;

int crearEnteroAleatorio(int inf,int sup)
{
	int numero;
	numero=inf + rand()%(sup+1-inf);

	return numero;
}

char* getName()
{
	char* dest;
	int r=rand()%15;
	dest= malloc(sizeof(char)*sizeof(nameTable[r]));

	strncpy(dest,nameTable[r],sizeof(nameTable[r]));

	return dest;
}

void liberarNombre(char* pt)
{
	free(pt);
}

/*void crearNombreAleatorio(char *nombre,int n)
{
	int limite_de_letras,i,letra;
	limite_de_letras=1+rand()%(n);

	for(i=0;i<limite_de_letras;i++)
	{
		letra=rand()%(26);

		nombre[i]=(letra+'a');
	}

	nombre[0]=nombre[0]-32;
}*/

Fanatico* crearFanaticos(int numFanaticos)
{
	Fanatico* pt;
	int i;
	char* aux;

	pt=(Fanatico*)malloc(numFanaticos*sizeof(Fanatico));

	for(i=0;i<numFanaticos;i++)
	{
		aux=getName();
		strcpy(pt[i].nombre,aux);	
		pt[i].edad=crearEnteroAleatorio(4,100);
		pt[i].agresividad=(double)crearEnteroAleatorio(0,500);
		liberarNombre(aux);
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
	char* aux;
	int roles[6];
	char clase[6][100];

	roles[0]=numDT;
	roles[1]=numPrepArq;
	roles[2]=numPrepFis;
	roles[3]=numAsis;
	roles[4]=numFisio;
	roles[5]=numDoc;

	strcpy(clase[0],"DT");
	strcpy(clase[1],"Preparador Arqueros");
	strcpy(clase[2],"Preparador Fisico");
	strcpy(clase[3],"Asistente");
	strcpy(clase[4],"Fisioterapeuta");
	strcpy(clase[5],"Doctor");

	pt=(Staff*)malloc(asistentes*sizeof(Staff));

	for(i=0;i<asistentes;i++)
	{
		aux=getName();
		strcpy(pt[i].nombre,aux);
		pt[i].edad=crearEnteroAleatorio(30,70);
		pt[i].experiencia=crearEnteroAleatorio(0,500);
		liberarNombre(aux);
	}

	i=0;

	//printf("%d\n",asistentes);

	while(i<asistentes)
	{
		//printf("%d %d %d %d %d %d\n",roles[0],roles[1],roles[2],roles[3],roles[4],roles[5]);
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
	char* aux;
	int roles[4];
	char clase[6][100];

	roles[0]=numArq;
	roles[1]=numDef;
	roles[2]=numCelt;
	roles[3]=numDel;

	strcpy(clase[0],"Arquero");
	strcpy(clase[1],"Defensa");
	strcpy(clase[2],"Centro");
	strcpy(clase[3],"Delantero");

	pt=(Jugador*)malloc(num_jugadores*sizeof(Jugador));

	for(i=0;i<num_jugadores;i++)
	{
		aux=getName();
		strcpy(pt[i].nombre,aux);
		pt[i].edad=crearEnteroAleatorio(18,30);
		pt[i].regate=(float)crearEnteroAleatorio(0,500);
		pt[i].defensa=(float)crearEnteroAleatorio(0,500);
		pt[i].reflejos=(float)crearEnteroAleatorio(0,500);
		pt[i].velocidad=(float)crearEnteroAleatorio(0,500);
		pt[i].dureza=(float)crearEnteroAleatorio(0,500);
		pt[i].resistencia=(float)crearEnteroAleatorio(0,500);
		liberarNombre(aux);
	}

	i=0;

	while(i<num_jugadores)
	{
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
	char* aux;

	pt=(Equipo*)malloc(numEquipos*sizeof(Equipo));

	for(i=0;i<numEquipos;i++)
	{
		aux=getName();
		strcpy(pt[i].nombre,aux);
		pt[i].anyoFundacion=crearEnteroAleatorio(1980,2018);
		pt[i].numFanaticos=crearEnteroAleatorio(0,100);
		liberarNombre(aux);

		for(j=0;j<4;j++)
		{
			pt[i].numJugadores[j]=crearEnteroAleatorio(10,20);
		}

		for(j=0;j<6;j++)
		{
			pt[i].numStaff[j]=crearEnteroAleatorio(5,10);
		}

		pt[i].staff=crearStaff(pt[i].numStaff[0],pt[i].numStaff[1],pt[i].numStaff[2],pt[i].numStaff[3],pt[i].numStaff[4],pt[i].numStaff[5]);
		pt[i].jugadores=crearJugadores(pt[i].numJugadores[0],pt[i].numJugadores[1],pt[i].numJugadores[2],pt[i].numJugadores[3]);
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

void ordenarFanaticos(Fanatico* arreglo,int numJugadores)
{
	int i,j;

	Fanatico aux;

	for(i=0;i<numJugadores-1;i++)
	{
		for(j=i+1;j<numJugadores;j++)
		{
			if(arreglo[i].agresividad>arreglo[i].agresividad)
			{
				aux=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=aux;
			}

			if(arreglo[i].agresividad==arreglo[i].agresividad)
			{
				if(strcmp(arreglo[i].nombre,arreglo[j].nombre)>0)
				{
					aux=arreglo[i];
					arreglo[i]=arreglo[j];
					arreglo[j]=aux;
				}
			}
		}
	}
}

void ordenarStaff(Staff* arreglo,int numStaff)
{
	int i,j;

	Staff aux;

	for(i=0;i<numStaff-1;i++)
	{
		for(j=i+1;j<numStaff;j++)
		{
			if(strcmp(arreglo[i].rol,arreglo[j].rol)>0)
			{
				aux=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=aux;
			}

			if(strcmp(arreglo[i].rol,arreglo[j].rol)==0)
			{
				if(strcmp(arreglo[i].nombre,arreglo[j].nombre)>0)
				{
					aux=arreglo[i];
					arreglo[i]=arreglo[j];
					arreglo[j]=aux;
				}
			}
		}
	}
}

void ordenarJugadores(Jugador* arreglo,int numJugadores)
{
	int i,j;

	Jugador aux;

	for(i=0;i<numJugadores-1;i++)
	{
		for(j=i+1;j<numJugadores;j++)
		{
			if(strcmp(arreglo[i].posicion,arreglo[j].posicion)>0)
			{
				aux=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=aux;
			}

			if(strcmp(arreglo[i].posicion,arreglo[j].posicion)==0)
			{
				if(strcmp(arreglo[i].nombre,arreglo[j].nombre)>0)
				{
					aux=arreglo[i];
					arreglo[i]=arreglo[j];
					arreglo[j]=aux;
				}
			}
		}
	}
}

void ordenarDB(Equipo* equipos,int num_de_equipos)
{
	int i,j;

	Equipo aux;

	for(i=0;i<num_de_equipos-1;i++)
	{
		for(j=i+1;j<num_de_equipos;j++)
		{
			if(strcmp(equipos[i].nombre,equipos[j].nombre)>0)
			{
				aux=equipos[i];
				equipos[i]=equipos[j];
				equipos[j]=aux;
			}
		}
	}

	int num1[num_de_equipos];

	for(i=0;i<num_de_equipos;i++)
	{
		num1[i]=0;

		for(j=0;j<6;j++)
		{
			num1[i]+=equipos[i].numStaff[j];
		}
	}

	int num2[num_de_equipos];

	for(i=0;i<num_de_equipos;i++)
	{
		num2[i]=0;

		for(j=0;j<4;j++)
		{
			num2[i]+=equipos[i].numJugadores[j];
		}
	}

	for(i=0;i<num_de_equipos;i++)
	{
		printf("%d\n",i);
		ordenarJugadores(equipos[i].jugadores,num2[i]);
		ordenarStaff(equipos[i].staff,num1[i]);
		ordenarFanaticos(equipos[i].fanaticos,equipos[i].numFanaticos);
	}
}

//============================================================================================================

void imprimiDB(Equipo* pt,int n)
{
	int i,j,k,num_jugadores,num_staff;

	num_jugadores=0;
	num_staff=0;

	for(i=0;i<6;i++)
	{
		num_staff+=pt->numStaff[i];
	}

	for(i=0;i<4;i++)
	{
		num_jugadores+=pt->numJugadores[i];
	}

	printf("los equipos son los siguientes:\n\n");

	for(i=0;i<n;i++)
	{
		printf("equipo %d\n",i+1);
		printf("nombre: %s\n",pt[i].nombre);
		printf("año de fundacion: %d\n",pt[i].anyoFundacion);
		printf("jugadores:\n\n");

		for(j=0;j<num_jugadores;j++)
		{
			printf("\njugador %d\n",j+1);
			printf("\nnombre: %s\n",pt[i].jugadores[j].nombre);
			printf("\nedad: %d\n",pt[i].jugadores[j].edad);
			printf("\nposicion: %s\n",pt[i].jugadores[j].posicion);
			printf("\nregate: %g\n",pt[i].jugadores[j].regate);
			printf("\ndefensa: %g\n",pt[i].jugadores[j].defensa);
			printf("\nreflejos: %g\n",pt[i].jugadores[j].reflejos);
			printf("\nvelocidad: %g\n",pt[i].jugadores[j].velocidad);
			printf("\ndureza: %g\n",pt[i].jugadores[j].dureza);
			printf("\nresistencia: %g\n",pt[i].jugadores[j].resistencia);
			printf("\n");
		}

		printf("staff:\n\n");

		for(j=0;j<num_staff;j++)
		{
			printf("\nstaff %d\n",j+1);
			printf("\nnombre: %s\n",pt[i].staff[j].nombre);
			printf("\nedad: %d\n",pt[i].staff[j].edad);
			printf("\nrol: %s\n",pt[i].staff[j].rol);
			printf("\nexperiencia: %d\n",pt[i].staff[j].experiencia);
		}

		printf("fanaticos\n");

		for(j=0;j<pt->numFanaticos;j++)
		{
			printf("\nfanatico %d\n",j+1);
			printf("\nnombre: %s\n",pt[i].fanaticos[j].nombre);
			printf("\nedad: %d\n",pt[i].fanaticos[j].edad);
			printf("\nagresividad: %g\n",pt[i].fanaticos[j].agresividad);
		}
	}
}

int main()
{

	srand(time(NULL));
	Equipo* equipos;

	equipos=crearEquipos(10);
	ordenarDB(equipos,10);
	imprimiDB(equipos,10);
	liberarEquipos(equipos,10);

	return 0;
}