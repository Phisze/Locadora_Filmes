/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conCategoria.h
 * Author: alunos
 *
 * Created on 19 de Outubro de 2018, 14:11
 */

#ifndef CONCATEGORIA_H
#define CONCATEGORIA_H
#include "vector.h"
#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif



int salvaCategoria(Categoria*c);

int atualizaCategoria(Categoria c);

int deletaCategoria(float codCategoria);

Categoria* listaCategorias();

Categoria consultaCategoria(float codigo);




#endif /* CONCATEGORIA_H */

