
#include "../tamanho.h"
#include "../structs.h"
#include "../funcionarioDAO.h"
#include "../conPersistencia.h"

int qtdFuncionario() {
    if (getTipoPersistencia() == MEMORIA) {

        return tamanhoFuncionarios;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoFuncionario();
    } else {
        return getTamanhoFuncionarioTexto();
    }
}
int salvaFuncionario(Funcionario*f) {

    float tamanhoFuncionario = getTamanhoFuncionario() + 1;
    (*f).codigo = tamanhoFuncionario;

    if (getTipoPersistencia() == MEMORIA) {

        return insereFuncionarioArrayDinamico(*f);
    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoFuncionarios(*f);
    } else {
        return inclusaoFuncionarioTexto(*f);
    }
}

int atualizaFuncionario(Funcionario f) {
    if (getTipoPersistencia() == MEMORIA) {

        return alterarFuncionarioArrayDinamico((int) f.codigo, f);
    } else if (getTipoPersistencia() == BINARIO) {
        return alterarFuncionarios(f, f.codigo);
    } else {
        return alterarFuncionarioTexto(f.codigo, f);
    }
}
//

int deletaFuncionario(float codFun) {
    if (getTipoPersistencia() == MEMORIA) {

        return excluirFuncionarioArrayDinamico((int) codFun);
    } else if (getTipoPersistencia() == BINARIO) {
        return excluirFuncionarios(codFun);
    } else {
        return excluirFuncionarioTexto(codFun);
    }
}
//

Funcionario* listaFuncionarios() {
    if (getTipoPersistencia() == MEMORIA) {

        return listarFuncionarioArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listarFuncionarios();
    } else {
        return ListarFuncionarioTexto();
    }
}

//implementar esse olhar se no codigo do wev tem

Funcionario consultaFuncionario(float codFun) {
    if (getTipoPersistencia() == MEMORIA) {

        return consultaFuncionarioArrayDinamico((int) codFun);
    } else if (getTipoPersistencia() == BINARIO) {
        return consultarFuncionarios(codFun);
    } else {
        return ConsultarFuncionarioTexto(codFun);
    }
}

