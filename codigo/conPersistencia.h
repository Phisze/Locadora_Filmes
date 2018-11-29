///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   conPersistencia.h
// * Author: Administrador
// *
// * Created on 9 de Novembro de 2018, 16:05
// */
//
//#ifndef CONPERSISTENCIA_H
//#define CONPERSISTENCIA_H
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
//
//extern int tipoPersistencia;
//
//int getTipoPersistencia();
//void setTipoPersistencia(int tipo);
//
//#endif /* CONPERSISTENCIA_H */
//
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conPersistencia.h
 * Author: Administrador
 *
 * Created on 9 de Novembro de 2018, 16:05
 */

#ifndef CONPERSISTENCIA_H
#define CONPERSISTENCIA_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#define MEMORIA 0
#define TEXTO 2
#define BINARIO 1

extern int tipoPersistencia;

int getTipoPersistencia();
void setTipoPersistencia(int tipo);

//    if (getTipoPersistencia() == MEMORIA) {
//
//
//    } else if (getTipoPersistencia() == BINARIO) {
//
//    } else {
//
//    }
#endif /* CONPERSISTENCIA_H */

