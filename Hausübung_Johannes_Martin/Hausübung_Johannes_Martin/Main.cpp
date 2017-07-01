#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


void main(){
	
	student stud[120];
	firma f[120];

	int i=0;
	char befehl='x';
	char eingabebefehl='x';
	char eingabebefehl2='x';
	char ausgabebefehl='x';
	char einlesebefehl='x';
	char bearbeitungsbefehl='x';
	printf("Willkommen in der Studentendatenbank!");

	int positions;										//Einlesen der Anzahl der momentan gespeicherten Studenten
	FILE * anzahls_daten_alt;
	anzahls_daten_alt = fopen("anzahls.txt", "r+");
	fscanf(anzahls_daten_alt, "%i", &positions);
	fclose(anzahls_daten_alt);

	int positionf;										//Einlesen der Anzahl der momentan gespeicherten Firmen
	FILE * anzahlf_daten_alt;
	anzahlf_daten_alt = fopen("anzahlf.txt", "r+");
	fscanf(anzahlf_daten_alt, "%i", &positionf);
	fclose(anzahlf_daten_alt);



	do{
		menu(&befehl);
		

		switch(befehl){
		
		case 'e':	eingabeauswahl(stud,f,i);						//Eingabe
					break;


		case 'a':	ausgabeauswahl(stud,f,i);						//Ausgabe
					break;

		case 'c':	bearbeiten(stud,f,i);							//Bearbeiten
					break;

		case 's':	student_suchen(stud);							//Suchen
					break;

		case 'l':	datensatz_löschen(stud, positions);				//Daten löschen
					break;
		case 'b':	break;

		default:	printf("Falsche Eingabe. Bitte erneut versuchen!");
					break;
					system("cls");	
		}
	}while(i<120 && befehl!='b');

	printf("\n-------------------------------------------------------------------------------\n");
	printf(" Die Studentendatenbank wurde beendet!");
	printf("\n-------------------------------------------------------------------------------\n");



	getch();
	}
	