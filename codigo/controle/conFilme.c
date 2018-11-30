/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../filmeDAO.h"
#include "../tamanho.h"
#include "../conPersistencia.h"

int salvaFilme(Filme*f) {

    float tamanhoFilme = getTamanhoFilme() + 1;
    (*f).codigo = tamanhoFilme;
    if (getTipoPersistencia() == MEMORIA) {

        return insereFilmeArrayDinamico(*f);
    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoFilmes(*f);
    } else {
        return inclusaoFilmeTexto(*f);
    }
}

int atualizaFilme(Filme f) {
    if (getTipoPersistencia() == MEMORIA) {

        return alterarFilmeArrayDinamico((int) f.codigo, f);
    } else if (getTipoPersistencia() == BINARIO) {
        return atualizaFilme(f);
    } else {
        return alterarFilmeTexto(f.codigo, f);
    }


}

int deletaFilme(float codFilme) {
    if (getTipoPersistencia() == MEMORIA) {
        return excluirFilmeArrayDinamico((int) codFilme);

    } else if (getTipoPersistencia() == BINARIO) {
        return deletaFilme(codFilme);
    } else {
        return excluirFilmeTexto(codFilme);
    }
}

Filme* listaFilmes() {
    if (getTipoPersistencia() == MEMORIA) {

        return listarFilmeArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listarFilmes();
    } else {
        return ListarFilmesTexto();
    }
    return listarFilmes();
}

//implementar esse olhar se no codigo do wev tem

Filme consultaFilme(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {
        return consultaFilmeArrayDinamico((int) codigo);

    } else if (getTipoPersistencia() == BINARIO) {
        return consultaFilme(codigo);
    } else {
        return ConsultarFilmesTexto(codigo);
    }
}

Filme consultaFilmeNome(char*nome) {

}

int qtdFilme() {
    if (getTipoPersistencia() == MEMORIA) {

        return tamanhoFilmes;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoFilme();
    } else {
        return getTamanhoFilmeTexto();
    }
}

