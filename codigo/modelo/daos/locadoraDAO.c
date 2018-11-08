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

void inclusaoLocadoraTexto(Locadora l) {
    FILE *arquivo;
    arquivo = fopen("locadora.txt", "wt");
    fprintf(arquivo, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
    fclose(arquivo);
}

//Funções de Listar

Locadora* listarLocadora() {
    int i = 0;

    Locadora l;
    Locadora *fw = &l;
    Locadora *array = malloc(getTamanhoLocadora() * sizeof l);
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
            i++;
        }
    }
    fclose(arq);
    return array;
}

Locadora* ListarLocadoraTexto() {
    int i = 0;
    Locadora l;
    FILE *arquivo;
    Locadora *array = malloc(getTamanhoLocadora() * sizeof l);
    arquivo = fopen("locadora.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        if (l.deletado != '*') {
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
            i++;
        }
    }
    fclose(arquivo);
    return array;
}

//Funções de Consultar

Locadora consultarLocadora(float cod) {

    FILE *arq = fopen("locadora.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Locadora v;
        return v;
    }

    Locadora l;

    //float cod;
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

Locadora ConsultarLocadoraTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("locadora.txt", "rt");
    Locadora l;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        if (l.codigo == cod && l.deletado != '*') {
            break;
        }
    }
    return l;
}

//Funções de Alteração

int alterarLocadora(Locadora locadora, float cod) {
    FILE *arq = fopen("locadora.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locadora l;
    //float cod, 
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

void alterarLocadoraTexto(float cod, Locadora loc) {
    FILE *arquivo;
    FILE *arq;
    Locadora l;
    arquivo = fopen("locadora.txt", "rt");
    arq = fopen("locadoraBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        if (cod == l.codigo && l.deletado != '*') {
            l.codigo = loc.codigo;
            strcpy(l.nome, loc.nome);
            strcpy(l.endereco, loc.endereco);
            strcpy(l.telefone, loc.telefone);
            strcpy(l.email, loc.email);
            strcpy(l.razao_social, loc.razao_social);
            strcpy(l.inscricao_estadual, loc.inscricao_estadual);
            strcpy(l.cnpj, loc.cnpj);
            strcpy(l.nome_responsavel, loc.nome_responsavel);
            strcpy(l.tel_responsavel, loc.tel_responsavel);
            fprintf(arq, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        } else {
            fprintf(arq, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("locadora.txt");
    rename("locadoraBackup.txt", "locadora.txt");
}

//Funcções de exclusão
int excluirLocadora(float cod) {

    FILE *arq = fopen("locadora.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locadora l;
    //float cod, 
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

void excluirLocadoraTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Locadora l;
    arquivo = fopen("locadora.txt", "rt");
    arq = fopen("locadoraBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        if (cod == l.codigo && l.deletado != '*') {
        } else {
            fprintf(arq, "%f %s %s %s %s %s %s %s %s %s\n", l.codigo, l.nome, l.razao_social, l.inscricao_estadual, l.cnpj, l.endereco, l.telefone, l.email, l.nome_responsavel, l.tel_responsavel);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("locadora.txt");
    rename("locadoraBackup.txt", "locadora.txt");
}