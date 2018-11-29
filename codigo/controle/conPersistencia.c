///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//#define MEMORIA 0
//#define TEXTO 2
//#define BINARIO 1
//
//
//int tipoPersistencia=BINARIO;
//
//int getTipoPersistencia(){
//    return tipoPersistencia;
//}
//
//int setTipoPersistencia(int tipo){
//    if (tipo==MEMORIA || tipo==TEXTO || tipo==BINARIO){
//        tipoPersistencia=tipo;
//    }
//}
//
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define MEMORIA 0
#define TEXTO 2
#define BINARIO 1


int tipoPersistencia = TEXTO;

int getTipoPersistencia() {
    return tipoPersistencia;
}

int setTipoPersistencia(int tipo) {
    if (tipo == MEMORIA || tipo == TEXTO || tipo == BINARIO) {
        tipoPersistencia = tipo;
    }
}

