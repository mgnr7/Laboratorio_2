#pragma once
#include "Tipo_Actividad.h"
#include <vector>
#include <string>
//Aqui se define la secuencia de estructura de cada proyecto (Ejemplo: Proyecto -> Fase -> Tarea)
class Tipo_Proyecto {

public:
	Tipo_Proyecto(std::string nombre);
	std::string getNombre();
	void setNombre(std::string nombre);

private:
	std::string nombre;
	std::vector<Tipo_Actividad> secuenciaActividades;
	
	//std::vector<std::string> estructura;
};

Tipo_Proyecto::Tipo_Proyecto(std::string nombre) {
	this->setNombre(nombre);
}

std::string Tipo_Proyecto::getNombre() {
	return nombre;
}

void Tipo_Proyecto::setNombre(std::string nombre) {
	this->nombre = nombre;
}

