#pragma once
#include <string>
using namespace std;

class Actividad_Hija
{
public:
	Actividad_Hija();
	~Actividad_Hija();

private:

	string responsable;
	//Por ahora estoy poniendo las fechas como strings
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;

	string descripcion;
};

Actividad_Hija::Actividad_Hija()
{
}

Actividad_Hija::~Actividad_Hija()
{
}