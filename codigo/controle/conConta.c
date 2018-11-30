#include "../contaDAO.h"
#include <stdlib.h>
#include "../tamanho.h"
#include <stdio.h>
#include "../conPersistencia.h"
//funcionando ok

int salvaConta(Conta * c) {
    Conta j = *c;

    float tamanhoCli = qtdConta() + 1;
    j.codigo = tamanhoCli;
    //printf(" tamain Conta %f\n",j.codigo);

    if (getTipoPersistencia() == MEMORIA) {
        return insereContaArrayDinamico(j);
    } else if (getTipoPersistencia() == BINARIO) {
        return inclusaoConta(j);
    } else {
        return inclusaoContaTexto(j);

    }

    ///  return 1;
}
//funcionando ok

int atualizaConta(Conta c) {
    if (getTipoPersistencia() == MEMORIA) {
        return alterarContaArrayDinamico(c.codigo, c);

    } else if (getTipoPersistencia() == BINARIO) {
        return alterarConta(c, c.codigo);
    } else {
        return alterarContaTexto(c.codigo, c);
    }
}
//funcionando ok

int deletaConta(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {
        return excluirContaArrayDinamico((int) codigo);
    } else if (getTipoPersistencia() == BINARIO) {
        return excluirConta(codigo);
    } else {
        excluirContaTexto(codigo);
        return 1;
    }


}

Conta* listaContas() {
    if (getTipoPersistencia() == MEMORIA) {
        return listarContaArrayDinamico();
    } else if (getTipoPersistencia() == BINARIO) {
        return listarConta();
    } else {
        return ListarContaTexto();
    }
}

int qtdConta() {
    if (getTipoPersistencia() == MEMORIA) {
        return tamanhoContas;
    } else if (getTipoPersistencia() == BINARIO) {
        return getTamanhoConta();
    } else {
        return getTamanhoContaTexto();
    }
}

Conta* contasPagar() {
    Conta * contas = listaContas();
    int tamanhoConta = qtdConta();

    int contadorPagar = 1;
    Conta * contasPagar = malloc(contadorPagar * sizeof (Conta));

    for (int i = 0; i < tamanhoConta; i++) {
        if (contas[i].qtdParcela == 0) {
            contadorPagar++;
            contasPagar = realloc(contasPagar, contadorPagar * sizeof (Conta));
            contasPagar[i]=contas[i];
        }
    }
    contasPagar[contadorPagar-1].codigo=-1;
    
    return contasPagar;
}
Conta consultaConta(float codigo) {
    if (getTipoPersistencia() == MEMORIA) {
        
        return consultaContaArrayDinamico(codigo);
    } else if (getTipoPersistencia() == BINARIO) {
        return consultarConta(codigo);
    } else {
        return ConsultarContaTexto(codigo);
    }
}