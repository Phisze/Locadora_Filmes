#include<stdio.h>
#include "../filmeDAO.h"
#include "../structs.h"
#include "../conFilme.h"
#include <string.h>

void funcionariomenu() {

    int x;

    do {
        printf("MENU FUNCIONARIO");
        printf("---------------------------------------------\n");        
        printf("0. Sair do programa \n");
        printf("1. Salvar Funcionario \n");
        printf("2. Atualizar Funcionario \n");
        printf("3. Deletar Funcionario \n");
        printf("4. Listar Funcionario \n");
        printf("5. Consultar Funcionario \n");
        printf("6. Voltar para o menu principal \n");
        printf("---------------------------------------------\n");        
        printf("Digite uma das opções: \n");
        scanf("%d%*c", &x);
        printf("---------------------------------------------\n");        
        switch (x) {
            //enceerra
            case 0:
                printf("SAINDO!");
                exit(1);
                break;
            case 1: //salva 
                salveFuncionario();
                break;

            case 2: //atualiza 
                attFuncionario();
                break;

            case 3: // deleta
                deletfuncionario();
                break;

            case 4: // Lista
                listaFuncionario();
                break;

            case 5://consulta
                consulteFuncionario();
                break;

            case 6: //Menu Principal
                menuPrincipal();
                break;
        }
    } while (x != 0);

}

void salveFuncionario() { //salva funcionario
    Funcionario funcionario;

    fflush(stdin); //limpa                       
    printf("Digite o nome do Funcinario: \n");
    scanf("%[^\n]%*c", funcionario.nome); //Até o usuario dar enter
    fflush(stdin); //limpa

    printf("Digite o cargo do funcionario: \n");
    scanf("%[^\n]%*c", funcionario.cargo); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o endereço completo: \n");
    scanf("%[^\n]%*c", funcionario.endereco); //Até o usuario dar enter
    fflush(stdin);

    printf("Digite o e-mail: \n");
    scanf("%[^\n]%*c", funcionario.email); //Até o usuario dar enter
    fflush(stdin);
    
    printf("Digite o Telefone: \n");
    scanf("%[^\n]%*c", funcionario.telefone); //Até o usuario dar enter
    fflush(stdin);

    mensagem_operacao(salvaFuncionario(&funcionario));
}

void attFuncionario(){ //atualiza funionario
    Funcionario funcionario;
    Funcionario *p = listarFuncionarios();
    int tamanho = qtdFuncionario();
    float cod;
    printf("---------------------------------------------\n");
    printf("\t Digite o codigo do cliente que deseja deletar:");
    scanf("%f", &cod);
    printf("---------------------------------------------\n");  
    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
            
            fflush(stdin); //limpa                       
            printf("Digite o nome do Funcinario: \n");
            scanf("%[^\n]%*c", p[i].nome); //Até o usuario dar enter
            strcpy(funcionario.nome, p[i].nome);
            fflush(stdin); //limpa

            printf("Digite o cargo do funcionario: \n");
            scanf("%[^\n]%*c", p[i].cargo); //Até o usuario dar enter
            strcpy(funcionario.cargo, p[i].cargo);
            fflush(stdin);

            printf("Digite o endereço completo: \n");
            scanf("%[^\n]%*c", p[i].endereco); //Até o usuario dar enter
            strcpy(funcionario.endereco, p[i].endereco);
            fflush(stdin);

            printf("Digite o e-mail: \n");
            scanf("%[^\n]%*c", p[i].email); //Até o usuario dar enter
            strcpy(funcionario.email,p[i].email);
            fflush(stdin);

            printf("Digite o Telefone: \n");
            scanf("%[^\n]%*c", p[i].telefone); //Até o usuario dar enter
            strcpy(funcionario.telefone, p[i].telefone);
            fflush(stdin);

         mensagem_operacao(salvaFuncionario(funcionario));   
        }
    }
    
  }

void listaFuncionario() {

    Funcionario *p = listarFuncionarios(); //p vetor com todos os clientes 
    int tamanho = qtdFuncionario(); //quantidade de clientes do vetor

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].deletado != '*') { //Não mostrar os deletados
            printf("Codigo: %0.f \n Nome: %s\n Cargo: %s\n Endereço: %s\n Telefone: %s\n E-mail: %s \n____________________________________________\n", p[i].codigo, p[i].nome,p[i].cargo, p[i].endereco, p[i].telefone, p[i].email);
        }
    }
}

void consulteFuncionario() {

    Funcionario funcionario;
    Funcionario *p = listarFuncionarios();
    int tamanho = qtdFuncionario();
    float cod;

    printf("Digite o codigo do clinte que deseja atualizar: \n");
    scanf("%f*c", &cod);

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) { //Não mostrar os deletados
            printf("Codigo: %0.f\n Nome: %s\n Cargo: %s\n Endereço: %s\n Telefone: %s\n E-mail: %s \n____________________________________________\n", p[i].codigo, p[i].nome,p[i].cargo, p[i].endereco, p[i].telefone, p[i].email);
        } else
            printf("Clinte Inexistente!");
    }

}
int deletfuncionario() {
    
    Funcionario funcionario;
    Funcionario *p = listarFuncionarios();
    int tamanho = qtdFuncionario();
    float cod;

    printf("Digite o codigo do clinte que deseja deletar: \n");
    scanf("%f", &cod);

    for (int i = 0; i <= tamanho; i++) {
        if (p[i].codigo == cod) {
             mensagem_operacao(deletaFuncionario(p[i].codigo));
            break;

        } else
            printf("Clinte Inexistente!");
    }
 }


