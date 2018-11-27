
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../structs.h"
#include "../locacaoDAO.h"
#include "../funcoesUteis.h"
#include "../conCliente.h"
#include "../conPersistencia.h"
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


//int locaFilmes(float cliCodigo,Filme* filmes,int * Qtd,float totalPago,int tipo,int numParcela,float entrada){

int locaFilmes(float cliCodigo, float* filmesCod, int qtdFilme, float totalPago, int tipo, int numParcela, float entrada) {


    Locacao l;
    l.filCodigo1 = -1;
    l.filCodigo2 = -1;
    l.filCodigo3 = -1;
    l.qtdParcelaInicial = numParcela;
    l.qtdParcela = numParcela;
    l.valorParcela = (totalPago - entrada) / numParcela;



    l.qtde_Filmes_Locados = qtdFilme;
    l.cliCodigo = cliCodigo;
    l.tipo = tipo;
    l.valor = totalPago;

    //    for (int i=0;i<10;i++){
    //        l.data[i]=pegaDataAtual();
    //    }
    //se essa nao der certo tentar a funcao comentada acima
    l.data = pegaDataAtual();


    //l.data

    //+1 porcausa da ultima posicao -1 que guarda o término das parcelas

    //se nao tiver entrada 



    //        int i = 0;
    //        while (qtdFilme[i] != 0) {
    //            l.filCodigo[i]
    //            i++;
    //        }
}

int devolveFilmes(float cliCodigo, float filCodigo) {

    char * dataAtual = pegaDataAtual();

    Locacao * locacoes;
    if (getTipoPersistencia() == MEMORIA) {
        locacoes = listarLocacaoArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        locacoes = listarLocacaos();
    } else {
        locacoes = ListarLocacaoTexto();
    }

    int qtdLoco = 0;
    qtdLoco = qtdLocacao();
    int contadorMemoria = 1;

    Locacao * locacaoCliente = malloc(contadorMemoria * sizeof (Locacao));

    //pra saber quando cliente nao tem locacoes pendentes em seu nome
    locacaoCliente[0].codigo = -1;

    for (int i = 0; i < qtdLocacao; i++) {
        if (locacoes[i].cliCodigo == cliCodigo && i == 0) {
            locacaoCliente[i] = locacoes[i];
        } else if (locacoes[i].cliCodigo == cliCodigo) {
            contadorMemoria++;
            locacaoCliente = realloc(locacaoCliente, contadorMemoria * sizeof (Locacao));
            locacaoCliente[i] = locacoes[i];
        }
    }
//ordena o array de locacoes por data
    for (int i = 0; i < qtdLocacao-1; i++) {
        Locacao aux;
        time_t dataI=to_seconds(locacaoCliente[i].data);
        for (int j=1; j < qtdLocacao; j++) {
            time_t dataJ=to_seconds(locacaoCliente[j].data);
            if(dataI<dataJ){
                aux=locacaoCliente[i];
                locacaoCliente[i]=locacaoCliente[j];
                locacaoCliente[j]=aux;
            }
        }
    }

    if (locacaoCliente[contadorMemoria - 1].codigo != -1) {
        if (locacaoCliente[contadorMemoria - 1].filCodigo1 == filCodigo) {
            locacaoCliente[contadorMemoria - 1].filCodigo1 = -1;
            return 1;
        } else if (locacaoCliente[contadorMemoria - 1].filCodigo2 == filCodigo) {
            locacaoCliente[contadorMemoria - 1].filCodigo2 = -1;
            return 1;
        } else if (locacaoCliente[contadorMemoria - 1].filCodigo3 == filCodigo) {
            locacaoCliente[contadorMemoria - 1].filCodigo3 = -1;
            return 1;
        }
        //2 quando o cliente por acaso esta tentando retornar um filme que nao está na sua ultima locacao
        return 2;
    }
    return 0;

}

int deletaLocacao(float codLoc) {
}

Locacao* listaLocacoes() {
    return listarLocacaos();
}

Locacao consultaLocacao(float codigo) {
}

int qtdLocacao() {
    if (getTipoPersistencia() == MEMORIA) {
        return tamanhoLocacaos;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoLocacao();
    } else if (getTipoPersistencia() == TEXTO) {
        return getTamanhoLocacaoTexto();
    }
}