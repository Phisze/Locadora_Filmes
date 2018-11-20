#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "../structs.h"
#include "../conCliente.h"
#include "../conFilme.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
time_t to_seconds(const char *date) {
    struct tm storage = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char *p = NULL;
    time_t retval = 0;
    p = (char *) strptime(date, "%d/%m/%Y", &storage);
    if (p == NULL) {
        retval = 0;
    } else {
        retval = mktime(&storage);
    }
    return retval;
}

Cliente* clienteCodigoFeedback(int cod1, int cod2) {
    Cliente *Clientes;
    Clientes = listaClientes();
    Cliente *array = malloc((qtdCliente()) * sizeof (Cliente));
    int j = 0;
    for (int i = 0; i < qtdCliente(); i++) {
        if (cod1 > Clientes[i].codigo && cod2 < Clientes[i].codigo) {
            if (Clientes[i].deletado != '*') {
                array[j].codigo = Clientes[i].codigo;
                strcpy(array[j].nome, Clientes[i].nome);
                strcpy(array[j].endereco, Clientes[i].endereco);
                strcpy(array[j].cpf, Clientes[i].cpf);
                strcpy(array[j].telefone, Clientes[i].telefone);
                strcpy(array[j].email, Clientes[i].email);
                array[j].sexo = Clientes[i].sexo;
                strcpy(array[j].estado_civil, Clientes[i].estado_civil);
                strcpy(array[j].data_nascimento, Clientes[i].data_nascimento);
                j++;
            }
        }
    }
    array = realloc(array, j * sizeof (Cliente));
    return array;
}

Cliente* clienteSexoFeedback(char sexo) {
    Cliente *Clientes;
    Clientes = listaClientes();
    Cliente *array = malloc((qtdCliente()) * sizeof (Cliente));
    int j = 0;
    for (int i = 0; i < qtdCliente(); i++) {
        if (sexo == Clientes[i].sexo) {
            if (Clientes[i].deletado != '*') {
                array[j].codigo = Clientes[i].codigo;
                strcpy(array[j].nome, Clientes[i].nome);
                strcpy(array[j].endereco, Clientes[i].endereco);
                strcpy(array[j].cpf, Clientes[i].cpf);
                strcpy(array[j].telefone, Clientes[i].telefone);
                strcpy(array[j].email, Clientes[i].email);
                array[j].sexo = Clientes[i].sexo;
                strcpy(array[j].estado_civil, Clientes[i].estado_civil);
                strcpy(array[j].data_nascimento, Clientes[i].data_nascimento);
                j++;
            }
        }
    }
    array = realloc(array, j * sizeof (Cliente));
    return array;
}

Filme* filmeCodigoFeedback(int cod1, int cod2) {
    Filme *Filmes;
    Filmes = listaFilmes();
    Filme *array = malloc((qtdFilme()) * sizeof (Filme));
    int j = 0;
    for (int i = 0; i < qtdFilme(); i++) {
        if (cod1 > Filmes[i].codigo && cod2 < Filmes[i].codigo) {
            if (Filmes[i].deletado != '*') {
                array[j].codigo = Filmes[i].codigo;
                strcpy(array[j].descricao, Filmes[i].descricao);
                strcpy(array[j].lingua, Filmes[i].lingua);
                array[j].exemplares = Filmes[i].exemplares;
                j++;
            }
        }
    }
    array = realloc(array, j * sizeof (Filme));
    return array;
}

//DAQUI PARA FRENTE NÃO FUNCIONA PQ TEM QUE PERSISTIR

int qtdeLocacoesParaQueSePague(int cod, float precoTotal, float precoFilme) {
    //Não entendi isso aqui não
    Locacao *Locacoess;
    float qtde;
    //Locacoess = listaLocacoes();
    //Locacao *array = malloc(/*(qtdLocacoes())*/ 1 * sizeof (Locacao));
    Filme f;
    float j = 0;
    for (int i = 0; i < 2/*(qtdLocacoes())*/; i++) {
        for (int w = 0; w < Locacoess[i].qtde_Filmes_Locados; w++) {
            f = consultaFilme(Locacoess[i].filCodigo[w]);
            if (cod == f.codigo) {
                if (Locacoess[i].deletado != '*') {
                    j++;
                }
            }
        }
    }
    qtde = (precoTotal / precoFilme) - j;
    if (qtde > 0) {
        qtde = (int) ceilf(qtde);
        return qtde;
    }
    return 0;
}

Locacao * locacoesCodigoFeedback(int tipo) {
    Locacao *Locacoess;
    //Locacoess = listaLocacoes();
    Locacao *array = malloc(/*(qtdLocacoes())*/ 1 * sizeof (Locacao));
    int j = 0;
    int w = 0;
    for (int i = 0; i < 2/*(qtdLocacoes())*/; i++) {
        if (tipo == Locacoess[i].codigo) {
            if (Locacoess[i].deletado != '*') {
                array[j].codigo = Locacoess[i].codigo;
                array[j].cliCodigo = Locacoess[i].cliCodigo;
                //Filme é um array
                w = 0;
                while (Locacoess[i].filCodigo[w] != -1) {
                    array[j].filCodigo[w] = Locacoess[i].filCodigo[w];
                    w++;
                }
                array[j].qtde_Filmes_Locados = Locacoess[i].qtde_Filmes_Locados;
                array[j].tipo = Locacoess[i].tipo;
                array[j].valor = Locacoess[i].valor;
                strcpy(array[j].data, Locacoess[i].data);
                j++;
            }
        }
    }
    array = realloc(array, j * sizeof (Locacao));
    return array;
}

Locacao * locacoesNomeFeedback(Cliente cli) {
    Locacao *Locacoess;
    //Locacoess = listaLocacoes();
    Locacao *array = malloc(/*(qtdLocacoes())*/ 1 * sizeof (Locacao));
    Cliente c;
    int w = 0;
    int j = 0;
    for (int i = 0; i < 2/*(qtdLocacoes())*/; i++) {
        c = consultaCliente(array[i].cliCodigo);
        if (strcmp(cli.nome, c.nome) == 0) {
            if (Locacoess[i].deletado != '*') {
                array[j].codigo = Locacoess[i].codigo;
                array[j].cliCodigo = Locacoess[i].cliCodigo;
                //Filme é um array
                w = 0;
                while (Locacoess[i].filCodigo[w] != -1) {
                    array[j].filCodigo[w] = Locacoess[i].filCodigo[w];
                    w++;
                }
                array[j].qtde_Filmes_Locados = Locacoess[i].qtde_Filmes_Locados;
                array[j].tipo = Locacoess[i].tipo;
                array[j].valor = Locacoess[i].valor;
                strcpy(array[j].data, Locacoess[i].data);
                j++;
            }
        }
    }
    array = realloc(array, j * sizeof (Locacoess));
    return array;
}

//Locacao * movimentacaoCaixaFeedbackLocacao(char *data1, char *data2) {
//    Locacao *Locacoess;
//    //Locacoess = listaLocacoes();
//    Locacao *array = malloc(/*(qtdLocacoes())*/ 1 * sizeof (Locacao));
//    time_t d1 = to_seconds(data1);
//    time_t d2 = to_seconds(data2);
//    time_t dataLocacoes;
//    int w = 0;
//    int j = 0;
//    for (int i = 0; i < 2/*(qtdLocacoes())*/; i++) {
//        dataLocacoes = to_seconds(Locacoess[i].data);
//        if (d1 > dataLocacoes && d2 < dataLocacoes) {
//            if (Locacoess[i].deletado != '*') {
//                array[j].codigo = Locacoess[i].codigo;
//                array[j].cliCodigo = Locacoess[i].cliCodigo;
//                //Filme é um array
//                while (Locacoess[i].filCodigo[w] != -1) {
//                    array[j].filCodigo[w] = Locacoess[i].filCodigo[w];
//                    w++;
//                }
//                array[j].qtde_Filmes_Locados = Locacoess[i].qtde_Filmes_Locados;
//                array[j].tipo = Locacoess[i].tipo;
//                array[j].valor = Locacoess[i].valor;
//                strcpy(array[j].data, Locacoess[i].data);
//                j++;
//            }
//        }
//    }
//    array = realloc(array, j * sizeof (Locacao));
//    return array;
//}

Locacao * contasReceberDataFeedback(char *data1, char *data2) {
    Locacao *Locacoess;
    //Locacoess = listaConta();
    Locacao *array = malloc(/*(qtdConta())*/ 1 * sizeof (Conta));
    time_t d1 = to_seconds(data1);
    time_t d2 = to_seconds(data2);
    time_t dataLocacoes;
    int w = 0;
    int j = 0;
    for (int i = 0; i < 2/*(qtdConta())*/; i++) {
        dataLocacoes = to_seconds(Locacao[i].data);
        if (d1 > dataLocacoes && d2 < dataLocacoes) {
            if (Locacoess[i].deletado != '*') {
                array[j].codigo = Locacoess[i].codigo;
                array[j].cliCodigo = Locacoess[i].cliCodigo;
                //Filme é um array
                w = 0;
                while (Locacoess[i].filCodigo[w] != -1) {
                    array[j].filCodigo[w] = Locacoess[i].filCodigo[w];
                    w++;
                }
                array[j].qtde_Filmes_Locados = Locacoess[i].qtde_Filmes_Locados;
                array[j].tipo = Locacoess[i].tipo;
                array[j].valor = Locacoess[i].valor;
                array[j].parcelas = Locacoess[i].parcelas;
                strcpy(array[j].data, Locacoess[i].data);
                j++;
            }
        }
    }
    array = realloc(array, j * sizeof (Locacao));
    return array;
}

Locacao * contasReceberCodigoFeedback(int cod1, int cod2) {
    Locacao *Locacoess;
    //Locacoess = listaConta();
    Locacao *array = malloc(/*(qtdConta())*/ 1 * sizeof (Conta));
    int j = 0;
    int w;
    for (int i = 0; i < 2/*(qtdConta())*/; i++) {
        if (Locacoess[i].tipo == 0) {
            if (cod1 > Locacoess[i].codigo && cod2 < Locacoess[i].codigo) {
                if (Locacoess[i].deletado != '*') {
                    array[j].codigo = Locacoess[i].codigo;
                    array[j].cliCodigo = Locacoess[i].cliCodigo;
                    //Filme é um array
                    w = 0;
                    while (Locacoess[i].filCodigo[w] != -1) {
                        array[j].filCodigo[w] = Locacoess[i].filCodigo[w];
                        w++;
                    }
                    array[j].qtde_Filmes_Locados = Locacoess[i].qtde_Filmes_Locados;
                    array[j].tipo = Locacoess[i].tipo;
                    array[j].valor = Locacoess[i].valor;
                    array[j].parcelas = Locacoess[i].parcelas;
                    strcpy(array[j].data, Locacoess[i].data);
                    j++;
                }
            }
        }
    }
    array = realloc(array, j * sizeof (Conta));
    return array;
}

Conta * contasPagarDataFeedback(char *data1, char *data2) {
    Conta *Contas;
    //Locacoess = listaConta();
    Conta *array = malloc(/*(qtdConta())*/ 1 * sizeof (Conta));
    time_t d1 = to_seconds(data1);
    time_t d2 = to_seconds(data2);
    time_t dataLocacoes;
    int w = 0;
    int j = 0;
    for (int i = 0; i < 2/*(qtdConta())*/; i++) {
        if (Contas[i].tipo == 1) {
            dataLocacoes = to_seconds(Contas[i].data);
            if (d1 > dataLocacoes && d2 < dataLocacoes) {
                if (Contas[i].deletado != '*') {
                    array[j].codigo = Contas[i].codigo;
                    strcpy(array[j].data, Contas[i].data);
                    array[j].tipo = array[i].tipo;
                    array[j].valor = array[i].valor;
                    //Perguntar o Thomas como ele sabe o numero de parcelas
                    w = 0;
                    while (Contas[i].parcelas[w] != -1) {
                        array[j].parcelas[w] = Contas[i].parcelas[w];
                        w++;
                    }
                    j++;
                }
            }
        }
    }
    array = realloc(array, j * sizeof (Conta));
    return array;
}

Conta * contasPagarCodigoFeedback(int cod1, int cod2) {
    Conta *Contas;
    //Locacoess = listaConta();
    Conta *array = malloc(/*(qtdConta())*/ 1 * sizeof (Conta));
    int w = 0;
    int j = 0;
    for (int i = 0; i < 2/*(qtdConta())*/; i++) {
        if (Contas[i].tipo == 1) {
            if (cod1 > Contas[i].codigo && cod2 < Contas[i].codigo) {
                if (Contas[i].deletado != '*') {
                    array[j].codigo = Contas[i].codigo;
                    strcpy(array[j].data, Contas[i].data);
                    array[j].tipo = array[i].tipo;
                    array[j].valor = array[i].valor;
                    //Perguntar o Thomas como ele sabe o numero de parcelas
                    w = 0;
                    while (Contas[i].parcelas[w] != -1) {
                        array[j].parcelas[w] = Contas[i].parcelas[w];
                        w++;
                    }
                    j++;
                }
            }
        }
    }
    array = realloc(array, j * sizeof (Conta));
    return array;
}