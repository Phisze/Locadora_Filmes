/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../clienteDAO.h"
//#include "../conCliente.h"
#include "../tamanho.h"
#include <stdio.h>
#include "../conPersistencia.h"
//funcionando ok

int salvaCliente(Cliente * c) {
    Cliente j = *c;

    float tamanhoCli = qtdCliente() + 1;
    j.codigo = tamanhoCli;
    //printf(" tamain cliente %f\n",j.codigo);

    if (getTipoPersistencia() == MEMORIA) {

    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoCliente(j);
    } else {
        return inclusaoClienteTexto(j);
    }

    ///  return 1;
}
//funcionando ok

int atualizaCliente(Cliente c) {
    if (getTipoPersistencia() == MEMORIA) {


    } else if (getTipoPersistencia() == BINARIO) {
        alterarCliente(c, c.codigo);
    } else {
        alterarClienteTexto(c.codigo, c);
    }
}
//funcionando ok

int deletaCliente(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {

    } else if (getTipoPersistencia() == BINARIO) {
        return excluirCliente(codigo);
    } else {
        return excluirClienteTexto(codigo);
    }


}

Cliente* listaClientes() {
    if (getTipoPersistencia() == MEMORIA) {

        
    } else if (getTipoPersistencia() == BINARIO) {
        return lClientes();
    } else {

    }
    
}

int qtdCliente() {
    if (getTipoPersistencia() == MEMORIA) {


    } else if (getTipoPersistencia() == BINARIO) {
          return getTamanhoCliente();
    } else {
          return getTamanhoClienteTexto();
    }
  
}

Cliente consultaCliente(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {


    } else if (getTipoPersistencia() == BINARIO) {
            return consultarClientes(codigo);
    } else {
                return ConsultarClientesTexto(codigo);
    }

}




