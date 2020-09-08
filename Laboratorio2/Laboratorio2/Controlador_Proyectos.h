#pragma once
#include "Proyecto.h"
#include "Tipo_Proyecto.h"
#include <vector>
//Representa 
class Controlador_Proyectos {
public:
	void crearProyecto(Tipo_Proyecto tp);
	void eliminarProyecto();
	void modificarProyecto();
	void consultarProyecto();
	void menu(); //Aqui se despliega el menu de los metodos del controlador

private:
	std::vector<Proyecto> proyectosAlmacenados;
};

void Controlador_Proyectos::crearProyecto(Tipo_Proyecto tp) {

}

void Controlador_Proyectos::eliminarProyecto() {

}

void Controlador_Proyectos::modificarProyecto() {

}

void Controlador_Proyectos::consultarProyecto() {

}

void menu() {

}