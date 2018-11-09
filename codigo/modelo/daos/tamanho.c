/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../../vector.h"
#include "../../structs.h"
#include "../../clienteDAO.h"
#include "../../filmeDAO.h"
#include "../../categoriaDAO.h"
#include "../../fornecedorDAO.h"
#include "../../filmeDAO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setTamanhoCliente(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoCli.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoCli.pro");

    FILE *arqB = fopen("tamanhoCli.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoCliente() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoCli.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;

}

void setTamanhoClienteTexto(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoClitxt.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoClitxt.pro");

    FILE *arqB = fopen("tamanhoClitxt.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoClienteTexto() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoClitxt.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;

}

void setTamanhoFilme(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoFil.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoFil.pro");

    FILE *arqB = fopen("tamanhoFil.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoFilme() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoFil.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoFilmeTexto(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoFiltxt.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoFiltxt.pro");

    FILE *arqB = fopen("tamanhoFiltxt.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoFilmeTexto() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoFiltxt.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoCategoria(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoCat.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoCat.pro");

    FILE *arqB = fopen("tamanhoCat.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoCategoria() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoCat.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoCategoriaTexto(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoCattxt.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoCattxt.pro");

    FILE *arqB = fopen("tamanhoCattxt.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoCategoriaTexto() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoCattxt.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoFornecedor(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoFor.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoFor.pro");

    FILE *arqB = fopen("tamanhoFor.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoFornecedor() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoFor.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoFornecedorTexto(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoFor.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoFortxt.pro");

    FILE *arqB = fopen("tamanhoFortxt.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoFornecedorTexto() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoFortxt.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoFuncionario(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoFun.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoFun.pro");

    FILE *arqB = fopen("tamanhoFun.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoFuncionario() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoFun.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoFuncionarioTexto(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoFuntxt.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoFuntxt.pro");

    FILE *arqB = fopen("tamanhoFuntxt.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoFuncionarioTexto() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoFuntxt.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoLocadora(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoLoc.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoLoc.pro");

    FILE *arqB = fopen("tamanhoLoc.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoLocadora() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoLoc.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}

void setTamanhoLocadoraTexto(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("tamanhoLoctxt.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("tamanhoLoctxt.pro");

    FILE *arqB = fopen("tamanhoLoctxt.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoLocadoraTexto() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("tamanhoLoctxt.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        tamanho = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return tamanho;
}