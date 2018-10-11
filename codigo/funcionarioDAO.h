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
Fornecedor* listarFuncionarios();

/*
 **  Consultar Fornecedor em arquivo binario
 */
Fornecedor consultarFuncionarios(int cod);
/*
 **  Altera Fornecedor em arquivo binario
 */
int alterarFuncionarios(Funcionario funcionario, int cod);
/*
 **  Deleta Filmes em arquivo binario
 */
int excluirFuncionarios(int cod);
#endif /* FUNCIONARIO_H */

