#include<stdio.h>
#include "../locadoraDAO.h"
#include "../structs.h"
#include "../conLocadora.h"
#include <string.h>

void locadoraMenu(){
    int x;
    do{
    printf("\t MENU LOCADORA\n");
    printf("---------------------------------------------\n");
    printf("0. Sair \n");
    printf("1. Salvar Locadora \n");//ok
    printf("2. Atualizar locadora \n"); //ok
    printf("3. Deletar locadora \n"); //ñ
    printf("4. Listar locadora \n"); ///ok
    printf("5. Consultar locadora \n"); //ok
    printf("6. Voltar para o menu principal \n");
    printf("---------------------------------------------\n");
    printf("\t Digite uma das opções: ");
    scanf("%d%*c", &x);
    printf("---------------------------------------------\n");

    switch(x){
        case 0:
            printf("SAINDO!");
            exit(1);
        case 1:
            salveLoc();
            break;
        case 2:
            attLoc();
            break;
        case 3:
            deletLoc();
            break;
        case 4:
            lisLoc();
            break;
        case 5:
            consulteLoc();
            break;
        case 6:
            menuPrincipal();
            break;
    }
    }while(x!= 0);

 }

void salveLoc(){

    Locadora locadora;

    fflush(stdin); //limpa
    printf("Digite o nome fantasia da locadora: \n");
    scanf("%[^\n]%*c", locadora.nome); //Até o usuario dar enter
    fflush(stdin); //limpa


    printf("Digite a razão social da empresa: \n");
    scanf("%[^\n]%*c", locadora.razao_social); //Até o usuario dar enter
    fflush(stdin); //limpa


    printf("Digite a inscrição estadual da empresa: \n");
    scanf("%[^\n]%*c", locadora.inscricao_estadual); //Até o usuario dar enter
    fflush(stdin); //limpa


    printf("Digite o CNPJ da empresa: \n");
    scanf("%[^\n]%*c", locadora.cnpj); //Até o usuario dar enter
    fflush(stdin); //limpa

        //observações aqui
    printf("Digite o endereço completo : \n");
    scanf("%[^\n]%*c", locadora.endereco); //Até o usuario dar enter
    fflush(stdin); //limpa

    printf("Digite o tefone: \n");
    scanf("%[^\n]%*c", locadora.telefone); //Até o usuario dar enter
    fflush(stdin); //limpa

    printf("Digite o e-mail: \n");
    scanf("%[^\n]%*c", locadora.email); //Até o usuario dar enter
    fflush(stdin); //limpa

    //observaçoes aqui
    printf("Digite o nome do dono ou gerente da empresa: \n");
    scanf("%[^\n]%*c", locadora.nome_responsavel); //Até o usuario dar enter
    fflush(stdin); //limpa

    printf("Digite o telefone do responsavel pela empresa: \n");
    scanf("%[^\n]%*c", locadora.tel_responsavel); //Até o usuario dar enter
    fflush(stdin); //limpa

     mensagem_operacao(salvaLocadora(&locadora));
}
void attLoc(){
    Locadora locadora;
    Locadora *p = listarLocadora(); //p vetor com todas Locadoraes
    int tamanho = qtdLocadora(); //quantidade de Fornecesores do vetor
    float cod;
    printf("-------------------------------------------------------\n"); 
    printf("Digite o codigo do cliente que deseja atluaizar: ");
    fflush(stdin);
    scanf("%f%*c", &cod);
    fflush(stdin); //limpa 
    printf("------------------------------------------------------\n"); 
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
            locadora =p[i];

            printf("Digite o nome fantasia da locadora: \n");
            scanf("%[^\n]%*c", p[i].nome); //Até o usuario dar enter
            strcpy(locadora.nome, p[i].nome);
            fflush(stdin); //limpa

            printf("Digite a razão social da empresa: \n");
            scanf("%[^\n]%*c", p[i].razao_social); //Até o usuario dar enter
            strcpy(locadora.razao_social, p[i].razao_social);
            fflush(stdin); //limpa

            printf("Digite a inscrição estadual da empresa: \n");
            scanf("%[^\n]%*c", p[i].inscricao_estadual); //Até o usuario dar enter
            strcpy(locadora.inscricao_estadual, p[i].inscricao_estadual);
            fflush(stdin); //limpa

            printf("Digite o CNPJ da empresa: \n");
            scanf("%[^\n]%*c", p[i].cnpj); //Até o usuario dar enter
            strcpy(locadora.cnpj, p[i].cnpj);
            fflush(stdin); //limpa

            printf("Digite o endereço completo : \n");
            scanf("%[^\n]%*c", p[i].endereco); //Até o usuario dar enter
            strcpy(locadora.endereco, p[i].endereco);
            fflush(stdin); //limpa

            printf("Digite o tefone da locadora: \n");
            scanf("%[^\n]%*c", p[i].telefone); //Até o usuario dar enter
            strcpy(locadora.telefone, p[i].telefone);
            fflush(stdin); //limpa

            printf("Digite o e-mail: \n");
            scanf("%[^\n]%*c", p[i].email); //Até o usuario dar enter
            strcpy(locadora.email, p[i].email);
            fflush(stdin); //limpa

            printf("Digite o nome do dono ou gerente da empresa: \n");
            scanf("%[^\n]%*c", p[i].nome_responsavel); //Até o usuario dar enter
            strcpy(locadora.nome_responsavel, p[i].nome_responsavel);
            fflush(stdin); //limpa

            printf("Digite o telefone do responsavel pela empresa: \n");
            scanf("%[^\n]%*c", locadora.tel_responsavel); //Até o usuario dar enter
            strcpy(locadora.tel_responsavel, p[i].tel_responsavel);
            fflush(stdin); //limpa
         mensagem_operacao(atualizaLocadora(locadora));
        }
    }
}
void lisLoc() {
    Locadora *p = listarLocadora(); //p vetor com todos os clientes
    int tamanho = qtdLocadora(); //quantidade de clientes do vetor
    printf("-------------------------------------------------------\n"); 
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].deletado != '*') { //Não mostrar os deletados
            printf("Codigo: %0.f \n Nome: %s \n Razão social: %s \n Inscrição Estadual: %s \n CNPJ: %s \n Endereço: %s \n Telefone: %s \n E-mail: %s\n Nome do responsavel: %s\n Telefone do Responsavel: %s\n-------------------------------------------------------\n",p[i].codigo, p[i].nome, p[i].razao_social, p[i].inscricao_estadual, p[i].cnpj, p[i].endereco, p[i].telefone, p[i].email, p[i].nome_responsavel, p[i].tel_responsavel);
        }
    }
 }
int deletLoc() {
     Locadora locadora;
    Locadora *p = listarLocadora(); //p vetor com todos os clientes 
    int tamanho = qtdLocadora(); //quantidade de clientes do vetor
    float cod;
    printf("-------------------------------------------------------\n"); 
    printf("Digite o codigo do clinte que deseja deletar: ");
    scanf("%f%*c",&cod);
    printf("-------------------------------------------------------\n"); 
    for (int i = 0; i <= tamanho; i++) {
        locadora=p[i];
        if (p[i].codigo == cod) { //Não mostrar os deletados
            locadora=p[i];
            mensagem_operacao(deletaLocadora(p[i].codigo));
            break;

        }
    }
}
void consulteLoc() {

    Locadora locadora;
    Locadora *p = listarLocadora(); //p vetor com todos os clientes 
    int tamanho = qtdLocadora(); //quantidade de clientes do vetor
    float cod;
    printf("-------------------------------------------------------\n"); 
    printf("Digite o codigo do locadora que deseja consultar: \n");
    scanf("%f%*c",&cod);
    printf("-------------------------------------------------------\n"); 
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) { //Não mostrar os deletados
            locadora=p[i];
             printf("Codigo: %0.f \n Nome: %s \n Razão social: %s \n Inscrição Estadual: %s \n CNPJ: %s \n Endereço: %s \n Telefone: %s \n E-mail: %s\n Nome do responsavel: %s\n Telefone do Responsavel: %s\n-------------------------------------------------------\n",p[i].codigo, p[i].nome, p[i].razao_social, p[i].inscricao_estadual, p[i].cnpj, p[i].endereco, p[i].telefone, p[i].email, p[i].nome_responsavel, p[i].tel_responsavel);
        } 
            
    }
    consultaLocadora(locadora.codigo);
}



