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
extern int tamanhoFuncionarios;
/*
 **  Inclui Fornecedor em arquivo binario
 */
int inclusaoFuncionarios(Funcionario f);
/*
 **  Inclui Fornecedor em arquivo Texto
 */
int inclusaoFuncionarioTexto(Funcionario f);
/*
 **  Inclui Fornecedor em Array Dinamico
 */
int insereFuncionarioArrayDinamico(Funcionario f);
/*
 **  Lista Fornecedor em arquivo binario
 */
Funcionario* listarFuncionarios();
/*
 **  Lista Fornecedor em arquivo binario
 */
Funcionario* ListarFuncionarioTexto();
/*
 **  Lista Fornecedor em Array Dinamico
 */
Funcionario* listarFuncionarioArrayDinamico();
/*
 **  Consultar Fornecedor em arquivo binario
 */
Funcionario consultarFuncionarios(float cod);
/*
 **  Consultar Fornecedor em arquivo Texto
 */
Funcionario ConsultarFuncionarioTexto(float cod);
/*
 **  Consultar Fornecedor em Array Dinamico
 */
Funcionario consultaFuncionarioArrayDinamico(int cod);
/*
 **  Altera Fornecedor em arquivo binario
 */
int alterarFuncionarios(Funcionario funcionario, float cod);
/*
 **  Deleta Filmes em arquivo Texto
 */
int alterarFuncionarioTexto(float cod, Funcionario fun);
/*
 **  Deleta Filmes em Array Dinamico
 */
int alterarFuncionarioArrayDinamico(int cod, Funcionario c);
/*
 **  Deleta Filmes em arquivo binario
 */
int excluirFuncionarios(float cod);
/*
 **  Deleta Filmes em arquivo Texto
 */
int excluirFuncionarioTexto(float cod);
/*
 **  Deleta Filmes em Array Dinamico
 */
int excluirFuncionarioArrayDinamico(int cod);
#endif /* FUNCIONARIO_H */

