#pragma once
#include <string>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Hoja : public Cmpnte_Proyecto
{
public:
	Actividad_Hoja();
	~Actividad_Hoja();

	void setPadre(Actividad_Grupo* p);
	Actividad_Grupo* getPadre();

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

private:

	string responsable;

	string nombre;
	//Por ahora estoy poniendo las fechas como strings
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;

	string descripcion;

};

Actividad_Hoja::Actividad_Hoja()
{
	responsable = "";
	nombre = "";
	fecha_plan_ini = "";
	fecha_plan_fin = "";
	fecha_real_ini = "";
	fecha_real_fin = "";
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
