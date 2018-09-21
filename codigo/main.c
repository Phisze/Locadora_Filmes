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
#include "conCliente.h"
#include "Util.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente c;
    init_Cliente(&c);

    VECTOR_INIT(teste);
    char nomew[] = "Weverton Rodrigues Arantes LSAKJDLKSA JDALKSDJ SAIUYRKSJLDKSA UYRWA IJSLKSJ DLKAJ AUYR SJ DLKSJ LKJS DLKJS DLKJSDLSAUR LSKDJLS KDALURLDKJLSAKJRLUYRLSAIJLSKJDLKSA JDLSKJHDLKSAJHRSALKSAJRLKSJHRLSKJR LKSJR";
    char nom[]="";
    VECTOR_ADD(teste, nomew);

    for (int i = 0; i < VECTOR_TOTAL(teste); i++)
        printf("%s ", VECTOR_GET(teste, char*, i));
    printf("\n");

    printf("Digite o nome: ");

    fgets(nom, 100, stdin);
    VECTOR_ADD(c.nome, nom);

    for (int z = 0; z < VECTOR_TOTAL(teste); z++) {
   
        printf("%s", VECTOR_GET(teste, char *, z));
    }



    return (EXIT_SUCCESS);
}

