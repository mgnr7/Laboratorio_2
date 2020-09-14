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

void Actividad_Grupo::setPadre(Actividad_Grupo* p)
{
	this->padre = p;
}

Actividad_Grupo* Actividad_Grupo::getPadre()
{
	return padre;
}

void Actividad_Grupo::agregar(Cmpnte_Proyecto* actividad)
{
	actividades.push_back(actividad);
	actividad->setPadre(this);
}

void Actividad_Grupo::eliminar()
{
	if (padre != NULL)
	{
		padre->eliminarSubActividad(nombre);
	}
}

void Actividad_Grupo::setNombre(string n)
{
	nombre = n;
}

string Actividad_Grupo::getNombre()
{
	return nombre;
}

void Actividad_Grupo::setResponsable(string r)
{
	responsable = r;
}

string Actividad_Grupo::getResponsable()
{
	return responsable;
}

void Actividad_Grupo::setResponsableAuto()
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

void Actividad_Grupo::setDescripcion(string d)
{
	descripcion = d;
}

string Actividad_Grupo::getDescripcion()
{
	return descripcion;
}

void Actividad_Grupo::setFechaInicio(string f)
{
	fecha_plan_ini = f;
}

string Actividad_Grupo::getFechaInicio()
{
	return fecha_plan_ini;
}

void Actividad_Grupo::setFechaFinal(string f)
{
	fecha_plan_fin = f;
}

string Actividad_Grupo::getFechaFinal()
{
	return fecha_plan_fin;
}

void Actividad_Grupo::setFechaRealInicio(string i)
{
	fecha_real_ini = i;
}

string Actividad_Grupo::getFechaRealInicio()
{
	return fecha_real_ini;
}

void Actividad_Grupo::setFechaRealFin(string f)
{
	fecha_real_fin = f;
}

string Actividad_Grupo::getFechaRealFin()
{
	return fecha_real_fin;
}


void Actividad_Grupo::eliminarSubActividad(string nombre)
{
	vector < Cmpnte_Proyecto* >::iterator actIterator;
	for (actIterator = actividades.begin(); actIterator != actividades.end(); actIterator++)
	{
		if ((*actIterator)->getNombre().compare(nombre) == 0)
		{
			actividades.erase(actIterator);
			break;
		}
	}

}


/*Se asume que ya las actividades hijas tienen las fechas.
La idea es llamar estos metodos desde el controlador en orden*/

void Actividad_Grupo::calcularFechaRealInicioFin()
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

void Actividad_Grupo::calcularFechaPlanInicioFin()
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
