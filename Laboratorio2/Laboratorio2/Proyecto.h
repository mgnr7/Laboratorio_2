#pragma once
#include "Tipo_Proyecto.h"
#include "Tipo_Actividad.h"
#include "Cmpnte_Proyecto.h"
#include <string>

class Proyecto {
public:
	Proyecto();
	Proyecto(std::string nombre, Tipo_Proyecto* tp);
	~Proyecto();
	void setNombre(std::string nombre);
	std::string getNombre();
	void setTipoProyecto(Tipo_Proyecto* tp);
	Tipo_Proyecto* getTipoProyecto();


private:
	std::string nombre;
	Tipo_Proyecto* tipo;

	Cmpnte_Proyecto* raiz; 
	//Actividad_Grupo* raiz;

};

Proyecto::Proyecto() {
	tipo = nullptr;
}

Proyecto::Proyecto(std::string nombre, Tipo_Proyecto* tp) {
	this->setNombre(nombre);
	this->setTipoProyecto(tp);
}

Proyecto::~Proyecto() {
	delete raiz;
}


void Proyecto::setNombre(std::string nombre) {
	this->nombre = nombre;
}

std::string Proyecto::getNombre() {
	return nombre;
}

void Proyecto::setTipoProyecto(Tipo_Proyecto* tp) {
	this->tipo = tp;
}

Tipo_Proyecto* Proyecto::getTipoProyecto() {
	return this->tipo;
}