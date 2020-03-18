/*------------------------------------------------------------------------------

	"rpn.c" :   Miriam Gertudix
                miriam.gertrudix@estudiants.urv.cat

	Implementació de la calculadora rpn.

------------------------------------------------------------------------------*/
#include "PILA.H"
#include "PILA.C"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* DosElemApilats: funció que retorna cert si 
    tenim dos o mes elements apilats*/
bool DosElemApilats(Pila p){
    if (p.n_Elem>=2)
    {
        return true;
    }
    return false;
}

/*Programa Principal*/
int main()
{ 
    char fcar;
    int num, n1, n2;
    Pila p;
    char *tractar;
    char* c="chs";

    p = Crear(10);   //creem la pila
    FILE *f = fopen("input.txt", "r");     //Obrim el fitxer tipus txt
    

    fscanf (f, "%c", &fcar);    //llegim el primer caracter del fitxer
    while (!feof(f))        //mentre no arribem al final del fitxer operem
    {
        switch (fcar)
        {
        case '+':   //en cas de suma
            if (DosElemApilats(p))      //comprovem que tenim prous elements per operar
            {
                n1=Cim(p);          //Afagem els dos elements de la pila i posteriorment els desapilem
                Desapilar(&p);
                n2=Cim(p);
                Desapilar(&p);
                n1=n1+n2;           //operem i els tornem a apilar
                Apilar(&p,n1);
            }else
            {
                printf("operacio no valida\n");     //si no tenim prous elements no operem
            }
            fscanf (f, "%c", &fcar);     //llegim el seguent caracter del fitxer
            break;

        case '-':
            fscanf (f, "%c", &fcar); //llegim el seguent caracter per comprovar si es tracta de l'operacio o del signe

            if ((fcar>='0')&&(fcar<='9')) //en el cas de que siguin car numerics es tracta de signe
            {
                strncpy(tractar, "", strlen(tractar));   //posem l'string en blanc per eliminar posibles caracters residuals
                strncpy(tractar, &fcar, 1);     //Copiem el caracter a l'string
                fscanf (f, "%c", &fcar);
                while ((!feof(f))&&(fcar>='0')&&(fcar<='9')) //mentre trobem numeros anem concatenant
                {
                    strncat(tractar, &fcar, 1);
                    fscanf (f, "%c", &fcar);
                }
                num= atoi(tractar);  //fem un cast de char a int
                num=num*-1;         //li apliquem el negatiu
                strncpy(tractar, "", strlen(tractar));
                Apilar(&p, num);       //apilem
            }else
            {
                if (DosElemApilats(p))   //en el cas d'operació
                {
                    n1=Cim(p);
                    Desapilar(&p);
                    n2=Cim(p);
                    Desapilar(&p);
                    n1=n2-n1;
                    Apilar(&p,n1);
                }else
                {
                    printf("operacio no valida\n");
                }   
            }
            fscanf (f, "%c", &fcar);
            break;

        case '*':
            if (DosElemApilats(p))
            {
                n1=Cim(p);
                Desapilar(&p);
                n2=Cim(p);
                Desapilar(&p);
                n1=n1*n2;
                Apilar(&p,n1);
            }else
            {
                printf("operacio no valida\n");
            } 
            fscanf (f, "%c", &fcar);
            break;

        case '/':  
            if (DosElemApilats(p))
            {
                n1=Cim(p);
                Desapilar(&p);
                n2=Cim(p);
                Desapilar(&p);
                if (n1==0)  //comprovem que el divisor no sigui 0
                {
                    printf("No es pot dividir entre 0");
                    break;
                }
                n1=n2/n1;
                Apilar(&p,n1);
            }else
            {
                printf("operacio no valida\n");
            }    
            fscanf (f, "%c", &fcar);
            break;
        
        case 'c':
            strncpy(tractar, "", strlen(tractar));
            strncpy(tractar, &fcar, 1);
            for (int i = 0; i < 2; i++)     //guardem tots els caracters
            {
                fscanf (f, "%c", &fcar);
                strcat(tractar, &fcar);
            }
            if (strcmp(tractar,"chs")) //comparem si el que hem llegit es 'chs'
            {
                if (EsBuida(p))
                {
                    printf("operacio no valida\n");
                    break;
                }else
                {
                    n1=Cim(p);
                    Desapilar(&p);
                    n1=n1*-1;
                    Apilar(&p,n1);
                }              
            }
            fscanf (f, "%c", &fcar);
            break;

        case ',':
            fscanf (f, "%c", &fcar);
            break;
        
        default: //si no es tracta de cap dels casos anteriors llavors tractem com a numeros
            strncpy(tractar, "", strlen(tractar));
            strncpy(tractar, &fcar, 1);
            fscanf (f, "%c", &fcar);
            while ((!feof(f))&&(fcar>='0')&&(fcar<='9'))
            {
                strncat(tractar, &fcar, 1);
                fscanf (f, "%c", &fcar);
            }
            num= atoi(tractar);
            strncpy(tractar, "", strlen(tractar));
            Apilar(&p, num);
             
            break;
        }
    }
    if (DosElemApilats(p))  //si ens han quedat dos elements a la pila vol dir que no s'ha pogut operar
    {
        printf("el calcul no s'ha pogut realitzar\n");
    }else
    {
        Imprimir(p);
    }
    fclose(f);
}

