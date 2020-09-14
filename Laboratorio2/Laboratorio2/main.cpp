
#include <iostream>
//#include "Controlador_Proyectos.h"
//#include "Controlador_Tipos_Proyecto.h"
//#include "Cmpnte_Proyecto.h"
#include "Actividad_Grupo.h"
#include "Actividad_Hoja.h"


int main()
{
   //Controlador_Proyectos cntr_proy;
   //Controlador_Tipos_Proyecto cntr_tipo;

	/*Pruebas*/

	Actividad_Grupo raiz;
	Actividad_Grupo a1;
	Actividad_Grupo a2;
	Actividad_Grupo b1;

	Actividad_Hoja b2("2020-09-15", "2020-09-20", "2020-09-15", "2020-09-20");
	Actividad_Hoja b3("2020-09-14", "2020-09-25", "2020-09-16", "2020-09-27");
	Actividad_Hoja b4("2020-09-19", "2020-09-31", "2020-09-19", "2020-09-31");

	Actividad_Hoja c1("2020-09-15", "2020-09-20", "2020-09-15", "2020-09-20");
	
	raiz.agregar(&a1);
	raiz.agregar(&a2);

	a1.agregar(&b1);

	a2.agregar(&b2);
	a2.agregar(&b3);
	a2.agregar(&b4);

	b1.agregar(&c1);


}
