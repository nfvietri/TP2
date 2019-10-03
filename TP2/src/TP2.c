/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayEmployees.h"

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0); //funcion utilizada por problemas con scanf en windows

	struct sEmployee aEmployees[QTY_EMPLOYEES];
	struct sEmployee bEmployee;
	float totalSalarios;
	float promedio;
	int opcion;
	int respuesta;
	int mayPromedio;

	initLugarLibreEmployees(aEmployees,QTY_EMPLOYEES);

	do{

	printf( "1-Alta\n"
			"2-Modificar\n"
			"3-Baja\n"
			"4-Informes\n"
			"5-Salir\n");

	getInt(&opcion,"Ingrese una opcion: \n","Error",0,5,3);

	switch(opcion)
	{
	case 1: getString(bEmployee.name, "Nombre?\n", "Error", 2, 40, 3);
			getString(bEmployee.lastName, "Apellido?\n", "Error", 2, 40, 3);
			getFloat(&bEmployee.salary, "Salario?\n", "Error", 2, 1000000, 3);
			getInt(&bEmployee.sector,"Sector? (0 a 10)\n","Error",0,10,3);
			altaEmployeePorId(aEmployees, QTY_EMPLOYEES, bEmployee);
			printf("Alta exitosa!\n");
			break;

	case 2:	if(comprobarSiHayEmpleadosCargados(aEmployees, QTY_EMPLOYEES) == 0)
			{
				imprimirArrayEmployees(aEmployees, QTY_EMPLOYEES);
				getInt(&bEmployee.id, "Ingrese el id a modificar:\n","Error",0,1000,3);
				buscarEmployeePorId(aEmployees, QTY_EMPLOYEES, bEmployee.id);
				printf("Employee seleccionado: Id: %d // Apellido: %s\n",aEmployees[bEmployee.id].id, aEmployees[bEmployee.id].lastName);
				getString(bEmployee.name, "Nombre?\n", "Error", 2, 40, 3);
				getString(bEmployee.lastName, "Apellido?\n", "Error", 2, 40, 3);
				getFloat(&bEmployee.salary, "Salario?\n", "Error", 2, 80000, 3);
				getInt(&bEmployee.sector,"Sector? (0 a 10)\n","Error",0,10,3);
				modificarEmployeePorId(aEmployees, QTY_EMPLOYEES, bEmployee);
				printf("Cliente modificado!\n");
			} else {
				printf("No hay empleados cargados!\n");
					}
			break;

	case 3: if(comprobarSiHayEmpleadosCargados(aEmployees, QTY_EMPLOYEES) == 0)
			{
				imprimirArrayEmployees(aEmployees, QTY_EMPLOYEES);
				getInt(&bEmployee.id, "Ingrese el id a eliminar:\n","Error",0,1000,3);
				buscarEmployeePorId(aEmployees, QTY_EMPLOYEES, bEmployee.id);
				printf("Employee seleccionado: Id: %d // Apellido: %s\n",aEmployees[bEmployee.id].id, aEmployees[bEmployee.id].lastName);
				getInt(&respuesta,"Desea eliminar? 1-si 2-no", "Error", 0, 3, 3);
				if(respuesta == 1){
						bajaEmployeePorId(aEmployees, QTY_EMPLOYEES, bEmployee.id);
						printf("Baja exitosa!\n");
				}
			}else{
				printf("No hay empleados cargados!\n");
			}
				break;

	case 4:	if(comprobarSiHayEmpleadosCargados(aEmployees, QTY_EMPLOYEES) == 0)
			{
				printf("Empleados ordenados por nombre: \n");
				ordenarArrayEmployeesPorNombre(aEmployees, QTY_EMPLOYEES);
				imprimirArrayEmployees(aEmployees, QTY_EMPLOYEES);
				printf("Empleados ordenados por sector: \n");
				ordenarArrayEmployeesPorSector(aEmployees, QTY_EMPLOYEES);
				imprimirArrayEmployees(aEmployees, QTY_EMPLOYEES);

				calcularTotalPromedioSalariosEmployee(&totalSalarios, &promedio, aEmployees, QTY_EMPLOYEES);
				printf("Total salarios: %f\n", totalSalarios);
				printf("Promedio salarios: %f\n", promedio);

				mayPromedio = cantMayorQuePromedio(aEmployees, promedio, QTY_EMPLOYEES);
				printf("Mayores que el promedio: %d\n", mayPromedio);

			} else {
				printf("No hay empleados cargados!\n");
			}
			break;
	}


	} while (opcion != 5);



	return EXIT_SUCCESS;
}


