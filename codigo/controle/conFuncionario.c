
#include "../tamanho.h"
#include "../structs.h"
#include "../funcionarioDAO.h"
#include "../conPersistencia.h"

int salvaFuncionario(Funcionario*f) {

    float tamanhoFuncionario = getTamanhoFuncionario() + 1;
    (*f).codigo = tamanhoFuncionario;
    return inclusaoFuncionarios(*f);
}

int atualizaFuncionario(Funcionario f) {
    return alterarFuncionarios(f, f.codigo);

}
//
int deletaFuncionario(float codFun) {
    return excluirFuncionarios(codFun);
}
//
Funcionario* listaFuncionarios() {
    Funcionario * pepe=listarFuncionarios();
    return pepe;
}

//implementar esse olhar se no codigo do wev tem

Funcionario consultaFuncionario(int codFun) {
    return consultarFuncionarios(codFun);
}

int qtdFuncionario() {
    return getTamanhoFuncionario();
}