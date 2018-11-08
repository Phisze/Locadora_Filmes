#include "../../vector.h"
#include "../../structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../../tamanho.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Funcao Inclusao 

int inclusaoFuncionarios(Funcionario f) {
    FILE *arq = fopen("funcionario.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&f, sizeof (f), 1, arq);
    fclose(arq);
    int tamanho = getTamanhoFuncionario();
    tamanho++;
    setTamanhoFuncionario(tamanho);
    return 1;

}

void inclusaoFuncionarioTexto(Funcionario f) {
    FILE *arquivo;
    arquivo = fopen("funcionario.txt", "wt");
    fprintf(arquivo, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
    fclose(arquivo);
}

//Funções de Listar

Funcionario* listarFuncionarios() {
    int i = 0;

    Funcionario f;
    Funcionario *fw = &f;
    Funcionario *array = malloc(getTamanhoFuncionario() * sizeof f);
    FILE *arq = fopen("funcionario.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&f, sizeof (f), 1, arq)) {
        if (f.deletado != '*') {

            // VECTOR_ADD(v,c);
            // array[i].nome = c.nome;
            array[i].codigo = f.codigo;
            strcpy(array[i].nome, f.nome);
            strcpy(array[i].endereco, f.endereco);
            strcpy(array[i].telefone, f.telefone);
            strcpy(array[i].email, f.email);
            strcpy(array[i].cargo, f.cargo);
            i++;
        }
    }
    fclose(arq);
    return array;
}

Funcionario* ListarFuncionarioTexto() {
    int i = 0;
    Funcionario f;
    FILE *arquivo;
    Funcionario *array = malloc(getTamanhoFuncionario() * sizeof f);
    arquivo = fopen("funcionario.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        if (f.deletado != '*') {
            array[i].codigo = f.codigo;
            strcpy(array[i].nome, f.nome);
            strcpy(array[i].endereco, f.endereco);
            strcpy(array[i].telefone, f.telefone);
            strcpy(array[i].email, f.email);
            strcpy(array[i].cargo, f.cargo);
            i++;
        }
    }
    fclose(arquivo);
    return array;
}

//Funções de Consultar

Funcionario consultarFuncionarios(float cod) {

    FILE *arq = fopen("funcionario.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Funcionario v;
        return v;
    }

    Funcionario f;

    //float cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if ((cod == f.codigo) && (f.deletado != '*')) {

            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            break;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    Funcionario v;
    return f;
}

Funcionario ConsultarFuncionarioTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("funcionario.txt", "rt");
    Funcionario f;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        if (f.codigo == cod && f.deletado != '*') {
            break;
        }
    }
    return f;
}

//Funções de Alteração

int alterarFuncionarios(Funcionario funcionario, float cod) {
    FILE *arq = fopen("funcionario.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Funcionario f;
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if (cod == f.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Funcionario)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&funcionario, sizeof (funcionario), 1, arq);
            fseek(arq, sizeof (funcionario)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

void alterarFuncionarioTexto(float cod, Funcionario fun) {
    FILE *arquivo;
    FILE *arq;
    Funcionario f;
    arquivo = fopen("funcionario.txt", "rt");
    arq = fopen("funcionarioBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        if (cod == f.codigo && f.deletado != '*') {
            f.codigo = f.codigo;
            strcpy(f.nome, fun.nome);
            strcpy(f.endereco, fun.endereco);
            strcpy(f.telefone, fun.telefone);
            strcpy(f.email, fun.email);
            strcpy(f.cargo, fun.cargo);
            fprintf(arq, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        } else {
            fprintf(arq, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("funcionario.txt");
    rename("funcionarioBackup.txt", "funcionario.txt");
}

//Funcções de exclusão
int excluirFuncionarios(float cod) {

    FILE *arq = fopen("funcionario.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Funcionario f;
    //float cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if (cod == f.codigo) {
            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                f.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Funcionario)*-1, SEEK_CUR);
                fwrite(&f, sizeof (f), 1, arq);
                fseek(arq, sizeof (f)* 0, SEEK_END);
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

void excluirFuncionarioTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Funcionario f;
    arquivo = fopen("funcionario.txt", "rt");
    arq = fopen("funcionarioBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        if (cod == f.codigo && f.deletado != '*') {
        } else {
            fprintf(arq, "%f %s %s %s %s %s\n", f.codigo, f.nome, f.cargo, f.endereco, f.telefone, f.email);
        }
    }
    fclose(arquivo);
    fclose(arq);
remove("funcionario.txt");
    rename("funcionarioBackup.txt", "funcionario.txt");
}