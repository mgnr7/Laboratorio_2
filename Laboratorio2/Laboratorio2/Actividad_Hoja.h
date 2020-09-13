#pragma once
#include <string>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Hoja : public Cmpnte_Proyecto
{
public:
	Actividad_Hoja(string planInicio, string planFin, string realInicio, string realFin);
	~Actividad_Hoja();

	void setPadre(Actividad_Grupo* p) override;
	Actividad_Grupo* getPadre() override;

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;
	 
	void setResponsable(string r) override;
	string getResponsable() override;
	void setResponsableAuto() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

	void setFechaInicio(string f) override;
	string getFechaInicio() override;

	void setFechaFinal(string f) override;
	string getFechaFinal() override;

	void setFechaRealInicio(string i) override;
	string getFechaRealInicio() override;

	void setFechaRealFin(string f) override;
	string getFechaRealFin() override;

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

};
