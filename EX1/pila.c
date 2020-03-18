/*------------------------------------------------------------------------------

	"pila.c" :  Miriam Gertudix
                miriam.gertrudix@estudiants.urv.cat

	Fitxer que conte totes les operacions de la pila

------------------------------------------------------------------------------*/
#include "PILA.H"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Crear: funció per a crear i reservar memoria 
            que necessitara la pila*/
Pila Crear(int size){
    Pila a_pila;
    if (size<=0) //si intentem crea una pila amb un num negatiu d'elements
    {
        printf("Aquest numero no es correcte (negatiu)\n");
        exit(EXIT_FAILURE);
    }
    
    a_pila.dades = (int*) malloc(size*sizeof(int)); //reservo la memoria que necessitare

    if (a_pila.dades == NULL) //si no tinc prou espai surto
    {
        printf("no hi ha suficient memoria!\n");
        exit(EXIT_FAILURE);
    }
    
    a_pila.m_Elem = size;
    a_pila.n_Elem = 0;
   
    return(a_pila);    
}

/* Cim: funcio per trobar el cim de la pila*/
int Cim(Pila p){
    int elem;
    if (EsBuida(p))
    {
        printf("error al trobar el cim! La pila es buida\n");
        return(1);
    }
    elem = p.dades[p.n_Elem-1];
    return(elem);
}


/* Apilar: funcio per afegir elements a la pila*/
void Apilar(Pila *ap, int elem){
    
    if (ap == NULL) //comprovem que existeixi la pila
    {
        printf("aquesta pila no existeix!\n");
        return;
    }
    
    if (EsPlena(*ap)) //comprovem que hi hagi espai per afegir elements
    {
        printf("has arribat al maxim de numeros apilats\n");
        return;
    }

    ap->dades[ap->n_Elem]=elem; //afegeixo el nou element
    ap->n_Elem++; //incremento el num d'elements
}


/* Desapilar: funcio per retirar elements 
                de la pila*/
void Desapilar(Pila *ap) {
    if (EsBuida(*ap))
    {
        printf("error! la pila ja es buida\n");
        return;
    }else
    {
        ap->n_Elem--; //decremento el num d'elements
    }
}

/* EsBuida: funcio que et retorna cert 
            si la pila es buida*/
bool EsBuida(Pila p){
    if (p.n_Elem<=0)
    {
        return true;
    }
    return false;  
}

/* EsPlena: funcio que et retorna cert 
            si la pila es plena*/
bool EsPlena(Pila p){
    if (p.n_Elem==p.m_Elem)
    {
        return true;
    }
    return false;
}

/* Destruir: funcio per alliberar memoria 
            que ocupa la pila*/
void Destruir(Pila *ap){
    ap->dades = NULL;
    ap->n_Elem = 0;   //num elements a 0
    free(ap);   //destrueixo el punter
}

/*FUNCIONS AUXILIARS:*/

/* Imprimir: funcio per mostrar per pantalla les dades de la pila*/
void Imprimir (Pila p){ 
   for (int i = p.n_Elem - 1; i >= 0; i--)
   {
       printf("| %d |\n", p.dades[i]);
   }  
}



