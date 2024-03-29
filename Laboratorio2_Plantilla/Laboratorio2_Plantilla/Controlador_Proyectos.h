#pragma once
#include "Proyecto.h"
#include "Tipo_Proyecto.h"
#include "Actividad_Grupo.h"
#include "Actividad_Hoja.h"
#include "Tipo_Proyecto.h"
#include<iostream>
#include <vector>
#include <algorithm>
//Representa el controlador que gestiona los proyectos
class Controlador_Proyectos {
public:
	Controlador_Proyectos();
	~Controlador_Proyectos();
	void crearProyecto(std::string nombre, Tipo_Proyecto* tp);
	void eliminarProyecto(std::string nombre);
	void modificarProyecto(std::string nombre); //CEMC de actividades
	Proyecto* consultarProyecto(std::string nombre);
	void agregarComponente(std::string nombreProyecto, Actividad_Grupo* componenentePadre, Cmpnte_Proyecto* componenteHijo); 
	void eliminarComponente(std::string nombreProyecto, Cmpnte_Proyecto* componentePorBorrar); 
	void getResponsable(std::string nombreProyecto, Cmpnte_Proyecto* componente);

private:
	Proyecto* buscarProyecto(std::string nombre);
	std::vector<Proyecto*> proyectosAlmacenados;
};
Controlador_Proyectos cntr_proy; //variable global


Controlador_Proyectos::Controlador_Proyectos() {
}

Controlador_Proyectos::~Controlador_Proyectos() {
	for (auto itr = proyectosAlmacenados.begin(); itr != proyectosAlmacenados.end(); itr++) {
		delete *itr;
	}
	proyectosAlmacenados.clear();
}

Proyecto* Controlador_Proyectos::buscarProyecto(std::string nombre) {
	Proyecto* proyecto = nullptr;
	for (auto itr = proyectosAlmacenados.begin(); itr != proyectosAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombre) {
			proyecto = *itr;
			break;
		}
	}
	return proyecto;
}

void Controlador_Proyectos::crearProyecto(std::string nombre,  Tipo_Proyecto* tp) {
	
	if (buscarProyecto(nombre) == nullptr) {//Agregar el proyecto solo si no existe otro con el mismo nombre
		proyectosAlmacenados.push_back(new Proyecto(nombre, tp)); // se crea y se almacena un nuevo proyecto con el tipo y nombre especificados
	}
	else {
		std::cerr << "No se pueden repetir nombres de proyectos." << std::endl;
	}
}

void Controlador_Proyectos::eliminarProyecto(std::string nombre) {
	Proyecto* proyectoPorEliminar = buscarProyecto(nombre);
	if (proyectoPorEliminar != nullptr) {
		auto itr = find(proyectosAlmacenados.begin(), proyectosAlmacenados.end(), proyectoPorEliminar);
		proyectosAlmacenados.erase(itr);
		delete proyectoPorEliminar;
	}
	else {
		std::cerr << "El proyecto que se esta tratando de borrar no existe." << std::endl;
	}
}

void Controlador_Proyectos::modificarProyecto(std::string nombre) {
	Proyecto* proyecto = buscarProyecto(nombre);

}

Proyecto* Controlador_Proyectos::consultarProyecto(std::string nombre) {
	Proyecto* proyecto = buscarProyecto(nombre);
	if (proyecto == nullptr) {
		std::cerr << "El proyecto especificado no existe" << std::endl;
	}
	return proyecto;
}
