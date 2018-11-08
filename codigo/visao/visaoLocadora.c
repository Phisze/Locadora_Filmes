#include<stdio.h>
#include "../filmeDAO.h"
#include "../structs.h"
#include "../conFilme.h"
#include <string.h>

void locadoraMenu(){
    
    int x;
    
    do{
    printf("MENU LOCADORA: \n");
    printf("---------------------------------------------\n");        
    printf("0. Sair \n");
    printf("1. Salvar Locadora \n");
    printf("2. Voltar para o menu principal \n");
    printf("---------------------------------------------\n");        
    printf("Digite uma das opções: \n");
    scanf("%d%", &x); 
    printf("---------------------------------------------\n");        

    switch(x){
       
        case 1:
            salveLoc();
            break;
        case 2:
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
    scanf("%[^\n]%*c", locadora.nome); //Até o usuario dar enter
    fflush(stdin); //limpa
    fflush(stdin); //limpa  
    
    printf("Digite o tefone: \n");
    scanf("%[^\n]%*c", locadora.telefone); //Até o usuario dar enter
    fflush(stdin); //limpa
                       
    printf("Digite o e-mail: \n");
    scanf("%[^\n]%*c", locadora.email); //Até o usuario dar enter
    fflush(stdin); //limpa
    
                      
    printf("Digite o nome fantasia da locadora: \n");
    scanf("%[^\n]%*c", locadora.nome); //Até o usuario dar enter
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


