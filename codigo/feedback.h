/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   feedback.h
 * Author: wever
 *
 * Created on 16 de Novembro de 2018, 10:57
 */

#ifndef FEEDBACK_H
#define FEEDBACK_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
time_t to_seconds(const char *date);

Cliente* clienteCodigoFeedback(int cod1, int cod2);

Cliente* clienteSexoFeedback(char sexo);

Filme* filmeCodigoFeedback(int cod1, int cod2);

int qtdeLocacoesParaQueSePague(int cod, float precoTotal, float precoFilme);

Locacoes * locacoesCodigoFeedback(int tipo);

Locacoes * locacoesNomeFeedback(Cliente c);

Locacoes * movimentacaoCaixaFeedback(char *data1, char *data2);

Conta * contasReceberDataFeedback(char *data1, char *data2);

Conta * contasReceberCodigoFeedback(int cod1, int cod2);

Conta * contasPagarDataFeedback(char *data1, char *data2);

Conta * contasPagarCodigoFeedback(int cod1, int cod2)
#endif /* FEEDBACK_H */

