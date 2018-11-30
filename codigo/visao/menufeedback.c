#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>
#include "VisaoCliente.h"
#include "../feedback.h"

void menufeedback() {

    int x = 1;

    while (x != 0) {

        printf("\t MENU PRINCIPAL MÓDULO DE FEEDBACK:\n\n");
        printf("-------------------------------------------------------\n");
        printf("0.  SAIR DO PROGRAMA ");
        printf("1.  RELATÓRIOS DE CLIENTES\n");
        printf("2.  RELATÓRIOS DE FILMES \n");
        printf("3.  RELATÓRIOS DE QUANTIDADE RESTANTE DE FILMES\n");
        printf("4.  RELATÓRIOS DE LOCAÇÕES\n");
        printf("5.  RELATÓRIOS DE CONTAS A RECEBER \n");
        printf("6.  RELATÓRIOS DE CONTAS A PAGAR \n");
        printf("7.  RELATÓRIOS DE MOVIMENTAÇÃO DE CAIXA\n");
        printf("8.  VOLTAR AO MENU INICIAL\n");
        printf("-------------------------------------------------------\n");
        printf("Digite uma das opções: ");
        scanf("%d%*c", &x);
        printf("-------------------------------------------------------\n");
        switch (x) {

            case 1:
                relatrio();
                break;
            case 2:
                relat_filme();
                break;
            case 3:

                break;
            case 4:
                relat_loc();
                break;
            case 5:
                relat_cont_receber();
                break;
            case 6:
                relat_cont_pagar();
                break;
            case 7:
                mov_caixa();
                break;
        }
    }
}

void relatrio() {
    Cliente cliente;
    Cliente cliente2;

    float cod_1, cod_2;
    printf("\t RELATÓRIO DE CLIENTES VIA CODIGO:");
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do clinte no qual deseja iniciar a listagem:\n");
    scanf("%f%*c", &cod_1);
    printf("Digite o codigo do clinte no qual deseja terminar a listagem:\n");
    scanf("%f%*c", &cod_2);
    printf("-------------------------------------------------------\n");

    Cliente *p = clienteCodigoFeedback(cod_1, cod_2);
    int contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Nome: %s \n Endereço: %s \n CPF: %s \n Telefone: %s \n E-mail: %s \n Sexo: %c\n Estado civil: %s \n Data de Nascimento: %s \n________________________________________________\n", p[contador].codigo, p[contador].nome, p[contador].endereco, p[contador].cpf, p[contador].telefone, p[contador].email, p[contador].sexo, p[contador].estado_civil, p[contador].data_nascimento);
        contador = contador + 1;
    }
    printf("-------------------------------------------------------\n");


    printf("\t RELATÓRIO DE CLIENTES VIA SEXO:");
    printf("-------------------------------------------------------\n");
    printf("Digite o sexo que deseja listar (M para masculino/ F para feminino:");
    scanf("%c%*c", &cliente.sexo);
    printf("-------------------------------------------------------\n");

    p = clienteSexoFeedback(cliente.sexo);
    contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Nome: %s \n Endereço: %s \n CPF: %s \n Telefone: %s \n E-mail: %s \n Sexo: %c\n Estado civil: %s \n Data de Nascimento: %s \n________________________________________________\n", p[contador].codigo, p[contador].nome, p[contador].endereco, p[contador].cpf, p[contador].telefone, p[contador].email, p[contador].sexo, p[contador].estado_civil, p[contador].data_nascimento);
        contador = contador + 1;
    }
    printf("-------------------------------------------------------\n");
}

void relat_filme() {
    Filme filme;
    float cod_1, cod_2;
    printf("\t RELATÓRIO DE FILMES VIA CODIGO:");
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do Filme no qual deseja iniciar a listagem:\n");
    scanf("%f%*c", &cod_1);
    printf("Digite o codigo do Filme no qual deseja terminar a listagem:\n");
    scanf("%f%*c", &cod_2);
    printf("-------------------------------------------------------\n");

    Filme *p = filmeCodigoFeedback(cod_1, cod_2);
    int contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Descrição: %s \n Quantidade de exemplares: %0.f \n Código da categoria: %0.f \n Lingua: %s\n --------------------------------------------------\n", p[contador].codigo, p[contador].descricao, p[contador].exemplares, p[contador].catCodigo, p[contador].lingua);
        contador = contador + 1;
    }
    printf("-------------------------------------------------------\n");

}

void qtd_filme_restante() {


}

void relat_loc() {
    int d;

    float cod;
    printf("\t RELATÓRIO DE LOCAÇOES VIA À PRAZO OU À VISTA:");
    printf("-------------------------------------------------------\n");
    printf("Digite se desejar a listagem (à prazo = 0 / à vista = 1):\n");
    scanf("%d%*c", &d);
    printf("-------------------------------------------------------\n");

    Locacao *p = locacoesCodigoFeedback(d);
    int contador = 0;
    while (p[contador].codigo != -1) {
    //    printf("Codigo: %0.f \n Nome: %s \n Endereço: %s \n CPF: %s \n Telefone: %s \n E-mail: %s \n Sexo: %c\n Estado civil: %s \n Data de Nascimento: %s \n________________________________________________\n", p[contador].codigo, p[contador].nome, p[contador].endereco, p[contador].cpf, p[contador].telefone, p[contador].email, p[contador].sexo, p[contador].estado_civil, p[contador].data_nascimento);
        contador = contador + 1;
    }
    printf("-------------------------------------------------------\n");
    printf("\t RELATÓRIO DE LOCAÇOES VIA CLIENTE:");
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do cliente");
    scanf("%f%*c", &cod);
    printf("-------------------------------------------------------\n");

    p = locacoesNomeFeedback(consultaCliente(cod));
    contador = 0;
    while (p[contador].codigo != -1) {
 //       printf("Codigo: %0.f \n Nome: %s \n Endereço: %s \n CPF: %s \n Telefone: %s \n E-mail: %s \n Sexo: %c\n Estado civil: %s \n Data de Nascimento: %s \n________________________________________________\n", p[contador].codigo, p[contador].nome, p[contador].endereco, p[contador].cpf, p[contador].telefone, p[contador].email, p[contador].sexo, p[contador].estado_civil, p[contador].data_nascimento);
        contador = contador + 1;
    }


}

void relat_cont_receber() {
    char data_1[10];
    char data_2[10];
    float cod_1, cod_2;
    printf("\t RELATÓRIO DE CONTAS A RECEBER VIA DATA:");
    printf("-------------------------------------------------------\n");
    printf("As datas devem ser apresentas no formato:\n \t dd/mm/aaaa\n");
    printf("-------------------------------------------------------\n");
    printf("Digite a data inicial para a listagem: \n");
    scanf("%[^\n]%*c", &data_1);
    printf("-------------------------------------------------------\n");
    printf("Digite a data final para a listagem: \n");
    scanf("%[^\n]%*c", &data_1);
    printf("-------------------------------------------------------\n");

    Locacao *p = contasReceberDataFeedback(data_1, data_2);
    int contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Codigo cliente: %0.f \n Valor: %0.f \n Quantidade de Parcelas: %d \n Valor da Parcela: %0.f \n Tipo:(0=A receber ou 1 = A pagar) %d \n Data da locação: %s\n Quantidade de filmes locados: %d \n________________________________________________\n", p[contador].codigo, p[contador].cliCodigo, p[contador].valor, p[contador].qtdParcela, p[contador].valorParcela, p[contador].tipo, p[contador].data, p[contador].qtde_Filmes_Locados);
        contador = contador + 1;
    }

    printf("\t RELATÓRIO DE CONTAS A RECEBER VIA CODIGO DO CLIENTE:");
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo cliente inicial para a listagem: \n");
    scanf("%f%*c", &cod_1);
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo final para a listagem: \n");
    scanf("%%*c", &cod_2);
    printf("-------------------------------------------------------\n");

    Conta *pi = contasReceberCodigoFeedback(cod_1, cod_2);
    contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Codigo cliente: %0.f \n Valor: %0.f \n Quantidade de Parcelas: %d \n Valor da Parcela: %0.f \n Tipo:(0=A receber ou 1 = A pagar) %d \n Data da locação: %s\n Quantidade de filmes locados: %d \n________________________________________________\n", pi[contador].codigo, pi[contador].cliCodigo, pi[contador].valor, pi[contador].qtdParcela, pi[contador].valorParcela, pi[contador].tipo, pi[contador].data);
        contador = contador + 1;
    }

}

void relat_cont_pagar() {
    char data_1[10];
    char data_2[10];
    float cod_1, cod_2;

    printf("\t RELATÓRIO DE CONTAS A PAGAR VIA DATA:");
    printf("-------------------------------------------------------\n");
    printf("As datas devem ser apresentas no formato:\n \t dd/mm/aaaa\n");
    printf("-------------------------------------------------------\n");
    printf("Digite a data inicial para a listagem: \n");
    scanf("%[^\n]%*c", &data_1);
    printf("-------------------------------------------------------\n");
    printf("Digite a data final para a listagem: \n");
    scanf("%[^\n]%*c", &data_1);
    printf("-------------------------------------------------------\n");

    Conta *p = contasPagarDataFeedback(data_1, data_2);
    int contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Codigo cliente: %0.f \n Valor: %0.f \n Quantidade de Parcelas: %d \n Valor da Parcela: %0.f \n Tipo:(0=A receber ou 1 = A pagar) %d \n Data da locação: %s\n________________________________________________\n", p[contador].codigo, p[contador].cliCodigo, p[contador].valor, p[contador].qtdParcela, p[contador].valorParcela, p[contador].tipo, p[contador].data);
        contador = contador + 1;
    }


    printf("\t RELATÓRIO DE CONTAS A RECEBER VIA CODIGO DA CONTA :");
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo cliente inicial para a listagem: \n");
    scanf("%f%*c", &cod_1);
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo final para a listagem: \n");
    scanf("%%*c", &cod_2);
    printf("-------------------------------------------------------\n");
    p = contasPagarCodigoFeedback(cod_1, cod_2);
    contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Codigo cliente: %0.f \n Valor: %0.f \n Quantidade de Parcelas: %d \n Valor da Parcela: %0.f \n Tipo:(0=A receber ou 1 = A pagar) %d \n Data da locação: %s \n________________________________________________\n", p[contador].codigo, p[contador].cliCodigo, p[contador].valor, p[contador].qtdParcela, p[contador].valorParcela, p[contador].tipo, p[contador].data);
        contador = contador + 1;
    }


}

void mov_caixa() {
    char data_1[10];
    char data_2[10];
    printf("\t RELATÓRIO DE CONTAS MOVIMENTAÇÃO DE CAIXA:");
    printf("-------------------------------------------------------\n");
    printf("As datas devem ser apresentas no formato:\n \t dd/mm/aaaa\n");
    printf("-------------------------------------------------------\n");
    printf("Digite a data inicial para a listagem: \n");
    scanf("%[^\n]%*c", data_1);
    printf("-------------------------------------------------------\n");
    printf("Digite a data final para a listagem: \n");
    scanf("%[^\n]%*c", data_1);
    printf("-------------------------------------------------------\n");
    printf("\t Contas a pagar");
    Conta *p = contasPagarDataFeedback(data_1, data_2);
    int contador = 0;
    while (p[contador].codigo != -1) {
        printf("Codigo: %0.f \n Codigo cliente: %0.f \n Valor: %0.f \n Quantidade de Parcelas: %d \n Valor da Parcela: %0.f \n Tipo:(0=A receber ou 1 = A pagar) %d \n Data da locação: %s\n________________________________________________\n", p[contador].codigo, p[contador].cliCodigo, p[contador].valor, p[contador].qtdParcela, p[contador].valorParcela, p[contador].tipo, p[contador].data);
        contador = contador + 1;
    }
    printf("\t Contas a receber");
    Locacao *pi = contasReceberDataFeedback(data_1, data_2);
    contador = 0;
    while (pi[contador].codigo != -1) {
        printf("Codigo: %0.f \n Codigo cliente: %0.f \n Valor: %0.f \n Quantidade de Parcelas: %d \n Valor da Parcela: %0.f \n Tipo:(0=A receber ou 1 = A pagar) %d \n Data da locação: %s\n________________________________________________\n", pi[contador].codigo, pi[contador].cliCodigo, pi[contador].valor, pi[contador].qtdParcela, pi[contador].valorParcela, pi[contador].tipo, pi[contador].data);
        contador = contador + 1;
    }


}