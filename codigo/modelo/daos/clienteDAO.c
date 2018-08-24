#include "../../vector.h"
#include "../../structs.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Funcao Inclusao 

void inclusao() {
    struct Cliente c;

    FILE *arq = fopen("produtos.pro", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o codigo do produto: \n");
    scanf("%d", &c.codigo);
    printf("Digite a descricao do produto: \n");
    fflush(stdin);
    scanf("%s", c.cpf);
    printf("Digite o valor do produto: \n");
    scanf("%f", &c.data_nascimento);
    fwrite(&c, sizeof (c), 1, arq);
    fclose(arq);
}
