#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "Cmpnte_Proyecto.h"
#include "Actividad_Hoja.h"


class Actividad_Grupo : public Cmpnte_Proyecto
{
public:
	Actividad_Grupo();
	~Actividad_Grupo();

	void setPadre(Actividad_Grupo* p) override;
	Actividad_Grupo* getPadre() override;

	void agregar(Cmpnte_Proyecto& actividad)

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;

	void setResponsable(string r) override;
	string getResponsable() override;
	void setResponsableAuto() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

	void setFechaRealInicio(string i) override;
	string getFechaRealInicio() override;

	void setFechaRealFin(string f) override;
	string getFechaRealFin() override;


	void eliminarSubActividad(string nombre);

	void calcularFechaRealInicio();
	void calcularFechaRealFin();

	void calcularFechaPlanInicio();
	void calcularFechaPlanFin();

private:
	
	string responsable;

	string nombre;
	//Por ahora estoy poniendo las fechas como strings
	//Se asume que el formato es YYYY-MM-DD
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;
	
	string descripcion;

	vector < Cmpnte_Proyecto > actividades;

};

Actividad_Grupo::Actividad_Grupo() 
{
	responsable = "";
	nombre = "";
	fecha_plan_ini = "";
	fecha_plan_fin = "";
	fecha_real_ini = "";
	fecha_real_fin = "";
	padre = NULL;
}

Actividad_Grupo::~Actividad_Grupo()
{
}

inline void Actividad_Grupo::setPadre(Actividad_Grupo* p)
{
	this->padre = p;
}

inline Actividad_Grupo* Actividad_Grupo::getPadre()
{
	return padre;
}

inline void Actividad_Grupo::agregar(Cmpnte_Proyecto& actividad)
{
	actividades.push_back(actividad);
}

inline void Actividad_Grupo::eliminar()
{
	if (padre != NULL)
	{
		padre->eliminarSubActividad(nombre);
	}
	~Actividad_Grupo();
}

inline void Actividad_Grupo::setNombre(string n)
{
	nombre = n;
}

inline string Actividad_Grupo::getNombre()
{
	return nombre;
}

inline void Actividad_Grupo::setResponsable(string r)
{
	responsable = r;
}

inline string Actividad_Grupo::getResponsable()
{
	return responsable;
}

inline void Actividad_Grupo::setResponsableAuto()
{
	if (padre != NULL)
	{
		if (!padre->getResponsable().empty())
		{
			responsable = padre->getResponsable();
		}
		else
		{
			padre->setResponsableAuto();
			responsable = padre->getResponsable();
		}
	}
}

inline void Actividad_Grupo::setDescripcion(string d)
{
	descripcion = d;
}

inline string Actividad_Grupo::getDescripcion()
{
	return descripcion;
}

inline void Actividad_Grupo::setFechaRealInicio(string i)
{
	fecha_real_ini = i;
}

inline string Actividad_Grupo::getFechaRealInicio()
{
	return fecha_real_ini;
}

inline void Actividad_Grupo::setFechaRealFin(string f)
{
	fecha_real_fin = f;
}

inline string Actividad_Grupo::getFechaRealFin()
{
	return fecha_real_fin;
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


/*Se asume que ya las actividades hijas tienen las fechas. 
La idea es llamar estos metodos desde el controlador en orden*/

inline void Actividad_Grupo::calcularFechaRealInicio()
{
	string fechaMenor = actividades.at(0).getFechaRealInicio();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = &actIterator->getFechaRealInicio();
		int yactual = atoi(fechaActual.substr(0, 4);
		int ymenor = atoi(fechaMenor.substr(0, 4);

		if ( yactual < ymenor)
		{
			fechaMenor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2);
			int mmenor = atoi(fechaMenor.substr(5,2));
			if (mactual < mmenor)
			{
				fechaMenor = fechaActual;
			}
			if (mactual == mmenor) 
			{
				int dactual = atoi(fechaActual.substr(8, 2);
				int dmenor = atoi(fechaMenor.substr(8, 2));
				if (dactual < dmenor) 
				{
					fechaMenor = fechaActual;
				}
			}
		}
	}

	fecha_real_ini = fechaMenor;
}

inline void Actividad_Grupo::calcularFechaRealFin()
{
	string fechaMayor = actividades.at(0).getFechaRealFin();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = &actIterator->getFechaRealFin();
		int yactual = atoi(fechaActual.substr(0, 4);
		int ymayor = atoi(fechaMayor.substr(0, 4);

		if (yactual > ymayor)
		{
			fechaMayor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2);
			int mmayor = atoi(fechaMayor.substr(5, 2));
			if (mactual > mmayor)
			{
				fechaMayor = fechaActual;
			}
			if (mactual == mayor)
			{
				int dactual = atoi(fechaActual.substr(8, 2);
				int dmayor = atoi(fechaMayor.substr(8, 2));
				if (dactual < dmayor)
				{
					fechaMayor = fechaActual;
				}
			}
		}
	}

	fecha_real_fin = fechaMayor;

}

inline void Actividad_Grupo::calcularFechaPlanInicio()
{
	string fechaMenor = actividades.at(0).getFechaInicio();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = &actIterator->getFechaInicio();
		int yactual = atoi(fechaActual.substr(0, 4);
		int ymenor = atoi(fechaMenor.substr(0, 4);

		if (yactual < ymenor)
		{
			fechaMenor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2);
			int mmenor = atoi(fechaMenor.substr(5, 2));
			if (mactual < mmenor)
			{
				fechaMenor = fechaActual;
			}
			if (mactual == mmenor)
			{
				int dactual = atoi(fechaActual.substr(8, 2);
				int dmenor = atoi(fechaMenor.substr(8, 2));
				if (dactual < dmenor)
				{
					fechaMenor = fechaActual;
				}
			}
		}
	}

	fecha_plan_ini = fechaMenor;
}

inline void Actividad_Grupo::calcularFechaPlanFin()
{
	string fechaMayor = actividades.at(0).getFechaFinal();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		string fechaActual = &actIterator->getFechaFinal();
		int yactual = atoi(fechaActual.substr(0, 4);
		int ymayor = atoi(fechaMayor.substr(0, 4);

		if (yactual > ymayor)
		{
			fechaMayor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2);
			int mmayor = atoi(fechaMayor.substr(5, 2));
			if (mactual > mmayor)
			{
				fechaMayor = fechaActual;
			}
			if (mactual == mayor)
			{
				int dactual = atoi(fechaActual.substr(8, 2);
				int dmayor = atoi(fechaMayor.substr(8, 2));
				if (dactual < dmayor)
				{
					fechaMayor = fechaActual;
				}
			}
		}
	}

	fecha_plan_fin = fechaMayor;
}
