///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   locadoraDAO.h
// * Author: wever
// *
// * Created on 11 de Outubro de 2018, 14:57
// */
//
//#ifndef LOCADORADAO_H
//#define LOCADORADAO_H
//
//#include "structs.h"
//
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
///*
// **  Inclui Locadora em arquivo binario
// */
//int inclusaoLocadora(Locadora l);
///*
// **  Inclui Locadora em arquivo Texto
// */
//void inclusaoLocadoraTexto(Locadora l);
///*
// **  Inclui Locadora em Array Dinamico
// */
//void insereLocadoraArrayDinamico(Locadora c);
///*
// **  Lista Locadora em arquivo binario
// */
//Locadora* listarLocadora();
///*
// **  Lista Locadora em arquivo Texto
// */
//Locadora* ListarLocadoraTexto();
///*
// **  Lista Locadora em Array Dinamico
// */
//Locadora* listarLocadoraArrayDinamico();
///*
// **  Consultar Locadora em arquivo binario
// */
//Locadora consultarLocadora(float cod);
///*
// **  Consultar Locadora em arquivo Texto
// */
//Locadora ConsultarLocadoraTexto(float cod);
///*
// **  Consultar Locadora em Array Dinamico
// */
//Locadora consultaLocadoraArrayDinamico(int cod);
///*
// **  Altera Locadora em arquivo binario
// */
//int alterarLocadora(Locadora locadora, float cod);
///*
// **  Altera Locadora em arquivo Texto
// */
//void alterarLocadoraTexto(float cod, Locadora loc);
///*
// **  Altera Locadora em arquivo Array Dinamico
// */
//void alterarLocadoraArrayDinamico(int cod, Locadora c);
///*
// **  Deleta Locadora em arquivo binario
// */
//int excluirLocadora(float cod);
///*
// **  Deleta Locadora em arquivo Texto
// */
//int excluirLocadoraTexto(float cod);
///*
// **  Deleta Locadora em Array Dinamico
// */
//void excluirLocadoraArrayDinamico(int cod);
//#endif /* LOCADORADAO_H */
//
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   locadoraDAO.h
 * Author: wever
 *
 * Created on 11 de Outubro de 2018, 14:57
 */

#ifndef LOCADORADAO_H
#define LOCADORADAO_H

#include "structs.h"


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
extern int tamanhoLocacadoras;
/*
 **  Inclui Locadora em arquivo binario
 */
int inclusaoLocadora(Locadora l);
/*
 **  Inclui Locadora em arquivo Texto
 */
int inclusaoLocadoraTexto(Locadora l);
/*
 **  Inclui Locadora em Array Dinamico
 */
int insereLocadoraArrayDinamico(Locadora c);
/*
 **  Lista Locadora em arquivo binario
 */
Locadora* listarLocadora();
/*
 **  Lista Locadora em arquivo Texto
 */
Locadora* ListarLocadoraTexto();
/*
 **  Lista Locadora em Array Dinamico
 */
Locadora* listarLocadoraArrayDinamico();
/*
 **  Consultar Locadora em arquivo binario
 */
Locadora consultarLocadora(float cod);
/*
 **  Consultar Locadora em arquivo Texto
 */
Locadora ConsultarLocadoraTexto(float cod);
/*
 **  Consultar Locadora em Array Dinamico
 */
Locadora consultaLocadoraArrayDinamico(int cod);
/*
 **  Altera Locadora em arquivo binario
 */
int alterarLocadora(Locadora locadora, float cod);
/*
 **  Altera Locadora em arquivo Texto
 */
int alterarLocadoraTexto(float cod, Locadora loc);
/*
 **  Altera Locadora em arquivo Array Dinamico
 */
int alterarLocadoraArrayDinamico(int cod, Locadora c);
/*
 **  Deleta Locadora em arquivo binario
 */
int excluirLocadora(float cod);
/*
 **  Deleta Locadora em arquivo Texto
 */
int excluirLocadoraTexto(float cod);
/*
 **  Deleta Locadora em Array Dinamico
 */
int excluirLocadoraArrayDinamico(int cod);
#endif /* LOCADORADAO_H */


