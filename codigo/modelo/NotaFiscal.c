/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

//int i = 0;

void notaFical(Fornecedor f, float frete, float imposto, Filme fil, float qtd, Conta c) {
    FILE *arquivo;
    float somador = 0;
    float somadorQTD = 0;
    float total = 0;
    float finalFrete = 0;
    float finalImposto = 0;
    arquivo = fopen("notaFiscal.txt", "rt");
    fprintf(arquivo, "Fornecedor: %s \n", f.nome);
    fprintf(arquivo, "CNPJ:  %s \n", f.cnpj);
    fprintf(arquivo, "Frete:  %.2f \t Imposto\n", frete, imposto);
    fprintf(arquivo, " \t\t Filmes \n");
    //for
    total = c.valor * qtd;
    fprintf(arquivo, "Descrição: %s | Preço: %.2f | Quantidade: %.2f | Total: %.2f \n", fil.descricao, c.valor, qtd, total);
    somador += total;
    somadorQTD += qtd;
    //}
    finalFrete = frete / somadorQTD;
    finalImposto = imposto / somadorQTD;
    fprintf(arquivo, "Total Nota(Filmes + Frete + Imposto): %d\n", finalFrete + finalImposto + total);
    fclose(arquivo);
}