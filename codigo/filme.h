/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   filme.h
 * Author: wever
 *
 * Created on 5 de Outubro de 2018, 14:14
 */

#ifndef FILME_H
#define FILME_H

#include "structs.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

/*
 **  Inclui Filmes em arquivo binario
 */
int inclusaoCliente(Cliente c);

/*
 **  Lista Filmes em arquivo binario
 */
Cliente* listaFilmes();


/*
 **  Consultar Filmes em arquivo binario
 */
Cliente consultarFilmes(int cod);
/*
 **  Altera Filmes em arquivo binario
 */
int alterarFilmes(Cliente clintes, int cod);
/*
 **  Deleta Filmes em arquivo binario
 */
int excluirFilmes(int cod);
#endif /* FILME_H */

