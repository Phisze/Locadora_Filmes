/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ex_Importacao.c
 * Author: wever
 *
 * Created on 13 de Novembro de 2018, 14:49
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ex_ImporatacaoCliente.c
 * Author: wever
 *
 * Created on 13 de Novembro de 2018, 14:31
 */

#include <stdio.h>
#include <stdlib.h>
#include "../structs.h"
#include "../conCliente.h"

/*
 * 
 */

void importacaoCliente() {
    Cliente *c;
    c = listaClientes();
    FILE *arquivo;
    arquivo = fopen("importacaoCli.txt", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=cliente>\n");
    for (int i = 0; i < qtdCliente(); i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
        fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
        fprintf(arquivo, "         <cpf>%s</cpf>\n", c[i].cpf);
        fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
        fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
        fprintf(arquivo, "         <sexo>%c</sexo>\n", c[i].sexo);
        fprintf(arquivo, "         <estado_civil>%s</estado_civil>\n", c[i].estado_civil);
        fprintf(arquivo, "         <data_nascimento>%s</data_nascimento>\n", c[i].data_nascimento);
        fprintf(arquivo, "      </registro>\n");
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoCliente(int qtde) {
    FILE *arquivo;
    Cliente *c;
    arquivo = fopen("exportacaoCli.txt", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=cliente>\n");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
        fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
        fprintf(arquivo, "         <cpf>%s</cpf>\n", c[i].cpf);
        fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
        fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
        fprintf(arquivo, "         <sexo>%c</sexo>\n", c[i].sexo);
        fprintf(arquivo, "         <estado_civil>%s</estado_civil>\n", c[i].estado_civil);
        fprintf(arquivo, "         <data_nascimento>%s</data_nascimento>", c[i].data_nascimento);
        fprintf(arquivo, "      </registro>\n");
        salvaCliente(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

