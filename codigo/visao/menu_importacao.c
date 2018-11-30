#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>
#include "VisaoCliente.h"
#include "../conImportacao.h"

void menuim() {

    int x = 1;

    while (x != 0) {

        printf("\t MENU MÓDULO IMPORTAÇÃO/EXPORTAÇÃO DE DADOS:\n\n");
        printf("-------------------------------------------------------\n");
        printf("0.  SAIR DO PROGRAMA ");
        printf("1.  IMPORTAR CLIENTE\n");
        printf("2.  EXPORTAR CLIENTE \n");
        printf("3.  IMPORTAR FILME\n");
        printf("4.  EXPORTAR FILME\n");
        printf("5.  IMPORTAR CATEGORIA\n");
        printf("6.  EXPORTAR CATEGORIA \n");
        printf("7.  IMPORTAR FUNCIONARIOS \n");
        printf("8.  EXPORTAR FUNCIONARIO\n");
        printf("9.  IMPORTAR FORNECEDOR\n");
        printf("10.  EXPORTAR FORNECEDOR \n");
        printf("11.  IMPORTAR LOCADORA\n");
        printf("12.  EXPORTAR LOCADORA\n");
        printf("-------------------------------------------------------\n");
        printf("Digite uma das opções: ");
        scanf("%d%*c", &x);
        printf("-------------------------------------------------------\n");
        int qnt;
        switch (x) {

            case 1:
                importaCliente();
                break;
            case 2:
                
                scanf("%d%*c",&qnt);
                exportaCliente(qnt);
                break;
            case 3:
                importaFilme();
                break;
            case 4:
               
                scanf("%d%*c",&qnt);
                exportaFilme(qnt);
                break;
            case 5:
                importaCategoria();
                break;
            case 6:
             
                scanf("%d%*c",&qnt);
                exportaCategoria(qnt);
                break;
            case 7:
                importaFuncionario();
                break;
            case 8:
           
                scanf("%d%*c",&qnt);
                exportaFuncionario(qnt);
                break;
            case 9:
                importaFornecedor();
                break;
            case 10:
                
                scanf("%d%*c",&qnt);
                exportaFornecedor(qnt);
                break;
            case 11:
                importaLocadora();
                break;
            case 12:
             
                scanf("%d%*c",&qnt);
                exportaLocadora(qnt);
                break;
             
                
        }
    }
}
