///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   conCliente.h
// * Author: alunos
// *
// * Created on 20 de Setembro de 2018, 13:48
// */
//
//#ifndef CONCLIENTE_H
//#define CONCLIENTE_H
//
//#include "vector.h"
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
//
//
//int salvaCliente(Cliente*c);
//
//int atualizaCliente(Cliente c);
//
//int deletaCliente(float codCliente);
//
//Cliente* listaClientes();
//
//Cliente consultaCliente(float codigo);
//
//
//
//
//
//
//
//#endif /* CONCLIENTE_H */
//

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conCliente.h
 * Author: alunos
 *
 * Created on 20 de Setembro de 2018, 13:48
 */

#ifndef CONCLIENTE_H
#define CONCLIENTE_H

#include "vector.h"
#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif



int salvaCliente(Cliente*c);

int atualizaCliente(Cliente c);

int deletaCliente(float codCliente);

Cliente* listaClientes();

Cliente consultaCliente(float codigo);



#endif /* CONCLIENTE_H */

