/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionario.h
 * Author: wever
 *
 * Created on 11 de Outubro de 2018, 14:47
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "structs.h"


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
/*
 **  Inclui Fornecedor em arquivo binario
 */
int inclusaoFuncionarios(Funcionario f);
/*
 **  Lista Fornecedor em arquivo binario
 */
Funcionario* listarFuncionarios();

/*
 **  Consultar Fornecedor em arquivo binario
 */
Funcionario consultarFuncionarios(float cod);
/*
 **  Altera Fornecedor em arquivo binario
 */
int alterarFuncionarios(Funcionario funcionario, float cod);
/*
 **  Deleta Filmes em arquivo binario
 */
int excluirFuncionarios(float cod);
#endif /* FUNCIONARIO_H */

