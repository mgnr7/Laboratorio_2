#pragma once
#include "Controlador.h"
#include "Proyecto.h"
#include <vector>
//Representa el controlador que gestiona los proyectos
class Controlador_Proyectos {
public:
	Controlador_Proyectos();
	~Controlador_Proyectos();
	void crearProyecto(std::string nombre, Tipo_Proyecto* tp);
	void eliminarProyecto();
	void modificarProyecto();
	void consultarProyecto();
	void agregarComponente(); //
	void eliminarComponente(); //
	void menu(); //Aqui se despliega el menu de los metodos del controlador a la consola

private:
	std::vector<Proyecto*> proyectosAlmacenados;
};


Controlador_Proyectos::Controlador_Proyectos() {
}

Controlador_Proyectos::~Controlador_Proyectos() {
	for (int i = 0; i < (int) proyectosAlmacenados.size(); i++) {
		delete proyectosAlmacenados[i];
	}
	proyectosAlmacenados.clear();
}

void Controlador_Proyectos::crearProyecto(std::string nombre,  Tipo_Proyecto* tp) {
	proyectosAlmacenados.push_back(new Proyecto(nombre,tp)); // se crea y se almacena un nuevo proyecto con el tipo y nombre especificados
}

void Controlador_Proyectos::eliminarProyecto() {

}

void Controlador_Proyectos::modificarProyecto() {

}

void Controlador_Proyectos::consultarProyecto() {

}

void Controlador_Proyectos::menu() {

}