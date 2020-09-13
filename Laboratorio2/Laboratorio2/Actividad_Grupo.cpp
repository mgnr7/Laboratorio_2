#include "Actividad_Grupo.h"

Actividad_Grupo::Actividad_Grupo()
{
	responsable = "";
	nombre = "";
	fecha_plan_ini = "";
	fecha_plan_fin = "";
	fecha_real_ini = "";
	fecha_real_fin = "";
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
	this->~Actividad_Grupo();
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
		if (actIterator->getNombre().compare(nombre) == 0)
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
	const char* fechaMenor = actividades.at(0).getFechaRealInicio().c_str();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		const char* fechaActual = actIterator->getFechaRealInicio().c_str();
		int yactual = atoi(fechaActual.substr(0, 4));
		int ymenor = atoi(fechaMenor.substr(0, 4));

		if (yactual < ymenor)
		{
			fechaMenor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2));
			int mmenor = atoi(fechaMenor.substr(5, 2));
			if (mactual < mmenor)
			{
				fechaMenor = fechaActual;
			}
			if (mactual == mmenor)
			{
				int dactual = atoi(fechaActual.substr(8, 2));
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
	const char* fechaMayor = actividades.at(0).getFechaRealFin().c_str();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		const char* fechaActual = actIterator->getFechaRealFin().c_str();
		int yactual = atoi(fechaActual.substr(0, 4));
		int ymayor = atoi(fechaMayor.substr(0, 4));

		if (yactual > ymayor)
		{
			fechaMayor = fechaActual;
		}
		if (yactual == ymayor)
		{
			int mactual = atoi(fechaActual.substr(5, 2));
			int mmayor = atoi(fechaMayor.substr(5, 2));
			if (mactual > mmayor)
			{
				fechaMayor = fechaActual;
			}
			if (mactual == mmayor)
			{
				int dactual = atoi(fechaActual.substr(8, 2));
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
	const char* fechaMenor = actividades.at(0).getFechaInicio().c_str();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		const char* fechaActual = actIterator->getFechaInicio().c_str();
		int yactual = atoi(fechaActual.substr(0, 4));
		int ymenor = atoi(fechaMenor.substr(0, 4));

		if (yactual < ymenor)
		{
			fechaMenor = fechaActual;
		}
		if (yactual == ymenor)
		{
			int mactual = atoi(fechaActual.substr(5, 2));
			int mmenor = atoi(fechaMenor.substr(5, 2));
			if (mactual < mmenor)
			{
				fechaMenor = fechaActual;
			}
			if (mactual == mmenor)
			{
				int dactual = atoi(fechaActual.substr(8, 2));
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
	const char* fechaMayor = actividades.at(0).getFechaFinal().c_str();

	vector < Cmpnte_Proyecto >::iterator actIterator;
	for (actIterator = actividades.begin() + 1; actIterator != actividades.end(); actIterator++)
	{
		const char* fechaActual = actIterator->getFechaFinal().c_str();
		int yactual = atoi(fechaActual.substr(0, 4));
		int ymayor = atoi(fechaMayor.substr(0, 4));

		if (yactual > ymayor)
		{
			fechaMayor = fechaActual;
		}
		if (yactual == ymayor)
		{
			int mactual = atoi(fechaActual.substr(5, 2));
			int mmayor = atoi(fechaMayor.substr(5, 2));
			if (mactual > mmayor)
			{
				fechaMayor = fechaActual;
			}
			if (mactual == mmayor)
			{
				int dactual = atoi(fechaActual.substr(8, 2));
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