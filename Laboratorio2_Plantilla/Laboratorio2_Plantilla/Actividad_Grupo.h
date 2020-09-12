#pragma once

#include <vector>
#include <string>
#include "Cmpnte_Proyecto.h"

using namespace std;

class Actividad_Grupo : public Cmpnte_Proyecto<Actividad_Grupo> 
{
public:
	Actividad_Grupo();
	~Actividad_Grupo();

	void eliminarSubActividad(string nombre);
	void agregar(Cmpnte_Proyecto& actividad);



private:
	vector < Cmpnte_Proyecto > actividades;
};

Actividad_Grupo::Actividad_Grupo() 
{
}

Actividad_Grupo::~Actividad_Grupo() 
{
}

inline void Actividad_Grupo::eliminarSubActividad(string nombre)
{
	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin(); actIterator != actividades.end(); actIterator++)
	{
		if (&actIterator->getNombre() == nombre)
		{
			actividades.erase(actIterator);
			actIterator = actividades.end();
		}
	}
}

inline void Actividad_Grupo::agregar(Cmpnte_Proyecto& actividad)
{
	actividades.push_back(actividad);
}

