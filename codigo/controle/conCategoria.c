///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//#include "../categoriaDAO.h"
//#include "../tamanho.h"
//#include "../structs.h"
////#include "../conPersistencia.h"
//
//int salvaCategoria(Categoria *f) {
//
//    float tamanhoCategoria = getTamanhoCategoria() + 1;
//    (*f).codigo = tamanhoCategoria;
//    return inclusaoCategoria(*f);
//}
//
//int atualizaCategoria(Categoria f) {
//    return alterarCategoria(f, f.codigo);
//
//}
//
//int deletaCategoria(float codCategoria) {
//    return deletaCategoria(codCategoria);
//}
//
//Categoria* listaCategoria() {
//    return listaCategoria();
//}
//
////implementar esse olhar se no codigo do wev tem
//
//Categoria consultaCategoria(float codigo) {
//    return consultarCategoria(codigo);
//}
//
//int qtdCategoria() {
//    return getTamanhoCategoria();
//}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../categoriaDAO.h"
#include "../tamanho.h"
#include "../structs.h"
#include "../conPersistencia.h"

int salvaCategoria(Categoria *f) {

    float tamanhoCategoria = getTamanhoCategoria() + 1;
    (*f).codigo = tamanhoCategoria;
    if (getTipoPersistencia() == MEMORIA) {
        insereCategoriaArrayDinamico(*f);
        return 1;
    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoCategoria(*f);
    } else {
        inclusaoCategoriaTexto(*f);
        return 1;
    }

    return inclusaoCategoria(*f);
}

int atualizaCategoria(Categoria f) {
    if (getTipoPersistencia() == MEMORIA) {

        alterarCategoriaArrayDinamico(f.codigo, f);
        return 1;
    } else if (getTipoPersistencia() == BINARIO) {
        alterarCategoria(f, f.codigo);
        return 1;
        
    } else {
        alterarCategoriaTexto(f.codigo, f);
        return 1;
    }

}

int deletaCategoria(float codCategoria) {
    if (getTipoPersistencia() == MEMORIA) {

        excluirCategoriaTexto(codCategoria);
        return 1;
    } else if (getTipoPersistencia() == BINARIO) {
        return deletaCategoria(codCategoria);
    } else {
        excluirCategoriaTexto(codCategoria);
        return 1;
    }
}

Categoria* listaCategoria() {
    if (getTipoPersistencia() == MEMORIA) {
        return listarCategoriaArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listarCategoria();
    } else {
        return ListarCategoriaTexto();
    }

}

//implementar esse olhar se no codigo do wev tem

Categoria consultaCategoria(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {
        return consultaCategoriaArrayDinamico((int)codigo);

    } else if (getTipoPersistencia() == BINARIO) {
        return consultarCategoria(codigo);
    } else {
        return ConsultarCategoriaTexto(codigo);
    }
}

int qtdCategoria() {
            if (getTipoPersistencia() == MEMORIA) {

                return tamanhoCategorias;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoCategoria();
    } else {
        return getTamanhoCategoriaTexto();
    }
}

