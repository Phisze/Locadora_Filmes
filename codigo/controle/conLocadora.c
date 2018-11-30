/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../tamanho.h"
#include "../structs.h"
#include "../locadoraDAO.h"
#include "../conPersistencia.h"

int qtdLocadora() {
    if (getTipoPersistencia() == MEMORIA) {
        return tamanhoLocadoras;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoLocadora();
    } else {
        return getTamanhoLocadoraTexto();
    }
}

int salvaLocadora(Locadora*f) {

    float tamanhoLocadora = getTamanhoLocadora() + 1;
    (*f).codigo = tamanhoLocadora;

    if (getTipoPersistencia() == MEMORIA) {

        return insereLocadoraArrayDinamico(*f);
    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoLocadora(*f);
    } else {
        return inclusaoLocadoraTexto(*f);
    }
}

int atualizaLocadora(Locadora f) {

    if (getTipoPersistencia() == MEMORIA) {

        return alterarLocadoraArrayDinamico((int) f.codigo, f);
    } else if (getTipoPersistencia() == BINARIO) {
        return alterarLocadora(f, f.codigo);
    } else {
        return alterarLocadoraTexto(f.codigo, f);
    }
}

int deletaLocadora(float codLocadora) {
    if (getTipoPersistencia() == MEMORIA) {

        return excluirLocadoraArrayDinamico(codLocadora);
    } else if (getTipoPersistencia() == BINARIO) {
        return deletaLocadora(codLocadora);
    } else {
        return excluirLocadoraTexto(codLocadora);
    }
}

Locadora* listaLocadoras() {
    if (getTipoPersistencia() == MEMORIA) {

        return listarLocadoraArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listaLocadoras();
    } else {
        return ListarLocadoraTexto();
    }
}

//implementar esse olhar se no codigo do wev tem

Locadora consultaLocadora(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {
        return consultaLocadoraArrayDinamico((int) codigo);
    } else if (getTipoPersistencia() == BINARIO) {
        return consultarLocadora(codigo);
    } else {
        return ConsultarLocadoraTexto(codigo);
    }
}
