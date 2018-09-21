/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conCliente.h
 * Author: alunos
 *
 * Created on 20 de Setembro de 2018, 13:48
 */

#ifndef CONCLIENTE_H
#define CONCLIENTE_H

#include "vector.h"
#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif



int salvaCliente(vector nome,vector endereco,vector cpf, vector telefone, vector email, char sexo, vector estado_civil, vector data_nascimento);

int atualizaCliente(Cliente c);

int deletaCliente(int codCliente);

Cliente* listaClientes();

Cliente consultaCliente(int codigo);







#endif /* CONCLIENTE_H */

