/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conLocadora.h
 * Author: alunos
 *
 * Created on 19 de Outubro de 2018, 13:51
 */

#ifndef CONLOCADORA_H
#define CONLOCADORA_H

#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif


int salvaLocadora(Locadora *l);
int atualizaLocadora(Locadora l);
int deletaLocadora(float codLoc);
Locadora* listaLocadoras();
Locadora consultaLocadora(float codigo);

#endif /* CONLOCADORA_H */

