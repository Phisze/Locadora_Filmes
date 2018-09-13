#include "../../vector.h"
#include "../../structs.h"
#include "../../clienteDAO.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Funcao Inclusao 

void inclusaoCliente(Cliente c) {

    FILE *arq = fopen("cliente.pro", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return;
    }

    fwrite(&c, sizeof (c), 1, arq);
    fclose(arq);
}

Cliente * listarClientes() {
    Cliente c;
    Cliente clientes[100];
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("cliente.pro", "rb");
    printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return;
    }
    while (fread(&c, sizeof (c), 1, arq)) {
        if (c.deletado != '*') {

            for (int i = 0; i < sizeof (c); i++) {
                clientes[i] = c;
            }

            // VECTOR_ADD(clientes, c); 
            //            printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n", c.codigo, produtos.descricao, produtos.valor);
        }
    }
    fclose(arq);
    return clientes;
}

Cliente consultarClientes(int cod) {

    FILE *arq = fopen("cliente.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return;
    }

    Cliente c;

    //int cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%d", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if ((cod == c.codigo) && (c.deletado != '*')) {

            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            return c;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    return;
}

void alterarCliente(Cliente clintes, int cod) {
    FILE *arq = fopen("cliente.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return;
    }

    Cliente c;
    //int cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&clintes, sizeof (clintes), 1, arq);
            fseek(arq, sizeof (clintes)* 0, SEEK_END);
            return;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
}

void excluirCliente(int cod) {

    FILE *arq = fopen("produtos.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return;
    }

    Cliente c;
    //int cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%d", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                c.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
                fwrite(&c, sizeof (c), 1, arq);
                fseek(arq, sizeof (c)* 0, SEEK_END);
                return;
            } else if (certeza == 'n')
                return;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
}