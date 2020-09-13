#pragma once
#include "Tipo_Proyecto.h"
#include <vector>
#include <string>
//Representa el controlador que gestiona los proyectos
class Controlador_Tipos_Proyecto {
public:
	void crearTipo(std::string nombre);
	void eliminarTipo();
	void modificarTipo();
	void consultarTipo();
	void modificarSecuencia();
	void menu(); //Aqui se despliega el menu de los metodos del controlador a la consola

private:
	std::vector<Tipo_Proyecto> tiposAlmacenados;
};

void Controlador_Tipos_Proyecto::crearTipo(std::string nombre) {
	
}

void Controlador_Tipos_Proyecto::eliminarTipo() {

}

void Controlador_Tipos_Proyecto::modificarTipo() {

}

void Controlador_Tipos_Proyecto::consultarTipo() {

}

void Controlador_Tipos_Proyecto::menu() {

}