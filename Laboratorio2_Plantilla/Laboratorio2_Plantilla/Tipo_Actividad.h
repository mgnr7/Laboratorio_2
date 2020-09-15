#pragma once
#include <string>
class Tipo_Actividad 
{
public:
	Tipo_Actividad(std::string nombre);
	~Tipo_Actividad();
	void setNombre(std::string nombre);
	std::string getNombre();

private:
	std::string nombre;
};

Tipo_Actividad::Tipo_Actividad(std::string nombre) 
{
}

Tipo_Actividad::~Tipo_Actividad()
{
}

inline void Tipo_Actividad::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

inline std::string Tipo_Actividad::getNombre()
{
	return this->nombre;
}
