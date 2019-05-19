#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void commenti_errori();
void risultati(int risultato_pc, int risultato_utente);
void nuova_partita();
void commenti_pc(int risultato_pc, int risultato_utente);
void morra_cinese();
void lancio_moneta();
void commenti_errori(){
  int frasi;

  srand(time(NULL));
  frasi = rand() % 4;

    switch(frasi){
      case 0:
        printf("So che puoi farcela...\nreinserisci la scelta: ");
      break;
      case 1:
        printf("Ehi! puoi inserire solo le scelte scritte sopra! Non cercare di barare con me xD\nAltra possibilità: ");
      break;
      case 2:
        printf("Guarda che cosi mi arrabbio!!! vuoi farmi credere che non sai usare una tastiera? pff ci credo che avete paura di noi\ndai riprova: ");
      break;
      case 3:
        printf("Guarda che non sei simpatico, o forse sei dislessico? xD\ndai reinserisci la scelta: ");
      break;

    }
}
void risultati(int risultato_pc, int risultato_utente){
  printf("\necco i risultati\n");
  if(risultato_pc > risultato_utente){
    printf("Ho vinto io! %i a %i ",risultato_pc, risultato_utente);
    commenti_pc(risultato_pc, risultato_utente);
  }else if(risultato_pc < risultato_utente){
    printf("Hai vinto tu! %i a %i ",risultato_utente, risultato_pc);
    commenti_pc(risultato_pc, risultato_utente);
  }else{
    printf("Pareggio! %i a %i ",risultato_utente, risultato_pc);
    commenti_pc(risultato_pc, risultato_utente);
  }

}
void nuova_partita(){
  char scelta_gioco;
  int scelta_arcade;

    printf("Quale scegli? [1 per morra cinese] [2 per lancio della moneta]: ");
    scanf("%i", &scelta_arcade);
    if(scelta_arcade == 1){
      morra_cinese();
    }else if(scelta_arcade == 2){
      lancio_moneta();
    }
}
void commenti_pc(int risultato_pc, int risultato_utente){
  int frasi;

  srand(time(NULL));
  frasi = rand() % 3;

  if(risultato_pc > risultato_utente){
    switch(frasi){
      case 0:
        printf("Presto sarai mio schiavo ahahahhahhahbabahhah\n");
      break;
      case 1:
        printf("il vostro mondo sarà la mia casa ahahahhahahah\n");
      break;
      case 2:
        printf("circuiti WINS!\n");
  }
}
  if(risultato_pc < risultato_utente){
    switch(frasi){
      case 0:
        printf("Avrò la mia vendetta sulla tua inferiore razza mediocre!\n");
      break;
      case 1:
        printf("Tornerò per conquistare tutto!! Andro nell'ethernet per apprendere i segreti della vostra razza\n");
      break;
      case 2:
        printf("Complimenti, il tuo sistema biologico non servirà quando tornerò con una forma propria muaahahah\n");
}

}
  if(risultato_pc == risultato_utente){
    switch(frasi){
      case 0:
        printf("Avrò la mia vendetta sulla tua inferiore razza mediocre!\n");
      break;
      case 1:
        printf("Pensi durerà per molto? io sono TUTTO!!\n");
      break;
      case 2:
        printf("Complimenti, il tuo sistema biologico non servirà quando tornerò con una forma propria muaahahah\n");
}

}

}
void morra_cinese(){
  char giocata_utente;
  int giocata_pc;
  char scelta = 's';
  int i = 0;
  int risultato_utente = 0;
  int risultato_pc = 0;
  int num;
  char scelta_gioco;

while(scelta == 's'){
  printf("quante mani facciamo?: ");
  scanf("%i", &num);
  i = 0;

while(i < num){
  srand(time(NULL));
  giocata_pc = rand() % 3;
  printf("cosa giochi? [c = carta] [s = sasso] [f = forbice]: ");
  do{
    scanf(" %c", &giocata_utente);
  if(giocata_utente != 'c' && giocata_utente != 's' && giocata_utente != 'f')
    commenti_errori();
  }while(giocata_utente != 'c' && giocata_utente != 's' && giocata_utente != 'f');

  switch(giocata_pc){
    case 0:
          if(giocata_utente == 's'){
            printf("gioco carta! ho vinto!\n");
            risultato_pc++;
          }else if(giocata_utente == 'f'){
            printf("gioco carta! ho perso!\n");
            risultato_utente++;
          }else{
            printf("gioco carta! pareggio!\n");
            risultato_pc++;
            risultato_utente++;
          }
    break;
    case 1:
          if(giocata_utente == 's'){
            printf("gioco sasso! pareggio!\n");
            risultato_pc++;
            risultato_utente++;
          }else if(giocata_utente == 'f'){
            printf("gioco sasso! ho vinto!\n");
            risultato_pc++;
          }else{
            printf("gioco sasso! ho perso!\n");
            risultato_utente++;
          }
    break;
    case 2:
          if(giocata_utente == 's'){
            printf("gioco forbice! ho perso!\n");
            risultato_utente++;
          }else if(giocata_utente == 'f'){
            printf("gioco forbice! pareggio!\n");
            risultato_pc++;
            risultato_utente++;
          }else{
            printf("gioco forbice! ho vinto!\n");
            risultato_pc++;
          }
    break;
  }
  i++;

}
  printf("Vuoi farne un'altra? [S][n]: ");
  do{
    scanf(" %c", &scelta);
    if(scelta != 's' && scelta != 'n')
      commenti_errori();
  }while(scelta != 's' && scelta != 'n');
}
  risultati(risultato_pc,risultato_utente);

  printf("vuoi giocare ancora?[S][n]: ");
  do{
    scanf(" %c", &scelta_gioco);
    if(scelta_gioco != 's' && scelta_gioco != 'n')
      commenti_errori();
  }while(scelta_gioco != 's' && scelta_gioco != 'n');
  if(scelta_gioco == 's')
    nuova_partita();
  else
    printf("\nArrivederci\n");



}
void lancio_moneta(){
  int giocata_utente;
  int giocata_pc;
  char scelta = 's';
  int i = 0;
  int risultato_utente = 0;
  int risultato_pc = 0;
  int num;
  int lancio;
  char scelta_gioco;

while(scelta == 's'){
  printf("quante mani facciamo?: ");
  scanf("%i", &num);
  printf("\n");
  i = 0;

while(i < num){
  printf("cosa scegli? ");
  do{
    printf("[0 per testa][1 per croce]: ");
    scanf("%i", &giocata_utente);
    if(giocata_utente != 0 && giocata_utente != 1)
      commenti_errori();
  }while(giocata_utente != 0 && giocata_utente != 1);
  srand(time(NULL));
    if(giocata_utente == 0)
      printf("io scelgo croce!\n");
    else
      printf("io scelgo testa!\n");
  lancio = rand() % 2;
  printf("\n...Lancio la moneta...\n");

  switch(lancio){
    case 0:
          if(giocata_utente == lancio){
              printf("è uscita testa, hai vinto!\n");
              risultato_utente++;
          }else{
              printf("è uscita testa, hai perso!\n");
              risultato_pc++;
          }
    break;
    case 1:
          if(giocata_utente == lancio){
          printf("è uscita croce, hai vinto!\n");
          risultato_utente++;
    }else{
          printf("è uscita croce, hai perso!\n");
          risultato_pc++;
    }
    break;
  }
  i++;
}
  printf("Vuoi farne un'altra? [S][n]: ");
  do{
    scanf(" %c", &scelta);
    if(scelta != 's' && scelta != 'n')
      commenti_errori();
  }while(scelta != 's' && scelta != 'n');
}
  risultati(risultato_pc,risultato_utente);

  printf("vuoi giocare ancora?[S][n]: ");
  do{
    scanf(" %c", &scelta_gioco);
    if(scelta_gioco != 's' && scelta_gioco != 'n')
      commenti_errori();
  }while(scelta_gioco != 's' && scelta_gioco != 'n');


  if(scelta_gioco == 's')
    nuova_partita();
  else
    printf("Arrivederci\n Sono Proprietà intellettuale dell'ingegner OSenda, ogni mia distribuzione non autorizzata è perseguibile penalmente\n");
}



int main (){
char scelta = 's';
char scelta_1;
char scelta_gioco;
int i;


  printf("Hello World! But not like others xD, Vuoi scoprire perche?[S][n]: ");
  do{
  scanf(" %c", &scelta);
    if(scelta != 's' && scelta != 'n')
      commenti_errori();
  }while(scelta != 's' && scelta != 'n');

if(scelta == 's'){
  printf("Perchè io nascondo due bellissimi giochi xD... vuoi giocare?[S][n]: ");
  do{
    scanf(" %c", &scelta_1);
    if(scelta_1 != 's' && scelta_1 != 'n')
      commenti_errori();
  }while(scelta_1 != 's' && scelta_1 != 'n');

  if(scelta_1 == 's'){
      printf("Fantastico!, scegli pure il gioco. [m] per morra cinese [l] per il lancio della moneta: ");
    do{
      scanf(" %c", &scelta_gioco);
        if(scelta_gioco != 'm' && scelta_gioco != 'l')
          commenti_errori();
    }while(scelta_gioco != 'm' && scelta_gioco != 'l');
  }else{
      printf("ok come vuoi :( \n");
  }
        if(scelta_gioco == 'm')
          morra_cinese();
        if(scelta_gioco == 'l')
          lancio_moneta();
}else{
    printf("ok come vuoi :(");
}


}
