#pragma once
#include <string>

using namespace std;

class Actividad_Grupo;

template<typename self>
class Cmpnte_Proyecto 
{
protected:
	Actividad_Grupo* padre;

public:
	Cmpnte_Proyecto();
	~Cmpnte_Proyecto();

	//Se incluyen los metodos que son comunes para ambas clases
	void setPadre(Actividad_Grupo* p);
	Actividad_Grupo* getPadre();
	
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
	responsable = "";
	nombre = "";
	fecha_plan_ini = "";
	fecha_plan_fin = "";
	fecha_real_ini = "";
	fecha_real_fin = "";
	padre = NULL;
}

template<typename self>
inline Cmpnte_Proyecto<self>::~Cmpnte_Proyecto()
{
}

template<typename self>
inline void Cmpnte_Proyecto<self>::setPadre(Actividad_Grupo* p)
{
	padre = p;
}

template<typename self>
inline Actividad_Grupo* Cmpnte_Proyecto<self>::getPadre()
{
	return padre;
}

template<typename self>
inline void Cmpnte_Proyecto<self>::eliminar()
{
	if (padre != NULL)
	{
		padre->eliminarSubActividad(nombre);
	}
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
	if (padre != NULL)
	{
		if (!padre->getResponsable().empty())
		{
			responsable = padre->getResponsable();
		}
		else
		{
			padre->setResponsableAuto();
			responsable = padre->getResponsable();
		}
	}

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
	fecha_real_fin = f;
}

template<typename self>
inline string Cmpnte_Proyecto<self>::getFechaRealFin()
{
	return fecha_real_fin;
}



