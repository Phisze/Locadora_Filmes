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

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
/*
 **  Inclui Clientes em arquivo binario
 */
void inclusaoCliente(Cliente c);

/*
 **  Lista Clientes em arquivo binario
 */
vector listarClientes();

/*
 **  Consultar Clientes em arquivo binario
 */
void consultarCliente();
/*
 **  Altera Clientes em arquivo binario
 */
void alterarCliente();
/*
 **  Deleta Clientes em arquivo binario
 */
void excluirCliente();
#endif /* CLIENTEDAO_H */

