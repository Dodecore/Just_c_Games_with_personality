#ifndef LIB_H
#define LIB_H

struct variabili{
  char gioco;
  char mano_usr;
  int mano_pc;
  int num_partite;
  int lancio;
  int max;
  int min;
  int num_usr;
};


struct variabili scelta;
void menu();
void morra_cinese(struct variabili scelta);
void lancio_moneta(struct variabili scelta);
void indovino(struct variabili scelta);
void commenti_errori();
void commenti_pc(int vince_pc, int vince_usr);

#endif
