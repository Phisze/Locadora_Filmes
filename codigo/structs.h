/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: alunos
 *
 * Created on 23 de Agosto de 2018, 15:02
 */

#ifndef STRUCTS_H
#define STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#include "../../vector.h"

typedef struct {
    float codigo;
    vector nome;
    vector endereco;
    vector cpf;
    vector telefone;
    vector email;
    char sexo;
    vector estado_civil;
    vector data_nascimento;

} Cliente;

typedef struct {
    float codigo;
    vector descricao;
    float exemplares;
    float catCodigo;
    char lingua;
} Filme;

typedef struct {
    float codigo;
    float descricao;
    float valor_locacao;
} Categoria;

typedef struct {
    float codigo;
    vector nome;
    vector cargo;
    vector endereco;
    vector telefone;
    vector email;
} Funcionario;

typedef struct {
    float codigo;
    vector nome;
    vector razão_social;
    vector inscricao_estadual;
    vector cnpj;
    vector endereco;
    vector telefone;
    vector email;
} Fornecedor;

typedef struct {
    vector nome;
    vector razao_social;
    vector inscricao_estadual;
    vector cnpj;
    vector endereco;
    vector telefone;
    vector email;
    vector nome_responsavel;
    vector tel_responsavel;
} Locadora;

#endif /* STRUCTS_H */
