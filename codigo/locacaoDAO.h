///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   locacaoDAO.h
// * Author: Administrador
// *
// * Created on 28 de Novembro de 2018, 16:58
// */
//
//#ifndef LOCACAODAO_H
//#define LOCACAODAO_H
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//
//
//
//#ifdef __cplusplus
//}
//#endif
//
//#endif /* LOCACAODAO_H */
//
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   locacoeDAO.h
 * Author: wever
 *
 * Created on 23 de Novembro de 2018, 15:33
 */

#ifndef LOCACOEDAO_H
#define LOCACOEDAO_H
#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
extern int tamanhoLocacaos;

int inclusao_parcela(Locacao f);

Locacao * listarParcelas();
/*
 **  Inclui Fornecedor em arquivo binario
 */
int inclusaoLocacaos(Locacao f);
/*
 **  Inclui Fornecedor em arquivo Texto
 */
int inclusaoLocacaoTexto(Locacao f);
/*
 **  Inclui Fornecedor em Array Dinamico
 */
int insereLocacaoArrayDinamico(Locacao f);
/*
 **  Lista Fornecedor em arquivo binario
 */
//Locacao* listarLocacaos();
Locacao* listarLocacao();
/*
 **  Lista Fornecedor em arquivo binario
 */
Locacao* ListarLocacaoTexto();
/*
 **  Lista Fornecedor em Array Dinamico
 */
Locacao* listarLocacaoArrayDinamico();
/*
 **  Consultar Fornecedor em arquivo binario
 */
Locacao consultarLocacaos(float cod);
/*
 **  Consultar Fornecedor em arquivo Texto
 */
Locacao ConsultarLocacaoTexto(float cod);
/*
 **  Consultar Fornecedor em Array Dinamico
 */
Locacao consultaLocacaoArrayDinamico(int cod);
/*
 **  Altera Fornecedor em arquivo binario
 */
int alterarLocacaos(Locacao Locacao, float cod);
/*
 **  Deleta Filmes em arquivo Texto
 */
int alterarLocacaoTexto(float cod, Locacao fun);
/*
 **  Deleta Filmes em Array Dinamico
 */
int alterarLocacaoArrayDinamico(int cod, Locacao c);
/*
 **  Deleta Filmes em arquivo binario
 */
int excluirLocacao(float cod);
/*
 **  Deleta Filmes em arquivo Texto
 */
int excluirLocacaoTexto(float cod);
/*
 **  Deleta Filmes em Array Dinamico
 */
int excluirLocacaoArrayDinamico(int cod);
#endif /* LOCACOEDAO_H */

