/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   categoriaDAO.h
 * Author: wever
 *
 * Created on 11 de Outubro de 2018, 13:34
 */

#ifndef CATEGORIADAO_H
#define CATEGORIADAO_H

#include "structs.h"


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif


/*
 **  Inclui Categoria em arquivo binario
 */
int inclusaoCategoria(Categoria c);
/*
 **  Inclui Categoria em arquivo Texto
 */
void inclusaoCategoriaTexto(Categoria c);
/*
 **  Lista Categoria em arquivo binario
 */
Categoria* listarCategoria();
/*
 **  Lista Categoria em arquivo Texto
 */
Categoria* ListarCategoriaTexto();
/*
 **  Consultar Categoria em arquivo binario
 */
Categoria consultarCategoria(float cod);
/*
 **  Consultar Categoria em arquivo Texto
 */
Categoria ConsultarCategoriaTexto(float cod);
/*
 **  Altera Categoria em arquivo binario
 */
int alterarCategoria(Categoria categoria, float cod);
/*
 **  Alterar Categoria em arquivo Texto
 */
void alterarCategoriaTexto(float cod, Categoria cat);
/*
 **  Deleta Categoria em arquivo binario
 */
int excluirCategoria(float cod);
/*
 **  Deleta Categoria em arquivo Texto
 */
void excluirCategoriaTexto(float cod);
/*
 **  Deleta Categoria em arquivo Array Dinamico
 */
#endif /* CATEGORIADAO_H */

