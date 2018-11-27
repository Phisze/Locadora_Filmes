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
int tamanhoCategorias = 0;
int tamanhoCategoriasListar = 0;
Categoria *Categorias; //=  malloc(sizeof (Categoria));
int static tamanho = 0;
int static tamanhoTexto = 0;

void criaArrayCategoria() {
    Categorias = malloc(sizeof (Categoria));
}

//Funções de Inclusão 

int inclusaoCategoria(Categoria c) {
    //printf("codcodcod %f ", c.codigo);

    FILE *arq = fopen("categoria.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&c, sizeof (c), 1, arq);
    fclose(arq);
    tamanho = getTamanhoCategoria();
    tamanho++;
    setTamanhoCategoria(tamanho);
    return 1;
}

int inclusaoCategoriaTexto(Categoria c) {
    FILE *arquivo;
    arquivo = fopen("categoria.txt", "a");
    fprintf(arquivo, "%f %s %f \n", c.codigo, c.descricao, c.valor_locacao);
    fclose(arquivo);
    tamanhoTexto = getTamanhoCategoriaTexto();
    tamanhoTexto++;
    setTamanhoCategoriaTexto(tamanhoTexto);
    return 1;
}

int insereCategoriaArrayDinamico(Categoria c) {
    tamanhoCategorias++;
    Categorias = realloc(Categorias, tamanhoCategorias * sizeof (Categoria));
    Categorias[tamanhoCategorias - 1].codigo = c.codigo;
    Categorias[tamanhoCategorias - 1].valor_locacao = c.valor_locacao;
    return 1;
}

//Funções de Listar

Categoria* listarCategoria() {
    int i = 0;

    Categoria c;
    Categoria *cw = &c;
    Categoria *array = malloc((getTamanhoCategoria()) * sizeof (Categoria));
    // VECTOR_INIT(v);
    FILE *arq = fopen("categoria.pro", "rb");
    //printf("Arquivo xistente!");
    //    int cont = 0;
    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&c, sizeof (c), 1, arq)) {
        //  if (c.deletado != '*') {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        array[i].codigo = c.codigo;
        strcpy(array[i].descricao, c.descricao);
        array[i].valor_locacao = c.valor_locacao;
        array[i].deletado = c.deletado;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //printf("Cod %s\n", c.nome);
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoCategoria() - 1) - cont) * sizeof (Categoria));
        //        };
    }
    fclose(arq);
    return array;
}

Categoria* ListarCategoriaTexto() {
    int i = 0;
    Categoria c;
    int cont = 0;
    FILE *arquivo;
    Categoria *array = malloc(getTamanhoCategoria() * sizeof c);
    //catente c;
    arquivo = fopen("categoria.txt", "rt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f \n", &c.codigo, &c.descricao, &c.valor_locacao);
        // if (c.deletado != '*') {
        array[i].codigo = c.codigo;
        strcpy(array[i].descricao, c.descricao);
        array[i].valor_locacao = c.valor_locacao;
        i++;
        //        } else {;
        //            cont++;
        //            array = realloc(array, ((getTamanhoCategoriaTexto() - 1) - cont) * sizeof (Categoria));
        //        }
    }
    fclose(arquivo);
    return array;
}

Categoria* listarCategoriaArrayDinamico() {
    //    Categoria *array = malloc((tamanhoCategorias) * sizeof (Categoria));
    //    tamanhoCategorias = tamanhoCategoriasListar;
    //    int i;
    //    int j = 0;
    //    int cont = 0;
    //    for (i = 0; i < tamanhoCategorias; i++) {
    //    //    if (Categorias[i].deletado != '*') {
    //            array[j].codigo = Categorias[i].codigo;
    //            strcpy(array[j].descricao, Categorias[i].descricao);
    //            array[j].valor_locacao = Categorias[i].valor_locacao;
    //            j++;
    //        } else {
    //            cont++;
    //            tamanhoCategoriasListar -= cont;
    //            array = realloc(array, (tamanhoCategoriasListar) * sizeof (Categoria));
    //        };
    //  }
    //printf("Listar %c\n", array[0].sexo);
    return Categorias;
}

//Funções de Consultar

Categoria consultarCategoria(float cod) {
    FILE *arq = fopen("categoria.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Categoria v;
        return v;
    }

    Categoria c;

    //float cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%f", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if ((cod == c.codigo) && (c.deletado != '*')) {

            // printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            break;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    Categoria v;
    return c;
}

Categoria ConsultarCategoriaTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("categoria.txt", "rt");
    Categoria c;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f \n", &c.codigo, &c.descricao, &c.valor_locacao);
        if (c.codigo == cod && c.deletado != '*') {
            break;
        }
    }
    return c;
}

Categoria consultaCategoriaArrayDinamico(int cod) {
    if (Categorias[cod - 1].deletado != '*') {
        return Categorias[cod - 1];
    }
    return;
}

//Funções de Alteração

int alterarCategoria(Categoria categoria, float cod) {
    FILE *arq = fopen("categoria.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Categoria c;
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%f", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Categoria)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&categoria, sizeof (categoria), 1, arq);
            fseek(arq, sizeof (categoria)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

int alterarCategoriaTexto(float cod, Categoria cat) {
    FILE *arquivo;
    FILE *arq;
    Categoria c;
    arquivo = fopen("categoria.txt", "rt");
    arq = fopen("categoriaBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f \n", c.codigo, c.descricao, c.valor_locacao);
        if (cod == c.codigo && c.deletado != '*') {
            c.codigo = cat.codigo;
            strcpy(c.descricao, cat.descricao);
            c.valor_locacao = cat.valor_locacao;

            fprintf(arq, "%f %s %f \n", c.codigo, c.descricao, c.valor_locacao);
        } else {
            fprintf(arq, "%f %s %f \n", c.codigo, c.descricao, c.valor_locacao);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("categoria.txt");
    rename("categoriaBackup.txt", "categoria.txt");
    return 1;
}

int alterarCategoriaArrayDinamico(int cod, Categoria c) {
    Categorias[cod - 1].codigo = c.codigo;
    strcpy(Categorias[cod - 1].descricao, c.descricao);
    Categorias[cod - 1].valor_locacao = c.valor_locacao;
    //printf("Alterar %c\n", Categorias[0].sexo);
    return 1;
}

//Funcções de exclusão

int excluirCategoria(float cod) {
    FILE *arq = fopen("categoria.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Categoria c;
    //float cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%f", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //  printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                c.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Categoria)*-1, SEEK_CUR);
                fwrite(&c, sizeof (c), 1, arq);
                fseek(arq, sizeof (c)* 0, SEEK_END);
                //return 1;
            }
        }
    }


    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

int excluirCategoriaTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Categoria c;
    arquivo = fopen("categoria.txt", "rt");
    arq = fopen("categoriaBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f \n", c.codigo, c.descricao, c.valor_locacao);
        if (cod == c.codigo && c.deletado != '*') {
        } else {
            fprintf(arq, "%f %s %f \n", c.codigo, c.descricao, c.valor_locacao);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("categoria.txt");
    rename("categoriaBackup.txt", "categoria.txt");
    tamanhoTexto = getTamanhoCategoriaTexto();
    tamanhoTexto--;
    setTamanhoCategoriaTexto(tamanhoTexto);
    return 1;
}

int excluirCategoriaArrayDinamico(int cod) {
    Categorias[cod - 1].deletado = '*';
    return 1;
}