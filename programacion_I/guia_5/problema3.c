#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordenarFanaticos(Fanatico* arreglo,int numJugadores)
{
	int i,j;

	Fanatico* aux;

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

	Staff* aux;

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

	Jugadores* aux;

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

	Equipo* aux;

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

	for(i=0;i<4;i++)
	{
		num2[i]=0;

		for(j=0;j<4;j++)
		{
			num2[i]+=equipos[i].numJugadores[j];
		}
	}

	for(i=0;i<num_de_equipos,i++)
	{
		ordenarJugadores(equipos[i].jugadores,num2[i]);
		ordenarStaff(equipos[i].staff,num1[i]);
		ordenarFanaticos(equipos[i].fanatico,equipos[i].numFaticos);
	}
}

int main()
{
	return 0;
}