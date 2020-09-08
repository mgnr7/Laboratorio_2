#pragma once
#include <string>
#include <vector>
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

	vector <Actividad_Hoja> actividades;

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
}

inline void Actividad_Grupo::eliminar()
{
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

inline void Actividad_Grupo::setDescripcion(string d)
{
	descripcion = d;
}

inline string Actividad_Grupo::getDescripcion()
{
	return descripcion;
}
