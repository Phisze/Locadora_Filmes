
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../structs.h"
#include "../locacoesDAO.h"
#include "../funcoesUteis.h"
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


//int locaFilmes(float cliCodigo,Filme* filmes,int * Qtd,float totalPago,int tipo,int numParcela,float entrada){

int locaFilmes(float cliCodigo, float* filmesCod, int qtdFilme, float totalPago, int tipo, int numParcela, float entrada) {


    Locacao l;
    l.filCodigo1=-1;
    l.filCodigo2=-1;
    l.filCodigo3=-1;
    l.qtdParcelaInicial=numParcela;
    l.qtdParcela=numParcela;
    l.valorParcela=(totalPago-entrada)/numParcela;
    
    

    l.qtde_Filmes_Locados = qtdFilme;
    l.cliCodigo = cliCodigo;
    l.tipo = tipo;
    l.valor=totalPago;
    
//    for (int i=0;i<10;i++){
//        l.data[i]=pegaDataAtual();
//    }
    //se essa nao der certo tentar a funcao comentada acima
    l.data=pegaDataAtual();
    
    
    //l.data
    
    //+1 porcausa da ultima posicao -1 que guarda o término das parcelas
    
    //se nao tiver entrada 
        
    
    
//        int i = 0;
//        while (qtdFilme[i] != 0) {
//            l.filCodigo[i]
//            i++;
//        }
}
int devolveFilmes(float cliCodigo){
    
    char * dataAtual=pegaDataAtual();
    
    Locacao * locacoes=listarLocacaos();
    int qtdLocacao=
    Locacao * locacaoCliente=malloc(1*sizeof(Locacao));
    //pra saber quando cliente nao tem locacoes pendentes em seu nome
    locacaoCliente[0].codigo=-1;
    
    
    
    
    
}
int deletaLocacao(float codLoc){}
Locacao* listaLocacoes(){
    return listarLocacaos();
}
Locacao consultaLocacao(float codigo){}