/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fornecedorDAO.h
 * Author: wever
 *
 * Created on 11 de Outubro de 2018, 13:55
 */

#ifndef FORNECEDORDAO_H
#define FORNECEDORDAO_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
/*
 **  Inclui Fornecedor em arquivo binario
 */
int inclusaoFornecedor(Fornecedor f);
/*
 **  Inclui Fornecedor em arquivo Texto
 */
void inclusaoFornecedorTexto(Fornecedor f);
/*
 **  Lista Fornecedor em arquivo binario
 */
Fornecedor* listarFornecedor();
/*
 **  Lista Fornecedor em arquivo Texto
 */
Fornecedor* ListarFornecedorTexto();
/*
 **  Consultar Fornecedor em arquivo binario
 */
Fornecedor consultarFornecedor(float cod);
/*
 **  Consultar Fornecedor em arquivo Texto
 */
Fornecedor ConsultarFornecedorTexto(float cod);
/*
 **  Altera Fornecedor em arquivo binario
 */
int alterarFornecedor(Fornecedor fornecedor, float cod);
/*
 **  Altera Fornecedor em arquivo Texto
 */
void alterarFornecedorTexto(float cod, Fornecedor forn);
/*
 **  Deleta Fornecedor em arquivo binario
 */
int excluirFornecedor(float cod);
/*
 **  Deleta Fornecedor em arquivo binario
 */
void excluirFornecedorTexto(float cod);
#endif /* FORNECEDORDAO_H */

