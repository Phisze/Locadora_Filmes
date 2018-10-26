//#include<stdio.h>
//#include "../conCliente.h"
////#include "../codigo/conCliente.h"
//#include "../structs.h"
//#include "../clienteDAO.h"
//#include <string.h>
//
//void categoriamenu() {
//    int x;
//
//    do {
//
//        printf("0. Sair do programa \n");
//        printf("1. Salvar Categoria\n");
//        printf("2. Atualizar Categoria \n");
//        printf("3. Deletar Categoria \n");
//        printf("4. Listar Categoria \n");
//        printf("5. Consultar Categoria \n");
//        printf("6. Voltar para o menu principal \n");
//
//        printf("Digite uma das opções: \n");
//        scanf("%d%*c", &x);
//
//        switch (x) {
//
//            case 1: //salva categoria
//                salveCategoria();
//                break;
//
//            case 2: //atualizar categoria
//                attCategoria();
//                break;
//
//            case 3: // deleta categoria 
//                break;
//
//            case 4: // Listar categoria
//                listaCategoria();
//                break;
//
//            case 5: //consulta categoria 
//                consulteCategoria();
//                break;
//
//            case 6: //Menu Principal
//                menuPrincipal();
//                break;
//        }
//    } while (x != 0);
//
//}
//
//void salveclient() {
//    Categoria categoria;
//
//    fflush(stdin); //limpa                       
//    printf("Digite o nome: \n");
//    scanf("%[^\n]%*c", categoria.descricao); //Até o usuario dar enter
//    fflush(stdin); //limpa
//
//    printf("Digite o valor da locação: \n");
//    scanf("%f*c", &categoria.valor_locacao); 
//    fflush(stdin);
//
//    mensagem_operacao(salvaCategoria(&categoria));
//}
//
//void listaClie() {
//
//    Categoria *p = lCategoria(); //p vetor com todos os clientes 
//    int tamanho = qtdCategoria(); //quantidade de clientes do vetor
//
//    for (int i = 0; i <= tamanho; i++) {
//        if (p[i].deletado != '*') { //Não mostrar os deletados
//            printf("Descrição: %s, Valor: %0f", p[i].descricao, p[i].valor_locacao);
//    }
//}
//
//void attCategoria() {
//
//    Categoria categoria;
//    Categoria *p = lCategoria(); //p vetor com todos os clientes 
//    int tamanho = qtdCategoria(); //quantidade de clientes do vetor
//    float cod;
//
//    printf("Digite o codigo do cliente que deseja atluaizar: ");
//    scanf("%f", &cod);
//
//    for (int i = 0; i <= tamanho; i++) {
//        if (p[i].codigo == cod) {
//            
//            fflush(stdin); //limpa                       
//            printf("Digite o nome: \n");
//            scanf("%[^\n]%*c", categoria.descricao); //Até o usuario dar enter
//            strcpy(categoria.descricao, p[i].descricao);
//            fflush(stdin); //limpa
//
//            printf("Digite o valor da locação: \n");
//            scanf("%f*c", p[i].valor_locacao);
//            categoria.valor_locacao = p[i].valor_locacao;
//            fflush(stdin);
//
//            mensagem_operacao(salvaCategoria(&categoria));  
//            
//        }
//    }
//} 
//
//void consulteCategoria() {
//
//    Categoria categoria;
//    Categoria *p = lCategoria(); //p vetore com todos os clientes 
//    int tamanho = qtdCategoria(); //quantidade de clientes do vetor
//    float cod;
//
//    printf("Digite o codigo do clinte que deseja atualizar: \n");
//    scanf("%f", &cod);
//
//    for (int i = 0; i <= tamanho; i++) {
//        if (p[i].codigo == cod) { //Não mostrar os deletados
//           printf("Descrição: %s, Valor: %0f", p[i].descricao, p[i].valor_locacao);
//        } else
//            printf("Clinte Inexistente!");
//    }
//
//}
//}
//
//void deletCategoria() {
//
//    Categoria categoria;
//    Categoria *p = lCategoria(); //p vetor com todos os clientes 
//    int tamanho = qtdCategoria(); //quantidade de clientes do vetor
//    float cod;
//
//    printf("Digite o codigo do clinte que deseja deletar: \n");
//    scanf("%f", &cod);
//
//    for (int i = 0; i <= tamanho; i++) {
//        if (p[i].codigo == cod) {
//
//        }
//    }
//
//
//}
//        
