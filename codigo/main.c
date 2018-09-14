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
#include "clienteDAO.h"

/*
 * 
 */
int main(int argc, char** argv) {

    //    Cliente incluir;
    //    printf("Insira o codigo:");
    //    scanf("%f%*c",&incluir.codigo);
    //    printf("Insira o nome:");
    //    scanf("%s%*c",&incluir.nome);
    //    inclusaoCliente(incluir);

    //Cliente c=consultarClientes(1);
    //printf(" %s",c.nome);
    Cliente *array;

    array = listarClientes();
    for (int i = 0; i < 6; i++) {

        printf("First name is %s\n", array[i].nome);
    }
    ///for (int i = 0; i < 100; i++) {
    //   printf("test");
    //     printf("\n %s", listarClientes()->nome);
    //}

    return (EXIT_SUCCESS);
}

