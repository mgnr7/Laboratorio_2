#pragma once
#include "Tipo_Proyecto.h"
#include <vector>
#include <string>
//Representa el controlador que gestiona los tipos de proyectos
class Controlador_Tipos_Proyecto {
public:
	Controlador_Tipos_Proyecto();
	~Controlador_Tipos_Proyecto();
	void crearTipo(std::string nombre);
	void eliminarTipo(std::string nombre);
	void modificarTipo(std::string nombre);
	void agregarActividad(std::string nombreTipo, Tipo_Actividad* actividadNueva);//agrega una actividad a la secuencia
	void eliminarActividad(std::string nombreTipo, Tipo_Actividad* actividad);//elimina una activdad de la secuencia

	Tipo_Proyecto* consultarTipo(std::string nombre);


private:
	Tipo_Proyecto* buscarTipo(std::string nombre);
	std::vector<Tipo_Proyecto*> tiposAlmacenados;
};

Controlador_Tipos_Proyecto cntr_tipo; // variable global 

inline Controlador_Tipos_Proyecto::Controlador_Tipos_Proyecto()
{
}

inline Controlador_Tipos_Proyecto::~Controlador_Tipos_Proyecto()
{
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		delete* itr;
	}
	tiposAlmacenados.clear();
}

Tipo_Proyecto* Controlador_Tipos_Proyecto::buscarTipo(std::string nombre) {
	Tipo_Proyecto* tipo = nullptr;
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombre) {
			tipo = *itr;
			break;
		}
	}
	return proyecto;
}

void Controlador_Tipos_Proyecto::crearTipo(std::string nombre) {
	if (buscarTipo(nombre) == nullptr) {
		tiposAlmacenados.push_back(new Tipo_Proyecto(nombre));
	}
	else {
		std::cerr << "No se pueden repetir nombres de tipos de proyectos." << std::endl;
	}
}

void Controlador_Tipos_Proyecto::eliminarTipo(std::string nombre) {
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombre) {
			tiposAlmacenados.erase(itr);
			break;
		}
	}
	return proyecto;
}

void Controlador_Tipos_Proyecto::modificarTipo(std::string nombre) {
	Tipo_Proyecto* tipo = buscarTipo(nombre);

}

void Controlador_Tipos_Proyecto::consultarTipo(std::string nombre) {
	Tipo_Proyecto* tipo = buscarTipo(nombre);
	if (tipo == nullptr) {
		std::current_exception << "El tipo especificado no existe." << std::endl;
	}
	return tipo;
}
