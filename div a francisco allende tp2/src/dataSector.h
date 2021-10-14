#ifndef DATASECTORES_H_INCLUDED
#define DATASECTORES_H_INCLUDED

struct
{
    int id;
    char descripcion[51];
} typedef eSector;

#endif // DATASECTORES_H_INCLUDED

void hardcodearSectores(eSector sectores[], int tamSec);

int cargarDescripcionSector(eSector sectores[], int tamSec, int idSector, char* descripcion);


