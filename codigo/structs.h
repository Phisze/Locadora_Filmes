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

typedef struct {
    float codigo;
    char nome[30];
    char endereco[50];
    char cpf[11];
    char telefone[13];
    char email[35];
    char sexo;
    char estado_civil[10];
    char data_nascimento[6];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Cliente;

typedef struct {
    float codigo;
    char descricao[100];
    float exemplares;
    float catCodigo;
    char lingua[10];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Filme;

typedef struct {
    float codigo;
    char descricao[50];
    float valor_locacao;
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Categoria;

typedef struct {
    float codigo;
    char nome[30];
    char cargo[10];
    char endereco[50];
    char telefone[13];
    char email[35];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Funcionario;

typedef struct {
    float codigo;
    char nome[30];
    char razao_social[20];
    char inscricao_estadual[20];
    char cnpj[14];
    char endereco[50];
    char telefone[13];
    char email[35];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Fornecedor;

typedef struct {
    char nome[30];
    char razao_social[20];
    char inscricao_estadual[20];
    char cnpj[14];
    char endereco[50];
    char telefone[13];
    char email[35];
    char nome_responsavel[30];
    char tel_responsavel[13];
    char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
} Locadora;

#endif /* STRUCTS_H */
