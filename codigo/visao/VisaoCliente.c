#include<stdio.h>
#include "../conCliente.h"
#include <string.h>
#include<strings.h>

void clientemenu(){
         
    int x;

        printf("Digite uma das opções:");

            printf("0. Sair");
            printf("1. Salvar Cliente");
            printf("2. Atualizar Cliente"); 
            printf("3. Deletar Cliente"); 
            printf("4. Listar cliente");
            printf("5. Consultar cliente");
            printf("6. Voltar para o menu");


        scanf("%d",&x);

                        char *nome;
                        char *endereco;
                        char *cpf;
                        char *telefone;
                        char *email;
                        char *sexo;
                        char *estado_civil;
                        char *data_nascimento;

            switch(x){

                case 1:
                       
                                               
                        printf ("Digite o nome: ");
                        scanf("%[^\n]", nome); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf("Digite o endereço: ");
                        scanf("%[^\n]", endereco); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf ("Digite o CPF: ");
                        scanf("%[^\n]", cpf); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf ("Digite o Telefone: ");
                        scanf("%[^\n]", telefone); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf ("Digite o e-mail: ");
                        scanf("%[^\n]", email); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf ("Digite o sexo F para femino e M para masculino: ");
                        scanf("%[^\n]", sexo); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf ("Digite Estado Civil: ");
                        scanf("%[^\n]", estado_civil); //Até o usuario dar enter
                        fflush(stdin);
                        
                        printf ("Digite o Ano de nascimento: ");
                        scanf("%[^\n]", data_nascimento); //Até o usuario dar enter
                        fflush(stdin);
                        
                        Cliente cliente;
                        
                        strcpy(cliente.nome,nome);
                        strcpy(cliente.endereco,endereco);
                        strcpy(cliente.cpf,cpf);
                        strcpy(cliente.telefone,telefone);
                        strcpy(cliente.email,email);
                        strcpy(cliente.sexo,sexo);
                        strcpy(cliente.estado_civil,estado_civil);
                        strcpy(cliente.data_nascimento,data_nascimento);
                        
                      
                         
                         mensagem_operacao(salvaCliente(&cliente));
                break;

                //case 2:
                  //  atualizaCliente();
                //break;

                 //case 3:
                //    deletaCliente();
                //break;

                // case 4:
                 //   listaClientes();
               // break;

                 //case 5:
              //       consultaCliente();
                     
              break;

            }
            
            
            return 0;
}

int mensagem_operacao(int cod){
    
    if ( cod == 1)
        printf("Opereção feita com sucesso!");
    else{
        printf("Operação não realizada com sucesso!");
    }
    }
    
