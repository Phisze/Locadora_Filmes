/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../structs.h"
#include "../conFilme.h"
#include "../funcoesUteis.h"
//int i = 0;

void notaFiscal(Fornecedor f, float frete, float imposto, Filme *fil, float *qtd, float *valor) {
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
    int i = 0;
    //DEIXA MEUS COMENTÁRIO EM PAZ
    //Qtd 0 indica que para de ler por que no fim do vetor tem que vir esse 0
    while (qtd[i] != 0) {
        total = valor[i] * qtd[i];
        fprintf(arquivo, "Descrição: %s | Preço: %.2f | Quantidade: %.2f | Total: %.2f \n", fil[i].descricao, qtd[i], valor[i], total);
        somador += total;
        somadorQTD += qtd[i];
        
 
        
        i++;
    }
    finalFrete = frete / somadorQTD;
    finalImposto = imposto / somadorQTD;
    fprintf(arquivo, "Total Nota(Filmes + Frete + Imposto): %d\n", finalFrete + finalImposto + total);
    fclose(arquivo);
    float valorCaixa=0.0;
    valorCaixa=valorCaixa-(finalFrete+finalImposto+total);
    movimentaCaixa(valorCaixa);
}