//
//#include <stdlib.h>
//#include <time.h>
//#include <stdio.h>
//#include "../structs.h"
///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//int locaFilmes(float cliCodigo, float* filmesCod, int * qtdFilme, float totalPago, int tipo, int numParcela, float entrada) {
//
//
//    Locacao l;
//    //apontar para o ponteiro
//    l.filCodigo = filmesCod;
//    //mas aqui o qtd vai com o -1 no final pra saber quando para
//    l.qtde_Filmes_Locados = qtdFilme;
//    l.cliCodigo = cliCodigo;
//    l.tipo = tipo;
//    l.valor=totalPago;
//    time_t mytime;
//    mytime=time(NULL);
//    struct tm tm=*localtime(&mytime);
//    char dia[snprintf(NULL,0,"%d",tm.tm_mday)+1];
//    sprintf(dia,"%d",tm.tm_mday);
//    char mes[snprintf(NULL,0,"%d",tm.tm_mon)+1];
//    sprintf(mes,"%d",tm.tm_mon);
//    char ano[snprintf(NULL,0,"%d",tm.tm_year+1900)+1];
//    sprintf(ano,"%d",tm.tm_year+1900);
//    
//    l.data[0]=dia[0];
//    l.data[1]=dia[1];
//    l.data[2]='/';
//    l.data[3]=mes[0];
//    l.data[4]=mes[1];
//    l.data[5]='/';
//    l.data[6]=ano[0];
//    l.data[7]=ano[1];
//    l.data[8]=ano[2];
//    l.data[9]=ano[3];
//
//    
//    
//    //l.data
//    
//    //+1 porcausa da ultima posicao -1 que guarda o término das parcelas
//    l.parcelas = malloc(numParcela+1 * sizeof (float));
//
//    //se nao tiver entrada ela vai ser 0
//    float calcParcela = totalPago - entrada;
//    float parcela=calcParcela/numParcela;
//    for (int j=0;j<=numParcela;j++){
//        l.parcelas[j]=parcela;
//        if(j==numParcela){
//            l.parcelas[j]=-1;
//        }        
// 
//    }
//        
//    
//    
////        int i = 0;
////        while (qtdFilme[i] != 0) {
////            l.filCodigo[i]
////            i++;
////        }
//}



#include "../../codigo/locacaoDAO.h"
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

    //    char * dataAtual;
    //    dataAtual = pegaDataAtual();
    ////    for (int i = 0; i < 10; i++) {
    ////        l.data[i] = dataAtual[i];
    ////    }
    //se essa nao der certo tentar a funcao comentada acima
    //l.data = pegaDataAtual();

}
//

int devolveFilmes(float cliCodigo, float filCodigo) {

    char * dataAtual = pegaDataAtual();

    Locacao * locacoes;
    if (getTipoPersistencia() == MEMORIA) {
        locacoes = listarLocacaoArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {

        locacoes = listarLocacao();
        //  locacoes = listaLocacoes();
    } else {
        locacoes = ListarLocacaoTexto();
    }

    int qtdLoca = 0;
    qtdLoca = qtdLocacao();
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
    for (int i = 0; i < qtdLocacao - 1; i++) {
        Locacao aux;
        time_t dataI = to_seconds(locacaoCliente[i].data);
        for (int j = 1; j < qtdLocacao; j++) {
            time_t dataJ = to_seconds(locacaoCliente[j].data);
            if (dataI < dataJ) {
                aux = locacaoCliente[i];
                locacaoCliente[i] = locacaoCliente[j];
                locacaoCliente[j] = aux;
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
    if (getTipoPersistencia() == MEMORIA) {
        return excluirLocacaoArrayDinamico(codLoc);
    } else if (getTipoPersistencia() == BINARIO) {
        return excluirLocacao(codLoc);
    } else if (getTipoPersistencia() == TEXTO) {
        return excluirLocacaoTexto(codLoc);
    }
}

Locacao* listaLocacoes() {
    if (getTipoPersistencia() == MEMORIA) {
        return listarLocacaoArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listarLocacao();
    } else if (getTipoPersistencia() == TEXTO) {
        return ListarLocacaoTexto();
    }
}
//
//

Locacao consultaLocacao(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {
        return consultaLocacaoArrayDinamico((int)codigo);
    } else if (getTipoPersistencia() == BINARIO) {
        return consultaLocacao(codigo);
    } else if (getTipoPersistencia() == TEXTO) {
        return ConsultarLocacaoTexto(codigo);
    }

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
