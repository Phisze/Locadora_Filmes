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
    return inclusaoFilmes(*f);
}

int atualizaFilme(Filme f){
    return alterarFilmes(f,f.codigo);

}
int deletaFilme(float codFilme){
    return deletaFilme(codFilme);
}

Filme* listaFilmes(){
    return listarFilmes();
}

//implementar esse olhar se no codigo do wev tem
Filme consultaFilme(float codigo){
    return consultarFilmes(codigo);
}

Filme consultaFilmeNome(char*nome){
    
}

int qtdFilme(){
    return getTamanhoFilme();
}

