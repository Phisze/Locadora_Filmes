
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../clienteDAO.h"
//#include "../conCliente.h"
#include "../tamanho.h"
#include <stdio.h>

//funcionando ok
int salvaCliente(Cliente * c){
    Cliente j=*c;
       
    float tamanhoCli=getTamanhoCliente()+1;
    j.codigo=tamanhoCli;
    //printf(" tamain cliente %f\n",j.codigo);
    
    return inclusaoCliente(j);
  ///  return 1;
}
//funcionando ok
int atualizaCliente(Cliente c){
    return alterarCliente(c,c.codigo);
}

//funcionando ok
int deletaCliente(float codigo){
    return excluirCliente(codigo);
}

Cliente* listaClientes(){
    return lClientes();
}

int qtdCliente(){
    return getTamanhoCliente();
}

Cliente consultaCliente(float codigo){
   return consultarClientes(codigo);
}

///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
////#include "../clienteDAO.h"
////#include "../conCliente.h"
//
//int salvaCliente(vector nome,vector endereco,vector cpf, vector telefone, vector email, char sexo, vector estado_civil
//, vector data_nascimento){
//   // Cliente c;
//  //  c.nome=nome;
////    printf("%s",c.nome);
////    c.nome=nome;
////    c.cpf=cpf;
////    c.data_nascimento=data_nascimento;
////    c.email=email;
////    c.endereco=endereco;
////    c.estado_civil=estado_civil;
////    c.sexo=sexo;
////    c.telefone=telefone;
////    c.deletado=' ';
//    
//  //  int tamanho= sizeof(listarClientes())/sizeof(Cliente);
//  //  c.codigo=tamanho;
//    
//  //  return inclusaoCliente(c);
//    return 1;
//}
//
//int atualizaCliente(Cliente c){
//    return alterarCliente(c,c.codigo);
//}
//
//int deletaCliente(int codigo){
//    return excluirCliente(codigo);
//}
//
//Cliente* listaClientes(){
//    return listarClientes();
//}
//
//Cliente consultaCliente(int codigo){
//    return consultarClientes(codigo);
//}
//



