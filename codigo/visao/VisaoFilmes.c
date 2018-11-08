#include<stdio.h>
#include "../filmeDAO.h"
#include "../structs.h"
#include "../conFilme.h"
#include <string.h>

void filmeMenu(){
    int x;
    
    do{
    printf("\t MENU FILME \n");
    printf("---------------------------------------------\n");        
    printf("0. Sair \n");
    printf("1. Salvar Filme \n");
    printf("2. Atualizar Filme \n");
    printf("3. Deletar Filme \n");
    printf("4. Listar Filme  \n");
    printf("5. Consultar Filme \n");
    printf("6. Voltar para o menu principal \n");
    printf("---------------------------------------------\n");        
    printf("\t Digite uma das opções: \n");
    scanf("%d%", &x); 
    printf("---------------------------------------------\n");        

    
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

    fflush(stdin); //limpa                       
    printf("Digite a descrição do filme: \n");
    scanf("%[^\n]%*c", filme.descricao); //Até o usuario dar enter
    fflush(stdin); //limpa
    
    printf("Digite a quantidade de exemplares do filme na locadora: \n");
    scanf("%f", &filme.exemplares); 
    fflush(stdin); //limpa
    
    printf("Digite a linguagem Dublado (Digite D) ou Legandado (Digite L) \n");
    scanf("%[^\n]%*c", filme.lingua); //Até o usuario dar enter
    fflush(stdin); //limpa
    
    printf("Digite a descrição do filme: \n");
    scanf("%[^\n]%*c", filme.descricao); //Até o usuario dar enter
    fflush(stdin); //limpa

     mensagem_operacao(salvaFilme(&filme));

}

void attFilmes(){
    
   Filme filme;    
   Filme *p = listaFilmes(); //p vetor com todos os Filmes
   int tamanho = qtdFilme(); //quantidade de filmes do vetor
   float cod;
   
   printf("Digite o codigo do filme que deseja atualizar: \n");
   scanf("%f%*c", &cod);
   
   for (int i = 0; i <= tamanho; i++) {
    if (p[i].codigo == cod) {
        
    fflush(stdin); //limpa                       
    printf("Digite a descrição do filme: \n");
    scanf("%[^\n]%*c", p[i].descricao); //Até o usuario dar enter
    strcpy(filme.descricao,p[i].descricao);
    fflush(stdin); //limpa
    
    printf("Digite a quantidade de exemplares do filme na locadora: \n");
    scanf("%f", p[i].exemplares); //Até o usuario dar enter
//    (filme.descricao = p[i].exemplares);
    fflush(stdin); //limpa
    
    printf("Digite a linguagem Dublado (Digite D) ou Legandado (Digite L) \n");
    scanf("%[^\n]%*c", p[i].lingua); //Até o usuario dar enter
    strcpy(filme.lingua,p[i].lingua);
    fflush(stdin); //limpa
    
    mensagem_operacao(atualizaFilme(filme));
    }
   }
      
}

int deletFilme(){
    
    Filme filme;
    Filme *p = listaFilmes(); //p vetor com todos os clientes 
    int tamanho = qtdFilme(); //quantidade de clientes do vetor
    float cod;
    printf("---------------------------------------------\n");  
    printf("\t Digite o codigo do clinte que deseja deletar: \n");
    scanf("%f", &cod);
    printf("---------------------------------------------\n");  
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
            printf("Codigo: %0f, \t| Descrição: %s, \t| Quantidade de exemplares: %0f, \t| Código da categoria: %0f, \t| Lingua: %s", p[i].codigo, p[i].descricao, p[i].exemplares, p[i].catCodigo, p[i].lingua);
        }
    }
    
}

void consulteFilme(){
    
   Filme filme;    
   Filme *p = listaFilmes(); //p vetor com todos os Filmes
   int tamanho = qtdFilme(); //quantidade de filmes do vetor
   float cod;
   
   printf("Digite o codigo do clinte que deseja atualizar: \n");
   scanf("%f", &cod);
   
   for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) { 
            printf("Codigo: %0f, \t|Descrição: %s, \t|Quantidade de exemplares: %0f,\t| Código da categoria: %0f,\t| Lingua: %s", p[i].codigo, p[i].descricao, p[i].exemplares, p[i].catCodigo, p[i].lingua);
        }else 
            printf("Cliente inexistente!");
    }
    
}


