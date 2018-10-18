/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conFilme.h
 * Author: alunos
 *
 * Created on 18 de Outubro de 2018, 14:56
 */

#ifndef CONFILME_H
#define CONFILME_H

#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif


int salvaFilme(Filme *f);
int atualizaFilme(Filme f);
int deletaFilme(int codFilme);
Filme* listaFilmes();
Filme consultaFilme(int codigo);


#endif /* CONFILME_H */

