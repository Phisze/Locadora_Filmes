/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

int inclusaoFilmes(Filme f) {
    FILE *arq = fopen("filme.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&f, sizeof (f), 1, arq);
    fclose(arq);
    int tamanho = getTamanhoFilme();
    tamanho++;
    setTamanhoFilme(tamanho);
    return 1;
}

void inclusaoFilmeTexto(Filme f) {
    FILE *arquivo;
    arquivo = fopen("filme.txt", "wt");
    fprintf(arquivo, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
    fclose(arquivo);
}

//Funções de Listar

Filme* listarFilmes() {
    int i = 0;

    Filme f;
    Filme *fw = &f;
    Filme *array = malloc(getTamanhoFilme() * sizeof f);
    // VECTOR_INIT(v);
    FILE *arq = fopen("filme.pro", "rb");
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
            strcpy(array[i].descricao, f.descricao);
            array[i].exemplares = f.exemplares;
            strcpy(array[i].lingua, f.lingua);
            // }
            //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

            //printf("Cod %s\n", c.nome);
            i++;
        }
    }
    fclose(arq);
    return array;
}

Filme* ListarFilmesTexto() {
    int i = 0;
    Filme f;
    FILE *arquivo;
    Filme *array = malloc(getTamanhoFilme() * sizeof f);
    arquivo = fopen("filme.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        if (f.deletado != '*') {
            array[i].codigo = f.codigo;
            strcpy(array[i].descricao, f.descricao);
            array[i].exemplares = f.exemplares;
            strcpy(array[i].lingua, f.lingua);
            i++;
        }
    }
    fclose(arquivo);
    return array;
}

//Funções de Consultar

Filme consultarFilmes(float cod) {
    FILE *arq = fopen("filme.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Filme v;
        return v;
    }

    Filme f;

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
    Filme v;
    return f;
}

Filme ConsultarFilmesTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("filme.txt", "rt");
    Filme f;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        if (f.codigo == cod && f.deletado != '*') {
            break;
        }
    }
    return f;
}

//Funções de Alteração

int alterarFilmes(Filme filme, float cod) {
    FILE *arq = fopen("filme.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Filme f;
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if (cod == f.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Filme)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&filme, sizeof (filme), 1, arq);
            fseek(arq, sizeof (filme)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

void alterarFilmeTexto(float cod, Filme fil) {
    FILE *arquivo;
    FILE *arq;
    Filme f;
    arquivo = fopen("filme.txt", "rt");
    arq = fopen("filmeBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        if (cod == f.codigo && f.deletado != '*') {
            f.codigo = fil.codigo;
            strcpy(f.descricao, fil.descricao);
            f.exemplares = fil.exemplares;
            strcpy(f.lingua, fil.lingua);
            fprintf(arq, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        } else {
            fprintf(arq, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("filme.txt");
    rename("filmeBackup.txt", "filme.txt");
}

//Funcções de exclusão

int excluirFilmes(float cod) {
    FILE *arq = fopen("filme.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Filme f;
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
                fseek(arq, sizeof (Filme)*-1, SEEK_CUR);
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

void excluirFilmeTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Filme f;
    arquivo = fopen("filme.txt", "rt");
    arq = fopen("filmeBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        if (cod == f.codigo && f.deletado != '*') {
        } else {
            fprintf(arq, "%f %s %f %f %s\n", f.codigo, f.descricao, f.exemplares, f.catCodigo, f.lingua);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("filme.txt");
    rename("filmeBackup.txt", "filme.txt");
}