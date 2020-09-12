#pragma once
#include <string>

using namespace std;

template<typename self>
class Cmpnte_Proyecto 
{
public:
	Cmpnte_Proyecto();
	~Cmpnte_Proyecto();

	//Se incluyen los metodos que son comunes para ambas clases

	void eliminar();

	void setNombre(string n);
	string getNombre();

	void setResponsable(string r);
	string getResponsable();
	void setResponsableAuto();

	void setDescripcion(string d);
	string getDescripcion();

	void setFechaInicio(string f);
	string getFechaInicio();

	void setFechaFinal(string f);
	string getFechaFinal();

	void setFechaRealInicio(string i);
	string getFechaRealInicio();

	void setFechaRealFin(string f);
	string getFechaRealFin();

private:
	string nombre;
	string responsable;
	string descripcion;
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;
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
	nombre = n;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getNombre()
{
	return nombre;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setResponsable(string r)
{
	responsable = r;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getResponsable()
{
	return responsable;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setResponsableAuto()
{

}

template<typename self>
inline void Cmpnte_Proyecto<self>::setDescripcion(string d)
{
	descripcion = d;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getDescripcion()
{
	return descripcion;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setFechaInicio(string f)
{
	fecha_plan_ini = f;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getFechaInicio()
{
	return fecha_plan_ini;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setFechaFinal(string f)
{
	fecha_plan_fin = f;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getFechaFinal()
{
	return fecha_plan_fin;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setFechaRealInicio(string i)
{
	fecha_real_ini = i;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getFechaRealInicio()
{
	return fecha_real_ini;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setFechaRealFin(string f)
{
	fecha_real_fin = f
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getFechaRealFin()
{
	return fecha_real_fin;
}



