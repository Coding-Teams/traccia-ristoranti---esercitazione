#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <stdbool.h>
#include <string.h>

#define maxRis 100
#define maxPren 100

//definizione delle strutture
typedef struct{

	char cod_sede[5];
	char citta_sede[50];
	int tot_posti;
	int posti_disp;

}ristoranti;

typedef struct{

	int cod_prenotazione; //equivale ad un tavolo
	char cod_sede_pren[5];
	int posti_richiesti;

}prenotazioni;

ristoranti ris[maxRis];  //dichiarazione di array di record
prenotazioni pren[maxPren];

//variabili globali
int n_ris = 0;
char citta_input[50];
int posti_rich = 0;
int cont_pren = 0; //per dare la dimensione della tabella prenotazioni
int i;

void inputTrace(){

	do{

		printf(":: quanti ristoranti si vuole inserire nel trace? \n");
		scanf("%d", &n_ris);

	}while(n_ris <= 0);

	for(i = 0; i < n_ris; i++){

		printf(":: codice sede ristorante \n");
		scanf("%s", ris[i].cod_sede);
		printf(":: citta sede del ristorante \n");
		scanf("%s", ris[i].citta_sede);
		printf(":: posti totali della sede del ristorante \n");
		scanf("%d", &ris[i].tot_posti);
		printf(":: posti disponibili della sede del ristorante \n");
		scanf("%d", &ris[i].posti_disp);
	}

}

void searchMax(){

	int max = 0;
	int pos = 0; //posizione del max

	printf(":: ecco i dati relativi alla prenotazione con il massimo di posti richiesti \n");

	for(i = 0; i < n_ris; i++){

		if(pren[i].posti_richiesti > max){ //elemento i-esimo

			max = pren[i].posti_richiesti;
			pos = i;
		}
	}

	printf("codice prenotazione: %d \n", pren[pos].cod_prenotazione);
	printf("codice della sede della prenotazione: %s \n", pren[pos].cod_sede_pren);
	printf("posti richiesti: %d \n", pren[pos].posti_richiesti);
	printf("\n");
}

void booking(){

	_Bool flag = 0; //flag = false

			printf(":: inserire la citta dove si desidera prenotare \n");
			scanf("%s", citta_input);

			 for(i = 0; i < n_ris; i++){

				 if(strcmp(citta_input, ris[i].citta_sede) == 0){

					 printf(":: inserire il numero di posti da prenotare \n");
					 scanf("%d", &posti_rich);

					 if(ris[i].posti_disp >= posti_rich){

						 flag = 1; //flag = true
						 ris[i].posti_disp -= posti_rich;

						 pren[i].posti_richiesti = posti_rich;
						 strcpy(pren[i].cod_sede_pren, ris[i].cod_sede);
						 pren[i].cod_prenotazione += 1;

						 cont_pren += 1;

					 }else{
						 printf(":: posti non disponibili nella sede rischiesta \n");
					 }
				 }
			 }

			if(flag == 1)
				printf(":: prenotazione effettuata! \n");
			else
				printf(":: prenotazione non effettuata! \n");

}

void output(){

	//int j;

	printf(":: ristoranti e sedi \n");

	for(i = 0; i < n_ris; i++){

		printf("codice sede: %s \n", ris[i].cod_sede);
		printf("citta sede: %s \n", ris[i].citta_sede);
		printf("posti totali sede: %d \n", ris[i].tot_posti);
		printf("posti disponibili sede: %d \n", ris[i].posti_disp);
		printf("\n");
	}

	printf("\n");
	printf(":: prenotazioni \n");

	for(i = 0; i < cont_pren; i++){

			printf("numero tavolo prenotazione: %d \n", pren[i].cod_prenotazione);
			printf("codice sede ristorante prenotato: %s \n", pren[i].cod_sede_pren);
			printf("posti richiesti al tavolo: %d \n", pren[i].posti_richiesti);
			printf("\n");
	}
}



