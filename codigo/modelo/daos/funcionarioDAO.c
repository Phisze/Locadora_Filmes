#include "../../vector.h"
#include "../../structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../../tamanho.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Funcao Inclusao 

//int inclusaoFuncionarios(Funcionario f) {
//    //printf("codcodcod %f ", f.codigo);
//    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
//    //FILE *arq = fopen("..\\..\\..\\..\\cliente.pro", "ab");
//    FILE *arq = fopen("funcionario.pro", "ab");
//
//    if (arq == NULL) {
//        printf("Erro ao abrir arquivo");
//        return 0;
//    }
//
//    fwrite(&f, sizeof (f), 1, arq);
//    fclose(arq);
//    int tamanho = getTamanhoFuncionario();
//    tamanho++;
//    setTamanhoFuncionario(tamanho);
//    return 1;
//
//}
//
//Funcionario* listarFuncionarios() {
//    int i = 0;
//
//    Funcionario f;
//    Funcionario *fw = &f;
//    Funcionario *array = malloc(getTamanhoFuncionario() * sizeof f);
//    // VECTOR_INIT(v);
//    //    Cliente *cli = &clientes;
//    FILE *arq = fopen("funcionario.pro", "rb");
//    //printf("Arquivo xistente!");
//
//    if (arq == NULL) {
//        printf("Arquivo inexistente!");
//
//        return;
//    }
//    while (fread(&f, sizeof (f), 1, arq)) {
//        if (f.deletado != '*') {
//
//            // VECTOR_ADD(v,c);
//            // array[i].nome = c.nome;
//            array[i].codigo = f.codigo;
//            strcpy(array[i].nome, f.nome);
//            strcpy(array[i].endereco, f.endereco);
//            strcpy(array[i].telefone, f.telefone);
//            strcpy(array[i].email, f.email);
//            strcpy(array[i].cargo, f.cargo);
//            // }
//            //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);
//
//            //VECTOR_ADD(clientes, cw);
//            //printf("Cod %s\n", c.nome);
//            i++;
//        }
//    }
//    fclose(arq);
//    return array;
//}
//
//Funcionario consultarFuncionarios(int cod) {
//
//    FILE *arq = fopen("funcionario.pro", "rb");
//    if (arq == NULL) {
//        printf("Arquivo inexistente!");
//        Funcionario v;
//        return v;
//    }
//
//    Funcionario f;
//
//    //int cod;
//    int achei = 0;
//    //printf("\nDigite o codigo que procura: \n");
//    //scanf("%d", &cod);
//
//    while (fread(&f, sizeof (f), 1, arq)) {
//        if ((cod == f.codigo) && (f.deletado != '*')) {
//
//            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
//            achei = 1;
//            return f;
//        }
//    }
//
//    if (!achei) {
//        printf("\nCodigo nao cadastrado!!\n");
//    }
//    fclose(arq);
//    Funcionario v;
//    return v;
//}
//
//int alterarFuncionarios(Funcionario funcionario, int cod) {
//    FILE *arq = fopen("funcionario.pro", "r+b");
//    if (arq == NULL) {
//        printf("Arquivo inexistente!");
//        return 0;
//    }
//
//    Funcionario f;
//    //int cod, 
//    int achei = 0;
//    //printf("\nDigite o codigo que deseja alterar: \n");
//    //scanf("%d", &cod);
//
//    while (fread(&f, sizeof (f), 1, arq)) {
//        if (cod == f.codigo) {
//            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
//            achei = 1;
//
//            fseek(arq, sizeof (Funcionario)*-1, SEEK_CUR);
//            //  printf("\nDigite a nova descricao: \n");
//            fflush(stdin);
//            //  scanf("%s", produtos.descricao);
//            // printf("\nDigite o novo preco....: \n");
//            //scanf("%f", &produtos.valor);
//
//            fwrite(&funcionario, sizeof (funcionario), 1, arq);
//            fseek(arq, sizeof (funcionario)* 0, SEEK_END);
//            return 1;
//        }
//    }
//
//    if (!achei)
//        printf("\nCodigo nao cadastrado!!\n");
//
//    fclose(arq);
//    return 0;
//}
//
//int excluirFuncionarios(int cod) {
//
//    FILE *arq = fopen("funcionario.pro", "r+b");
//    if (arq == NULL) {
//        printf("Arquivo inexistente!");
//        return 0;
//    }
//
//    Funcionario f;
//    //int cod, 
//    int achei = 0;
//    char certeza;
//    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
//    // scanf("%d", &cod);
//
//    while (fread(&f, sizeof (f), 1, arq)) {
//        if (cod == f.codigo) {
//            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
//            achei = 1;
//
//            printf("\nTem certeza que quer excluir este produto? s/n \n");
//            fflush(stdin);
//            scanf("%c", &certeza);
//            if (certeza == 's') {
//                f.deletado = '*';
//                printf("\nProduto excluido com Sucesso! \n");
//                fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
//                fwrite(&f, sizeof (f), 1, arq);
//                fseek(arq, sizeof (f)* 0, SEEK_END);
//                return 1;
//            } else if (certeza == 'n')
//                return 1;
//        }
//    }
//
//    if (!achei)
//        printf("\nCodigo nao cadastrado!!\n");
//
//    fclose(arq);
//    return 0;
//}