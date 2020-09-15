#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Cmpnte_Proyecto.h"
#include "Actividad_Hoja.h"

using namespace std;

class Actividad_Grupo : public Cmpnte_Proyecto<Actividad_Grupo> 
{
public:
	Actividad_Grupo();
	~Actividad_Grupo();

	void eliminarSubActividad(string nombre);

	void agregarHoja(Actividad_Hoja* actividad);
	void agregarGrupo(Actividad_Grupo* actividad);

	void calcularFechaRealInicioFin();
	void calcularFechaPlanInicioFin();

private:
	vector < Actividad_Grupo* > actividadesGrupo;
	vector < Actividad_Hoja* > actividadesHoja;
};

Actividad_Grupo::Actividad_Grupo()
{
}

Actividad_Grupo::~Actividad_Grupo()
{
}

void Actividad_Grupo::eliminarSubActividad(string nombre)
{
	bool eliminado = false;

	vector < Actividad_Grupo* >::iterator actIterator;
	for (actIterator = actividadesGrupo.begin(); actIterator != actividadesGrupo.end(); actIterator++)
	{
		if ((*actIterator)->getNombre().compare(nombre) == 0)
		{
			cout << "Eliminado: " << (*actIterator)->getNombre() << endl;
			actividadesGrupo.erase(actIterator);
			eliminado = true;
			break;
		}
	}

	if (!eliminado) 
	{
		vector < Actividad_Hoja* >::iterator actIterator;
		for (actIterator = actividadesHoja.begin(); actIterator != actividadesHoja.end(); actIterator++)
		{
			if ((*actIterator)->getNombre().compare(nombre) == 0)
			{
				cout << "Eliminado: " << (*actIterator)->getNombre() << endl;
				actividadesHoja.erase(actIterator);
				eliminado = true;
				break;
			}
		}
	}
}


void Actividad_Grupo::agregarHoja(Actividad_Hoja* actividad)
{
	actividad->setPadre(this);
	actividadesHoja.push_back(actividad);
}

void Actividad_Grupo::agregarGrupo(Actividad_Grupo* actividad)
{
	actividad->setPadre(this);
	actividadesGrupo.push_back(actividad);
}

void Actividad_Grupo::calcularFechaRealInicioFin()
{
	string fechaMenorG;
	string fechaMenorH;
	/*Primero se recorre el vector de ActividadesGrupo*/

	if (!actividadesGrupo.empty()) 
	{
		vector < Actividad_Grupo* >::iterator actIterator;

		string fechaMenor = (*actividadesGrupo.at(0)).getFechaRealInicio();

		for (actIterator = actividadesGrupo.begin() + 1; actIterator != actividadesGrupo.end(); actIterator++)
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

		fechaMenorG = fechaMenor;
	}

	

	/*Luego se recorre el vector de actividades Hoja*/
	if (!actividadesHoja.empty()) 
	{
		vector < Actividad_Hoja* >::iterator actIteratorH;

		string fechaMenor = (*actividadesHoja.at(0)).getFechaRealInicio();
		for (actIteratorH = actividadesHoja.begin() + 1; actIteratorH != actividadesHoja.end(); actIteratorH++)
		{
			string fechaActual = (*actIteratorH)->getFechaRealInicio();

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
		fechaMenorH = fechaMenor;
	}
	

	//Se asigna la fecha de inicio, de acuerdo a la fecha mas proxima entre todas las actividades hijas para iniciar la actividad.
	
	if (fechaMenorG.empty()) 
	{
		fecha_real_ini = fechaMenorH;
	}
	else 
	{
		if (fechaMenorH.empty()) 
		{
			fecha_real_ini = fechaMenorG;
		}
		else 
		{
			if (atoi(fechaMenorH.c_str()) < atoi(fechaMenorG.c_str()))
			{
				fecha_real_ini = fechaMenorH;
			}
			else 
			{
				fecha_real_ini = fechaMenorG;
			}
		}
	}

	string fechaMayorG;
	string fechaMayorH;

	if (!actividadesGrupo.empty()) 
	{
		vector < Actividad_Grupo* >::iterator actIterator;

		string fechaMayor = (*actividadesGrupo.at(0)).getFechaRealFin();
		for (actIterator = actividadesGrupo.begin() + 1; actIterator != actividadesGrupo.end(); actIterator++)
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

		fechaMayorG = fechaMayor;
	}

	/*Luego se recorre el vector de actividades Hoja*/
	if (!actividadesHoja.empty())
	{
		vector < Actividad_Hoja* >::iterator actIteratorH;
		string fechaMayor = (*actividadesHoja.at(0)).getFechaRealFin();

		for (actIteratorH = actividadesHoja.begin() + 1; actIteratorH != actividadesHoja.end(); actIteratorH++)
		{
			string fechaActual = (*actIteratorH)->getFechaRealFin();
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
		
		fechaMayorH = fechaMayor;

	}


	//Se asgina la fecha mas lejana de finalizacion de todas las actividades hijas como fecha de finalizacion de la actividad 
	if (fechaMayorG.empty())
	{
		fecha_real_fin = fechaMayorH;
	}
	else
	{
		if (fechaMayorH.empty())
		{
			fecha_real_fin = fechaMayorG;
		}
		else
		{
			if (atoi(fechaMayorH.c_str()) < atoi(fechaMayorG.c_str()))
			{
				fecha_real_fin = fechaMayorH;
			}
			else
			{
				fecha_real_fin = fechaMayorG;
			}
		}
	}
}

void Actividad_Grupo::calcularFechaPlanInicioFin()
{
	string fechaMenorG;
	string fechaMenorH;
	/*Primero se recorre el vector de ActividadesGrupo*/

	if (!actividadesGrupo.empty())
	{
		vector < Actividad_Grupo* >::iterator actIterator;

		string fechaMenor = (*actividadesGrupo.at(0)).getFechaInicio();

		for (actIterator = actividadesGrupo.begin() + 1; actIterator != actividadesGrupo.end(); actIterator++)
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

		fechaMenorG = fechaMenor;
	}



	/*Luego se recorre el vector de actividades Hoja*/
	if (!actividadesHoja.empty())
	{
		vector < Actividad_Hoja* >::iterator actIteratorH;

		string fechaMenor = (*actividadesHoja.at(0)).getFechaInicio();
		for (actIteratorH = actividadesHoja.begin() + 1; actIteratorH != actividadesHoja.end(); actIteratorH++)
		{
			string fechaActual = (*actIteratorH)->getFechaInicio();

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
		fechaMenorH = fechaMenor;
	}


	//Se asigna la fecha de inicio, de acuerdo a la fecha mas proxima entre todas las actividades hijas para iniciar la actividad.

	if (fechaMenorG.empty())
	{
		fecha_plan_ini = fechaMenorH;
	}
	else
	{
		if (fechaMenorH.empty())
		{
			fecha_plan_ini = fechaMenorG;
		}
		else
		{
			if (atoi(fechaMenorH.c_str()) < atoi(fechaMenorG.c_str()))
			{
				fecha_plan_ini = fechaMenorH;
			}
			else
			{
				fecha_plan_ini = fechaMenorG;
			}
		}
	}

	string fechaMayorG;
	string fechaMayorH;

	if (!actividadesGrupo.empty())
	{
		vector < Actividad_Grupo* >::iterator actIterator;

		string fechaMayor = (*actividadesGrupo.at(0)).getFechaFinal();
		for (actIterator = actividadesGrupo.begin() + 1; actIterator != actividadesGrupo.end(); actIterator++)
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
					if (dactual > dmayor)
					{
						fechaMayor = fechaActual;
					}
				}
			}
		}

		fechaMayorG = fechaMayor;
	}

	/*Luego se recorre el vector de actividades Hoja*/
	if (!actividadesHoja.empty())
	{
		vector < Actividad_Hoja* >::iterator actIteratorH;
		string fechaMayor = (*actividadesHoja.at(0)).getFechaFinal();

		for (actIteratorH = actividadesHoja.begin() + 1; actIteratorH != actividadesHoja.end(); actIteratorH++)
		{
			string fechaActual = (*actIteratorH)->getFechaFinal();
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

		fechaMayorH = fechaMayor;

	}


	//Se asgina la fecha mas lejana de finalizacion de todas las actividades hijas como fecha de finalizacion de la actividad 
	if (fechaMayorG.empty())
	{
		fecha_plan_fin = fechaMayorH;
	}
	else
	{
		if (fechaMayorH.empty())
		{
			fecha_plan_fin = fechaMayorG;
		}
		else
		{
			if (atoi(fechaMayorH.c_str()) < atoi(fechaMayorG.c_str()))
			{
				fecha_plan_fin = fechaMayorH;
			}
			else
			{
				fecha_plan_fin = fechaMayorG;
			}
		}
	}

}


