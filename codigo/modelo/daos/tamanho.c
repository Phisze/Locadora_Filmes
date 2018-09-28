/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../../vector.h"
#include "../../structs.h"
#include "../../clienteDAO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setTamanhoCliente(int tamanho) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("..\\..\\..\\..\\tamanhoCli.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("..\\..\\..\\..\\tamanhoCli.pro");

    FILE *arqB = fopen("..\\..\\..\\..\\tamanhoCli.pro", "wb");

    fwrite(&tamanho, sizeof (tamanho), 1, arqB);
    fclose(arqB);
}

int getTamanhoCliente() {

    int c;
    int tamanho;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("..\\..\\..\\..\\tamanhoCli.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
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