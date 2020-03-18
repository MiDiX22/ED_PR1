/*------------------------------------------------------------------------------

	"pila.h" :  Miriam Gertudix
            	miriam.gertrudix@estudiants.urv.cat

	Fitxer amb les capçaleres de la pila

------------------------------------------------------------------------------*/
#ifndef PILA_H
#define PILA_H
#include <stdbool.h>

	/* Pila: estructura on emmagatzarem les dades referents a la nostra pila*/
	typedef struct Pila {
		int *dades;
		int m_Elem; //maxim d'elements
		int n_Elem; //num d'elements totals
	} Pila;

	Pila Crear(int size);
	int Cim(Pila p);
	void Apilar(Pila *ap, int elem);
	void Desapilar(Pila *ap);
	bool EsBuida(Pila p);
	bool EsPlena(Pila p);
	void Destruir(Pila *ap);
	void Imprimir (Pila p);

#endif 
