/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conFornecedor.h
 * Author: alunos
 *
 * Created on 19 de Outubro de 2018, 14:01
 */

#ifndef CONFORNECEDOR_H
#define CONFORNECEDOR_H
#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif


int salvaFornecedor(Fornecedor*l);
int atualizaFornecedor(Fornecedor l);
int deletaFornecedor(float codFornecedor);
Fornecedor* listaFornecedor();
Fornecedor consultaFornecedor(float codigo);

#endif /* CONFORNECEDOR_H */

