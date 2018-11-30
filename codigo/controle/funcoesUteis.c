/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <time.h>
#include "../structs.h"
int movimentaCaixa(float valor){
    caixa=caixa+valor;
    return 1;
}

time_t to_seconds(const char *date) {
    struct tm storage = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char *p = NULL;
    time_t retval = 0;
    p = (char *) strptime(date, "%d/%m/%Y", &storage);
    if (p == NULL) {
        retval = 0;
    } else {
        retval = mktime(&storage);
    }
    return retval;
}

char * pegaDataAtual(){

    char data[10];
    
    time_t mytime;
    mytime=time(NULL);
    struct tm tm=*localtime(&mytime);
    char dia[snprintf(NULL,0,"%d",tm.tm_mday)+1];
    sprintf(dia,"%d",tm.tm_mday);
    char mes[snprintf(NULL,0,"%d",tm.tm_mon)+1];
    sprintf(mes,"%d",tm.tm_mon);
    char ano[snprintf(NULL,0,"%d",tm.tm_year+1900)+1];
    sprintf(ano,"%d",tm.tm_year+1900);

    data[0]=dia[0];
    data[1]=dia[1];
    data[2]='/';
    data[3]=mes[0];
    data[4]=mes[1];
    data[5]='/';
    data[6]=ano[0];
    data[7]=ano[1];
    data[8]=ano[2];
    data[9]=ano[3];
    
    return data;

} 
