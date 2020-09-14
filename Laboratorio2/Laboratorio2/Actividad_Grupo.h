#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Grupo : public Cmpnte_Proyecto
{
public:
	Actividad_Grupo();
	virtual ~Actividad_Grupo();

	void setPadre(Actividad_Grupo* p) override;
	Actividad_Grupo* getPadre() override;

	void agregar(Cmpnte_Proyecto* actividad);

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;

	void setResponsable(string r) override;
	string getResponsable() override;
	void setResponsableAuto() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

	void setFechaInicio(string f);
	string getFechaInicio();

	void setFechaFinal(string f);
	string getFechaFinal();

	void setFechaRealInicio(string i) override;
	string getFechaRealInicio() override;

	void setFechaRealFin(string f) override;
	string getFechaRealFin() override;

	void eliminarSubActividad(string nombre);

	void calcularFechaRealInicioFin();

	void calcularFechaPlanInicioFin();

private:
	
	string responsable;

	string nombre;
	//Por ahora estoy poniendo las fechas como strings
	//Se asume que el formato es YYYY-MM-DD
	string fecha_plan_ini;
	string fecha_plan_fin;
	string fecha_real_ini;
	string fecha_real_fin;
	
	string descripcion;

	vector < Cmpnte_Proyecto* > actividades;

};

