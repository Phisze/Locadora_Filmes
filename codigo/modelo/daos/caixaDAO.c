#include "caixaDAO.h"
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

int setCaixa(float caixa) {
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    FILE *arq = fopen("caixa.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
    }

    remove("caixa.pro");

    FILE *arqB = fopen("caixa.pro", "wb");

    fwrite(&caixa, sizeof (caixa), 1, arqB);
    fclose(arqB);
    return 1;
}

float getCaixa() {

    float c;
    float caixa;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("caixa.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        // printf("Arquivo inexistente!");

        return 0;
    }
    while (fread(&c, sizeof (c), 1, arq)) {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        caixa = c;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
    }
    fclose(arq);
    return caixa;

}

int inclusaoCaixaTexto(float caixa) {
    FILE *arquivo;
    arquivo = fopen("caixa.txt", "a");
    remove("caixa.txt");
    //
    fclose(arquivo);
    FILE *arq = fopen("caixa.txt", "a");
    fprintf(arq, "%f\n", caixa);
    fclose(arq);

    return 1;
}

float ListarCaixaTexto() {
    int i = 0;
    float c;
    float caixa = 0;
    FILE *arquivo;
    //catente c;
    arquivo = fopen("caixa.txt", "rt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %f \n", &caixa);
        // if (c.deletado != '*') {
        c=caixa;
        i++;
        //        } else {;
        //            cont++;
        //            array = realloc(array, ((getTamanhoCategoriaTexto() - 1) - cont) * sizeof (Categoria));
        //        }
    }
    fclose(arquivo);
    return c;
}
