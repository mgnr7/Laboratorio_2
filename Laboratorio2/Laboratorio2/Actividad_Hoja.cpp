#include "Actividad_Hoja.h"


//Una Actividad hoja siempre tiene que tener fechas para poder calcular la fecha real de las Actividades grupo.
Actividad_Hoja::Actividad_Hoja(string planInicio, string planFin, string realInicio, string realFin)
{
	responsable = "";
	nombre = "";
	fecha_plan_ini = planInicio;
	fecha_plan_fin = planFin;
	fecha_real_ini = realInicio;
	fecha_real_fin = realFin;
}

Actividad_Hoja::~Actividad_Hoja()
{
	delete this->padre;
}

void Actividad_Hoja::setPadre(Actividad_Grupo* p)
{
	this->padre = p;
}

Actividad_Grupo* Actividad_Hoja::getPadre()
{
	return padre;
}

void Actividad_Hoja::eliminar()
{
	if (padre != NULL)
	{
		padre->eliminarSubActividad(nombre);
	}
}

void Actividad_Hoja::setNombre(string n)
{
	nombre = n;
}

string Actividad_Hoja::getNombre()
{
	return nombre;
}

void Actividad_Hoja::setResponsable(string r)
{
	responsable = r;
}

string Actividad_Hoja::getResponsable()
{
	return responsable;
}

void Actividad_Hoja::setResponsableAuto()
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

void Actividad_Hoja::setDescripcion(string d)
{
	descripcion = d;
}

string Actividad_Hoja::getDescripcion()
{
	return descripcion;
}

void Actividad_Hoja::setFechaInicio(string f)
{
	fecha_plan_ini = f;
}

string Actividad_Hoja::getFechaInicio()
{
	return fecha_plan_ini;
}

void Actividad_Hoja::setFechaFinal(string f)
{
	fecha_plan_fin = f;
}

string Actividad_Hoja::getFechaFinal()
{
	return fecha_plan_fin;
}

void Actividad_Hoja::setFechaRealInicio(string i)
{
	fecha_real_ini = i;
}

string Actividad_Hoja::getFechaRealInicio()
{
	return fecha_real_ini;
}

void Actividad_Hoja::setFechaRealFin(string f)
{
	fecha_real_fin = f;
}

string Actividad_Hoja::getFechaRealFin()
{
	return fecha_real_fin;
}