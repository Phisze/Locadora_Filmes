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
    arquivo = fopen("importacaoCli.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=clientes>\n");
    for (int i = 0; i < qtdCliente(); i++) {
        if (c[i].deletado != '*') {
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
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoCliente(int qtde) {
    FILE *arquivo;
    Cliente *c;
    arquivo = fopen("exportacaoCli.xml", "wt");
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
        fprintf(arquivo, "         <data_nascimento>%s</data_nascimento>\n", c[i].data_nascimento);
        fprintf(arquivo, "      </registro>\n");
        salvaCliente(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void importacaoCategoria() {
    Categoria *c;
    c = listaCategoria();
    FILE *arquivo;
    arquivo = fopen("importacaoCat.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=categoria>\n");
    for (int i = 0; i < qtdCategoria(); i++) {
        if (c[i].deletado != '*') {
            fprintf(arquivo, "      <registro>\n");
            fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
            fprintf(arquivo, "         <descricao>%s</descricao>\n", c[i].descricao);
            fprintf(arquivo, "         <valor_locacao>%.0f</valor_locacao>\n", c[i].valor_locacao);
            fprintf(arquivo, "      </registro>\n");
        }
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoCategoria(int qtde) {
    FILE *arquivo;
    Categoria *c;
    arquivo = fopen("importacaoCat.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=categoria>\n");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <descricao>%s</descricao>\n", c[i].descricao);
        fprintf(arquivo, "         <valor_locacao>%.0f</valor_locacao>\n", c[i].valor_locacao);
        fprintf(arquivo, "      </registro>\n");
        salvaCategoria(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void importacaoFilme() {
    Filme *c;
    c = listaFilmes();
    FILE *arquivo;
    arquivo = fopen("importacaoFil.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=filme>\n");
    for (int i = 0; i < qtdFilme(); i++) {
        if (c[i].deletado != '*') {
            fprintf(arquivo, "      <registro>\n");
            fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
            fprintf(arquivo, "         <descricao>%s</descricao>\n", c[i].descricao);
            fprintf(arquivo, "         <exemplares>%.0f</exemplares>\n", c[i].exemplares);
            fprintf(arquivo, "         <lingua>%s</lingua>\n", c[i].lingua);
            fprintf(arquivo, "      </registro>\n");
        }
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoFilme(int qtde) {
    FILE *arquivo;
    Filme *c;
    arquivo = fopen("importacaoFilme.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=filme>\n");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <descricao>%s</descricao>\n", c[i].descricao);
        fprintf(arquivo, "         <exemplares>%.0f</exemplares>\n", c[i].exemplares);
        fprintf(arquivo, "         <lingua>%s</lingua>\n", c[i].lingua);
        fprintf(arquivo, "      </registro>\n");
        salvaFilme(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void importacaoFornecedor() {
    Fornecedor *c;
    c = listaFornecedor();
    FILE *arquivo;
    arquivo = fopen("importacaoFor.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=fornecedor>\n");
    for (int i = 0; i < qtdFornecedor(); i++) {
        if (c[i].deletado != '*') {
            fprintf(arquivo, "      <registro>\n");
            fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
            fprintf(arquivo, "         <cnpj>%s</cnpj>\n", c[i].cnpj);
            fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
            fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
            fprintf(arquivo, "         <inscricao_estadual>%s</inscricao_estadual>\n", c[i].inscricao_estadual);
            fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
            fprintf(arquivo, "         <razao_social>%s</razao_social>\n", c[i].razao_social);
            fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
            fprintf(arquivo, "      </registro>\n");
        }
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoFornecedor(int qtde) {
    FILE *arquivo;
    Fornecedor *c;
    arquivo = fopen("importacaoFor.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=fornecedor>\n");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <cnpj>%s</cnpj>\n", c[i].cnpj);
        fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
        fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
        fprintf(arquivo, "         <inscricao_estadual>%s</inscricao_estadual>\n", c[i].inscricao_estadual);
        fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
        fprintf(arquivo, "         <razao_social>%s</razao_social>\n", c[i].razao_social);
        fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
        fprintf(arquivo, "      </registro>\n");
        salvaFornecedor(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void importacaoFuncionario() {
    Funcionario *c;
    c = listaFuncionarios();
    FILE *arquivo;
    arquivo = fopen("importacaoFun.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=funcionario>\n");
    for (int i = 0; i < qtdFuncionario(); i++) {
        if (c[i].deletado != '*') {
            fprintf(arquivo, "      <registro>\n");
            fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
            fprintf(arquivo, "         <cnpj>%s</cnpj>\n", c[i].cargo);
            fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
            fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
            fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
            fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
            fprintf(arquivo, "      </registro>\n");
        }
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoFuncionario(int qtde) {
    FILE *arquivo;
    Funcionario *c;
    arquivo = fopen("importacaoFun.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=funcionario>\n");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <cnpj>%s</cnpj>\n", c[i].cargo);
        fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
        fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
        fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
        fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
        fprintf(arquivo, "      </registro>\n");
        salvaFuncionario(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void importacaoLocadora() {
    Locadora *c;
    c = listaLocadoras();
    FILE *arquivo;
    arquivo = fopen("importacaoLoc.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=locadora>\n");
    for (int i = 0; i < qtdLocadora(); i++) {
        if (c[i].deletado != '*') {
            fprintf(arquivo, "      <registro>\n");
            fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
            fprintf(arquivo, "         <cnpj>%s</cnpj>\n", c[i].cnpj);
            fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
            fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
            fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
            fprintf(arquivo, "         <inscricao_estadual>%s</inscricao_estadual>\n", c[i].inscricao_estadual);
            fprintf(arquivo, "         <nome_responsavel>%s</nome_responsavel>\n", c[i].nome_responsavel);
            fprintf(arquivo, "         <tel_responsavel>%s</tel_responsavel>\n", c[i].tel_responsavel);
            fprintf(arquivo, "         <razao_social>%s</razao_social>\n", c[i].razao_social);
            fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
            fprintf(arquivo, "      </registro>\n");
        }
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}

void exportacaoLocadora(int qtde) {
    FILE *arquivo;
    Locadora *c;
    arquivo = fopen("importacaoLoc.xml", "wt");
    fprintf(arquivo, "<dados>\n");
    fprintf(arquivo, "   <tabela=locadora>\n");
    for (int i = 0; i < qtde; i++) {
        fprintf(arquivo, "      <registro>\n");
        fprintf(arquivo, "         <codigo>%.0f</codigo>\n", c[i].codigo);
        fprintf(arquivo, "         <cnpj>%s</cnpj>\n", c[i].cnpj);
        fprintf(arquivo, "         <email>%s</email>\n", c[i].email);
        fprintf(arquivo, "         <endereco>%s</endereco>\n", c[i].endereco);
        fprintf(arquivo, "         <nome>%s</nome>\n", c[i].nome);
        fprintf(arquivo, "         <inscricao_estadual>%s</inscricao_estadual>\n", c[i].inscricao_estadual);
        fprintf(arquivo, "         <nome_responsavel>%s</nome_responsavel>\n", c[i].nome_responsavel);
        fprintf(arquivo, "         <tel_responsavel>%s</tel_responsavel>\n", c[i].tel_responsavel);
        fprintf(arquivo, "         <razao_social>%s</razao_social>\n", c[i].razao_social);
        fprintf(arquivo, "         <telefone>%s</telefone>\n", c[i].telefone);
        fprintf(arquivo, "      </registro>\n");
        salvaLocadora(c);
    }
    fprintf(arquivo, "   </tabela>\n");
    fprintf(arquivo, "</dados>\n");
    fclose(arquivo);
}