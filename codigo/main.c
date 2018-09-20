/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: alunos
 *
 * Created on 13 de Setembro de 2018, 14:49
 */

#include <stdio.h>
#include <stdlib.h>

//#include "conCliente.h"
#include "structs.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente c;
    printf("Digite o nome");
    scanf("%s%*c",&c.nome);
    printf("%s",c.nome);
    return (EXIT_SUCCESS);
}

