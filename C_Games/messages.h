#ifndef MESSAGES_H
#define MESSAGES_H

void commenti_errori(){
  int frasi;

  srand(time(NULL));
  frasi = rand() % 4;

    switch(frasi){
      case 0:
        printf("Mi stai forse mettendo alla prova?\nreinserisci la scelta: ");
      break;
      case 1:
        printf("Ehi! puoi inserire solo le scelte scritte sopra! Non cercare di barare con me ;)\nAltra possibilità: ");
      break;
      case 2:
        printf("Se lo stai facendo apposta non è simpatico...\ndai riprova: ");
      break;
      case 3:
        printf("Guarda che non mi freghi\ndai reinserisci la scelta: ");
      break;

    }
}

#endif
