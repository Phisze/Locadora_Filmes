/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: alunos
 *
 * Created on 24 de Agosto de 2018, 15:12
 */

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "structs.h"
#include "clienteDAO.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente c;

    printf("Digite o nome:");
    scanf("%s&*c", &c.nome);
    printf("Digite o Codigo:");
    scanf("%f&*c", &c.codigo);
    //printf("Nome do cliente: %s",c.nome);
    inclusaoCliente(c);
    
    return (EXIT_SUCCESS);
}

