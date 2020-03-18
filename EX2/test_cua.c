/*------------------------------------------------------------------------------

	"test_cua.c" :  Miriam Gertudix
                    miriam.gertrudix@estudiants.urv.cat

	Fitxer per testejar la cua

------------------------------------------------------------------------------*/
#include "CUA.H"
#include "CUA.C"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void menu_cua (){
    printf("\nBenvingut al menu del test:\n");
    printf("a - Crear una cua nova\n");
    printf("b - Encuar un element\n");
    printf("c - Desencuar un element\n");
    printf("d - Mostrar el cap de la cua\n");
    printf("e - Comprovar si la cua es buida\n");
    printf("f - Comprovar si la cua es plena\n");
    printf("g - Destruir la cua\n");
    printf("h - Mostrar cua\n");
    printf("i - Sortir\n");
}

int main()
{
    int error, size, cap, valor;
    bool buida, plena, sortir = false;
    char op;
    Cua c1;

    printf("RECORDA: prem m per veure el menu\n");
    while (!sortir)
    {
        printf("\nTria una opcio:\n");
        scanf("%c", &op);
        while ((getchar())!= '\n'); //per a buidar els scanf
        printf("\n");

        switch (op)
        {
        case 'a':   //CREAR CUA
            printf("mida maxima de la cua?\n");
            scanf("%d", &size);
            while ((getchar())!= '\n'); //per a buidar els scanf
            error = Crear(&c1, size);
            if (error == ERROR_CREAR)
            {
                printf("no hi ha suficient memoria o has posat una mida negativa!\n");
            }else
            {
                printf("La cua ha estat creada!\n");
            }
            
            break;
        
        case 'b':   //ENCUAR
            printf("valor a encuar:\n");
            scanf("%d", &valor);
            while ((getchar())!= '\n'); //per a buidar els scanf
            error = Encuar(&c1, valor);
            if (error == CUA_NO_CREADA)
            {
                printf("la cua indicada no existeix!\n");
            }else if (error == CUA_PLENA)
            {
                printf("la cua es plena!\n");
            }
            break;
        
        case 'c':   //DESENCUAR
            error = Desencuar(&c1);
            if (error == CUA_NO_CREADA)
            {
                printf("la cua indicada no existeix!\n");
            }else if (error == CUA_BUIDA)
            {
                printf("la cua es buida!\n");
            }
            break;

        case 'd':   //CAP
            error = Cap(c1, &cap);
            if (error == CUA_BUIDA)
            {
                printf("la cua es buida!\n");
            }
            else
            {
                printf("El cap de la cua es: %d\n", cap);
            }          
            break;

        case 'e':   //BUIDA
            error = EsBuida(c1, &buida);
            if (error == CUA_NO_CREADA)
            {
                printf("la cua indicada no existeix!\n");
            }else
            {
                printf("la cua es buida?\n");
                if (buida)
                {
                    printf("si\n");
                }else
                {
                    printf("no\n");
                }
            }
            break;

        case 'f':   //PLENA
            error = EsPlena(c1, &plena);
            if (error == CUA_NO_CREADA)
            {
                printf("la cua indicada no existeix!\n");
            }else
            {
                printf("la cua es plena?\n");
                if (plena)
                {
                    printf("si\n");
                }else
                {
                    printf("no\n");
                }
            }
            break;

        case 'g':   //DESTRUIR
            error = Destruir(&c1);
            if (error == ERROR_DESTRUIR)
            {
                printf("Error al destruir la cua!\n");
            }else
            {
                printf("La cua ha estat destruida!\n");
            }
            break;

        case 'h':   //IMPRIMIR
            printf("Aquesta es la teva cua:\n");
            Imprimir(c1);
            break;

        case 'i':   //SORTIR
            printf("Has escollit acabar amb el test!\n");
            sortir = true;
            break;

        case 'm':   //MENU
            menu_cua();
            break;
        }
    }
    return 0;
}
