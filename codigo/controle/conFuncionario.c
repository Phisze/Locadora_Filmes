/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../tamanho.h"


int salvaFuncionario(Funcionario*f) {
    
    float tamanhoFuncionario = getTamanhoFuncionario() + 1;
    (*f).codigo = tamanhoFuncionario;
    return inclusaoFuncionario(*f);
}

int atualizaFuncionario(Funcionario f){
    return alterarFuncionarios(f,f.codigo);

}
int deletaFuncionario(int codFun){
    return deletaFuncionario(codFun);
}

Funcionario* listaFuncionarios(){
    return listaFuncionarios();
}

//implementar esse olhar se no codigo do wev tem
Funcionario consultaFuncionario(int codigo){
    return consultarFuncionario(codigo);
}

int qtdFuncionario(){
    return qtdFuncionario();
}