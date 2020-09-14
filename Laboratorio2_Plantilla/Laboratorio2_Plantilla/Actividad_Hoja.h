#pragma once

#include "Cmpnte_Proyecto.h"

class Actividad_Hoja : public Cmpnte_Proyecto <Actividad_Hoja> 
{
public:
	Actividad_Hoja(string planInicio, string planFin, string realInicio, string realFin);
	~Actividad_Hoja();

};

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
}