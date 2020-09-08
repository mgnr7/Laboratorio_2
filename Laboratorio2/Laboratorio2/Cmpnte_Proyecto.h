#pragma once
#include <string>
using namespace std;

class Actividad_Hoja;

class Cmpnte_Proyecto 
{
protected:
	Cmpnte_Proyecto* padre;

public:

	virtual void setPadre(Cmpnte_Proyecto* p) = 0;
	virtual Cmpnte_Proyecto* getPadre() = 0;

	virtual void agregar(Cmpnte_Proyecto* actividad) = 0;
	
	virtual void eliminar() = 0;

	virtual void setNombre(string n) = 0;
	virtual string getNombre() = 0;

	virtual void setResponsable(string r) = 0;
	virtual string getResponsable() = 0;

	virtual void setDescripcion(string d) = 0;
	virtual string getDescripcion() = 0;



};