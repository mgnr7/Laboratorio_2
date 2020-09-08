#pragma once
#include "Tipo_Proyecto.h"
#include "Tipo_Actividad.h"

class Proyecto {
public:
	Proyecto();
	~Proyecto();
	void setTipoProyecto(Tipo_Proyecto);
	Tipo_Proyecto getTipoProyecto();
private:
	Tipo_Proyecto tipo;
};

Proyecto::Proyecto() {

}

Proyecto::~Proyecto() {

}

void Proyecto::setTipoProyecto(Tipo_Proyecto tp) {
	this->tipo = tp;
}

Tipo_Proyecto Proyecto::getTipoProyecto() {
	return this->tipo;
}