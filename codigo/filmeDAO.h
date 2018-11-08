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
int inclusaoFilmes(Filme f);
/*
 **  Inclui Filmes em arquivo Texto
 */
void inclusaoFilmeTexto(Filme f);
/*
 **  Lista Filmes em arquivo binario
 */
Filme* listarFilmes();
/*
 **  Lista Filmes em arquivo Texto
 */
Filme* ListarFilmesTexto();
/*
 **  Consultar Filmes em arquivo binario
 */
Filme consultarFilmes(float cod);
/*
 **  Consultar Filmes em arquivo Texto
 */
Filme ConsultarFilmesTexto(float cod);
/*
 **  Altera Filmes em arquivo binario
 */
int alterarFilmes(Filme filme, float cod);
/*
 **  Altera Filmes em arquivo Texto
 */
void alterarFilmeTexto(float cod, Filme fil);
/*
 **  Deleta Filmes em arquivo binario
 */
int excluirFilmes(float cod);
/*
 **  Deleta Filmes em arquivo Texto
 */
int excluirFilmesTexto(float cod);
#endif /* FILME_H */

