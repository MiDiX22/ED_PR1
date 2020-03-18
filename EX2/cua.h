/*------------------------------------------------------------------------------

	"cua.h" :   Miriam Gertudix
                miriam.gertrudix@estudiants.urv.cat

	Fitxer amb les capçaleres de la cua

------------------------------------------------------------------------------*/
#ifndef CUA_H
#define CUA_H
#include <stdbool.h>

#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define CUA_NO_CREADA 3
#define CUA_BUIDA 4
#define CUA_PLENA 5

/* Cua: estructura on emmagatzarem les dades referents a la nostra cua*/
typedef struct Cua {
    int *dades; //vector de dades de la cua
    int primer; //primer element de la cua
    int m_Elem; //maxim d'elements
    int n_Elem; //num d'elements totals
} Cua;

int Crear(Cua *ac, int size);
int Encuar(Cua *ac, int elem);
int Desencuar(Cua *ac);
int Cap(Cua c, int *elem);
int EsBuida(Cua c, bool *b);
int EsPlena(Cua c, bool *b);
int Destruir(Cua *ac);

#endif