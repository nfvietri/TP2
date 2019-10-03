#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayEmployees.h"

static int generarId(void)
{
	static int id = -1;
	id++;
	return id;
}

int initLugarLibreEmployees(struct sEmployee *aArray, int cantidad){
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0; i<cantidad; i++)
		{
			aArray[i].status = STATUS_EMPTY;
		}
	}

	return retorno;
}

int imprimirArrayEmployees(struct sEmployee *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status != 0)
			{
				printf("Id: %d // Status: %d // Nombre: %s // Apellido: %s // Salario: %f // Sector: %d\n", aArray[i].id, aArray[i].status, aArray[i].name, aArray[i].lastName, aArray[i].salary, aArray[i].sector);
			}

		}
	}
	return retorno;
}

int buscarLugarLibreEmployee(struct sEmployee *aArray, int cantidad)
{
	int index = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				index = i;
				break;
			}

		}

	}

	return index;
}

int altaEmployeePorId(struct sEmployee *aArray, int cantidad,struct sEmployee employee)
{
	int retorno = -1;
	int index;

	if(buscarLugarLibreEmployee(aArray,QTY_EMPLOYEES) != -1)
	{
		index = buscarLugarLibreEmployee(aArray,cantidad);
		aArray[index] = employee;
		aArray[index].status = STATUS_NOT_EMPTY;
		aArray[index].id = generarId();
		retorno = 0;

	}

	return retorno;
}

int modificarEmployeePorId(struct sEmployee *aArray, int cantidad,struct sEmployee employee)
{
	int retorno;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(aArray[i].id == employee.id)
		{
			retorno = 0;
			strcpy(aArray[i].name, employee.name);
			strcpy(aArray[i].lastName, employee.lastName);
			aArray[i].salary = employee.salary;
			aArray[i].sector = employee.sector;
			break;
		}
	}


	return retorno;
}

int bajaEmployeePorId(struct sEmployee *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = 0;
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].id == id)
				{
					retorno = 0;
					aArray[i].status = STATUS_EMPTY;
					break;
				}
			}
		}


	}

	return retorno;
}

int buscarEmployeePorId(struct sEmployee *aArray, int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0; i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				if(aArray[i].id == id)
				{
					retorno = i;
					break;
				}

			}

		}
	}

	return retorno;
}

int ordenarArrayEmployeesPorNombre(struct sEmployee *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sEmployee buffer;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].name,aArray[i+1].name,QTY_EMPLOYEES)>0)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}

			}
		}while(fSwap);
	}
	return retorno;
}

int ordenarArrayEmployeesPorSector(struct sEmployee *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sEmployee buffer;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(aArray[i].sector > aArray[i+1].sector)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}

			}
		}while(fSwap);
	}
	return retorno;
}

int calcularTotalPromedioSalariosEmployee(float *totalSalarios, float *promedio, struct sEmployee *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	float auxSalarios = 0;
	float auxPromedio;
	int cantActivos = 0;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == 1)
			{
				cantActivos++;
				auxSalarios = auxSalarios + aArray[i].salary;
			}

		}

		auxPromedio = auxSalarios / (float) cantActivos;
	}
		*totalSalarios = auxSalarios;
		*promedio = auxPromedio;

		return retorno;

}

int cantMayorQuePromedio(struct sEmployee *aArray, float promedio, int cantidad)
{
	int index = 0;
	int i;

	for(i=0;i<cantidad;i++)
	{
		if(aArray[i].status == 1 && aArray[i].salary > promedio)
		{
			index = index + 1;
		}
	}


	return index;
}

int comprobarSiHayEmpleadosCargados(struct sEmployee *aArray, int cantidad)
{
	int retorno = -1;
	int i;

	if(aArray != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == 1)
			{
				retorno = EXIT_SUCCESS;
			}
		}
	}

	return retorno;
}

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				fflush(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
					break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;

}

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = 0;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos)
{
	int retorno = -1;
	float buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}


