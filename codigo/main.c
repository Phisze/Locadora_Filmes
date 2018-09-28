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
#include <string.h>
#include "clienteDAO.h"
#include "vector.h"
#include "conCliente.h"
#include "tamanho.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente c;
    printf("Digite o nome do fulano: ");
    fgets(c.nome, 100, stdin);

    int tamanho = getTamanhoCliente();
    printf("Tamanho do cliente: %d\n", tamanho);
    salvaCliente(&c);

    tamanho = getTamanhoCliente();
    printf("Tamanho do cliente: %d\n", tamanho);
    printf("%s\n", listaClientes()[1].nome);
    printf("%f", listaClientes()[1].codigo);

    // printf("Digite o nome: ");
    //  fgets(c.nome,30,stdin);
    //  printf("O nome do cliente é: %s",c.nome);
    //  salvaCliente(&c);


    //    Cliente c;
    //    Cliente *cw;
    //    c.codigo = 1;
    //    strcpy(c.nome, "ASD");

    //c.nome = "ASD";
    //  printf("%s",((Cliente) listarClientes[1]).nome);
    //    inclusaoCliente(c);
    //    cw=lClientes();
    //    int i;
    //for (i = 0; i < 106; i++) {
    //        printf("%s", cw[0].nome);
    //}

    //   printf("%s", VECTOR_GET(listaClientes(), char*, 1));
    //    c.nome.capacity = 4;
    //    c.nome.total = 0;
    //    c.nome.items = calloc(sizeof (void *) * c.nome.capacity, sizeof (void*));
    //    // VECTOR_INIT(c.nome);
    //    printf("Digite o nome: ");
    //    //    scanf("%s%*c", &c.nome);
    //    //    printf("\n%s", c.nome);
    //    //    printf("\n%d", sizeof c.nome);
    //    //    printf("\n%d", sizeof (Cliente));
    //
    //
    //    char nom[] = "    ";
    //    fgets(nom, 100, stdin);
    //
    //
    //    //scanf("%s%*c", &nom);
    //    //  printf("%s\n", nom);
    //    //    for(int i=0; i<;i++){
    //    //    }
    //    //  printf("%d", strlen(nom));
    //
    //    //  VECTOR_ADD(c.nome,(char *)&nom);
    //
    //    printf("%s", VECTOR_GET(c.nome, char*, 0));
    //    //    for(int z=1;z<=VECTOR_TOTAL(c.nome);z++){
    //    //        printf("%c",VECTOR_GET(c.nome,char *,z));
    //    //    }
    //


    return (EXIT_SUCCESS);
}

