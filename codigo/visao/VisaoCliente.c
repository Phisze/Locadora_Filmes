#include<stdio.h>
#include "../conCliente.h"

void clientemenu(int x){
         
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



            switch(x){

                case 1:
                  //  salvaCliente((vector nome,vector endereco,vector cpf, vector telefone, vector email, char sexo, vector estado_civil, vector data_nascimento);
                break;

                case 2:
                //    atualizaCliente(Cliente c);
                break;

                 case 3:
                 //   deletaCliente(codigo);
                break;

                 case 4:
                 //    listaClientes();
                break;

                 case 5:
                 //    consultaCliente(int codigo);
              break;

            }
            
            return 0;
}

int cadastroCliente(){


}