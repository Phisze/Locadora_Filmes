//#include<stdio.h>
//#include "../filmeDAO.h"
//#include "../structs.h"
//#include "../conFilme.h"
//#include <string.h>
//
//void funcionariomenu() {
//
//    int x;
//
//    do {
//
//        printf("0. Sair do programa \n");
//        printf("1. Salvar Funcionario \n");
//        printf("2. Atualizar Funcionario \n");
//        printf("3. Deletar Funcionario \n");
//        printf("4. Listar Funcionario \n");
//        printf("5. Consultar Funcionario \n");
//        printf("6. Voltar para o menu principal \n");
//
//        printf("Digite uma das opções: \n");
//        scanf("%d%*c", &x);
//
//        switch (x) {
//
//            case 1: //salva clientes
//                salveFuncionario();
//                break;
//
//            case 2: //atualizar cliente 
//                attFuncionario();
//                break;
//
//            case 3: // deletar cliente
//                break;
//
//            case 4: // Listar cliente
//                listaFuncionario();
//                break;
//
//            case 5:
//                consulteFuncionario();
//                break;
//
//            case 6: //Menu Principal
//                menuPrincipal();
//                break;
//        }
//    } while (x != 0);
//
//}
//void salveFuncionario() {
//    Funcionario funcionario;
//
//    fflush(stdin); //limpa                       
//    printf("Digite o nome do Funcinario: \n");
//    scanf("%[^\n]%*c", funcionario.nome); //Até o usuario dar enter
//    fflush(stdin); //limpa
//
//    printf("Digite o cargo do funcionario: \n");
//    scanf("%[^\n]%*c", funcionario.cargo); //Até o usuario dar enter
//    fflush(stdin);
//
//    printf("Digite o endereço completo: \n");
//    scanf("%[^\n]%*c", funcionario.endereco); //Até o usuario dar enter
//    fflush(stdin);
//
//    printf("Digite o e-mail: \n");
//    scanf("%[^\n]%*c", funcionario.email); //Até o usuario dar enter
//    fflush(stdin);
//    
//    printf("Digite o Telefone: \n");
//    scanf("%[^\n]%*c", funcionario.telefone); //Até o usuario dar enter
//    fflush(stdin);
//
//    mensagem_operacao(salvaFuncionario(&funcionario));
//}
//
//void attFuncionario(){
//    Funcionario funcionario;
//    Funcionario *p = lFuncionario();
//    int tamanho = qtdFuncionario();
//    float cod;
//    
//    for (int i = 0; i <= tamanho; i++) {
//        if (p[i].codigo == cod) {
//            
//            fflush(stdin); //limpa                       
//            printf("Digite o nome do Funcinario: \n");
//            scanf("%[^\n]%*c", p[i].nome); //Até o usuario dar enter
//            strcpy(funcionario.nome, p[i].nome);
//            fflush(stdin); //limpa
//
//            printf("Digite o cargo do funcionario: \n");
//            scanf("%[^\n]%*c", p[i].cargo); //Até o usuario dar enter
//            strcpy(funcionario.cargo, p[i].cargo);
//            fflush(stdin);
//
//            printf("Digite o endereço completo: \n");
//            scanf("%[^\n]%*c", p[i].endereco); //Até o usuario dar enter
//            strcpy(funcionario.endereco, p[i].endereco);
//            fflush(stdin);
//
//            printf("Digite o e-mail: \n");
//            scanf("%[^\n]%*c", p[i].email); //Até o usuario dar enter
//            strcpy(funcionario.email,p[i].email);
//            fflush(stdin);
//
//            printf("Digite o Telefone: \n");
//            scanf("%[^\n]%*c", p[i].telefone); //Até o usuario dar enter
//            strcpy(funcionario.telefone, p[i].telefone);
//            fflush(stdin);
//
//         mensagem_operacao(salvaFuncionario(&funcionario));   
//        }
//    }
//    
//  }
//
//void listaClie() {
//
//    Cliente *p = lClientes(); //p vetor com todos os clientes 
//    int tamanho = qtdCliente(); //quantidade de clientes do vetor
//
//    for (int i = 0; i <= tamanho; i++) {
////        if (p[i].deletado != '*') { //Não mostrar os deletados
////            printf("Codigo: %0f, Nome: %s, Cargo: %s, Endereço: %s, Telefone: %s, E-mail: %s \n", p[i].codigo, p[i].nome,p[i].cargo, p[i].endereco, p[i].telefone, p[i].email);
////        }
//    }
//}
//
//void consulteFuncionario() {
//
//    Funcionario funcionario;
//    Funcionario *p = lFuncionario();
//    int tamanho = qtdFuncionario();
//    float cod;
//
//    printf("Digite o codigo do clinte que deseja atualizar: \n");
//    scanf("%f", &cod);
//
//    for (int i = 0; i <= tamanho; i++) {
//        if (p[i].codigo == cod) { //Não mostrar os deletados
//            printf("Codigo: %0f, Nome: %s, Cargo: %s, Endereço: %s, Telefone: %s, E-mail: %s \n", p[i].codigo, p[i].nome,p[i].cargo, p[i].endereco, p[i].telefone, p[i].email);
//        } else
//            printf("Clinte Inexistente!");
//    }
//
//}
//int deletCliente() {
//    
//    Funcionario funcionario;
//    Funcionario *p = lFuncionario();
//    int tamanho = qtdFuncionario();
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
