#include "../../vector.h"
#include "../../structs.h"
#include "../../clienteDAO.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Funcao Inclusao 

void inclusaoCliente(Cliente c) {

    FILE *arq = fopen("cliente.pro", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return;
    }
   
    fwrite(&c, sizeof (c), 1, arq);
    fclose(arq);
}

vector listarClientes() {
    Cliente c;
    vector clientes;
    FILE *arq = fopen("produtos.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return;
    }
    while (fread(&c, sizeof (c), 1, arq))
        if (c.deletado != '*') {
            VECTOR_ADD(clientes, c); 
//            printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n", c.codigo, produtos.descricao, produtos.valor);
        }
    fclose(arq);
    return clientes;
}
