
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../structs.h"
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../structs.h"

//int locaFilmes(float cliCodigo,Filme* filmes,int * Qtd,float totalPago,int tipo,int numParcela,float entrada){

int locaFilmes(float cliCodigo, float* filmesCod, int * qtdFilme, float totalPago, int tipo, int numParcela, float entrada) {


    Locacao l;
    //apontar para o ponteiro
    l.filCodigo = filmesCod;
    //mas aqui o qtd vai com o -1 no final pra saber quando para
    l.qtde_Filmes_Locados = qtdFilme;
    l.cliCodigo = cliCodigo;
    l.tipo = tipo;
    l.valor=totalPago;
    time_t mytime;
    mytime=time(NULL);
    struct tm tm=*localtime(&mytime);
    char dia[snprintf(NULL,0,"%d",tm.tm_mday)+1];
    sprintf(dia,"%d",tm.tm_mday);
    char mes[snprintf(NULL,0,"%d",tm.tm_mon)+1];
    sprintf(mes,"%d",tm.tm_mon);
    char ano[snprintf(NULL,0,"%d",tm.tm_year+1900)+1];
    sprintf(ano,"%d",tm.tm_year+1900);

    l.data[0]=dia[0];
    l.data[1]=dia[1];
    l.data[2]='/';
    l.data[3]=mes[0];
    l.data[4]=mes[1];
    l.data[5]='/';
    l.data[6]=ano[0];
    l.data[7]=ano[1];
    l.data[8]=ano[2];
    l.data[9]=ano[3];

    
    
    //l.data
    
    //+1 porcausa da ultima posicao -1 que guarda o término das parcelas
    l.parcelas = malloc(numParcela+1 * sizeof (float));

    //se nao tiver entrada ela vai ser 0
    float calcParcela = totalPago - entrada;
    float parcela=calcParcela/numParcela;
    for (int j=0;j<=numParcela;j++){
        l.parcelas[j]=parcela;
        if(j==numParcela){
            l.parcelas[j]=-1;
        }        
 
    }
        
    
    
//        int i = 0;
//        while (qtdFilme[i] != 0) {
//            l.filCodigo[i]
//            i++;
//        }
}
int deletaLocacao(float codLoc){}
Locacao* listaLocacoes(){}
Locacao consultaLocacao(float codigo){}