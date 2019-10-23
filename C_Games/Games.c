#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "lib.h"
#include "messages.h"

int main(){

  menu();

}

void menu(){

  printf("\nBenvenuto nel menu\n");
  printf("Ho tre giochi in memoria: \n");
  printf("-Morra Cinese\n-Lancio della moneta\n-Indovino\n-Uscita\n");
  printf("In base alle tue preferenze puoi digitare [m][l][i] ovvero le iniziali dei tre giochi, oppure [u] per uscire\n");
  printf("Scelta: ");
  do{
    scanf(" %c",&scelta.gioco);
    if(scelta.gioco != 'm' && scelta.gioco != 'l' && scelta.gioco != 'i' && scelta.gioco != 'u')
      commenti_errori();
  }while(scelta.gioco != 'm' && scelta.gioco != 'l' && scelta.gioco != 'i' && scelta.gioco != 'u');

  switch(scelta.gioco){
    case 'm': morra_cinese(scelta);
    break;
    case 'l': lancio_moneta(scelta);
    break;
    case 'i': indovino(scelta);
    break;
    case 'u': printf("Arrivederci\a\n");
              MessageBeep(MB_ICONQUESTION);
    return;
  }

}

void morra_cinese(struct variabili scelta){

  int vince_pc = 0;
  int vince_usr = 0;
  int num_partite = 0, i = 0;


  printf("\nBenvenuto nella morra cinese\n");
  printf("Hai tre possibilità: \n");
  printf("-Sasso\n-Carta\n-Forbice\n");
  printf("Fai la tua scelta digitando [s] o [c] o [f]\n");
  printf("Nello stesso momento in cui sceglierai anche io farò lo stesso\n");
  printf("Quante partite vuoi fare?: ");
  do{
    scanf("%i", &scelta.num_partite);
    if(scelta.num_partite <= 0)
      commenti_errori();
    }while(scelta.num_partite <= 0);

  while( i < scelta.num_partite){
    printf("Scegli cosa buttare: ");
    do{
      scanf(" %c", &scelta.mano_usr);
      if(scelta.mano_usr != 's' && scelta.mano_usr != 'c' && scelta.mano_usr != 'f')
      commenti_errori();
    }while(scelta.mano_usr != 's' && scelta.mano_usr != 'c' && scelta.mano_usr != 'f');

    srand(time(NULL));
    scelta.mano_pc = rand() % 3;

    switch(scelta.mano_pc)
    {
        case 0: if( scelta.mano_usr == 'c' ){
                  printf("Io butto sasso!\n");
                  printf("Hai vinto tu!\n");
                  vince_usr++;
                }else if( scelta.mano_usr == 'f'){
                  printf("Io butto sasso!\n");
                  printf("Ho vinto io!\n");
                  vince_pc++;
                }else{
                  printf("Io butto sasso!\n");
                  printf("Pareggio!\n");
                }
        break;
        case 1: if( scelta.mano_usr == 's' ){
                printf("Io butto carta!\n");
                printf("Ho vinto io!\n");
                vince_pc++;
                }else if( scelta.mano_usr == 'f'){
                  printf("Io butto carta!\n");
                  printf("Hai vinto tu!\n");
                  vince_usr++;
                }else{
                  printf("Io butto carta!\n");
                  printf("Pareggio!\n");
                }
        break;
        case 2: if( scelta.mano_usr == 'c' ){
                printf("Io butto forbice!\n");
                printf("Ho vinto io!\n");
                  vince_pc++;
                }else if( scelta.mano_usr == 's'){
                  printf("Io butto forbice!\n");
                  printf("Hai vinto tu!\n");
                  vince_usr++;
                }else{
                  printf("Io butto forbice!\n");
                  printf("Pareggio!\n");
                }
        break;
    }

    i++;
  }

    printf("\nRisultati\n");
    if( vince_pc > vince_usr ){
      printf("Vinco io %i a %i!\n",vince_pc , vince_usr);
    }else if( vince_pc < vince_usr ){
      printf("Vinci tu %i a %i\n", vince_usr ,vince_pc);
    }else{
      printf("Pareggio!\n");
    }

menu();
}

void lancio_moneta(struct variabili scelta){

  int i = 0;
  int vince_pc = 0;
  int vince_usr = 0;

  printf("\nBenvenuto nel lancio della moneta\n");
  printf("Hai due possibilità: \n");
  printf("-Testa\n-Croce\n");
  printf("Fai la tua scelta digitando [t] o [c]\n");
  printf("Io mi occuperò di tirare la moneta\n");
  printf("Quante partite vuoi fare?: ");
  do{
    scanf("%i", &scelta.num_partite);
    if(scelta.num_partite <= 0)
      commenti_errori();
  }while(scelta.num_partite <= 0);

  while( i < scelta.num_partite){

    printf("Quale lato scegli?: ");
    do{
      scanf(" %c", &scelta.mano_usr);
      if(scelta.mano_usr != 't' && scelta.mano_usr != 'c');
        commenti_errori();
    }while(scelta.mano_usr != 't' && scelta.mano_usr != 'c');

    if(scelta.mano_usr == 't')
      printf("Ok allora io scelgo croce\n");
    else
      printf("Ok allora io scelgo testa\n");

    printf("Lancio la moneta\n...\n..\n.\n");
    srand(time(NULL));
    scelta.lancio = rand() % 2;

    switch(scelta.lancio)
    {
      case 0: if(scelta.mano_usr == 't'){
                printf("Testa hai vinto tu!\n");
                vince_usr++;
              }else{
                printf("Testa ho vinto io\n");
                vince_pc++;
              }
      break;
      case 1: if(scelta.mano_usr == 'c'){
                printf("Croce hai vinto tu!\n");
                vince_usr++;
              }else{
                printf("Croce ho vinto io\n");
                vince_pc++;
              }
      break;
    }
    i++;
  }

  printf("\nRisultati\n");
  if( vince_pc > vince_usr ){
    printf("Vinco io %i a %i!\n",vince_pc , vince_usr);
  }else if( vince_pc < vince_usr ){
    printf("Vinci tu %i a %i\n",vince_usr ,vince_pc);
  }else{
    printf("Pareggio!\n");
  }
menu();
}

void indovino(struct variabili scelta){

  int ampiezza;

  printf("\nBenvenuto nell'indovino\n");
  printf("Io penso a un numero compreso tra due estremi da te scelti, sta a te indovinare quale!\n");
  do{
    printf("Scegli un minimo positivo maggiore di zero: ");
    do{
      scanf("%i", &scelta.min);
      if(scelta.min <= 0)
        commenti_errori();
    }while(scelta.min <= 0);
    printf("Scegli un massimo positivo che sia maggiore del minimo: ");
    do{
      scanf("%i", &scelta.max);
      if(scelta.max <= 0)
        commenti_errori();
    }while(scelta.max <= 0);
    if(scelta.min <= 0 && scelta.max <= 0){
      printf("\nDevi scegliere due estremi maggiori di zero\n");
    }else if(scelta.max <= 0){
      printf("\nDevi scegliere un massimo maggiore di 0\n");
    }else if(scelta.min <= 0){
      printf("\nDevi scegliere un minimo maggiore di 0\n");
    }else if(scelta.min >= scelta.max){
      printf("\nIl minimo deve essere piu grande del massimo\n");
    }
  }while((scelta.min <= 0 || scelta.max <= 0) || (scelta.min >= scelta.max));

  srand(time(NULL));

  ampiezza = scelta.max - scelta.min + 1; //ampiezza è il max sottratto a K
  scelta.lancio = rand() % ampiezza + scelta.min; //intervallo tra min e max + K ovvero l'originale max

  printf("\nOk, ho pensato a un numero compreso tra %i e %i\n", scelta.min, scelta.max);

  while(scelta.num_usr != scelta.lancio){

    printf("Scelta: ");
    do{
      scanf("%i", &scelta.num_usr);
      if(scelta.num_usr < scelta.min){
        printf("Non puoi inserire un numero piu piccolo del minimo, riprova: ");
      }else if(scelta.num_usr > scelta.max){
        printf("Non puoi inserire un numero piu grande del massimo, riprova: ");
      }
    }while(scelta.num_usr < scelta.min || scelta.num_usr > scelta.max);

    if(scelta.num_usr == scelta.lancio){
      printf("Hai indovinato, bravo!\n");
      menu();
    }else if(scelta.num_usr < scelta.lancio){
      printf("Sbagliato, sto pensando a un numero piu grande\n");
      scelta.min = scelta.num_usr;
      printf("\nNumero compreso tra %i e %i\n", scelta.min, scelta.max);
    }else{
      printf("Sbagliato, sto pensando a un numero piu piccolo\n");
      scelta.max = scelta.num_usr;
      printf("\nNumero compreso tra %i e %i\n", scelta.min, scelta.num_usr);
    }
  }

  }
