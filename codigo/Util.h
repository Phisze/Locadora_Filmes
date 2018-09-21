/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: alunos
 *
 * Created on 21 de Setembro de 2018, 14:07
 */

#ifndef UTIL_H
#define UTIL_H

#include "structs.h"


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

int init_Cliente(Cliente *c) {
    
    c->nome.capacity = VECTOR_INIT_CAPACITY;
    c->nome.total = 0;
    c->nome.items = malloc(sizeof (void *) * c->nome.capacity);
 //   c->nome.items = calloc(sizeof (void *) * c->nome.capacity, sizeof (void*));

    c->cpf.capacity = VECTOR_INIT_CAPACITY;
    c->cpf.total = 0;
    c->cpf.items = calloc(sizeof (void *) * c->cpf.capacity, sizeof (void*));

    c->data_nascimento.capacity = VECTOR_INIT_CAPACITY;
    c->data_nascimento.total = 0;
    c->data_nascimento.items = calloc(sizeof (void *) * c->data_nascimento.capacity, sizeof (void*));

    c->email.capacity = VECTOR_INIT_CAPACITY;
    c->email.total = 0;
    c->email.items = calloc(sizeof (void *) * c->email.capacity, sizeof (void*));

    c->endereco.capacity = VECTOR_INIT_CAPACITY;
    c->endereco.total = 0;
    c->endereco.items = calloc(sizeof (void *) * c->endereco.capacity, sizeof (void*));

    c->estado_civil.capacity = VECTOR_INIT_CAPACITY;
    c->estado_civil.total = 0;
    c->estado_civil.items = calloc(sizeof (void *) * c->estado_civil.capacity, sizeof (void*));

    c->telefone.capacity = VECTOR_INIT_CAPACITY;
    c->telefone.total = 0;
    c->telefone.items = calloc(sizeof (void *) * c->telefone.capacity, sizeof (void*));

}


#endif /* UTIL_H */

