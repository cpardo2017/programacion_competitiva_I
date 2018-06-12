#include <stdio.h>
#include <stdlib.h>

int main()
{
	typedef struct 
	{
		char nombre[100];
		int edad;
		double agresividad;
	} Fanatico;

	Fanatico seguidores[1000];

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

	Jugador integrantes[100];

	typedef struct 
	{
		char nombre[100];
		int edad;
		char rol[100];
		int experiencia;
	} Staff;

	Staff asistentes[1000];

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

	Equipo paricipantes;

	paricipantes.staff=&asistentes[0];
	paricipantes.jugadores=&integrantes[0];
	paricipantes.fanatcos==&seguidores[0];

	return 0;
}