/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../tamanho.h"
#include "../structs.h"
#include "../funcionarioDAO.h"

int salvaFuncionario(Funcionario*f) {

    float tamanhoFuncionario = getTamanhoFuncionario() + 1;
    (*f).codigo = tamanhoFuncionario;
    return inclusaoFuncionarios(*f);
}

int atualizaFuncionario(Funcionario f) {
    return alterarFuncionarios(f, f.codigo);

}
//
int deletaFuncionario(int codFun) {
    return excluirFuncionarios(codFun);
}
//
//Funcionario* listaFuncionarios() {
//    return listarFuncionarios();
//}

//implementar esse olhar se no codigo do wev tem

//Funcionario consultaFuncionario(int codFun) {
//    return consultarFuncionarios(codFun);
//}

int qtdFuncionario() {
    return getTamanhoFuncionario();
}