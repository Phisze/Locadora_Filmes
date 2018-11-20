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

int tamanhoLocacaos = 0;
int tamanhoLocacaosListar = 0;
Locacao *Locacaos;
int static tamanho = 0;
int static tamanhoTexto = 0;

void criaArrayLocacao() {
    Locacaos = malloc(sizeof (Locacao));
}

//Funcao Inclusao 
//Lebre-se de pensar sobre isso

int inclusaoLocacaos(Locacao f) {
    FILE *arq = fopen("Locacao.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&f, sizeof (f), 1, arq);
    fclose(arq);
    tamanho = getTamanhoLocacao();
    tamanho++;
    setTamanhoLocacao(tamanho);
    return 1;

}

void inclusaoLocacaoTexto(Locacao f) {
    FILE *arquivo;
    int i = 0;
    arquivo = fopen("Locacao.txt", "wt");
    fprintf(arquivo, "%f %f %s %f", f.codigo, f.cliCodigo, f.data);
    while (f.filCodigo[i] != -1) {
        fprintf(arquivo, "%f ", f.filCodigo);
        i++;
    }
    i = 0;
    while (f.parcelas[i] != -1) {
        fprintf(arquivo, "%f ", f.parcelas);
        i++;
    }
    fprintf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
    fclose(arquivo);
    tamanhoTexto = getTamanhoLocacaoTexto();
    tamanhoTexto++;
    setTamanhoLocacaoTexto(tamanhoTexto);
}

void insereLocacaoArrayDinamico(Locacao f) {
    int i = 0;
    tamanhoLocacaos++;
    Locacaos = realloc(Locacaos, tamanhoLocacaos * sizeof (Locacao));
    Locacaos[tamanhoLocacaos - 1].codigo = f.codigo;
    strcpy(Locacaos[tamanhoLocacaos - 1].data, f.data);
    Locacaos[tamanhoLocacaos - 1].cliCodigo = f.cliCodigo;
    while (Locacaos[tamanhoLocacaos - 1].filCodigo[i] != -1) {
        Locacaos[tamanhoLocacaos - 1].filCodigo[i] = f.filCodigo;
        i++;
    }
    i = 0;
    while (Locacaos[tamanhoLocacaos - 1].parcelas[i] != -1) {
        Locacaos[tamanhoLocacaos - 1].parcelas[i] = f.parcelas[i];
        i++;
    }
    Locacaos[tamanhoLocacaos - 1].qtde_Filmes_Locados = f.qtde_Filmes_Locados;
    Locacaos[tamanhoLocacaos - 1].tipo = f.tipo;
    Locacaos[tamanhoLocacaos - 1].valor = f.valor;
}

//Funções de Listar

Locacao * listarLocacaos() {
    int i = 0;
    int cont = 0;
    Locacao f;
    Locacao *fw = &f;
    int tana = getTamanhoLocacao();
    Locacao *array = malloc((tana) * sizeof (Locacao));
    FILE *arq = fopen("Locacao.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&f, sizeof (f), 1, arq)) {
        //if (f.deletado != '*') {

        // VECTOR_ADD(v,c);
        // array[i].nome = nome;
        array[i].codigo = f.codigo;
        strcpy(array[i].data, f.data);
        array[i].cliCodigo = f.cliCodigo;
        array[i].filCodigo = f.filCodigo;
        array[i].qtde_Filmes_Locados = f.qtde_Filmes_Locados;
        array[i].tipo = f.tipo;
        array[i].valor = f.valor;
        array[i].parcelas = f.parcelas;
        i++;
        // } else {
        //    cont++;
        //}
    }
    // array = realloc(array, ((tana-1) - cont) * sizeof (Locacao));

    // fclose(arq);
    return array;
}

Locacao * ListarLocacaoTexto() {
    int i = 0;
    int cont = 0;
    Locacao f;
    FILE *arquivo;
    Locacao *array = malloc(getTamanhoLocacao() * sizeof f);
    arquivo = fopen("Locacao.txt", "rt");
    int w;
    while (!feof(arquivo)) {
        w = 0;
        fscanf(arquivo, "%f %f %s ", f.codigo, f.cliCodigo, f.data);
        while (f.filCodigo[i] != -1) {
            fscanf(arquivo, "%f ", f.filCodigo[w]);
            w++;
        }
        w = 0;
        while (f.parcelas[w] != -1) {
            fscanf(arquivo, "%f ", f.parcelas[w]);
            w++;
        }
        fscanf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        //        if (f.deletado != '*') {
        array[i].codigo = f.codigo;
        strcpy(array[i].data, f.data);
        array[i].cliCodigo = f.cliCodigo;
        w = 0;
        while (f.filCodigo[i] != -1) {
            array[i].filCodigo = f.filCodigo;
            w++;
        }
        array[i].qtde_Filmes_Locados = f.qtde_Filmes_Locados;
        array[i].tipo = f.tipo;
        array[i].valor = f.valor;
        w = 0;
        while (f.parcelas[w] != -1) {
            array[i].parcelas = f.parcelas;
            w++;
        }
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoLocacaoTexto() - 1) - cont) * sizeof (Locacao));
        //        }
    }
    fclose(arquivo);
    return array;
}

Locacao * listarLocacaoArrayDinamico() {
    //    Locacao *array = malloc((tamanhoLocacaos ) * sizeof (Locacao));
    //    tamanhoLocacaos = tamanhoLocacaosListar;
    //    int i;
    //    int j = 0;
    //    int cont = 0;
    //    for (i = 0; i < tamanhoLocacaos; i++) {
    ////        if (Locacaos[i].deletado != '*') {
    //            array[j].codigo = Locacaos[i].codigo;
    //            strcpy(array[j].nome, Locacaos[i].nome);
    //            strcpy(array[j].endereco, Locacaos[i].endereco);
    //            strcpy(array[j].cargo, Locacaos[i].cargo);
    //            strcpy(array[j].telefone, Locacaos[i].telefone);
    //            strcpy(array[j].email, Locacaos[i].email);
    //  j++;
    //        } else {
    //            cont++;
    //            tamanhoLocacaosListar -= cont;
    //            array = realloc(array, (tamanhoLocacaosListar) * sizeof (Locacao));
    //        }
    //}
    return Locacaos;
}

//Funções de Consultar

Locacao consultarLocacaos(float cod) {

    FILE *arq = fopen("Locacao.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Locacao v;
        return v;
    }

    Locacao f;

    //float cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if ((cod == f.codigo) && (f.deletado != '*')) {

            // printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            break;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    Locacao v;
    return f;
}

Locacao ConsultarLocacaoTexto(float cod) {
    FILE *arquivo;
    int i;
    arquivo = fopen("Locacao.txt", "rt");
    Locacao f;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %s ", f.codigo, f.cliCodigo, f.data, f.filCodigo);
        i = 0;

        while (f.parcelas[i] != -1) {
            fscanf(arquivo, "%f ", f.parcelas);
            i++;
        }
        fscanf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        if (f.codigo == cod && f.deletado != '*') {
            break;
        }
    }
    return f;
}

Locacao consultaLocacaoArrayDinamico(int cod) {
    if (Locacaos[cod - 1].deletado != '*') {
        return Locacaos[cod - 1];
    }
    return;
}

//Funções de Alteração

int alterarLocacaos(Locacao Locacao, float cod) {
    FILE *arq = fopen("Locacao.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locacao f;
    //float cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if (cod == f.codigo) {
            //printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", codigo, produtos.descricao, produtos.valor);
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

void alterarLocacaoTexto(float cod, Locacao fun) {
    FILE *arquivo;
    FILE *arq;
    Locacao f;
    int i;
    arquivo = fopen("Locacao.txt", "rt");
    arq = fopen("LocacaoBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %s ", f.codigo, f.cliCodigo, f.data, f.filCodigo);
        i = 0;

        while (f.parcelas[i] != -1) {
            fscanf(arquivo, "%f ", f.parcelas);
            i++;
        }
        fscanf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        if (cod == f.codigo && f.deletado != '*') {
            f.codigo = fun.codigo;
            strcpy(f.data, fun.data);
            f.cliCodigo = fun.cliCodigo;
            i = 0;
            while (Locacaos[i].filCodigo[i] != -1) {
                f.filCodigo[i] = fun.filCodigo[i];
                i++;
            }
            i = 0;
            while (f.parcelas[i] != -1) {
                f.parcelas[i] = fun.parcelas[i];
                i++;
            }
            f.qtde_Filmes_Locados = fun.qtde_Filmes_Locados;
            f.tipo = fun.tipo;
            f.valor = fun.valor;

            //asdasd
            fprintf(arquivo, "%f %f %s %f", f.codigo, f.cliCodigo, f.data);
            i = 0;
            while (f.filCodigo[i] != -1) {
                fprintf(arquivo, "%f ", f.filCodigo);
                i++;
            }

            i = 0;

            i = 0;
            while (f.parcelas[i] != -1) {
                fprintf(arquivo, "%f ", f.parcelas);
                i++;
            }
            fprintf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        } else {
            fprintf(arquivo, "%f %f %s %f", f.codigo, f.cliCodigo, f.data);
            while (f.filCodigo[i] != -1) {
                fprintf(arquivo, "%f ", f.filCodigo);
                i++;
            }
            i = 0;
            while (f.parcelas[i] != -1) {
                fprintf(arquivo, "%f ", f.parcelas);
                i++;
            }
            fprintf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("Locacao.txt");
    rename("LocacaoBackup.txt", "Locacao.txt");
}

void alterarLocacaoArrayDinamico(int cod, Locacao f) {
    int i = 0;
    Locacaos[cod - 1].codigo = f.codigo;
    strcpy(Locacaos[cod - 1].data, f.data);
    Locacaos[cod - 1].cliCodigo = f.cliCodigo;
    Locacaos[cod - 1].filCodigo = f.filCodigo;
    while (Locacaos[cod - 1].filCodigo[i] != -1) {
        Locacaos[cod - 1].filCodigo[i] = f.filCodigo;
        i++;
    }
    i = 0;
    while (Locacaos[cod - 1].parcelas[i] != -1) {
        Locacaos[cod - 1].parcelas[i] = f.parcelas[i];
        i++;
    }
    Locacaos[cod - 1].qtde_Filmes_Locados = f.qtde_Filmes_Locados;
    Locacaos[cod - 1].tipo = f.tipo;
    Locacaos[cod - 1].valor = f.valor;
}
//printf("Alterar %c\n", Locacaos[0].sexo);

//Funcções de exclusão

int excluirLocacaos(float cod) {

    FILE *arq = fopen("Locacao.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Locacao f;
    //float cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%d", &cod);

    while (fread(&f, sizeof (f), 1, arq)) {
        if (cod == f.codigo) {
            //  printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                f.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Locacao)*-1, SEEK_CUR);
                fwrite(&f, sizeof (f), 1, arq);
                fseek(arq, sizeof (f)* 0, SEEK_END);
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

void excluirLocacaoTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Locacao f;
    arquivo = fopen("Locacao.txt", "rt");
    arq = fopen("LocacaoBackup.txt", "wt");
    int i = 0;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %f %s ", f.codigo, f.cliCodigo, f.data, f.filCodigo);
        i = 0;

        while (f.parcelas[i] != -1) {
            fscanf(arquivo, "%f ", f.parcelas);
            i++;
        }
        fscanf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        if (cod == f.codigo && f.deletado != '*') {
            fprintf(arquivo, "%f %f %s %f", f.codigo, f.cliCodigo, f.data);
            while (f.filCodigo[i] != -1) {
                fprintf(arquivo, "%f ", f.filCodigo);
                i++;
            }
            i = 0;
            while (f.parcelas[i] != -1) {
                fprintf(arquivo, "%f ", f.parcelas);
                i++;
            }
            fprintf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        } else {
            fprintf(arquivo, "%f %f %s %f", f.codigo, f.cliCodigo, f.data);
            while (f.filCodigo[i] != -1) {
                fprintf(arquivo, "%f ", f.filCodigo);
                i++;
            }
            i = 0;
            while (f.parcelas[i] != -1) {
                fprintf(arquivo, "%f ", f.parcelas);
                i++;
            }
            fprintf(arquivo, "%d %d %f\n", f.qtde_Filmes_Locados, f.tipo, f.valor);
        }
    }

    fclose(arquivo);
    fclose(arq);
    remove("Locacao.txt");
    rename("LocacaoBackup.txt", "Locacao.txt");
    tamanhoTexto = getTamanhoLocacaoTexto();
    tamanhoTexto--;
    setTamanhoLocacaoTexto(tamanhoTexto);
}

void excluirLocacaoArrayDinamico(int cod) {
    Locacaos[cod - 1].deletado = '*';
}