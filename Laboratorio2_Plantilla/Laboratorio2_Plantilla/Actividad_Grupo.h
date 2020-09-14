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

	void calcularFechaRealInicioFin();
	void calcularFechaPlanInicioFin();
};

Actividad_Grupo::Actividad_Grupo()
{
}

Actividad_Grupo::~Actividad_Grupo()
{
}

inline void Actividad_Grupo::eliminarSubActividad(string nombre)
{
	vector < Cmpnte_Proyecto* >::iterator actIterator;
	for (actIterator = actividades.begin(); actIterator != actividades.end(); actIterator++)
	{
		if ((*actIterator)->getNombre().compare(nombre) == 0)
		{
			actividades.erase(actIterator);
			actIterator = actividades.end();
		}
	}
}

inline void Actividad_Grupo::calcularFechaRealInicioFin()
{
	vector < Cmpnte_Proyecto* >::iterator actIterator;

	string fechaMenor = (*actividades.at(0)).getFechaRealInicio();

	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = (*actIterator)->getFechaRealInicio();

		int yactual = atoi(fechaActual.substr(0, 4).c_str());
		int ymenor = atoi(fechaMenor.substr(0, 4).c_str());

		if (yactual < ymenor)
		{
			fechaMenor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2).c_str());
			int mmenor = atoi(fechaMenor.substr(5, 2).c_str());
			if (mactual < mmenor)
			{
				fechaMenor = fechaActual;
			}
			if (mactual == mmenor)
			{
				int dactual = atoi(fechaActual.substr(8, 2).c_str());
				int dmenor = atoi(fechaMenor.substr(8, 2).c_str());
				if (dactual < dmenor)
				{
					fechaMenor = fechaActual;
				}
			}
		}
	}
	//Se asigna la fecha de inicio, de acuerdo a la fecha mas proxima entre todas las actividades hijas para iniciar la actividad.
	fecha_real_ini = fechaMenor;


	string fechaMayor = (*actividades.at(0)).getFechaRealFin();
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = (*actIterator)->getFechaRealFin();
		int yactual = atoi(fechaActual.substr(0, 4).c_str());
		int ymayor = atoi(fechaMayor.substr(0, 4).c_str());

		if (yactual > ymayor)
		{
			fechaMayor = fechaActual;
		}
		if (yactual == ymayor)
		{
			int mactual = atoi(fechaActual.substr(5, 2).c_str());
			int mmayor = atoi(fechaMayor.substr(5, 2).c_str());
			if (mactual > mmayor)
			{
				fechaMayor = fechaActual;
			}
			if (mactual == mmayor)
			{
				int dactual = atoi(fechaActual.substr(8, 2).c_str());
				int dmayor = atoi(fechaMayor.substr(8, 2).c_str());
				if (dactual > dmayor)
				{
					fechaMayor = fechaActual;
				}
			}
		}
	}

	//Se asgina la fecha mas lejana de finalizacion de todas las actividades hijas como fecha de finalizacion de la actividad 
	fecha_real_fin = fechaMayor;
}

inline void Actividad_Grupo::calcularFechaPlanInicioFin()
{
	vector < Cmpnte_Proyecto* >::iterator actIterator;


	string fechaMenor = (*actividades.at(0)).getFechaInicio();

	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = (*actIterator)->getFechaInicio();
		int yactual = atoi(fechaActual.substr(0, 4).c_str());
		int ymenor = atoi(fechaMenor.substr(0, 4).c_str());

		if (yactual < ymenor)
		{
			fechaMenor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2).c_str());
			int mmenor = atoi(fechaMenor.substr(5, 2).c_str());
			if (mactual < mmenor)
			{
				fechaMenor = fechaActual;
			}
			if (mactual == mmenor)
			{
				int dactual = atoi(fechaActual.substr(8, 2).c_str());
				int dmenor = atoi(fechaMenor.substr(8, 2).c_str());
				if (dactual < dmenor)
				{
					fechaMenor = fechaActual;
				}
			}
		}
	}

	fecha_plan_ini = fechaMenor;


	string fechaMayor = (*actividades.at(0)).getFechaFinal();
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = (*actIterator)->getFechaFinal();
		int yactual = atoi(fechaActual.substr(0, 4).c_str());
		int ymayor = atoi(fechaMayor.substr(0, 4).c_str());

		if (yactual > ymayor)
		{
			fechaMayor = fechaActual;
		}
		if (yactual == ymayor)
		{
			int mactual = atoi(fechaActual.substr(5, 2).c_str());
			int mmayor = atoi(fechaMayor.substr(5, 2).c_str());
			if (mactual > mmayor)
			{
				fechaMayor = fechaActual;
			}
			if (mactual == mmayor)
			{
				int dactual = atoi(fechaActual.substr(8, 2).c_str());
				int dmayor = atoi(fechaMayor.substr(8, 2).c_str());
				if (dactual < dmayor)
				{
					fechaMayor = fechaActual;
				}
			}
		}
	}

	fecha_plan_fin = fechaMayor;

}


