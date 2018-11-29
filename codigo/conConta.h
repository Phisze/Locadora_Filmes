/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conConta.h
 * Author: alunos
 *
 * Created on 29 de Novembro de 2018, 19:08
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

int salvaConta(Conta * c);

int atualizaConta(Conta c);

int deletaConta(float codigo);

Conta* listaContas();

int qtdConta();

Conta consultaConta(float codigo);

#endif /* CONCONTA_H */

