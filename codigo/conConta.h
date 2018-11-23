/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conConta.h
 * Author: alunos
 *
 * Created on 23 de Novembro de 2018, 14:26
 */

#ifndef CONCONTA_H
#define CONCONTA_H

#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

int salvaConta(Conta *l);
int deletaConta(float codLoc);
Conta* listaContas();
Conta consultaConta(float codigo);

#endif /* CONCONTA_H */

