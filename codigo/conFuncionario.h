/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conFuncionario.h
 * Author: alunos
 *
 * Created on 19 de Outubro de 2018, 13:33
 */

#ifndef CONFUNCIONARIO_H
#define CONFUNCIONARIO_H

#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif


int salvaFuncionario(Funcionario *f);
int atualizaFuncionario(Funcionario f);
int deletaFuncionario(float codFunc);
Funcionario* listaFuncionarios();
Funcionario consultaFuncionario(float codigo);

#endif /* CONFUNCIONARIO_H */

