#pragma once

template<typename self>
class Cmpnte_Proyecto 
{

protected:
	Actividad_Grupo* padre;

public:
	Cmpnte_Proyecto();
	~Cmpnte_Proyecto();


	virtual void setPadre(Actividad_Grupo* p) = 0;
	virtual Cmpnte_Proyecto* getPadre() = 0;

	virtual void eliminar() = 0;

	virtual void setNombre(string n) = 0;
	virtual string getNombre() = 0;

	virtual void setResponsable(string r) = 0;
	virtual string getResponsable() = 0;
	virtual void setResponsableAuto() = 0;

	virtual void setDescripcion(string d) = 0;
	virtual string getDescripcion() = 0;
};

template<typename self>
inline Cmpnte_Proyecto<self>::Cmpnte_Proyecto()
{
}

template<typename self>
inline Cmpnte_Proyecto<self>::~Cmpnte_Proyecto()
{
}
