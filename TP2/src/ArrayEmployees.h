#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define QTY_EMPLOYEES 1000


struct sEmployee{

	int id;
	int status;

	char name[50];
	char lastName[50];
	float salary;
	int sector;


};
//brief inicializa un array con valor 0
//param array a inicializar y cantidad de elementos
//return 0 si esta ok, -1 error
int initLugarLibreEmployees(struct sEmployee *aArray, int cantidad);

//brief imprime un array
//param array a imprimir y cantidad de elementos
//return 0 si esta ok, -1 error
int imprimirArrayEmployees(struct sEmployee *aArray, int cantidad);

//brief busca el primer lugar libre de un array
//param array a buscar y cantidad elementos
//return index de posicion libre, -1 si error
int buscarLugarLibreEmployee(struct sEmployee *aArray, int cantidad);

//brief alta employee dentro de un array de tipo sEmployee
//param array employee, cantidad elementos, employee
//return 0 si esta ok, -1 error
int altaEmployeePorId(struct sEmployee *aArray, int cantidad,struct sEmployee employee);

//brief modifica employee dado de alta
//param array de tipo semployee, cantidad elementos, employee
//return 0 si esta ok, -1 error
int modificarEmployeePorId(struct sEmployee *aArray, int cantidad,struct sEmployee employee);

//brief busca employee por id
//param array, cantidad elementos, id
//return id del employee, -1 error
int buscarEmployeePorId(struct sEmployee *aArray, int cantidad,int id);

//brief baja employee dado de alta
//param array de tipo semployee, cantidad elementos, id
//return 0 si esta ok, -1 error
int bajaEmployeePorId(struct sEmployee *aArray, int cantidad,int id);

//brief ordena array de tipo sEmployee por nombre
//param array de tipo semployee, cantidad elementos
//return 0 si esta ok, -1 error
int ordenarArrayEmployeesPorNombre(struct sEmployee *aArray, int cantidad);

//brief ordena array de tipo sEmployee por sector
//param array de tipo semployee, cantidad elementos
//return 0 si esta ok, -1 error
int ordenarArrayEmployeesPorSector(struct sEmployee *aArray, int cantidad);

//brief calcula total salarios y promedio
//param array de tipo semployee, cantidad elementos, puntero total salarios, puntero promedio
//return 0 si esta ok, -1 error
int calcularTotalPromedioSalariosEmployee(float *totalSalarios, float *promedio, struct sEmployee *aArray, int cantidad);


//brief calcula cantidad de employees que ganan mas que el promedio
//param array de tipo semployee, promedio, cantidad elementos
//return index con cantidad employees, -1 error
int cantMayorQuePromedio(struct sEmployee *aArray, float promedio, int cantidad);

//brief recorre array y chequea si hay altas
//param array de tipo semployee, cantidad elementos
//return 0 si esta ok, -1 error
int comprobarSiHayEmpleadosCargados(struct sEmployee *aArray, int cantidad);


int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos);

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);


