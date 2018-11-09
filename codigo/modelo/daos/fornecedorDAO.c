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

int tamanhoFornecedors = 0;
int tamanhoFornecedorsListar = 0;
Fornecedor *Fornecedors;
int static tamanho = 0;
int static tamanhoTexto = 0;

//Funcao Inclusao 

int inclusaoFornecedor(Fornecedor f) {

    FILE *arq = fopen("fornecedor.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&f, sizeof (f), 1, arq);
    fclose(arq);
    tamanho = getTamanhoFornecedor();
    tamanho++;
    setTamanhoFornecedor(tamanho);
    return 1;

}

void inclusaoFornecedorTexto(Fornecedor f) {
    FILE *arquivo;
    arquivo = fopen("fornecedor.txt", "wt");
    fprintf(arquivo, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
    fclose(arquivo);
    tamanhoTexto = getTamanhoFornecedorTexto();
    tamanhoTexto++;
    setTamanhoFornecedorTexto(tamanhoTexto);
}

void insereFornecedorArrayDinamico(Fornecedor f) {
    tamanhoFornecedors++;
    Fornecedors = realloc(Fornecedors, tamanhoFornecedors * sizeof (Fornecedor));
    Fornecedors[tamanhoFornecedors - 1].codigo = f.codigo;
    strcpy(Fornecedors[tamanhoFornecedors - 1].nome, f.nome);
    strcpy(Fornecedors[tamanhoFornecedors - 1].endereco, f.endereco);
    strcpy(Fornecedors[tamanhoFornecedors - 1].razao_social, f.razao_social);
    strcpy(Fornecedors[tamanhoFornecedors - 1].telefone, f.telefone);
    strcpy(Fornecedors[tamanhoFornecedors - 1].email, f.email);
    strcpy(Fornecedors[tamanhoFornecedors - 1].inscricao_estadual, f.inscricao_estadual);
    strcpy(Fornecedors[tamanhoFornecedors - 1].cnpj, f.cnpj);
}

//Funções de Listar

Fornecedor* listarFornecedor() {
    int i = 0;
    Fornecedor f;
    Fornecedor *fw = &f;
    int cont = 0;
    Fornecedor *array = malloc((getTamanhoFornecedor() -1)* sizeof f);
    // VECTOR_INIT(v);
    FILE *arq = fopen("fornecedor.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&f, sizeof (f), 1, arq)) {
        if (f.deletado != '*') {

            // VECTOR_ADD(v,c);
            // array[i].nome = f.nome;
            array[i].codigo = f.codigo;
            strcpy(array[i].nome, f.nome);
            strcpy(array[i].endereco, f.endereco);
            strcpy(array[i].telefone, f.telefone);
            strcpy(array[i].email, f.email);
            strcpy(array[i].razao_social, f.razao_social);
            strcpy(array[i].inscricao_estadual, f.inscricao_estadual);
            strcpy(array[i].cnpj, f.cnpj);
            i++;
        } else {
            cont++;
            array = realloc(array, ((getTamanhoFornecedor() - 1) - cont) * sizeof (Fornecedor));
        }
    }
    fclose(arq);
    return array;
}

Fornecedor* ListarFornecedorTexto() {
    int i = 0;
    Fornecedor f;
    int cont = 0;
    FILE *arquivo;
    Fornecedor *array = malloc(getTamanhoFornecedor() * sizeof f);
    arquivo = fopen("fornecedor.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        if (f.deletado != '*') {
            array[i].codigo = f.codigo;
            strcpy(array[i].nome, f.nome);
            strcpy(array[i].endereco, f.endereco);
            strcpy(array[i].telefone, f.telefone);
            strcpy(array[i].email, f.email);
            strcpy(array[i].razao_social, f.razao_social);
            strcpy(array[i].inscricao_estadual, f.inscricao_estadual);
            strcpy(array[i].cnpj, f.cnpj);
            i++;
        } else {
            cont++;
            array = realloc(array, ((getTamanhoFornecedorTexto() - 1) - cont) * sizeof (Fornecedor));
        }
    }
    fclose(arquivo);
    return array;
}

Fornecedor* listarFornecedorArrayDinamico() {
    Fornecedor *array = malloc((tamanhoFornecedors - 1) * sizeof (Fornecedor));
    tamanhoFornecedors = tamanhoFornecedorsListar;
    int i;
    int j = 0;
    int cont = 0;
    for (i = 0; i < tamanhoFornecedors; i++) {
        if (Fornecedors[i].deletado != '*') {
            array[j].codigo = Fornecedors[i].codigo;
            strcpy(array[j].nome, Fornecedors[i].nome);
            strcpy(array[j].endereco, Fornecedors[i].endereco);
            strcpy(array[j].telefone, Fornecedors[i].telefone);
            strcpy(array[j].email, Fornecedors[i].email);
            strcpy(array[j].razao_social, Fornecedors[i].razao_social);
            strcpy(array[j].inscricao_estadual, Fornecedors[i].inscricao_estadual);
            strcpy(array[j].cnpj, Fornecedors[i].cnpj);
            j++;
        } else {
            cont++;
            tamanhoFornecedorsListar -= cont;
            array = realloc(array, (tamanhoFornecedorsListar) * sizeof (Fornecedor));
        }
    }
    //printf("Listar %c\n", array[0].sexo);

    return array;
}

//Funções de Consultar

Fornecedor consultarFornecedor(float cod) {

    FILE *arq = fopen("fornecedor.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Fornecedor v;
        return v;
    }

    Fornecedor f;

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
    Fornecedor v;
    return f;
}

Fornecedor ConsultarFornecedorTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("fornecedor.txt", "rt");
    Fornecedor f;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        if (f.codigo == cod && f.deletado != '*') {
            break;
        }
    }
    return f;
}

Fornecedor consultaFornecedorArrayDinamico(int cod) {
    if (Fornecedors[cod - 1].deletado != '*') {
        return Fornecedors[cod - 1];
    }
    return;
}

//Funções de Alteração

int alterarFornecedor(Fornecedor fornecedor, float cod) {
    FILE *arq = fopen("fornecedor.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Fornecedor f;
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if (cod == f.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", f.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Fornecedor)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&fornecedor, sizeof (fornecedor), 1, arq);
            fseek(arq, sizeof (fornecedor)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

void alterarFornecedorTexto(float cod, Fornecedor forn) {
    FILE *arquivo;
    FILE *arq;
    Fornecedor f;
    arquivo = fopen("fornecedor.txt", "rt");
    arq = fopen("fornecedorBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        if (cod == f.codigo && f.deletado != '*') {
            f.codigo = forn.codigo;
            strcpy(f.nome, forn.nome);
            strcpy(f.endereco, forn.endereco);
            strcpy(f.telefone, forn.telefone);
            strcpy(f.email, forn.email);
            strcpy(f.razao_social, forn.razao_social);
            strcpy(f.inscricao_estadual, forn.inscricao_estadual);
            strcpy(f.cnpj, forn.cnpj);
            fprintf(arq, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        } else {
            fprintf(arq, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("fornecedor.txt");
    rename("fornecedorBackup.txt", "fornecedor.txt");
}

void alterarFornecedorArrayDinamico(int cod, Fornecedor f) {
    Fornecedors[cod - 1].codigo = f.codigo;
    strcpy(Fornecedors[cod - 1].nome, f.nome);
    strcpy(Fornecedors[cod - 1].endereco, f.endereco);
    strcpy(Fornecedors[cod - 1].telefone, f.telefone);
    strcpy(Fornecedors[cod - 1].email, f.email);
    strcpy(Fornecedors[cod - 1].razao_social, f.razao_social);
    strcpy(Fornecedors[cod - 1].inscricao_estadual, f.inscricao_estadual);
    strcpy(Fornecedors[cod - 1].cnpj, f.cnpj);
    //printf("Alterar %c\n", Fornecedors[0].sexo);
}

//Funcções de exclusão

int excluirFornecedor(float cod) {

    FILE *arq = fopen("fornecedor.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Fornecedor f;
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
                fseek(arq, sizeof (Fornecedor)*-1, SEEK_CUR);
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

void excluirFornecedorTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Fornecedor f;
    arquivo = fopen("fornecedor.txt", "rt");
    arq = fopen("fornecedorBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        if (cod == f.codigo && f.deletado != '*') {
        } else {
            fprintf(arq, "%f %s %s %s %s %s %s %s\n", f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.endereco, f.telefone, f.email);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("fornecedor.txt");
    rename("fornecedorBackup.txt", "fornecedor.txt");
}

void excluirFornecedorArrayDinamico(int cod) {
    Fornecedors[cod - 1].deletado = '*';
}