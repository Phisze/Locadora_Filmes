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

int tamanhoLocacaos = 0;
int tamanhoLocacaosListar = 0;
Locacao static *Locacaos;
int static tamanho = 0;
int static tamanhoTexto = 0;

void criaArrayLocacao() {
    Locacaos = malloc(sizeof (Locacao));
}
//Funcao Inclusao 

int inclusaoLocacao(Locacao l) {
    FILE *arq = fopen("Locacao.pro", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&l, sizeof (l), 1, arq);
    fclose(arq);
    tamanho = getTamanhoLocacao();
    tamanho++;
    setTamanhoLocacao(tamanho);
    return 1;
}

int inclusaoLocacaoTexto(Locacao l) {
    FILE *arquivo;
    arquivo = fopen("Locacao.txt", "a");
    fprintf(arquivo, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
    fclose(arquivo);
    tamanhoTexto = getTamanhoLocacaoTexto();
    tamanhoTexto++;
    setTamanhoLocacaoTexto(tamanhoTexto);
    return 1;
}

int insereLocacaoArrayDinamico(Locacao c) {
    tamanhoLocacaos++;
    Locacaos = realloc(Locacaos, tamanhoLocacaos * sizeof (Locacao));
    Locacaos[tamanhoLocacaos - 1].codigo = c.codigo;
    strcpy(Locacaos[tamanhoLocacaos - 1].data, c.data);
    Locacaos[tamanhoLocacaos - 1].cliCodigo = c.cliCodigo;
    Locacaos[tamanhoLocacaos - 1].deletado = c.deletado;
    Locacaos[tamanhoLocacaos - 1].filCodigo1 = c.filCodigo1;
    Locacaos[tamanhoLocacaos - 1].filCodigo2 = c.filCodigo2;
    Locacaos[tamanhoLocacaos - 1].filCodigo3 = c.filCodigo3;
    Locacaos[tamanhoLocacaos - 1].qtdParcela = c.qtdParcela;
    Locacaos[tamanhoLocacaos - 1].qtdParcelaInicial = c.qtdParcelaInicial;
    Locacaos[tamanhoLocacaos - 1].qtde_Filmes_Locados = c.qtde_Filmes_Locados;
    Locacaos[tamanhoLocacaos - 1].tipo = c.tipo;
    Locacaos[tamanhoLocacaos - 1].valor = c.valor;
    Locacaos[tamanhoLocacaos - 1].valorParcela = c.valorParcela;
    return 1;
}
//Funções de Listar
Locacao l;
Locacao* listarLocacao(){
    int i = 0;
    int cont = 0;

    Locacao *fw = &l;
    Locacao *array = malloc(getTamanhoLocacao() * sizeof (Locacao));
    FILE *arq = fopen("Locacao.pro", "rb");
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
        array[i].filCodigo1 = l.filCodigo1;
        array[i].filCodigo2 = l.filCodigo2;
        array[i].filCodigo3 = l.filCodigo3;
        array[i].qtdParcela = l.qtdParcela;
        array[i].qtdParcelaInicial = l.qtdParcelaInicial;
        array[i].qtde_Filmes_Locados = l.qtde_Filmes_Locados;
        array[i].tipo = l.tipo;
        array[i].valor = l.valor;
        array[i].valorParcela = l.valorParcela;
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoLocacao() - 1) - cont) * sizeof (Locacao));
        //        }
    }
    fclose(arq);
    return array;
}

Locacao* ListarLocacaoTexto() {
    int i = 0;
    int cont;
    Locacao l;
    FILE *arquivo;
    Locacao *array = malloc(getTamanhoLocacaoTexto() * sizeof l);
    arquivo = fopen("Locacao.txt", "rt");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        //  if (l.deletado != '*') {
        array[i].codigo = l.codigo;
        strcpy(array[i].data, l.data);
        array[i].cliCodigo = l.cliCodigo;
        array[i].deletado = l.deletado;
        array[i].filCodigo1 = l.filCodigo1;
        array[i].filCodigo2 = l.filCodigo2;
        array[i].filCodigo3 = l.filCodigo3;
        array[i].qtdParcela = l.qtdParcela;
        array[i].qtdParcelaInicial = l.qtdParcelaInicial;
        array[i].qtde_Filmes_Locados = l.qtde_Filmes_Locados;
        array[i].tipo = l.tipo;
        array[i].valor = l.valor;
        array[i].valorParcela = l.valorParcela;
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoLocacaoTexto() - 1) - cont) * sizeof (Locacao));
        //        }
    }
    fclose(arquivo);
    return array;
}

Locacao* listarLocacaoArrayDinamico() {
    //    Locacao *array = malloc((tamanhoLocacaos) * sizeof (Locacao));
    //    tamanhoLocacaos = tamanhoLocacaosListar;
    //    int i;
    //    int j = 0;
    //    int cont = 0;
    //    for (i = 0; i < tamanhoLocacaos; i++) {
    //    //    if (Locacaos[i].deletado != '*') {
    //            array[j].codigo = Locacaos[i].codigo;
    //            strcpy(array[j].nome, Locacaos[i].nome);
    //            strcpy(array[j].endereco, Locacaos[i].endereco);
    //            strcpy(array[j].razao_social, Locacaos[i].razao_social);
    //            strcpy(array[j].inscricao_estadual, Locacaos[i].inscricao_estadual);
    //            strcpy(array[j].cnpj, Locacaos[i].cnpj);
    //            strcpy(array[j].telefone, Locacaos[i].telefone);
    //            strcpy(array[j].email, Locacaos[i].email);
    //            strcpy(array[j].nome_responsavel, Locacaos[i].nome_responsavel);
    //            strcpy(array[j].tel_responsavel, Locacaos[i].tel_responsavel);
    //            j++;
    //        } else {
    //            cont++;
    //            tamanhoLocacaosListar -= cont;
    //            array = realloc(array, (tamanhoLocacaosListar) * sizeof (Locacao));
    //        };
    //   }
    //printf("Listar %c\n", array[0].sexo);

    return Locacaos;
}

//Funções de Consultar

Locacao consultarLocacao(float cod) {

    FILE *arq = fopen("Locacao.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Locacao v;
        return v;
    }

    Locacao l;

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
    Locacao v;
    return v;
}

Locacao ConsultarLocacaoTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("Locacao.txt", "rt");
    Locacao l;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        if (l.codigo == cod && l.deletado != '*') {
            break;
        }
    }
    return l;
}

Locacao consultaLocacaoArrayDinamico(int cod) {
    if (Locacaos[cod - 1].deletado != '*') {
        return Locacaos[cod - 1];
    }
    return;
}

//Funções de Alteração
Locacao l;
int alterarLocacao(Locacao Locacao, float cod) {
    FILE *arq = fopen("Locacao.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&l, sizeof (l), 1, arq)) {
        if (cod == l.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Locacao)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&Locacao, sizeof (Locacao), 1, arq);
            fseek(arq, sizeof (Locacao)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

int alterarLocacaoTexto(float cod, Locacao loc) {
    FILE *arquivo;
    FILE *arq;
    Locacao l;
    arquivo = fopen("Locacao.txt", "rt");
    arq = fopen("LocacaoBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        if (cod == l.codigo && l.deletado != '*') {
            l.codigo = loc.codigo;
            l.codigo = loc.codigo;
            strcpy(l.data, loc.data);
            l.cliCodigo = loc.cliCodigo;
            l.deletado = loc.deletado;
            l.filCodigo1 = loc.filCodigo1;
            l.filCodigo2 = loc.filCodigo2;
            l.filCodigo3 = loc.filCodigo3;
            l.qtdParcela = loc.qtdParcela;
            l.qtdParcelaInicial = loc.qtdParcelaInicial;
            l.qtde_Filmes_Locados = loc.qtde_Filmes_Locados;
            l.tipo = loc.tipo;
            l.valor = loc.valor;
            l.valorParcela = loc.valorParcela;
            fprintf(arq, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        } else {
            fprintf(arq, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("Locacao.txt");
    rename("LocacaoBackup.txt", "Locacao.txt");
    return 1;
}

int alterarLocacaoArrayDinamico(int cod, Locacao c) {
    Locacaos[cod - 1].codigo = c.codigo;
    strcpy(Locacaos[cod - 1].data, c.data);
    Locacaos[cod - 1].cliCodigo = c.cliCodigo;
    Locacaos[cod - 1].deletado = c.deletado;
    Locacaos[cod - 1].filCodigo1 = c.filCodigo1;
    Locacaos[cod - 1].filCodigo2 = c.filCodigo2;
    Locacaos[cod - 1].filCodigo3 = c.filCodigo3;
    Locacaos[cod - 1].qtdParcela = c.qtdParcela;
    Locacaos[cod - 1].qtdParcelaInicial = c.qtdParcelaInicial;
    Locacaos[cod - 1].qtde_Filmes_Locados = c.qtde_Filmes_Locados;
    Locacaos[cod - 1].tipo = c.tipo;
    Locacaos[cod - 1].valor = c.valor;
    Locacaos[cod - 1].valorParcela = c.valorParcela;
    return 1;
}

//Funcções de exclusão

int excluirLocacao(float cod) {

    FILE *arq = fopen("Locacao.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locacao l;
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
                fseek(arq, sizeof (Locacao)*-1, SEEK_CUR);
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
    return 1;
}

int excluirLocacaoTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Locacao l;
    arquivo = fopen("Locacao.txt", "rt");
    arq = fopen("LocacaoBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        if (cod == l.codigo && l.deletado != '*') {
        } else {
            fprintf(arq, "%f %f %d %d %d %d %s %f %d %d %d %f\n", l.codigo, l.cliCodigo, l.filCodigo1, l.filCodigo2, l.filCodigo3, l.tipo, l.data, l.valor, l.qtde_Filmes_Locados, l.qtdParcelaInicial, l.qtdParcela, l.valorParcela);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("Locacao.txt");
    rename("LocacaoBackup.txt", "Locacao.txt");
    tamanhoTexto = getTamanhoLocacaoTexto();
    tamanhoTexto--;
    setTamanhoLocacaoTexto(tamanhoTexto);
    return 1;
}

int excluirLocacaoArrayDinamico(int cod) {
    Locacaos[cod - 1].deletado = '*';
    return 1;
}