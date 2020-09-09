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

	void setPadre(Cmpnte_Proyecto* p);
	Cmpnte_Proyecto* getPadre();

	void agregar(Cmpnte_Proyecto* actividad) override;

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;

	void setResponsable(string r) override;
	string getResponsable() override;
	void setResponsableAuto() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

	void eliminarSubActividad(string nombre);

private:
	
	string responsable;

	string nombre;
	//Por ahora estoy poniendo las fechas como strings
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;
	
	string descripcion;

	vector < Cmpnte_Proyecto > actividades;

};

Actividad_Grupo::Actividad_Grupo() 
{
}

Actividad_Grupo::~Actividad_Grupo()
{
}

inline void Actividad_Grupo::setPadre(Cmpnte_Proyecto* p)
{
	this->padre = p;
}

inline Cmpnte_Proyecto* Actividad_Grupo::getPadre()
{
	return padre;
}

inline void Actividad_Grupo::agregar(Cmpnte_Proyecto* actividad)
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

inline void Actividad_Grupo::eliminarSubActividad(string nombre)
{
	if (find(actividades.begin(), actividades.end(), nombre) != actividades.end()) 
	{
		actividades.erase(find(actividades.begin(), actividades.end(), nombre));
	}
}
