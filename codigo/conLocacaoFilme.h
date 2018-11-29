///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   conLocacaoFilme.h
// * Author: Administrador
// *
// * Created on 20 de Novembro de 2018, 19:10
// */
//
//#ifndef CONLOCACAOFILME_H
//#define CONLOCACAOFILME_H
//
//#include "structs.h"
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
//int locaFilmes(float cliCodigo, float* filmesCod, int * qtdFilme, float totalPago, int tipo, int numParcela, float entrada);
//
//#endif /* CONLOCACAOFILME_H */
//
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conLocacaoFilme.h
 * Author: Administrador
 *
 * Created on 20 de Novembro de 2018, 19:10
 */

#ifndef CONLOCACAOFILME_H
#define CONLOCACAOFILME_H

#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

int locaFilmes(float cliCodigo, float* filmesCod, float totalPago, int tipo, int numParcela, float entrada);
int deletaLocacao(float codLoc);
Locacao* listaLocacoes();
Locacao consultaLocacao(float codigo);
int qtdLocacao();
int devolveFilmes(float cliCodigo, float filCodigo);
#endif /* CONLOCACAOFILME_H */

