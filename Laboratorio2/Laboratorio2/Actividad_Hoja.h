#pragma once
#include <string>
using namespace std;

class Actividad_Hoja
{
public:
	Actividad_Hoja();
	~Actividad_Hoja();

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