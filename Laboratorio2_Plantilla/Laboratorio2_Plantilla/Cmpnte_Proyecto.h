#pragma once
#include <string>

using namespace std;

template<typename self>
class Cmpnte_Proyecto 
{
public:
	Cmpnte_Proyecto();
	~Cmpnte_Proyecto();

	void eliminar();

	void setNombre(string n);
	string getNombre();

	void setResponsable(string r);
	string getResponsable();
	void setResponsableAuto();

	virtual void setDescripcion(string d) = 0;
	virtual string getDescripcion() = 0;

private:
	string nombre;
	string responsable;
	string descripcion;

};

template<typename self>
inline Cmpnte_Proyecto<self>::Cmpnte_Proyecto()
{
}

template<typename self>
inline Cmpnte_Proyecto<self>::~Cmpnte_Proyecto()
{
}

template<typename self>
inline void Cmpnte_Proyecto<self>::eliminar()
{
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setNombre(string n)
{
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getNombre()
{
	return string();
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setResponsable(string r)
{
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getResponsable()
{
	return string();
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setResponsableAuto()
{
}



