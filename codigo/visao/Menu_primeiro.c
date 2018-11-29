#include<stdio.h>
#include <string.h>
#include<strings.h>

void Menu_primeiro() {

    int x=1;

    while (x!=0) {
        printf("\t MENU PRINCIPAL:\n\n");
        printf("-------------------------------------------------------\n");     
        printf("0. SAIR DO PROGRAMA \n");
        printf("1. MENU DE CADASTRO E GESTÃO DE DADOS:\n");
        printf("2. MENU DE MÓDULO DE TRANSAÇÕES \n");
        printf("3. MENU MÓDULO FEEDBACK\n");
        printf("4. MENU MÓDULO IMPORTAÇÃO/EXPORTAÇÃO DE DADOS \n");
        printf("5. MENU LOCAÇÂO DE FILMES \n");
        printf("-------------------------------------------------------\n");         
        printf("\tDigite uma das opções: ");
         __fpurge(stdin);
        scanf("%d%*c",&x);
         __fpurge(stdin);
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
        //      locacao_filme();
                break;
        }
    }
}