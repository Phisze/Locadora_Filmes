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
#include "../clienteDAO.h"

/*
 * 
 */

void importacaoCliente() {
    Cliente *c;
    c = listaClientes();
    FILE *arquivo;
    arquivo = fopen("importacaoCli.txt", "wt");
    fprintf(arquivo, "<dados>");
    fprintf(arquivo, "   <tabela=cliente>");
    for (int i = 0; i < qtdCliente(); i++) {
        fprintf(arquivo, "      <registro>");
        fprintf(arquivo, "         <codigo>%f</codigo>", c.codigo);
        fprintf(arquivo, "         <nome>%s</nome>", c.nome);
        fprintf(arquivo, "         <endereco>%s</endereco>", c.endereco);
        fprintf(arquivo, "         <cpf>%s</cpf>", c.cpf);
        fprintf(arquivo, "         <telefone>%s</telefone>", c.telefone);
        fprintf(arquivo, "         <email>%s</email>", c.email);
        fprintf(arquivo, "         <sexo>%c</sexo>", c.sexo);
        fprintf(arquivo, "         <estado_civil>%s</estado_civil>", c.estado_civil);
        fprintf(arquivo, "         <data_nascimento>%s</data_nascimento>", c.data_nascimento);
        fprintf(arquivo, "      </registro>");
    }
    fprintf(arquivo, "   </tabela>");
    fprintf(arquivo, "</dados>");
    fclose(arquivo);
}

void exportacaoCliente(int qtde) {
    FILE *arquivo;
    Cliente *c;
    arquivo = fopen("exportacaoCli.txt", "wt");
    fprintf(arquivo, "<dados>");
    fprintf(arquivo, "   <tabela=cliente>");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>");
        fprintf(arquivo, "         <codigo>%f</codigo>", c.codigo);
        fprintf(arquivo, "         <nome>%s</nome>", c.nome);
        fprintf(arquivo, "         <endereco>%s</endereco>", c.endereco);
        fprintf(arquivo, "         <cpf>%s</cpf>", c.cpf);
        fprintf(arquivo, "         <telefone>%s</telefone>", c.telefone);
        fprintf(arquivo, "         <email>%s</email>", c.email);
        fprintf(arquivo, "         <sexo>%c</sexo>", c.sexo);
        fprintf(arquivo, "         <estado_civil>%s</estado_civil>", c.estado_civil);
        fprintf(arquivo, "         <data_nascimento>%s</data_nascimento>", c.data_nascimento);
        fprintf(arquivo, "      </registro>");
        salvaCliente(c);
    }
    fprintf(arquivo, "   </tabela>");
    fprintf(arquivo, "</dados>");
    fclose(arquivo);
}

