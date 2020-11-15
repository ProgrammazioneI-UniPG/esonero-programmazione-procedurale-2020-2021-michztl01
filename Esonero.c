//Diaconu Mihail Matricola:330302 Anno di Corso:1 Prof:Francesco Santini A.A:2020/21
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define lun 128
//dichiaro la lunghezza delle stringhe
FILE * stdin;
//stringhe plaintext(M),Chiave di cifratura(K),stringa cifrata(C)
char M[lun];
char K[lun];
char C[lun];
//variabile che fa scegliere all'utente l'opzione desiderata
int input_utente;

void chiave_random();
void chiave_manuale();

int main(){

  printf("Inserisci una stringa: \n");
  fgets(M,128,stdin);
  printf("\n");
  puts(M);
  //precauzione dall'inserimento da parte dell'utente
  while(input_utente!=1 && input_utente != 2){
    printf("Inserisci 1 se vuoi generare manualmente la chiave altrimenti premi 2\n");
    printf("Attenzione, verra' letto solo il primo carattere inserito:");
    scanf("%1d", &input_utente);
    while(getchar()!='\n');
  }

  switch (input_utente){
    case 1:
      chiave_manuale();
      break;
    case 2:
      chiave_random();
      break;
  }
  //Effettuo la cifratura
  for(int i=0;i<(strlen(M));i++){
    C[i]=M[i]^K[i];
  }
  printf("Stampa di C: ");
  puts(C);
  printf("\n Fine stampa di C \n");
  //Trovo e stampo la stringa iniziale
  for(int i=0;i<(strlen(C));i++){
    M[i]=C[i]^K[i];
  }
  printf("Stampa di M:");
  puts(M);
  printf("\n Fine Stampa di M\n");

  return 0;
}//fine main

//chiave inserita da tastiera
void chiave_manuale(){
  printf("Opzione 1: chiave da generare manualmente\n");
  do{
    printf("Immetti la chiave k: \n");
    fgets(K,lun,stdin);
    puts(K);
    if (strlen(K)<strlen(M))
      printf("Lunghezza della chiave minore della lunghezza della stringa");
  }while(strlen(K)<strlen(M));
}
//chiave generata con random()
void chiave_random(){
  time_t t;
  srand((unsigned)time(&t));
  printf("Opzione 2: chiave generata randomicamente\n");
  for(int i=0;i<lun;i++){
    K[i]=rand()%lun;
  }
  printf("Stampa della chiave:");
  puts(K);
  printf("Fine Stampa chiave K \n");
}
