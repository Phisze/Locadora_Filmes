#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>

void menuPrincipal(){
    
    int x;
    printf("Digite uma das opções: ");
    scanf("%d",&x);
    
    do{    
        printf("MENU PRINCIPAL:\n");
        printf("1. LOCADORA \n");
        printf("2. CLIENTE \n");
        printf("3. FILMES \n");
        printf("4. FUNCIONARIOS \n");
        printf("5. FORNECEDORES \n");
        printf("6. SAIR DO PROGRAMA \n");



        switch (x){
            case 1: 
                break;
            case 2:
                clientemenu();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }while(x != 6);      
}