/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../tamanho.h"

int salvaLocadora(Locadora*f) {

    float tamanhoLocadora= getTamanhoLocadora() + 1;
    (*f).codigo = tamanhoLocadora;
    return inclusaoLocadora(*f);
}

int atualizaLocadora(Locadora f) {
    return alterarLocadora(f, f.codigo);

}

int deletaLocadora(int codLocadora) {
    return deletaLocadora(codLocadora);
}

Locadora* listaLocadoras() {
    return listaLocadoras();
}

//implementar esse olhar se no codigo do wev tem

Locadora consultaLocadora(int codigo) {
    return consultarLocadora(codigo);
}

int qtdLocadora() {
    return getTamanhoLocadora();
}