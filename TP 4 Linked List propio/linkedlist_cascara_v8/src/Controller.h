#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//mis controllers
int controller_getEmployeeById(LinkedList* lista, int id);
int controller_getLastId(LinkedList* pArrayListEmployee);
int controller_clearList(LinkedList* pArrayListEmployee);
LinkedList* controller_cutList(LinkedList* pArrayListEmployee);
int controller_removeByIndex(LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
