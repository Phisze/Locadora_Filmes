#include<stdio.h>
#include "../structs.h"
#include "../conFuncionario.h"
#include "../funcionarioDAO.h"
#include <string.h>

void funcionariomenu() {

    int x;

    do {
        printf("\tMENU FUNCIONARIO\n");
        printf("-------------------------------------------------------\n");
        printf("0. Sair do programa \n");
        printf("1. Salvar Funcionario \n"); //ok
        printf("2. Atualizar Funcionario \n"); //ok
        printf("3. Deletar Funcionario \n"); //(ñ deleta porem dá operação feita com sucesso)
        printf("4. Listar Funcionario \n"); //ok
        printf("5. Consultar Funcionario \n"); //ok
        printf("6. Voltar para o menu principal \n");
        printf("-------------------------------------------------------\n");
        printf("\tDigite uma das opções: \n");
        scanf("%d%*c", &x);
        fflush(stdin);
        printf("-------------------------------------------------------\n");
        switch (x) {
                //enceerra
            case 0:
                printf("SAINDO!");
                exit(1);
                break;
            case 1: //salva 
                salveFuncionario();
                break;

            case 2: //atualiza 
                attFuncionario();
                break;

            case 3: // deleta
                deletfuncionario();
                break;

            case 4: // Lista
                listaFunci();
                break;

            case 5://consulta
                consulteFuncionario();
                break;

            case 6: //Menu Principal
                menuPrincipal();
                break;
        }
    } while (x != 0);

}

void salveFuncionario() { //salva funcionario
    Funcionario funcionario;

    fflush(stdin); //limpa                       
    printf("Digite o nome do Funcinario: \n");
    scanf("%[^\n]%*c", funcionario.nome); //Até o usuario dar enter
    fflush(stdin); //limpa

    printf("Digite o cargo do funcionario: \n");
    scanf("%[^\n]%*c", funcionario.cargo); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o endereço completo: \n");
    scanf("%[^\n]%*c", funcionario.endereco); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o e-mail: \n");
    scanf("%[^\n]%*c", funcionario.email); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o Telefone: \n");
    scanf("%[^\n]%*c", funcionario.telefone); //Até o usuario dar enter
    fflush(stdin);

    mensagem_operacao(salvaFuncionario(&funcionario));
}

void attFuncionario() { //atualiza funionario
    Funcionario funcionario;
    Funcionario *p = listarFuncionarios();
    int tamanho = qtdFuncionario();
    float cod;
    printf("---------------------------------------------\n");
    printf("\t Digite o codigo do cliente que deseja atualizar:");
    scanf("%f%*c", &cod);
    fflush(stdin);
    printf("---------------------------------------------\n");
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {

            funcionario.codigo = cod;

            fflush(stdin); //limpa                       
            printf("Digite o nome do Funcinario: \n");
            scanf("%[^\n]%*c", p[i].nome); //Até o usuario dar enter
            strcpy(funcionario.nome, p[i].nome);
            fflush(stdin); //limpa

            printf("Digite o cargo do funcionario: \n");
            scanf("%[^\n]%*c", p[i].cargo); //Até o usuario dar enter
            strcpy(funcionario.cargo, p[i].cargo);
            fflush(stdin);

            printf("Digite o endereço completo: \n");
            scanf("%[^\n]%*c", p[i].endereco); //Até o usuario dar enter
            strcpy(funcionario.endereco, p[i].endereco);
            fflush(stdin);

            printf("Digite o e-mail: \n");
            scanf("%[^\n]%*c", p[i].email); //Até o usuario dar enter
            strcpy(funcionario.email, p[i].email);
            fflush(stdin);

            printf("Digite o Telefone: \n");
            scanf("%[^\n]%*c", p[i].telefone); //Até o usuario dar enter
            strcpy(funcionario.telefone, p[i].telefone);
            fflush(stdin);

            mensagem_operacao(atualizaFuncionario(funcionario));
        }
    }

}

void listaFunci() {

    Funcionario *j;
    j = listaFuncionarios(); //p vetor com todos os clientes 
    int tamanho = qtdFuncionario(); //quantidade de clientes do vetor

    for (int i = 0; i <= (tamanho - 1); i++) {
        if (j[i].deletado != '*') {
            printf("Codigo: %0.f \n Nome: %s\n Cargo: %s\n Endereço: %s\n Telefone: %s\n E-mail: %s \n____________________________________________\n", j[i].codigo, j[i].nome, j[i].cargo, j[i].endereco, j[i].telefone, j[i].email);
        }
    }
}

void consulteFuncionario() {
    //    Funcionario funcionario;
    //    Funcionario *p = listarFuncionarios();
    //int tamanho = qtdFuncionario();
    float cod;
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do clinte que deseja consultar: \n");
    scanf("%f%*c", &cod);
    Funcionario funcionario = consultarFuncionarios(cod);

    printf("-------------------------------------------------------\n");
    //    for (int i = 0; i <= tamanho; i++) {
    //        if (p[i].codigo == cod) {
    printf("Codigo: %0.f\n Nome: %s\n Cargo: %s\n Endereço: %s\n Telefone: %s\n E-mail: %s \n____________________________________________\n", funcionario.codigo, funcionario.nome, funcionario.cargo, funcionario.endereco, funcionario.telefone, funcionario.email);
    //  }

    //}

}

int deletfuncionario() {

    //    Funcionario funcionario;
    //    Funcionario *p = listarFuncionarios();
    //    int tamanho = qtdFuncionario();
    float cod;
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do clinte que deseja deletar: \n");
    scanf("%f%*c", &cod);
    printf("-------------------------------------------------------\n");
    //    for (int i = 0; i <= tamanho; i++) {
    //if (p[i].codigo == cod) {
    mensagem_operacao(deletaFuncionario(cod));
    //  break;

    //}

    //    }
}


