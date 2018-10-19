/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conFornecedcor.c
 * Author: alunos
 *
 * Created on 19 de Outubro de 2018, 14:05
 */
#include "../tamanho.h"

int salvaFornecedor(Fornecedor *f) {

    float tamanhoFornecedor= getTamanhoFornecedor() + 1;
    (*f).codigo = tamanhoFornecedor;
    return inclusaoFornecedor(*f);
}

int atualizaFornecedor(Fornecedor f) {
    return alterarFornecedor(f, f.codigo);

}

int deletaFornecedor(int codFornecedor) {
    return deletaFornecedor(codFornecedor);
}

Fornecedor* listaFornecedor() {
    return listaFornecedor();
}

//implementar esse olhar se no codigo do wev tem

Fornecedor consultaFornecedor(int codigo) {
    return consultarFornecedor(codigo);
}

int qtdFornecedor() {
    return qtdFornecedor();
}


