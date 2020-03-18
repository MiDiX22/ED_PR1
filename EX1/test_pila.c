/*------------------------------------------------------------------------------

	"test_pila.c" : Miriam Gertudix
                    miriam.gertrudix@estudiants.urv.cat

	Fitxer per testejar la pila

------------------------------------------------------------------------------*/
#include "PILA.H"
#include "PILA.C"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int el=0;
    /*CREAR PILA*/
    Pila p1;
    p1 = Crear(5);
    printf("capacitat max de la pila:\n %d", p1.m_Elem);

    /*ES BUIDA*/
    printf("\nLa llista es buida?\n");
    if (EsBuida(p1))
    {
        printf("Si");
    }else
    {
        printf("No");
    }

    /*APILAR 1 ELEMENT*/
    printf("\napilant!");
    Apilar(&p1, 1);
    printf("\naquesta es la teva pila:\n");
    Imprimir(p1);

    /*ES BUIDA*/
    printf("\nLa llista es buida?\n");
    if (EsBuida(p1))
    {
        printf("Si");
    }else
    {
        printf("No");
    }

    /*APILAR ELEMENT*/
    printf("\napilant!");
    Apilar(&p1, 2);
    Apilar(&p1, 3);
    Apilar(&p1, 4);
    Apilar(&p1, 5);
    printf("\naquesta es la teva pila:\n");
    Imprimir(p1);

    /*CIM*/
    el=Cim(p1);
    printf("Cim: %d\n", el);

    /*ES PLENA*/
    printf("\nLa llista es plena?\n");
    if (EsPlena(p1))
    {
        printf("Si");
    }else
    {
        printf("No");
    }
    
    /*DESAPILAR 1 ELEMENT*/
    printf("\ndesapilant!");
    Desapilar(&p1);
    printf("\naquesta es la teva pila:\n");
    Imprimir(p1);

    /*ES PLENA*/
    printf("\nLa llista es plena?\n");
    if (EsPlena(p1))
    {
        printf("Si");
    }else
    {
        printf("No");
    }
    
    /*DESAPILAR ELEMENT*/
    printf("\ndesapilant!");
    Desapilar(&p1);
    Desapilar(&p1);
    printf("\naquesta es la teva pila:\n");
    Imprimir(p1);

    
    return 0;
}
