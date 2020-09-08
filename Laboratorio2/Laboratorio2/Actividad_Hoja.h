#pragma once
#include <string>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Hoja : public Cmpnte_Proyecto
{
public:
	Actividad_Hoja();
	~Actividad_Hoja();

	void setPadre(Cmpnte_Proyecto* p);
	Cmpnte_Proyecto* getPadre();

	void agregar(Cmpnte_Proyecto* actividad) override;

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;
	 
	void setResponsable(string r) override;
	string getResponsable() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

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
}

Actividad_Hoja::~Actividad_Hoja()
{
}

inline void Actividad_Hoja::setPadre(Cmpnte_Proyecto* p)
{
	this->padre = p;
}

inline Cmpnte_Proyecto* Actividad_Hoja::getPadre()
{
	return padre;
}

inline void Actividad_Hoja::agregar(Cmpnte_Proyecto* actividad)
{
}

inline void Actividad_Hoja::eliminar()
{
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

inline void Actividad_Hoja::setDescripcion(string d)
{
	descripcion = d;
}

inline string Actividad_Hoja::getDescripcion()
{
	return descripcion;
}
