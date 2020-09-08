#pragma once
#include "Tipo_Actividad.h"
#include <vector>
//Aqui se la secuencia de estrcutura de cada proyecto (Ejemplo: Proyecto -> Fase -> Tarea)
class Tipo_Proyecto {

public:
	Tipo_Proyecto();
	~Tipo_Proyecto();

private:
	std::vector<Tipo_Actividad> secuenciaActividades;

};

