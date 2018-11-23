#include "../../vector.h"
#include "../../structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tamanho.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

int tamanhoContas = 0;
int tamanhoContasListar = 0;
Conta static *Contas;
int static tamanho = 0;
int static tamanhoTexto = 0;

void criaArrayConta() {
    Contas = malloc(sizeof (Conta));
}
//Funcao Inclusao 

int inclusaoConta(Conta l) {
    FILE *arq = fopen("Conta.pro", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&l, sizeof (l), 1, arq);
    fclose(arq);
    tamanho = getTamanhoConta();
    tamanho++;
    setTamanhoConta(tamanho);
    return 1;
}

void inclusaoContaTexto(Conta l) {
    FILE *arquivo;
    arquivo = fopen("Conta.txt", "a");
    fprintf(arquivo, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
    fclose(arquivo);
    tamanhoTexto = getTamanhoContaTexto();
    tamanhoTexto++;
    setTamanhoContaTexto(tamanhoTexto);
}

void insereContaArrayDinamico(Conta c) {
    tamanhoContas++;
    Contas = realloc(Contas, tamanhoContas * sizeof (Conta));
    Contas[tamanhoContas - 1].codigo = c.codigo;
    strcpy(Contas[tamanhoContas - 1].data, c.data);
    Contas[tamanhoContas - 1].cliCodigo = c.cliCodigo;
    Contas[tamanhoContas - 1].deletado = c.deletado;
    Contas[tamanhoContas - 1].qtdParcela = c.qtdParcela;
    Contas[tamanhoContas - 1].qtdParcelaInicial = c.qtdParcelaInicial;
    Contas[tamanhoContas - 1].tipo = c.tipo;
    Contas[tamanhoContas - 1].valor = c.valor;
    Contas[tamanhoContas - 1].valorParcela c.valorParcela;

}
//Funções de Listar

Conta* listarConta() {
    int i = 0;
    int cont = 0;
    Conta l;
    Conta *fw = &l;
    Conta *array = malloc(getTamanhoConta() * sizeof l);
    FILE *arq = fopen("Conta.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&l, sizeof (l), 1, arq)) {
        //        if (l.deletado != '*') {

        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        array[i].codigo = l.codigo;
        strcpy(array[i].data, l.data);
        array[i].cliCodigo = l.cliCodigo;
        array[i].deletado = l.deletado;
        array[i].qtdParcela = l.qtdParcela;
        array[i].qtdParcelaInicial = l.qtdParcelaInicial;
        array[i].tipo = l.tipo;
        array[i].valor = l.valor;
        array[i].valorParcela = l.valorParcela;
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoConta() - 1) - cont) * sizeof (Conta));
        //        }
    }
    fclose(arq);
    return array;
}

Conta* ListarContaTexto() {
    int i = 0;
    int cont;
    Conta l;
    FILE *arquivo;
    Conta *array = malloc(getTamanhoContaTexto() * sizeof l);
    arquivo = fopen("Conta.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        //  if (l.deletado != '*') {
        array[i].codigo = l.codigo;
        strcpy(array[i].data, l.data);
        array[i].cliCodigo = l.cliCodigo;
        array[i].deletado = l.deletado;
        array[i].qtdParcela = l.qtdParcela;
        array[i].qtdParcelaInicial = l.qtdParcelaInicial;
        array[i].tipo = l.tipo;
        array[i].valor = l.valor;
        array[i].valorParcela = l.valorParcela;
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoContaTexto() - 1) - cont) * sizeof (Conta));
        //        }
    }
    fclose(arquivo);
    return array;
}

Conta* listarContaArrayDinamico() {
    //    Conta *array = malloc((tamanhoContas) * sizeof (Conta));
    //    tamanhoContas = tamanhoContasListar;
    //    int i;
    //    int j = 0;
    //    int cont = 0;
    //    for (i = 0; i < tamanhoContas; i++) {
    //    //    if (Contas[i].deletado != '*') {
    //            array[j].codigo = Contas[i].codigo;
    //            strcpy(array[j].nome, Contas[i].nome);
    //            strcpy(array[j].endereco, Contas[i].endereco);
    //            strcpy(array[j].razao_social, Contas[i].razao_social);
    //            strcpy(array[j].inscricao_estadual, Contas[i].inscricao_estadual);
    //            strcpy(array[j].cnpj, Contas[i].cnpj);
    //            strcpy(array[j].telefone, Contas[i].telefone);
    //            strcpy(array[j].email, Contas[i].email);
    //            strcpy(array[j].nome_responsavel, Contas[i].nome_responsavel);
    //            strcpy(array[j].tel_responsavel, Contas[i].tel_responsavel);
    //            j++;
    //        } else {
    //            cont++;
    //            tamanhoContasListar -= cont;
    //            array = realloc(array, (tamanhoContasListar) * sizeof (Conta));
    //        };
    //   }
    //printf("Listar %c\n", array[0].sexo);

    return Contas;
}

//Funções de Consultar

Conta consultarConta(float cod) {

    FILE *arq = fopen("Conta.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Conta v;
        return v;
    }

    Conta l;

    //float cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if ((cod == l.codigo) && (l.deletado != '*')) {

            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            return l;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    Conta v;
    return v;
}

Conta ConsultarContaTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("Conta.txt", "rt");
    Conta l;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        if (l.codigo == cod && l.deletado != '*') {
            break;
        }
    }
    return l;
}

Conta consultaContaArrayDinamico(int cod) {
    if (Contas[cod - 1].deletado != '*') {
        return Contas[cod - 1];
    }
    return;
}

//Funções de Alteração

int alterarConta(Conta Conta, float cod) {
    FILE *arq = fopen("Conta.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Conta l;
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if (cod == l.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Conta)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&Conta, sizeof (Conta), 1, arq);
            fseek(arq, sizeof (Conta)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

void alterarContaTexto(float cod, Conta loc) {
    FILE *arquivo;
    FILE *arq;
    Conta l;
    arquivo = fopen("Conta.txt", "rt");
    arq = fopen("ContaBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        if (cod == l.codigo && l.deletado != '*') {
            l.codigo = loc.codigo;
            l.codigo = loc.codigo;
            strcpy(l.data, loc.data);
            l.cliCodigo = loc.cliCodigo;
            l.deletado = loc.deletado;
            l.qtdParcela = loc.qtdParcela;
            l.qtdParcelaInicial = loc.qtdParcelaInicial;
            l.tipo = loc.tipo;
            l.valor = loc.valor;
            l.valorParcela = loc.valorParcela;
            fprintf(arq, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        } else {
            fprintf(arq, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("Conta.txt");
    rename("ContaBackup.txt", "Conta.txt");
}

void alterarContaArrayDinamico(int cod, Conta c) {
    Contas[cod - 1].codigo = c.codigo;
    strcpy(Contas[cod - 1].data, c.data);
    Contas[cod - 1].cliCodigo = c.cliCodigo;
    Contas[cod - 1].deletado = c.deletado;    
    Contas[cod - 1].qtdParcela = c.qtdParcela;
    Contas[cod - 1].qtdParcelaInicial = c.qtdParcelaInicial;
    Contas[cod - 1].tipo = c.tipo;
    Contas[cod - 1].valor = c.valor;
    Contas[cod - 1].valorParcela = c.valorParcela;
}

//Funcções de exclusão

int excluirConta(float cod) {

    FILE *arq = fopen("Conta.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Conta l;
    //float cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if (cod == l.codigo) {
            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                l.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Conta)*-1, SEEK_CUR);
                fwrite(&l, sizeof (l), 1, arq);
                fseek(arq, sizeof (l)* 0, SEEK_END);
                // return 1;
            } else if (certeza == 'n')
                return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

void excluirContaTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Conta l;
    arquivo = fopen("Conta.txt", "rt");
    arq = fopen("ContaBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        if (cod == l.codigo && l.deletado != '*') {
        } else {
            fprintf(arq, "%f %f %f %d %d %d %s %f\n", l.codigo, l.cliCodigo, l.valor, l.tipo, l.qtdParcelaInicial, l.qtdParcela, l.data, l.valorParcela);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("Conta.txt");
    rename("ContaBackup.txt", "Conta.txt");
    tamanhoTexto = getTamanhoContaTexto();
    tamanhoTexto--;
    setTamanhoContaTexto(tamanhoTexto);
}

void excluirContaArrayDinamico(int cod) {
    Contas[cod - 1].deletado = '*';
}