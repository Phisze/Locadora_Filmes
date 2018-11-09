#include<stdio.h>
#include "../filmeDAO.h"
#include "../structs.h"
#include "../conFilme.h"
#include <string.h>

void fornecedorMenu(){
    
    int x;
        do{
    printf("\t MENU FORNECEDOR\n");
    printf("---------------------------------------------\n");        
    printf("0. Sair \n");
    printf("1. Salvar Locadora \n");
    printf("2. Atualizar Locadora \n");
    printf("3. Deletar Locadora \n");
    printf("4. Listar Locadora  \n");
    printf("5. Consultar Locadora \n");
    printf("6. Voltar para o menu principal \n");
    printf("---------------------------------------------\n");        
    printf("Digite uma das opções: \n");
    scanf("%d%*c", &x); 
    printf("---------------------------------------------\n");        

    switch(x){
        //Salva 
        case 1:
            salveFornecedor();
            break;
        //Atualiza
        case 2:
            attLocadora();
            break;
        //deleta
        case 3:
           deletFornecedor();
            break;
        //lista
        case 4: 
             listLocadora();
            break;
         //consulta
        case 5:
            consulteFornecedor();
            break;
        //Menu Principal
        case 6:
            menuPrincipal();
            break;
           
    }
          
    }while(x!= 0);
    
 }
//int mensagem_operacao(int cod) {
//
//    if (cod == 1)
//        printf("Opereção feita com sucesso!\n");
//    else {
//        printf("Operação não realizada com sucesso!\n");
//    }
//}
void salveFornecedor(){
    
    Fornecedor fornecedor;

    fflush(stdin); //limpa                       
    printf("Digite o nome fantasia da locadora: \n");
    scanf("%[^\n]%*c", fornecedor.nome); //Até o usuario dar enter
    fflush(stdin); //limpa
    
                           
    printf("Digite a razão social da empresa: \n");
    scanf("%[^\n]%*c", fornecedor.razao_social); //Até o usuario dar enter
    fflush(stdin); //limpa
    
                          
    printf("Digite a inscrição estadual da empresa: \n");
    scanf("%[^\n]%*c", fornecedor.inscricao_estadual); //Até o usuario dar enter
    fflush(stdin); //limpa
    
                         
    printf("Digite o CNPJ da empresa: \n");
    scanf("%[^\n]%*c", fornecedor.cnpj); //Até o usuario dar enter
    fflush(stdin); //limpa
    
        //observações aqui                
    printf("Digite o endereço completo : \n");
    scanf("%[^\n]%*c", fornecedor.endereco); //Até o usuario dar enter
    fflush(stdin); //limpa
       
    printf("Digite o tefone: \n");
    scanf("%[^\n]%*c", fornecedor.telefone); //Até o usuario dar enter
    fflush(stdin); //limpa
                       
    printf("Digite o e-mail: \n");
    scanf("%[^\n]%*c", fornecedor.email); //Até o usuario dar enter
    fflush(stdin); //limpa
                         
        
     mensagem_operacao(salvaFornecedor(&fornecedor));
}
void attLocadora(){
  
  Fornecedor fornecedor;
  
  Fornecedor *p = listarFornecedor(); //p vetor com todas Fornecedores
  int tamanho = qtdFornecedor(); //quantidade de Fornecesores do vetor
  float cod;

    printf("Digite o codigo do cliente que deseja atluaizar: ");
    scanf("%f", &cod);

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
   
            fflush(stdin); //limpa                       
            printf("Digite o nome fantasia da locadora: \n");
            scanf("%[^\n]%*c", p[i].nome); //Até o usuario dar enter
            strcpy(fornecedor.nome, p[i].nome);
            fflush(stdin); //limpa


            printf("Digite a razão social da empresa: \n");
            scanf("%[^\n]%*c", p[i].razao_social); //Até o usuario dar enter
            strcpy(fornecedor.razao_social, p[i].nome);
            fflush(stdin); //limpa


            printf("Digite a inscrição estadual da empresa: \n");
            scanf("%[^\n]%*c", p[i].inscricao_estadual); //Até o usuario dar enter
            strcpy(fornecedor.inscricao_estadual, p[i].nome);
            fflush(stdin); //limpa


            printf("Digite o CNPJ da empresa: \n");
            scanf("%[^\n]%*c", p[i].cnpj); //Até o usuario dar enter
            strcpy(fornecedor.cnpj, p[i].cnpj);
            fflush(stdin); //limpa

                //observações aqui                
            printf("Digite o endereço completo : \n");
            scanf("%[^\n]%*c", p[i].endereco); //Até o usuario dar enter
            strcpy(fornecedor.nome, p[i].nome);
            fflush(stdin); //limpa
            
            printf("Digite o tefone: \n");
            scanf("%[^\n]%*c", p[i].telefone); //Até o usuario dar enter
            strcpy(fornecedor.telefone, p[i].telefone);
            fflush(stdin); //limpa

            printf("Digite o e-mail: \n");
            scanf("%[^\n]%*c", p[i].email); //Até o usuario dar enter
            strcpy(fornecedor.email, p[i].email);
            fflush(stdin); //limpa

            mensagem_operacao(atualizaFornecedor(fornecedor));
        }
    }
}
void listLocadora() {

    Fornecedor *p = listarFornecedor(); //p vetor com todos os clientes 
    int tamanho = qtdFornecedor(); //quantidade de clientes do vetor

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].deletado != '*') { //Não mostrar os deletados
            printf("Codigo: %0f, \n Nome: %s, \n Razão social: %s,\n Inscrição Estadual: %s,\n CNPJ: %s,\n Endereço: %s,\n Telefone: %s,\n E-mail: %s \n -------------------------------------------------\n",p[i].codigo, p[i].nome, p[i].razao_social, p[i].inscricao_estadual, p[i].cnpj, p[i].endereco, p[i].telefone, p[i].email);
        }
    }
    }
void consulteFornecedor() {

  Fornecedor fornecedor;
  Fornecedor *p = listarFornecedor(); //p vetor com todas Fornecedores
  int tamanho = qtdFornecedor(); //quantidade de Fornecesores do vetor
  float cod;

    printf("---------------------------------------------\n");        
    printf("Digite o codigo do clinte que deseja atualizar: \n");
    scanf("%f", &cod);
    printf("---------------------------------------------\n");        


    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) { //Não mostrar os deletados
            printf("Codigo: %0f, \n Nome: %s, \n Razão social: %s,\n Inscrição Estadual: %s,\n CNPJ: %s,\n Endereço: %s,\n Telefone: %s,\n E-mail: %s \n -------------------------------------------------\n",p[i].codigo, p[i].nome, p[i].razao_social, p[i].inscricao_estadual, p[i].cnpj, p[i].endereco, p[i].telefone, p[i].email);
        } else
            printf("Clinte Inexistente!");
    }
    mensagem_operacao(consultaFornecedor(&cod));

}
 int deletFornecedor(){
    
    Fornecedor fornecedor;
    Fornecedor *p = listaFornecedor(); //p vetor com todos os clientes 
    int tamanho = qtdFornecedor(); //quantidade de clientes do vetor
    float cod;
    printf("---------------------------------------------\n");  
    printf("\t Digite o codigo do clinte que deseja deletar: \n");
    scanf("%f", &cod);
    printf("---------------------------------------------\n");  
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
            mensagem_operacao(deletaFornecedor(p[i].codigo));
            break;

        }else
            printf("Clinte Inexistente!");
    }
}   
