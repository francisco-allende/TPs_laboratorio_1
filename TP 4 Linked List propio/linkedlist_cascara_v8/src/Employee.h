#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr,char* horasTrabajadasStr,  char* salarioStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


//mis funciones
int employee_print(Employee* emp);
int employee_sortId(void* empOne, void* empTwo);
int employee_sortName(void* empOne, void* empTwo);
int employee_sortHours(void* empOne, void* empTwo);
int employee_sortSalary(void* empOne, void* empTwo);
int employee_filterSalariesOver31k(void* pElement);

#endif // EMPLOYEE_H_INCLUDED
