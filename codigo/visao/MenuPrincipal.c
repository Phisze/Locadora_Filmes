#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>

#include "VisaoCliente.h"

void menuPrincipal() {

    int x;

    while (x!=6) {
        printf("MENU PRINCIPAL:\n");
        printf("1. LOCADORA \n");
        printf("2. CLIENTE \n");
        printf("3. FILMES \n");
        printf("4. FUNCIONARIOS \n");
        printf("5. FORNECEDORES \n");
        printf("6. SAIR DO PROGRAMA \n");

        
        printf("Digite uma das opções: ");
        scanf("%d%*c",&x);

        switch (x) {
            
            case 1:
                locadoraMenu();
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
        }
    }
}