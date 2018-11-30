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
#include "structs.h"
#include "../codigo/vector.h"
#include "../codigo/conCliente.h"
#include "../codigo/tamanho.h"
#include "Ex_Importacao.h"
#include "visao/Menu_primeiro.h"

/*
 * 
 */
Locacao* teste() {
    return listarLocacao();
}

int main(int argc, char** argv) {
    //    Cliente c;
    //    printf("Digite o nome do fulano: ");
    //    fgets(c.nome, 100, stdin);
    caixa = 0;
    Menu_primeiro();
    //  listarLocacao();
    //importacaoCliente();
    //[

    //    int i;
    //        for (i = 0; i < 4; i++) {
    //           printf("%.0f",listaClientes()[i].codigo);
    //        }

    //setTamanhoFuncionario(5);
    //printf("%d" ,getTamanhoFuncionario());
    //Cliente c;
    //[
    //    for (int i = 0; i < 4; i++) {
    //        c.codigo = i;
    //        strcpy(c.cpf, "123456");
    //        strcpy(c.data_nascimento, "212131");
    //        strcpy(c.email, "adsasd");
    //        strcpy(c.endereco, "adasdsa");
    //        strcpy(c.estado_civil, "esda");
    //        strcpy(c.nome, "32weewq");
    //        strcpy(c.telefone, "2312");
    //        c.sexo = "M";
    //        inclusaoCliente(c);
    //    }
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

