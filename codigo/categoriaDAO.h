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
 **  Lista Categoria em arquivo binario
 */
Categoria* listarCategoria();

/*
 **  Consultar Categoria em arquivo binario
 */
Categoria consultarCategoria(int cod);
/*
 **  Altera Categoria em arquivo binario
 */
int alterarCategoria(Categoria categoria, int cod);
/*
 **  Deleta Categoria em arquivo binario
 */
int excluirCategoria(int cod);

#endif /* CATEGORIADAO_H */

