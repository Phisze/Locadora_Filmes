#include "../../vector.h"
#include "../../structs.h"
//#include "../../clienteDAO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tamanho.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//vector v = {NULL, 4, 0};
int tamanhoClientes = 0;
int tamanhoClientesListar = 0;
Cliente *Clientes;
int static tamanho = 0;
int static tamanhoTexto = 0;

void criaArrayCliente() {
    Clientes = malloc(sizeof (Clientes));
}

//Funcões de Inclusao 

int inclusaoCliente(Cliente c) {
    tamanho = getTamanhoCliente();
    //c.codigo = tamanho + 1;
    //printf("codcodcod %f ", c.codigo);
    //FILE *arq = fopen("C:\\Projetos\\Locadora_Filmes\\codigo\\cliente.pro", "ab");
    //FILE *arq = fopen("..\\..\\..\\..\\cliente.pro", "ab");
    FILE *arq = fopen("cliente.pro", "ab");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo");
        return 0;
    }

    fwrite(&c, sizeof (c), 1, arq);
    fclose(arq);

    tamanho++;
    setTamanhoCliente(tamanho);
    return 1;
}

void inclusaoClienteTexto(Cliente c) {
    FILE *arquivo;
    tamanhoTexto = getTamanhoClienteTexto();
    arquivo = fopen("cliente.txt", "a");
    fprintf(arquivo, "%f %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
    fclose(arquivo);
    tamanhoTexto++;
    setTamanhoClienteTexto(tamanhoTexto);
}

void insereClienteArrayDinamico(Cliente c) {
    tamanhoClientes++;
    Clientes = realloc(Clientes, tamanhoClientes * sizeof (Cliente));
    Clientes[tamanhoClientes - 1].codigo = c.codigo;
    strcpy(Clientes[tamanhoClientes - 1].nome, c.nome);
    strcpy(Clientes[tamanhoClientes - 1].endereco, c.endereco);
    strcpy(Clientes[tamanhoClientes - 1].cpf, c.cpf);
    strcpy(Clientes[tamanhoClientes - 1].telefone, c.telefone);
    strcpy(Clientes[tamanhoClientes - 1].email, c.email);
    Clientes[tamanhoClientes - 1].sexo = c.sexo;
    strcpy(Clientes[tamanhoClientes - 1].estado_civil, c.estado_civil);
    strcpy(Clientes[tamanhoClientes - 1].data_nascimento, c.data_nascimento);
}

//Funções de Listar

Cliente* lClientes() {
    int i = 0;
    Cliente c;
    Cliente *cw = &c;
    Cliente *array = malloc((getTamanhoCliente()) * sizeof c);
    int cont = 0;
    // VECTOR_INIT(v);
    //    Cliente *cli = &clientes;
    FILE *arq = fopen("cliente.pro", "rb");
    //printf("Arquivo xistente!");

    if (arq == NULL) {
        printf("Arquivo inexistente!");

        return;
    }
    while (fread(&c, sizeof (c), 1, arq)) {
        //  if (c.deletado != '*') {
        // VECTOR_ADD(v,c);
        // array[i].nome = c.nome;
        array[i].codigo = c.codigo;
        strcpy(array[i].nome, c.nome);
        strcpy(array[i].endereco, c.endereco);
        strcpy(array[i].cpf, c.cpf);
        strcpy(array[i].telefone, c.telefone);
        strcpy(array[i].email, c.email);
        array[i].sexo = c.sexo;
        strcpy(array[i].estado_civil, c.estado_civil);
        strcpy(array[i].data_nascimento, c.data_nascimento);
        array[i].deletado = c.deletado;
        // }
        //printf("Cod %f --- Descricao: %s\n", c.codigo, c.nome);

        //VECTOR_ADD(clientes, cw);
        //printf("Cod %s\n", c.nome);
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoCliente() - 1) - cont) * sizeof (Cliente));
        //        }
    }
    fclose(arq);
    return array;
}

Cliente* ListarClientesTexto() {
    int i = 0;
    Cliente c;
    int cont = 0;
    FILE *arquivo;
    Cliente *array = malloc((getTamanhoClienteTexto()) * sizeof (Cliente));
    //Cliente c;
    arquivo = fopen("cliente.txt", "r");

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %c %s %s\n", &c.codigo, &c.nome, &c.endereco, &c.cpf, &c.telefone, &c.email, &c.sexo, &c.estado_civil, &c.data_nascimento);
        // if (c.deletado != '*') {
        array[i].codigo = c.codigo;
        strcpy(array[i].nome, c.nome);
        strcpy(array[i].endereco, c.endereco);
        strcpy(array[i].cpf, c.cpf);
        strcpy(array[i].telefone, c.telefone);
        strcpy(array[i].email, c.email);
        array[i].sexo = c.sexo;
        strcpy(array[i].estado_civil, c.estado_civil);
        strcpy(array[i].data_nascimento, c.data_nascimento);
        i++;
        //        } else {
        //            cont++;
        //            array = realloc(array, ((getTamanhoClienteTexto() - 1) - cont) * sizeof (Cliente));
        //        };
    }
    fclose(arquivo);
    return array;
}

Cliente* listarClienteArrayDinamico() {
    //    Cliente *array = realloc((tamanhoClientes) * sizeof (Cliente));;
    //    tamanhoClientes = tamanhoClientesListar;
    //    int i;
    //    int j = 0;
    //    int cont = 0;
    //    for (i = 0; i < tamanhoClientes; i++) {
    //      //  if (Clientes[i].deletado != '*') {
    //            array[j].codigo = Clientes[i].codigo;
    //            strcpy(array[j].nome, Clientes[i].nome);
    //            strcpy(array[j].endereco, Clientes[i].endereco);
    //            strcpy(array[j].cpf, Clientes[i].cpf);
    //            strcpy(array[j].telefone, Clientes[i].telefone);
    //            strcpy(array[j].email, Clientes[i].email);
    //            array[j].sexo = Clientes[i].sexo;
    //            strcpy(array[j].estado_civil, Clientes[i].estado_civil);
    //            strcpy(array[j].data_nascimento, Clientes[i].data_nascimento);
    //            j++;
    //        } else {
    //            cont++;
    //            tamanhoClientesListar -= cont;
    //            array = realloc(array, (tamanhoClientesListar) * sizeof (Cliente));
    //        };
    //   }
    //printf("Listar %c\n", array[0].sexo);

    return Clientes;
}


//Funções de Consultar

Cliente consultarClientes(int cod) {

    FILE *arq = fopen("cliente.pro", "rb");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        Cliente v;
        return v;
    }

    Cliente c;

    //int cod;
    int achei = 0;
    //printf("\nDigite o codigo que procura: \n");
    //scanf("%f", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if ((cod == c.codigo) && (c.deletado != '*')) {

            // printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;
            break;
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    return c;
}

Cliente ConsultarClientesTexto(float cod) {
    FILE *arquivo;
    arquivo = fopen("cliente.txt", "rt");
    Cliente c;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %c %s %s\n", &c.codigo, &c.nome, &c.endereco, &c.cpf, &c.telefone, &c.email, &c.sexo, &c.estado_civil, &c.data_nascimento);
        if (c.codigo == cod) {
            break;
        }
    }
    return c;
}

Cliente consultaClienteArrayDinamico(int cod) {
    if (Clientes[cod - 1].deletado != '*') {
        return Clientes[cod - 1];
    }
    return;
}

//Funções de Alteração

int alterarCliente(Cliente clintes, float cod) {
    FILE *arq = fopen("cliente.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Cliente c;
    //int cod, 
    int achei = 0;
    //printf("\nDigite o codigo que deseja alterar: \n");
    //scanf("%f", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n\n", c.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
            //  printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            //  scanf("%s", produtos.descricao);
            // printf("\nDigite o novo preco....: \n");
            //scanf("%f", &produtos.valor);

            fwrite(&clintes, sizeof (clintes), 1, arq);
            fseek(arq, sizeof (clintes)* 0, SEEK_END);
            return 1;
        }
    }

    if (!achei)
        printf("\nCodigo nao cadastrado!!\n");

    fclose(arq);
    return 0;
}

void alterarClienteTexto(float cod, Cliente cli) {
    FILE *arquivo;
    FILE *arq;
    Cliente c;
    arquivo = fopen("cliente.txt", "rt");
    arq = fopen("clienteBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
        if (cod == c.codigo && c.deletado != '*') {
            c.codigo = cli.codigo;
            strcpy(c.nome, cli.nome);
            strcpy(c.endereco, cli.endereco);
            strcpy(c.cpf, cli.cpf);
            strcpy(c.telefone, cli.telefone);
            strcpy(c.email, cli.email);
            c.sexo = cli.sexo;
            strcpy(c.estado_civil, cli.estado_civil);
            strcpy(c.data_nascimento, cli.data_nascimento);
            fprintf(arq, "%f %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
        } else {
            fprintf(arq, "%f %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("cliente.txt");
    rename("clienteBackup.txt", "cliente.txt");
}

void alterarClienteArrayDinamico(int cod, Cliente c) {
    Clientes[cod - 1].codigo = c.codigo;
    strcpy(Clientes[cod - 1].nome, c.nome);
    strcpy(Clientes[cod - 1].endereco, c.endereco);
    strcpy(Clientes[cod - 1].cpf, c.cpf);
    strcpy(Clientes[cod - 1].telefone, c.telefone);
    strcpy(Clientes[cod - 1].email, c.email);
    Clientes[cod - 1].sexo = c.sexo;
    strcpy(Clientes[cod - 1].estado_civil, c.estado_civil);
    strcpy(Clientes[cod - 1].data_nascimento, c.data_nascimento);
    //printf("Alterar %c\n", Clientes[0].sexo);
}

//Funcções de exclusão

int excluirCliente(float cod) {

    FILE *arq = fopen("cliente.pro", "r+b");
    if (arq == NULL) {
        printf("Arquivo inexistente!");
        return 0;
    }

    Cliente c;
    //int cod, 
    int achei = 0;
    char certeza;
    // printf("\nDigite o codigo que deseja EXCLUIR: \n");
    // scanf("%f", &cod);

    while (fread(&c, sizeof (c), 1, arq)) {
        if (cod == c.codigo) {
            //  printf("Cod %f --- Descricao: %-8s --- Valor R$ %4.2f\n\n", produtos.codigo, produtos.descricao, produtos.valor);
            achei = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's') {
                c.deletado = '*';
                printf("\nProduto excluido com Sucesso! \n");
                fseek(arq, sizeof (Cliente)*-1, SEEK_CUR);
                fwrite(&c, sizeof (c), 1, arq);
                fseek(arq, sizeof (c)* 0, SEEK_END);
                // return 1;
            }
        }
    }

    if (!achei) {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(arq);
    return 0;
}

void excluirClienteTexto(float cod) {
    FILE *arquivo;
    FILE *arq;
    Cliente c;
    arquivo = fopen("cliente.txt", "rt");
    arq = fopen("clienteBackup.txt", "wt");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%f %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
        if (cod == c.codigo && c.deletado != '*') {
        } else {
            fprintf(arq, "%f %s %s %s %s %s %c %s %s\n", c.codigo, c.nome, c.endereco, c.cpf, c.telefone, c.email, c.sexo, c.estado_civil, c.data_nascimento);
        }
    }
    fclose(arquivo);
    fclose(arq);
    remove("cliente.txt");
    rename("clienteBackup.txt", "cliente.txt");
    tamanhoTexto = getTamanhoClienteTexto();
    tamanhoTexto--;
    setTamanhoClienteTexto(tamanhoTexto);
}

void excluirClienteArrayDinamico(int cod) {
    Clientes[cod - 1].deletado = '*';
}