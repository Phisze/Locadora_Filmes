#include<stdio.h>
#include "../conCliente.h"
//#include "../codigo/conCliente.h"
#include "../structs.h"
#include "../clienteDAO.h"
#include <string.h>

void clientemenu() {

    int x;

    do {
        printf("\t MENU CLIENTE\n");
        printf("---------------------------------------------\n");       
        printf("0. Sair do programa \n");
        printf("1. Salvar Cliente \n");
        printf("2. Atualizar Cliente \n");
        printf("3. Deletar Cliente \n");
        printf("4. Listar cliente \n");
        printf("5. Consultar cliente \n");
        printf("6. Voltar para o menu principal \n");
        printf("---------------------------------------------\n");        
        printf("\t Digite uma das opções: \n");
        scanf("%d%*c", &x);
        printf("---------------------------------------------\n");        

        switch (x) {

            case 0:
                printf("SAINDO!");
                break;
            case 1: //salva clientes
                salvecli();
                break;

            case 2: //atualizar cliente 
                attCli();
                break;

            case 3: // deletar cliente
                break;

            case 4: // Listar cliente
                listaCli();
                break;

            case 5:
                consulteCli();
                break;

            case 6: //Menu Principal
                menuPrincipal();
                break;
        }
    } while (x != 0);

}

int mensagem_operacao(int cod) {

    if (cod == 1)
        printf("Opereção feita com sucesso!\n");
    else {
        printf("Operação não realizada com sucesso!\n");
    }
}

void salvecli() {
    Cliente cliente;

    fflush(stdin); //limpa                       
    printf("Digite o nome: \n");
    scanf("%[^\n]%*c", cliente.nome); //Até o usuario dar enter
    fflush(stdin); //limpa

    printf("Digite o endereço: \n");
    scanf("%[^\n]%*c", cliente.endereco); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o CPF: \n");
    scanf("%[^\n]%*c", cliente.cpf); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o Telefone: \n");
    scanf("%[^\n]%*c", cliente.telefone); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o e-mail: \n");
    scanf("%[^\n]%*c", cliente.email); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o sexo F para femino e M para masculino: \n");
    scanf("%c%*c", &cliente.sexo); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite Estado Civil: \n");
    scanf("%[^\n]%*c", cliente.estado_civil); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o Ano de nascimento: \n");
    scanf("%[^\n]%*c", cliente.data_nascimento); //Até o usuario dar enter
    fflush(stdin);

    mensagem_operacao(salvaCliente(&cliente));
}

void listaCli() {

    Cliente *p = lClientes(); //p vetor com todos os clientes 
    int tamanho = qtdCliente(); //quantidade de clientes do vetor

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].deletado != '*') { //Não mostrar os deletados
            printf("Codigo: %0f, \t| Nome: %s, \t| Endereço: %s, \t| CPF: %s, \t| Telefone: %s, \t| E-mail: %s, \t| Sexo: %c,\t| Estado civil: %s, \t| Data de Nascimento: %s. \n", p[i].codigo, p[i].nome, p[i].endereco, p[i].cpf, p[i].telefone, p[i].email, p[i].sexo, p[i].estado_civil, p[i].data_nascimento);
        }
    }
}

void attCli() {

    Cliente cliente;
    Cliente *p = lClientes(); //p vetor com todos os clientes 
    int tamanho = qtdCliente(); //quantidade de clientes do vetor
    float cod;

    printf("Digite o codigo do cliente que deseja atluaizar: ");
    scanf("%f", &cod);

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {

            fflush(stdin); //limpa                       
            printf("Digite o nome: \n");
            scanf("%[^\n]%*c", p[i].nome); //Até o usuario dar enter
            strcpy(cliente.nome, p[i].nome); //concatenação
            fflush(stdin); //limpa

            printf("Digite o endereço: \n");
            scanf("%[^\n]%*c", p[i].endereco); //Até o usuario dar enter
            strcpy(cliente.endereco, p[i].endereco); //concatenação
            fflush(stdin);

            printf("Digite o CPF: \n");
            scanf("%[^\n]%*c", p[i].cpf); //Até o usuario dar enter
            strcpy(cliente.cpf, p[i].cpf); //concatenação
            fflush(stdin);

            printf("Digite o Telefone: \n");
            scanf("%[^\n]%*c", p[i].telefone); //Até o usuario dar enter
            strcpy(cliente.telefone, p[i].telefone); //concatenação
            fflush(stdin);

            printf("Digite o e-mail: \n");
            scanf("%[^\n]%*c", p[i].email); //Até o usuario dar enter
            strcpy(cliente.email, p[i].email); //concatenação
            fflush(stdin);

            printf("Digite o sexo F para femino e M para masculino: \n");
            scanf("%c%*c", p[i].sexo); //Até o usuario dar enter
            strcpy(cliente.sexo, p[i].sexo); //concatenação
            fflush(stdin);

            printf("Digite Estado Civil: \n");
            scanf("%[^\n]%*c", p[i].estado_civil); //Até o usuario dar enter
            strcpy(cliente.estado_civil, p[i].estado_civil); //concatenação
            fflush(stdin);

            printf("Digite o Ano de nascimento: \n");
            scanf("%[^\n]%*c", p[i].data_nascimento); //Até o usuario dar enter
            strcpy(cliente.data_nascimento, p[i].data_nascimento); //concatenação
            fflush(stdin);

        }

        mensagem_operacao(atualizaCliente(&cliente));
    }
}

void consulteCli() {

    Cliente cliente;
    Cliente *p = lClientes(); //p vetor com todos os clientes 
    int tamanho = qtdCliente(); //quantidade de clientes do vetor
    float cod;

    printf("Digite o codigo do clinte que deseja atualizar: \n");
    scanf("%f", &cod);

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) { //Não mostrar os deletados
            printf("Codigo: %0f,\t| Nome: %s,\t| Endereço: %s,\t| CPF: %s,\t| Telefone: %s,\t| E-mail: %s,\t| Sexo: %c,\t| Estado civil: %s,\t| Data de Nascimento: %s. \n", p[i].codigo, p[i].nome, p[i].endereco, p[i].cpf, p[i].telefone, p[i].email, p[i].sexo, p[i].estado_civil, p[i].data_nascimento);
        } else
            printf("Clinte Inexistente!");
    }
    mensagem_operacao(consultaCliente(&cliente));

}

int deletCli() {

    Cliente cliente;
    Cliente *p = lClientes(); //p vetor com todos os clientes 
    int tamanho = qtdCliente(); //quantidade de clientes do vetor
    float cod;
    printf("---------------------------------------------\n");  
    printf("\t Digite o codigo do clinte que deseja deletar: \n");
    scanf("%f", &cod);
    printf("---------------------------------------------\n");  
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
            mensagem_operacao(deletaCliente(p[i].codigo));
            break;

        }else
            printf("Clinte Inexistente!");
    }
}   