// Laboratorio2_Plantilla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cmpnte_Proyecto.h"
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

 Actividad_Hoja b2("2020-09-15", "2020-09-30", "2020-09-15", "2020-09-20");
 Actividad_Hoja b3("2020-09-14", "2020-09-25", "2020-09-16", "2020-09-27");
 Actividad_Hoja b4("2020-09-19", "2020-09-31", "2020-09-19", "2020-09-31");

 b1.setNombre("Desayunar");
 b2.setNombre("Dormir");
 b3.setNombre("Comer");
 b4.setNombre("Jugar");


 Actividad_Hoja c1("2020-09-15", "2020-09-20", "2020-09-15", "2020-09-20");
 
 raiz.agregarGrupo(&a1);
 raiz.agregarGrupo(&a2);

 a1.agregarGrupo(&b1);

 a2.agregarHoja(&b2);
 a2.agregarHoja(&b3);
 a2.agregarHoja(&b4);

 b1.agregarHoja(&c1);

//raiz.setResponsable("Oscar");
//
//c1.setResponsableAuto();
//b4.setResponsableAuto();
//b3.setResponsableAuto();
//b2.setResponsableAuto();


//cout << "Responsable: " << a1.getResponsable() << endl;
//cout << "Responsable: " << a2.getResponsable() << endl;
//cout << "Responsable: " << b1.getResponsable() << endl;


//b1.eliminar();

 

 
// a2.calcularFechaRealInicioFin();
//
// cout << "Inicio Real: " << a2.getFechaRealInicio() << endl;
// cout << "Final Real: " << a2.getFechaRealFin() << endl;
//
//
//
//a2.calcularFechaPlanInicioFin();
// cout << "Inicio plan: " << a2.getFechaInicio() << endl;
// cout << "Final plan: " << a2.getFechaFinal() << endl;

}

