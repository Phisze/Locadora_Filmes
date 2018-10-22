#include "../../vector.h"
#include "../../structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tamanho.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Funcao Inclusao 

int inclusaoLocadora(Locadora l) {
    //printf("codcodcod %f ", f.codigo);
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    //FILE *arq = fopen("..\\..\\..\\..\\cliente.pro", "ab");
    FILE *arq = fopen("locadora.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&l, sizeof (l), 1, arq);
    fclose(arq);
    int tamanho = getTamanhoLocadora();
    tamanho++;
    setTamanhoLocadora(tamanho);
    return 1;

}

Locadora* listarLocadora() {
    int i = 0;

    Locadora l;
    Locadora *fw = &l;
    Locadora *array = malloc(getTamanhoLocadora() * sizeof l);
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("locadora.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&l, sizeof (l), 1, arq)) {
        if (l.deletado != '*') {

            // VECTOR_ADD(v,c);
            // array[i].nome = c.nome;
            array[i].codigo = l.codigo;
            strcpy(array[i].nome, l.nome);
            strcpy(array[i].endereco, l.endereco);
            strcpy(array[i].telefone, l.telefone);
            strcpy(array[i].email, l.email);
            strcpy(array[i].razao_social, l.razao_social);
            strcpy(array[i].inscricao_estadual, l.inscricao_estadual);
            strcpy(array[i].cnpj, l.cnpj);
            strcpy(array[i].nome_responsavel, l.nome_responsavel);
            strcpy(array[i].tel_responsavel, l.tel_responsavel);

            // }
            //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

            //VECTOR_ADD(clientes, cw);
            //printf("Cod %s\n", c.nome);
            i++;
        }
    }
    fclose(arq);
    return array;
}

Locadora consultarLocadora(int cod) {

    FILE *arq = fopen("locadora.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Locadora v;
        return v;
    }

    Locadora l;

    //int cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if ((cod == l.codigo) && (l.deletado != '*')) {

            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            return l;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    Locadora v;
    return v;
}

int alterarLocadora(Locadora locadora, int cod) {
    FILE *arq = fopen("locadora.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locadora l;
    //int cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if (cod == l.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Locadora)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&locadora, sizeof (locadora), 1, arq);
            fseek(arq, sizeof (locadora)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

int excluirLocadora(int cod) {

    FILE *arq = fopen("locadora.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locadora l;
    //int cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if (cod == l.codigo) {
            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                l.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Locadora)*-1, SEEK_CUR);
                fwrite(&l, sizeof (l), 1, arq);
                fseek(arq, sizeof (l)* 0, SEEK_END);
                return 1;
            } else if (certeza == 'n')
                return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}