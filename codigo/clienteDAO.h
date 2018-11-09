/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clienteDAO.h
 * Author: alunos
 *
 * Created on 24 de Agosto de 2018, 14:32
 */

#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H

#include "structs.h"


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
/*
 **  Inclui Clientes em arquivo binario
 */
int inclusaoCliente(Cliente c);
/*
 **  Inclui Clientes em arquivo texto
 */
void inclusaoClienteTexto(Cliente c);
/*
 **  Inclui Clientes em Array Dinamico
 */
void insereClienteArrayDinamico(Cliente c);
/*
 **  Lista Clientes em arquivo binario
 */
Cliente* lClientes();
/*
 **  Lista Clientes em arquivo binario
 */
Cliente* ListarClientesTexto();
/*
 **  Consultar Clientes em Array Dinamico
 */
Cliente* listarClienteArrayDinamico();
/*
 **  Consultar Clientes em arquivo binario
 */
Cliente consultarClientes(float cod);
/*
 **  Consultar Clientes em arquivo texto
 */
Cliente ConsultarClientesTexto(float cod);
/*
 **  Altera Clientes em arquivo Array Dinamico
 */
Cliente consultaClienteArrayDinamico(int cod);
/*
 **  Altera Clientes em arquivo binario
 */
int alterarCliente(Cliente clintes, float cod);
/*
 **  Altera Clientes em arquivo texto
 */
void alterarClienteTexto(float cod, Cliente cli);
/*
 **  Altera Clientes em Array Dinamico
 */
void alterarClienteArrayDinamico(int cod, Cliente c);
/*
 **  Deleta Clientes em arquivo binario
 */
int excluirCliente(float cod);
/*
 **  Deleta Clientes em Array Dinamico
 */
void excluirClienteTexto(int cod);
#endif /* CLIENTEDAO_H */

