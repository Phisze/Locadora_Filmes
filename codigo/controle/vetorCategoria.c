/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include "../structs.h"


int add_vetorCategoria(vetorCategoria * initV, Categoria* c) {
    
    if (initV->tamanho == initV->total) {
        initV->itens = realloc(initV->itens, 2 * initV->tamanho * sizeof (Categoria));
        initV->tamanho = initV->tamanho * 2;
    }
    //seta o codigo do cliente
    c->codigo = initV->total;
    initV->itens[initV->total] = *c;
    initV->total++;

    return 1;
}

int remove_vetorCategoria(vetorCategoria * initV, int codigo) {
    Categoria initC = {-1, "", -1,'*'};
    if (codigo < initV->total) {
        //tamanho -1 pra ele não tentar mudar de posição um cliente fora do limite do array
        for (int i = codigo; i < initV->tamanho - 1; i++) {

            initV->itens[i] = initV->itens[i + 1];
            initV->itens[i].codigo = i;

        }
        initV->itens[initV->tamanho - 1] = initC;

        //!= 1 pra não ficar com 0 posições de clientes o se remover o primeiro quando se tem um so cliente
        //por que o algoritmo de adicionar dobra o tamanho do vetor toda vez que sua capacidade total é atingida
        //e não funcionaria ao multiplicar 2*tamanho com tamanho=0
        if (initV->total < initV->tamanho && initV->tamanho != 1) {
            initV->itens = realloc(initV->itens, (initV->tamanho - initV->total) * sizeof (Categoria));
            initV->tamanho = initV->total;
        }
        return 1;
    } else {
        return 0;
    }



}