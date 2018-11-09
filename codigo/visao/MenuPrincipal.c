#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>
#include "VisaoCliente.h"

void menuPrincipal() {

    int x=1;

    while (x!=0) {
        
        printf("\t MENU PRINCIPAL DE CADASTRO E GESTÃO DE DADOS:\n\n");
        printf("---------------------------------------------\n");
        printf("0. SAIR DO PROGRAMA \n");
        printf("1. LOCADORA \n");
        printf("2. CLIENTE \n");
        printf("3. FILMES \n");
        printf("4. FUNCIONARIOS \n");
        printf("5. FORNECEDORES \n");
        printf("6. VOLTAR AO MENU PRINCIPAL \n\n");
        printf("---------------------------------------------\n");
        printf("Digite uma das opções: ");
        scanf("%d%*c",&x);
        printf("---------------------------------------------\n");        

        switch (x) {
            
            case 0:
                printf("SAINDO!");
                break;
            case 1:
               // locadoraMenu();
                break;
            case 2:
                clientemenu();
                break;
            case 3:
                filmeMenu();
                break;
            case 4:
                funcionariomenu();
                break;
            case 5:
                fornecedorMenu();
                break;
            case 6:
                ;
                break;
        }
    }
}