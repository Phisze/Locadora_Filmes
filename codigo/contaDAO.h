/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   contaDAO.h
 * Author: wever
 *
 * Created on 27 de Novembro de 2018, 19:04
 */

#ifndef CONTADAO_H
#define CONTADAO_H
#include "structs.h"
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
/*
 * *Variavel para saber o tamanho do array dinamico
 */ 
extern int tamanhoContas;
/*
 **  Inclui Contas em arquivo binario
 */
int inclusaoConta(Conta c);
/*
 **  Inclui Contas em arquivo texto
 */
int inclusaoContaTexto(Conta c);
/*
 **  Inclui Contas em Array Dinamico
 */
int insereContaArrayDinamico(Conta c);
/*
 **  Lista Contas em arquivo binario
 */
Conta* listarConta();
/*
 **  Lista Contas em arquivo binario
 */
Conta* ListarContaTexto();
/*
 **  Consultar Contas em Array Dinamico
 */
Conta* listarContaArrayDinamico();
/*
 **  Consultar Contas em arquivo binario
 */
Conta consultarConta(float cod);
/*
 **  Consultar Contas em arquivo texto
 */
Conta ConsultarContaTexto(float cod);
/*
 **  Altera Contas em arquivo Array Dinamico
 */
Conta consultaContaArrayDinamico(int cod);
/*
 **  Altera Contas em arquivo binario
 */
int alterarConta(Conta clintes, float cod);
/*
 **  Altera Contas em arquivo texto
 */
int alterarContaTexto(float cod, Conta cli);
/*
 **  Altera Contas em Array Dinamico
 */
int alterarContaArrayDinamico(int cod, Conta c);
/*
 **  Deleta Contas em arquivo binario
 */
int excluirConta(float cod);
/*
 **  Deleta Contas em Array Dinamico
 */
int excluirContaTexto(int cod);
#endif /* CONTADAO_H */

