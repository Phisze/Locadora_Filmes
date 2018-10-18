/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.h
 * Author: alunos
 *
 * Created on 23 de Agosto de 2018, 14:18
 */

#ifndef VECTOR_H
#define VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

//https://eddmann.com/posts/implementing-a-dynamic-vector-array-in-c/
#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) vector vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct vector {
    void **items;
    int capacity;
    int total;
} vector;

typedef struct {
    Cliente *items;
    int capacity;
    int total;
} vectorCliente;




void vector_init(vector *);
int vector_total(vector *);
static void vector_resize(vector *, int);
void vector_add(vector *, void *);
void vector_set(vector *, int, void *);
void *vector_get(vector *, int);
void vector_delete(vector *, int);
void vector_free(vector *);

int vector_init_Cli(Cliente *);
int vector_add_Cli(Cliente *, Cliente *);
int vector_delete(Cliente *, int);
Cliente *vector_get(Cliente *, int);
int vector_set(Cliente *, int, Cliente *);
int vector_free(Cliente *);
static Cliente* vector_resize(vector *, int);

#endif /* VECTOR_H */
