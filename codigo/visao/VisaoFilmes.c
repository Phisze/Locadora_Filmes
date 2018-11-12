#include<stdio.h>
#include "../filmeDAO.h"
#include "../structs.h"
#include "../conFilme.h"
#include "VisaoCliente.h"
#include <string.h>

void filmeMenu(){
    int x;
    do{
    printf("\t MENU FILME \n");
    printf("-------------------------------------------------------\n");        
    printf("0. Sair \n");
    printf("1. Salvar Filme \n");
    printf("2. Atualizar Filme \n");
    printf("3. Deletar Filme \n");
    printf("4. Listar Filme  \n");
    printf("5. Consultar Filme \n");
    printf("6. Voltar para o menu principal \n");
    printf("-------------------------------------------------------\n");        
    printf("\t Digite uma das opções: \n");
    fflush(stdin); 
    scanf("%d%*c", &x); 
    fflush(stdin); 
    printf("-------------------------------------------------------\n");      
    
    switch(x){
        case 0:
            printf("SAINDO!");
            break;
        //Salva Filme 
        case 1:
            salveFlimes();
            break;
        //Atualiza Filme
        case 2:
            attFilmes();
            break;
        //deletar Filme
        case 3:
            deletFilme();
            break;
        //Listar Filme
        case 4:
            listarFilme();
            break;
         //consultar Filme 
        case 5:
            consulteFilme();
            break;
        case 6:
            menuPrincipal();
            break;
                           
    }
          
    }while(x!= 0);
    
 }

void salveFlimes(){
 
    Filme filme;
               
    printf("Digite a descrição do filme: \n");
    scanf("%[^\n]%*c", filme.descricao); //Até o usuario dar enter
    fflush(stdin);
 
    printf("Digite a quantidade de exemplares do filme na locadora: \n");
    scanf("%f%*c", &filme.exemplares); 
    fflush(stdin);
   
    printf("Digite a linguagem Dublado (Digite D) ou Legandado (Digite L) \n");
    scanf("%[^\n]%*c", filme.lingua); //Até o usuario dar enter
    fflush(stdin);
    
    printf("Digite a descrição do filme: \n");
    scanf("%[^\n]%*c", filme.descricao); //Até o usuario dar enter
    fflush(stdin);

     mensagem_operacao(salvaFilme(&filme));

}

void attFilmes(){
    
   Filme filme;    
   Filme *p = listaFilmes(); //p vetor com todos os Filmes
   int tamanho = qtdFilme(); //quantidade de filmes do vetor
   float cod;
   printf("-------------------------------------------------------\n");
   printf("Digite o codigo do filme que deseja atualizar: \n");
   scanf("%f%*c", &cod);
   printf("-------------------------------------------------------\n");
   int achou = 0;
   for (int i = 0; i <= tamanho; i++) {
    if (p[i].codigo == cod) { 
        achou=1;
        filme=p[i];
         fflush(stdin); //limpa                       
         printf("Digite a descrição do filme: \n");
         scanf("%[^\n]%*c", p[i].descricao); //Até o usuario dar enter
         strcpy(filme.descricao,p[i].descricao);
         fflush(stdin); //limpa

         printf("Digite a quantidade de exemplares do filme na locadora: \n");
         scanf("%f", p[i].exemplares); //Até o usuario dar enter
     //    (filme.descricao = p[i].exemplares);
         fflush(stdin); //limpa

         printf("Digite a linguagem Dublado ou Legandado \n");
         scanf("%[^\n]%*c", p[i].lingua); //Até o usuario dar enter
         strcpy(filme.lingua,p[i].lingua);
         fflush(stdin); //limpa
          mensagem_operacao(atualizaFilme(filme));
    
    }if ( achou == 1)
        break;
       
   }if (achou == 0){
       mensagem_operacao(achou);
   }
      
}

int deletFilme(){
    
    Filme filme;
    Filme *p = listaFilmes(); //p vetor com todos os clientes 
    int tamanho = qtdFilme(); //quantidade de clientes do vetor
    float cod;
    printf("-------------------------------------------------------\n");  
    printf("\t Digite o codigo do cliente que deseja deletar: \n");
    scanf("%f", &cod);
    printf("-------------------------------------------------------\n");
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
            mensagem_operacao(deletaFilme(p[i].codigo));
            break;

        }else
            printf("Clinte Inexistente!");
    }
    
}

void listarFilme(){
    
   Filme *p = listaFilmes(); //p vetor com todos os Filmes
   int tamanho = qtdFilme(); //quantidade de filmes do vetor
   
   for (int i = 0; i <= tamanho; i++) {
        if (p[i].deletado != '*') { //Não mostrar os deletados
            printf("Codigo: %0.f \n Descrição: %s \n Quantidade de exemplares: %0.f \n Código da categoria: %0.f \n Lingua: %s\n --------------------------------------------------\n", p[i].codigo, p[i].descricao, p[i].exemplares, p[i].catCodigo, p[i].lingua);
        }
    }
    
}

void consulteFilme(){
    
   Filme filme;    
   Filme *p = listaFilmes(); //p vetor com todos os Filmes
   int tamanho = qtdFilme(); //quantidade de filmes do vetor
   float cod;
   printf("-------------------------------------------------------\n");
   printf("Digite o codigo do clinte que deseja atualizar: \n");
   scanf("%f", &cod);
   printf("-------------------------------------------------------\n");
   for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) { 
            printf("Codigo: %0.f \n Descrição: %s \n Quantidade de exemplares: %0.f \n Código da categoria: %0.f \n Lingua: %s\n --------------------------------------------------\n", p[i].codigo, p[i].descricao, p[i].exemplares, p[i].catCodigo, p[i].lingua);
        } 
            
    }
    
}


