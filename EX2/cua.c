/*------------------------------------------------------------------------------

	"cua.c" :   Miriam Gertudix
                miriam.gertrudix@estudiants.urv.cat

	Fitxer que conte totes les operacions de la cua

------------------------------------------------------------------------------*/
#include "CUA.H"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool buida, plena;

/* Crear: funció per a crear la cua*/
int Crear(Cua *ac, int size){
    if (size<=0)
    {
        return ERROR_CREAR;
    }
    ac->dades = (int*) malloc(size*sizeof(int)); //reservo la memoria que necessitare
    if (ac->dades == NULL)
    {
        return ERROR_CREAR;
    }
    ac->m_Elem = size;    
    ac->n_Elem = 0;
    ac->primer = 0;
    return SUCCESS;
}

/* Encuar: funcio per afegir 
            elements a la cua*/
int Encuar(Cua *ac, int elem){
    int pos;
    if (ac == NULL) //comprovo que la cua existeixi
    {
        return CUA_NO_CREADA;
    }

    EsPlena(*ac, &plena);
    if (plena)  //comprovo que no estigui plena
    {
        return CUA_PLENA;
    }
    pos=(ac->primer + ac->n_Elem) % ac->m_Elem; //(primer + n_elem) mod m_elem
    ac->dades[pos] = elem; //encuo el nou element
    ac->n_Elem++; //incremento el num d'elements
}

/* Desencuar: funcio per retirar
             elements de la cua*/
int Desencuar(Cua *ac){
    if (ac == NULL) //comprovo que la cua existeixi
    {
        return CUA_NO_CREADA;
    }

    EsBuida(*ac, &buida);
    if (buida)  //comprovo que no estigui buida
    {
        return CUA_BUIDA;
    }

    ac->dades[ac->primer] = 0; //desencuo el primer element de la cua
    ac->primer = ((ac->primer)+1) % ac->m_Elem; //actualitzo el primer element de la cua
    ac->n_Elem--;   //decremento el num d'elements
}

/* Cap: funcio per trobar el cap de la cua*/
int Cap(Cua c, int *elem){
    EsBuida(c, &buida);
    if (buida)  //comprovo que no estigui buida
    {
        return CUA_BUIDA;
    }
    *elem = c.dades[c.primer];
    return SUCCESS;
    
}

/* EsBuida: funcio que et posa a cert 
            la variable b si la cua es buida*/
int EsBuida(Cua c, bool *b){
    if (&c == NULL) //comprovem que la cua existeixi
    {
        return CUA_NO_CREADA;
    }
    //comprovem si es buida
    if (c.n_Elem <= 0)
    {
        *b = true;
    }else
    {
        *b = false;
    }
    return SUCCESS; 
}

/* EsPlena: funcio que et posa a cert 
            la variable b si la cua es plena*/
int EsPlena(Cua c, bool *b){
    if (&c == NULL)//comprovem que la cua existeixi
    {
        return CUA_NO_CREADA;
    }
    //comprovem si es plena
    if (c.n_Elem == c.m_Elem)
    {
        *b = true;
    }else
    {
        *b = false;
    }
    return SUCCESS; 
}

/* Destruir: funcio per alliberar memoria 
            que ocupa la cua*/
int Destruir(Cua *ac){
    free(ac->dades);    //destrueixo el punter
    ac->n_Elem = 0; //num elements a 0
    ac->primer = 0; //primer a 0
    free(ac);   //destrueixo el punter
    return SUCCESS;
    
}

/*FUNCIONS AUXILIARS:*/

/* Imprimir: funcio per mostrar per pantalla les dades de la cua*/
void Imprimir (Cua c){
    int element;
    element= c.primer;
    for (int i = 0;  i < c.n_Elem; i++)
    {
        printf("%d ", element);
        printf("|%d|\n", c.dades[element]);
        element= (element + 1)% c.m_Elem;
    }
}