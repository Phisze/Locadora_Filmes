//#include <stdio.h>
//#include <string.h>
//#include"../structs.h"
//#include"locacao_filme.h"
//#include "VisaoCliente.h"
//
//void locacao_filme() {
//
//    int x=1;
//
//    do {
//        printf("-------------------------------------------------------\n");
//        printf("\t MENU LOCAÇÂO DE FILMES\n");
//        printf("-------------------------------------------------------\n");       
//        printf("0. Sair do programa \n");
//        printf("1. Locar filme \n"); 
//        printf("2. Voltar para o menu principal \n");
//        printf("-------------------------------------------------------\n");       
//        printf("\t Digite uma das opções: ");
//        scanf("%d%*c", &x);
//        printf("-------------------------------------------------------\n");       
//
//        switch (x) {
//
//            //enceerra
//            case 0:
//                printf("SAINDO!");
//                exit(1);
//                break;
//            case 1: //salva clientes
//                loc_filme();
//                break;
//            case 2: //Menu Principal
//                menuPrincipal();
//                break;
//        }
//    } while (x != 0);
//
//}
//void loc_filme(){
//    
//    Locacao locacao;
//    
//    printf("\t Cadastro de locação: \n");
//    
//    printf("1. Digite a quantidade de filmes a serem locados:");
//    scanf("%[^\n]%*c", &locacao.qtde_Filmes_Locados);
//    
//    printf("2. Digite o tipo de pagamento: (à prazo = 0 / à vista = 1):");
//    scanf("%d*c",&locacao.tipo);
//    
//   if (locacao.tipo == 0){ 
//    printf("2.1 Digite a quantidade de parcelas: ");
//    scanf("%f%*c", &locacao.parcelas);
//   }
//    
//    printf("3. Digite o valor da locação do filme: ");
//    scanf("%f%*C", &locacao.valor);
//   
//}
