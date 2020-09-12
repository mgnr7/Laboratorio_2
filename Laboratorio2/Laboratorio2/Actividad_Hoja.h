#pragma once
#include <string>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Hoja : public Cmpnte_Proyecto
{
public:
	Actividad_Hoja(string planInicio, string planFin, string realInicio, string realFin);
	~Actividad_Hoja();

	void setPadre(Actividad_Grupo* p) override;
	Actividad_Grupo* getPadre() override;

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;
	 
	void setResponsable(string r) override;
	string getResponsable() override;
	void setResponsableAuto() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

	void setFechaInicio(string f) override;
	string getFechaInicio() override;

	void setFechaFinal(string f) override;
	string getFechaFinal() override;

	void setFechaRealInicio(string i) override;
	string getFechaRealInicio() override;

	void setFechaRealFin(string f) override;
	string getFechaRealFin() override;

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

};

//Una Actividad hoja siempre tiene que tener fechas para poder calcular la fecha real de las Actividades grupo.
Actividad_Hoja::Actividad_Hoja(string planInicio, string planFin, string realInicio, string realFin)
{
	responsable = "";
	nombre = "";
	fecha_plan_ini = planInicio;
	fecha_plan_fin = planFin;
	fecha_real_ini = realInicio;
	fecha_real_fin = realFin;
	padre = NULL;
}

Actividad_Hoja::~Actividad_Hoja()
{
}

inline void Actividad_Hoja::setPadre(Actividad_Grupo* p)
{
	this->padre = p;
}

inline Actividad_Grupo* Actividad_Hoja::getPadre()
{
	return padre;
}

inline void Actividad_Hoja::eliminar()
{
	if (padre != NULL) 
	{
		padre->eliminarSubActividad(nombre);
	}

	~Actividad_Hoja();
}

inline void Actividad_Hoja::setNombre(string n)
{
	nombre = n;
}

inline string Actividad_Hoja::getNombre()
{
	return nombre;
}

inline void Actividad_Hoja::setResponsable(string r)
{
	responsable = r;
}

inline string Actividad_Hoja::getResponsable()
{
	return responsable;
}

inline void Actividad_Hoja::setResponsableAuto()
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

inline void Actividad_Hoja::setDescripcion(string d)
{
	descripcion = d;
}

inline string Actividad_Hoja::getDescripcion()
{
	return descripcion;
}

inline void Actividad_Hoja::setFechaInicio(string f)
{
	fecha_plan_ini = f;
}

inline string Actividad_Hoja::getFechaInicio()
{
	return fecha_plan_ini;
}

inline void Actividad_Hoja::setFechaFinal(string f)
{
	fecha_plan_fin = f;
}

inline string Actividad_Hoja::getFechaFinal()
{
	return fecha_plan_fin;
}

inline void Actividad_Hoja::setFechaRealInicio(string i)
{
	fecha_real_ini = i;
}

inline string Actividad_Hoja::getFechaRealInicio()
{
	return fecha_real_ini;
}

inline void Actividad_Hoja::setFechaRealFin(string f)
{
	fecha_real_fin = f;
}

inline string Actividad_Hoja::getFechaRealFin()
{
	return fecha_real_fin;
}
