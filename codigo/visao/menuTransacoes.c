#include<stdio.h>
#include <string.h>
#include<strings.h>
#include "../funcoesUteis.h"
#include "../conCliente.h"
#include "../conPersistencia.h"
#include "../conFilme.h"
#include"../conLocacaoFilme.h"
#include "VisaoCliente.h"
#include"../conFornecedor.h"

void menuTransacoes() {

    int x = 1;

    while (x != 0) {

        printf("\t MENU PRINCIPAL MÓDULO DE TRANSAÇOES:\n");
        printf("-------------------------------------------------------\n");
        printf("0. SAIR DO PROGRAMA\n ");
        printf("1. LOCAÇÃO DE FILMES \n");
        printf("2. DEVOLUÇÃO DE FILMES \n");
        printf("3. CONTAS A RECEBER \n");
        printf("4. ENTRADA DE FILMES \n");
        printf("5. CONTAS A PAGAR\n");
        printf("6. VOLTAR AO MENU PRINCIPAL \n\n");
        printf("-------------------------------------------------------\n");
        printf("Digite uma das opções: ");
        scanf("%d%*c", &x);
        printf("-------------------------------------------------------\n");

        switch (x) {

            case 1:
                loc_filme();
                break;
            case 2:
                devolver_filme();
                break;
            case 3:
                List_loc();
                break;
            case 4:
                Entrada_filmes();
                break;
            case 5:

                break;
            case 6:

                break;
        }
    }
}

void loc_filme() {

    Locacao locacao;

    printf("\t Cadastro de locação: \n");

    printf("1. Digite a quantidade de filmes a serem locados:");
    scanf("%[^\n]%*c", &locacao.qtde_Filmes_Locados);

    printf("2. Digite o tipo de pagamento: (à prazo = 0 / à vista = 1):");
    scanf("%d*c", &locacao.tipo);

    if (locacao.tipo == 0) {
        printf("2.1 Digite a quantidade de parcelas: ");
        //  scanf("%f%*c", &locacao.parcelas);
    }

    printf("3. Digite o valor da locação do filme: ");
    scanf("%f%*C", &locacao.valor);

    // mensagem_operacao(locaFilme(locacao));
}

void devolver_filme() {
    Locacao locacao;
    Locacao *p = listaLocacoes();
    int tamanho = qtdLocacao();
    float cod_1;
    float cod_2;
    printf("\t Devolução de filmes");
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do cliente que deseja esfetuar a entrega:");
    scanf("%f%*c", &cod_1);
    printf("-------------------------------------------------------\n");
    printf("Digite o codigo do filme que deseja esfetuar a entrega:");
    scanf("%f%*c", &cod_2);
    printf("-------------------------------------------------------\n");
    for (int i = 0; i <= tamanho; i++) {
        if ((p[i].cliCodigo == cod_1)&&((p[i].filCodigo1 == cod_2) || (p[i].filCodigo2 == cod_2) || (p[i].filCodigo3 == cod_2))) {
            mensagem_operacao(devolveFilmes(cod_1, cod_2));

            break;

        }
    }

}

void List_loc() {
    Locacao locacao;
    Locacao *p = listaLocacoes();
    int tamanho = qtdLocacao();
    printf("-------------------------------------------------------\n");
    for (int i = 0; i <= tamanho; i++) {

        printf("Codigo:%0.f \n Codigo do cliente: %0.f \n Codigo do Filme 1: %0.f\n Codigo do Filme 2: %0.f\n Codigo do Filme 3: %0.f"
                "Tipo de pagamento: %d \n Data de Nascimento: %s\n Valor da Parcela: %2.f \n Valor do pagamento: %2.f\n"
                "Quantidade da Parcela Inicial:%d \n Quantidade de parcelas:%d \n Quantidade de Filmes Locados:%d \n", p[i].codigo, p[i].cliCodigo,
                p[i].filCodigo1, p[i].filCodigo2, p[i].filCodigo3, p[i].tipo, p[i].data, p[i].valorParcela, p[i].valor, p[i].qtdParcelaInicial,
                p[i].qtdParcela, p[i].qtde_Filmes_Locados);
    }
}

void Entrada_filmes() {
    Fornecedor fornecedor;
    float cod, precoFrete, imposto;
    int qtdFilmes = 1, qtdfilme = 1;

    printf("\t Entrada de Filmes");
    printf("-------------------------------------------------------\n");

    printf("Digite o codigo do fornecedor de filmes:");
    scanf("%f%*c", &cod);
    printf("-------------------------------------------------------\n");
    fornecedor = consultaFornecedor(cod);
    printf("-------------------------------------------------------\n");
    printf("Digite o preço do frete: \n");
    scanf("%f%*c", &precoFrete);

    printf("Digite o valor do imposto: \n");
    scanf("%f%*c", &precoFrete);


    Filme *p = malloc(qtdfilme * sizeof (Filme));
    float *f = malloc(qtdfilme * sizeof (float));
    int *i = malloc(qtdfilme * sizeof (int));
    i[0] = 0;
    int op;
    do {
        float codfilme, qntfilme, CompraFilmes;
        printf("Digite o Codigo do Filme a ser comprado: ");
        scanf("%f%*c", &codfilme);

        printf("Digite o valor da compra do filmes:\n");
        scanf("%f%*c", &CompraFilmes);

        printf("Digite a quantidade de comprada desse filme:");
        scanf("%f%*c", &qntfilme);

        Filme filme = consultaFilme(codfilme);
        p[qtdfilme - 1] = filme;
        f[qtdfilme - 1] = CompraFilmes;
        i[qtdfilme - 1] = qntfilme;
        qtdfilme = qtdfilme + 1;



        printf("Deseja continua a comprar filmes? (0-não / 1-sim)");
        scanf("%d%*c", op);

    } while (op != 0);
    i = realloc(i, (qtdfilme) * sizeof (int));
    i[qtdfilme - 1] = 0;
    mensagem_operacao(conEntraFilme(fornecedor, precoFrete, imposto, p, f, i));
}
