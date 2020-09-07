#pragma once
#include <string>
#include <vector>
using namespace std;

#include "Cmpnte_Proyecto.h"
#include "Actividad_Hoja.h"


class Actividad_Grupo 
{
public:
	Actividad_Grupo();
	~Actividad_Grupo();

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