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
#include "../structs.h"
#include "../fornecedorDAO.h"
#include "../conPersistencia.h"

int qtdFornecedor() {
    if (getTipoPersistencia() == MEMORIA) {

        return tamanhoFornecedors;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoFornecedor();
    } else {
        return getTamanhoFornecedorTexto();
    }
}

int salvaFornecedor(Fornecedor *f) {

    float tamanhoFornecedor = qtdFornecedor() + 1;
    (*f).codigo = tamanhoFornecedor;

    if (getTipoPersistencia() == MEMORIA) {
        return insereFuncionarioArrayDinamico(*f);
    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoFornecedor(*f);
    } else {
        return inclusaoFornecedorTexto(*f);
    }

}

int atualizaFornecedor(Fornecedor f) {
    if (getTipoPersistencia() == MEMORIA) {

        return alterarFornecedorArrayDinamico(f.codigo, f);
    } else if (getTipoPersistencia() == BINARIO) {
        return alterarFornecedor(f, f.codigo);
    } else {
        return alterarFornecedorTexto(f.codigo, f);
    }

}

int deletaFornecedor(float codFornecedor) {

    if (getTipoPersistencia() == MEMORIA) {
        return excluirFornecedorArrayDinamico((int) codFornecedor);
    } else if (getTipoPersistencia() == BINARIO) {
        return deletaFornecedor(codFornecedor);
    } else {
        return excluirFornecedorTexto(codFornecedor);
    }

}

Fornecedor* listaFornecedor() {

    if (getTipoPersistencia() == MEMORIA) {

        return listarFornecedorArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listarFornecedor();
    } else {
        return ListarFornecedorTexto();
    }

}

//implementar esse olhar se no codigo do wev tem

Fornecedor consultaFornecedor(float codigo) {

    if (getTipoPersistencia() == MEMORIA) {

        return consultaFornecedorArrayDinamico((int) codigo);
    } else if (getTipoPersistencia() == BINARIO) {
        return consultarFornecedor(codigo);
    } else {
        return ConsultarFornecedorTexto(codigo);
    }
}




