/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../clienteDAO.h"

int salvaCliente(vector nome,vector endereco,vector cpf, vector telefone, vector email, char sexo, vector estado_civil
, vector data_nascimento){
    Cliente c;
    c.nome=nome;
    c.cpf=cpf;
    c.data_nascimento=data_nascimento;
    c.email=email;
    c.endereco=endereco;
    c.estado_civil=estado_civil;
    c.sexo=sexo;
    c.telefone=telefone;
    c.deletado=" ";
    
    return inclusaoCliente(c);
}

int atualizaCliente(Cliente c){
    return alterarCliente(c,c.codigo);
}

int deletaCliente(int codigo){
    return excluirCliente(codigo);
}

vector listaClientes(){
    return listarClientes();
}

Cliente consultaCliente(int codigo){
    return consultarClientes(codigo);
}


