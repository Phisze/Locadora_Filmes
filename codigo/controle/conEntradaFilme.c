/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//o valor da compra sai do caixa e a entrada fica salva
int conEntraFilme(char * nomeFornecedor,float precoFrete,float imposto,Filme* filmesComprados,float * valorCompraFilmes,int * qtdFilmes){
    float precoTotal=0.0+precoFrete+imposto;
    int index=0;
    //o último index do qtdFilmes tem que ter um 0 
    //pro algoritmo saber quando parar
    while(qtdFilmes[index]!=0){
        
        //fazer um consulta filme por nome
        //if
        //  atualizaFilme()  
        //else
        //  salvaFilme()
            
        precoTotal=precoTotal+((float)valorCompraFilmes[index]*qtdFilmes[index]);
        index++;        
    }
    
        
        
     //vou ter que chamar um método do dao "salvaNota()" pra passar os dados da nota que será persistida
}