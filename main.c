/*
 * tracia di programmazione
 * gestione prenotazioni catena ristoranti
 *
 *
 * spicoli piersilvio - uniba computer science
 */

#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <stdbool.h>
#include <string.h>

int main(){

	setbuf(stdout, NULL);

	int ch = 0, ch2 = 0; //choise

	inputTrace();

	system("cls");

	do{
		do{
				booking();
				printf(":: effettuare una nuova prenotazione? (1 - si) (2 - no) \n");
				scanf("%d", &ch);
			}while(ch == 1);

			printf("\n");
			searchMax();
			printf("\n");
			output();

			printf(":: effettuare una nuova simulazione sul trace selezionato? (1 - si) (2 - no) \n");
	}while(ch2 == 1);


	return 0;
}
