#pragma once
#include <string>
using namespace std;

class Actividad_Grupo 
{
public:
	Actividad_Grupo();
	~Actividad_Grupo();

private:
	
	string responsable;
	//Por ahora estoy poniendo las fechas como strings
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;
	
	string descripcion;
};

Actividad_Grupo::Actividad_Grupo() 
{
}

Actividad_Grupo::~Actividad_Grupo()
{
}