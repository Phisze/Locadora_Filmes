#include "../../vector.h"
#include "../../structs.h"
//#include "../../clienteDAO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tamanho.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//vector v = {NULL, 4, 0};
const int controla = 1;

//Funcões de Inclusao 

int inclusaoCliente(Cliente c) {
    int tamanho = getTamanhoCliente();
    //c.codigo = tamanho + 1;
    //printf("codcodcod %f ", c.codigo);
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    //FILE *arq = fopen("..\\..\\..\\..\\cliente.pro", "ab");
    FILE *arq = fopen("cliente.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&c, sizeof (c), 1, arq);
    fclose(arq);

    tamanho++;
    setTamanhoCliente(tamanho);
    return 1;
}

int inclusaoClienteTexto(Cliente c) {
    FILE *arquivo;
    arquivo = fopen("cliente.txt", "wt");
    c.data_nascimento = '/'
            fprintf(arquivo, "%d %s %s %s %s %s %c %s %s %c\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento, c.deletado);
    fclose(arquivo);
    return 1;
}

//Funções de Listar

Cliente* lClientes() {
    int i = 0;

    Cliente c;
    Cliente *cw = &c;
    Cliente *array = malloc(getTamanhoCliente() * sizeof c);
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("cliente.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&c, sizeof (c), 1, arq)) {
        if (c.deletado != '*') {

            // VECTOR_ADD(v,c);
            // array[i].nome = c.nome;
            array[i].codigo = c.codigo;
            strcpy(array[i].nome, c.nome);
            strcpy(array[i].endereco, c.endereco);
            strcpy(array[i].cpf, c.cpf);
            strcpy(array[i].telefone, c.telefone);
            strcpy(array[i].email, c.email);
            array[i].sexo = c.sexo;
            strcpy(array[i].estado_civil, c.estado_civil);
            strcpy(array[i].data_nascimento, c.data_nascimento);
            // }
            //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

            //VECTOR_ADD(clientes, cw);
            //printf("Cod %s\n", c.nome);
            i++;
        }
    }
    fclose(arq);
    return array;
}

Cliente* Listar() {
    int i = 0;
    Cliente c;
    FILE *arquivo;
    Cliente *array = malloc(getTamanhoCliente() * sizeof c);
    char nome[30];
    int telefone;
    //Cliente c;
    arquivo = fopen("vendas.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%d %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
        if (c.deletado != '*') {
            array[i].codigo = c.codigo;
            strcpy(array[i].nome, c.nome);
            strcpy(array[i].endereco, c.endereco);
            strcpy(array[i].cpf, c.cpf);
            strcpy(array[i].telefone, c.telefone);
            strcpy(array[i].email, c.email);
            array[i].sexo = c.sexo;
            strcpy(array[i].estado_civil, c.estado_civil);
            strcpy(array[i].data_nascimento, c.data_nascimento);
            i++;
        }
    }
    fclose(arquivo);
    return array;
}

//Funções de Consultar

Cliente consultarClientes(int cod) {

    FILE *arq = fopen("cliente.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Cliente v;
        return v;
    }

    Cliente c;

    //int cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%d", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if ((cod == c.codigo) && (c.deletado != '*')) {

            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            return c;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    Cliente v;
    return v;
}

Cliente Consultar(int cod) {
    FILE *arquivo;
    arquivo = fopen("vendas.txt", "rt");
    Cliente c;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d %s %d ", &c.codigo, &c.nome, &c.telefone);
        if (c.codigo == cod && c.deletado != '*') {
            break;
        }
    }
    return c;
}

//Funções de Alteração
int alterarCliente(Cliente clintes, int cod) {
    FILE *arq = fopen("cliente.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Cliente c;
    //int cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&clintes, sizeof (clintes), 1, arq);
            fseek(arq, sizeof (clintes)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

//Funcções de exclusão

int excluirCliente(int cod) {

    FILE *arq = fopen("produtos.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Cliente c;
    //int cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%d", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                c.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
                fwrite(&c, sizeof (c), 1, arq);
                fseek(arq, sizeof (c)* 0, SEEK_END);
                return 1;
            } else if (certeza == 'n')
                return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}