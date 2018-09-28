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

#include "vector.h"

#define NOME 30
#define ENDERECO 50
#define CPF 11
#define TELEFONE 13
#define EMAIL 35
#define ESTADO_CIVIL 10
#define DATA_NASCIMENTO 8
#define DESCRICAO 100
#define LINGUA 10
#define CARGO 10
#define RAZAO_SOCIAL 20
#define INSCRICAO_ESTADUAL 20
#define CNPJ 14



typedef struct {
    float codigo;
    char nome[NOME];
    char endereco[ENDERECO];
    char cpf[CPF];
    char telefone[TELEFONE];
    char email[EMAIL];
    char sexo;
    char estado_civil[ESTADO_CIVIL];
    char data_nascimento[DATA_NASCIMENTO];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Cliente;

typedef struct {
    float codigo;
    char descricao[DESCRICAO];
    float exemplares;
    float catCodigo;
    char lingua[LINGUA];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Filme;

typedef struct {
    float codigo;
    char descricao[DESCRICAO];
    float valor_locacao;
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Categoria;

typedef struct {
    float codigo;
    char nome[NOME];
    char cargo[CARGO];
    char endereco[ENDERECO];
    char telefone[TELEFONE];
    char email[EMAIL];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Funcionario;

typedef struct {
    float codigo;
    char nome[NOME];
    char razao_social[RAZAO_SOCIAL];
    char inscricao_estadual[INSCRICAO_ESTADUAL];
    char cnpj[CNPJ];
    char endereco[ENDERECO];
    char telefone[TELEFONE];
    char email[EMAIL];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Fornecedor;

typedef struct {
    char nome[NOME];
    char razao_social[RAZAO_SOCIAL];
    char inscricao_estadual[INSCRICAO_ESTADUAL];
    char cnpj[CNPJ];
    char endereco[ENDERECO];
    char telefone[TELEFONE];
    char email[EMAIL];
    char nome_responsavel[NOME];
    char tel_responsavel[TELEFONE];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Locadora;

#endif /* STRUCTS_H */