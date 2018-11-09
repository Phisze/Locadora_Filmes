#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>
#include "VisaoCliente.h"

void MenuPrincipal_1() {

    int x;

    while (x!=5) {
        printf("\t MENU PRINCIPAL:\n\n");
        printf("-------------------------------------------------------\n");     
        printf("0. SAIR DO PROGRAMA \n");
        printf("1. MENU DE CADASTRO E GESTÃO DE DADOS:\n");
        printf("2. MENU DE MÓDULO DE TRANSAÇÕES \n");
        printf("3.  MENU MÓDULO FEEDBACK");
        printf("4. MENU MÓDULO IMPORTAÇÃO/EXPORTAÇÃO DE DADOS \n");
        printf("-------------------------------------------------------\n");         
        printf("Digite uma das opções: ");
        printf("-------------------------------------------------------\n");      

        switch (x) {
            
            case 1:
                menuPrincipal();
                break;
            case 2:
               
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
        }
    }
}