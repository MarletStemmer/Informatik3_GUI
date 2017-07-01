#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"



	


void ausgabe_student(student stud[120], int positions){
			
	system("cls");
	FILE * anzahls_daten_alt;
	anzahls_daten_alt = fopen("anzahls.txt", "r");
	fscanf(anzahls_daten_alt, "%i", &positions);
	fclose(anzahls_daten_alt);

	for(int i=0; i<positions; i++){	
		
			printf("\nDatensatz %i \nMatrikelnummer: %s \nVor- und Nachname: %s %s\nStartjahr: %s\nStrasse und Hausnummer: %s %s \nPLZ und Wohnort: %s %s \nMobilfunknummer: %s \nFestnetznummer: %s  \nMailadresse: %s \nFirmenname: %s \nVorname des Betreuers: %s \nNachname des Betreuers: %s\n", i, stud[i].matr, stud[i].vorname, stud[i].nachname, stud[i].startdatum, stud[i].strasse, stud[i].hausnr, stud[i].plz, stud[i].ort, stud[i].telmobil, stud[i].telfest, stud[i].mail, stud[i].firma, stud[i].betreuervor, stud[i].betreuernach);
	}
			
}

void ausgabe_firma(firma f[120], int positionf){
		
	system("cls");
	FILE * anzahlf_daten_alt;
	anzahlf_daten_alt = fopen("anzahlf.txt", "r");
	fscanf(anzahlf_daten_alt, "%i", &positionf);
	fclose(anzahlf_daten_alt);

	for(int i=0; i<positionf; i++){	
		
			printf("\nDatensatz %i\nFirmenname: %s\nStrasse und Hausnummer: %s %s\nPLZ und Ort: %s %s\nAnsprechpartner: %s %s\nPosition: %s\nHandynummer: %s\nFestnetznummer: %s\nMailadresse: %s\n", i, f[i].firma, f[i].strasse, f[i].hausnr, f[i].plz, f[i].ort, f[i].vorname, f[i].nachname, f[i].position, f[i].telmobil, f[i].telfest, f[i].mail);
	}
}


void ausgabeauswahl(student stud[120], firma f[120], int i){

			char ausgabebefehl;		
			do{

					einlesen_student(stud);
					einlesen_firma(f);

					int positions;												//Einlesen der Anzahl an momentan gespeicherten Studenten				
					FILE * anzahls_daten_alt;
					anzahls_daten_alt = fopen("anzahls.txt", "r+");
					fscanf(anzahls_daten_alt, "%i", &positions);
					fclose(anzahls_daten_alt);

					int positionf;												//Einlesen der Anzahl an momentan gespeicherten Praxispartnern
					FILE * anzahlf_daten_alt;
					anzahlf_daten_alt = fopen("anzahlf.txt", "r+");
					fscanf(anzahlf_daten_alt, "%i", &positionf);
					fclose(anzahlf_daten_alt);


					printf("\n-------------------------------------------------------------------------------\n");
					printf(" s .... Ausgabe der Studentendaten\n");
					printf(" f .... Ausgabe der Firmendaten\n");
					printf(" x .... Zurueck ins Hauptmenue ");
					printf("\n-------------------------------------------------------------------------------\n");
					scanf("%c", &ausgabebefehl);
					fflush(stdin);
				

					switch(ausgabebefehl){												//Auswahl, ob Studenten- oder Firmendaten ausgegeben werden sollen
						case 's':	ausgabe_student(stud, positions);
									break;
						case 'f':	ausgabe_firma(f, positionf);
									break;
						case 'x':	break;
						default:	printf("Falsche Eingabe. Bitte erneut versuchen");
									break;
					}}while(i<120 && ausgabebefehl !='x');
					system("cls");
}

void eingabeauswahl(student stud[120], firma f[120], int i){

	char eingabebefehl = 'x';
	do{
					
					
					
					int positions;														//Einlesen der Anzahl an momentan gespeicherten Studenten
					FILE * anzahls_daten_alt;
					anzahls_daten_alt = fopen("anzahls.txt", "r+");
					fscanf(anzahls_daten_alt, "%i", &positions);
					fclose(anzahls_daten_alt);

	
					int positionf;														//Einlesen der Anzahl an momentan gespeicherten Praxispartnern
					FILE * anzahlf_daten_alt;
					anzahlf_daten_alt = fopen("anzahlf.txt", "r+");
					fscanf(anzahlf_daten_alt, "%i", &positionf);
					fclose(anzahlf_daten_alt);

					printf("\n-------------------------------------------------------------------------------\n");
					printf(" s .... Eingabe eines neuen Studenten (optional mit Praxispartner)\n");
					printf(" f .... Eingabe eines neuen Praxispartners\n");
					printf(" x .... Zurueck ins Hauptmenue\n");
					printf("\n-------------------------------------------------------------------------------\n");
					
					scanf("%c", &eingabebefehl);
					fflush(stdin);
					system("cls");	

					switch(eingabebefehl){
					
					case 's':	eingabe_student(stud, positions);																						//Studenteneingabe
								char eingabebefehl2;
								printf("\n-------------------------------------------------------------------------------\n");
								printf(" p ....................... Firma des Studenten eingeben\n");
								printf(" beliebiger Buchstabe .... Eingabe beenden\n");
								printf("\n-------------------------------------------------------------------------------\n");
								scanf("%c", &eingabebefehl2);																							//Auswahl, ob mit der FIrmeneingabe fortgefahren werden soll oder der User zurück ins Menü möchte
								fflush(stdin);
								system("cls");
									
									switch(eingabebefehl2){
									case 'p':	eingabe_firma(f, positionf);																			//Firmeneingabe
												char speicherbefehl1;
												printf("\n-------------------------------------------------------------------------------\n");
												printf(" s .................. Datensatz speichern\n");
												printf(" beliebige Taste .... Datensatz verwerfen\n");
												printf("\n-------------------------------------------------------------------------------\n");
												scanf("%c", &speicherbefehl1);
												fflush(stdin);
												system("cls");
												switch(speicherbefehl1){																				//Abfrage, ob eingegebene Daten gespeichert werden sollen(Student + Firma)
													case 's':	speichern_student(stud);																
																speichern_firma(f);
																positions=positions+1;																	//Ändern der Position der vorhandenen Datensätze (Studenten)
																positionf=positionf+1;																	//Ändern der Position der vorhandenen Datensätze (Praxispartner)
																printf("Die Änderungen wurden gespeichert.\n");	
																break;
													default:	printf("Die Änderungen wurden verworfen.\n");	
																break;
												}
												break;
									default:	char speicherbefehl2;																					//Abfrage, ob eingegebene Daten gespeichert werden sollen (Nur Student)
												printf("\n-------------------------------------------------------------------------------\n");
												printf(" s .................. Datensatz speichern\n");
												printf(" beliebige Taste .... Datensatz verwerfen\n");
												printf("\n-------------------------------------------------------------------------------\n");
												scanf("%c", &speicherbefehl2);
												fflush(stdin);
												system("cls");
												switch(speicherbefehl2){
													case 's':	speichern_student(stud);												
																positions=positions+1;
																printf("Die Änderungen wurden gespeichert.\n");	
																break;
													default:	printf("Die Änderungen wurden verworfen.\n");	
																break;
												}
												break;
									}
									break;

					case 'f':	eingabe_firma(f, positionf);
								char speicherbefehl3;
												printf("\n-------------------------------------------------------------------------------\n");
												printf(" s .................. Datensatz speichern\n");
												printf(" beliebige Taste .... Datensatz verwerfen\n");
												printf("\n-------------------------------------------------------------------------------\n");
												scanf("%c", &speicherbefehl3);
												fflush(stdin);
												system("cls");
												switch(speicherbefehl3){																				//Speicherabfrage
													case 's':	speichern_firma(f);
																positionf=positionf+1;
																printf("Die Änderungen wurden gespeichert.\n");	
																break;
													default:	printf("Die Änderungen wurden verworfen.\n");	
																break;
												}
												break;
								break;
					case 'x':	break;
					default:	printf("Falsche Eingabe. Bitte erneut versuchen\n");
								break;

					}
					FILE * anzahls_daten_neu;									//Schreiben der aktualisierten Anzahl der vorhandenen Studentendaten in externe Datei
					anzahls_daten_neu = fopen("anzahls.txt", "w");
					fprintf(anzahls_daten_neu, "%i", positions);
					fclose(anzahls_daten_neu);
	
	
					FILE * anzahlf_daten_neu;									//Schreiben der aktualisierten Anzahl der vorhandenen Firmendaten in externe Datei
					anzahlf_daten_neu = fopen("anzahlf.txt", "w");
					fprintf(anzahlf_daten_neu, "%i", positionf);
					fclose(anzahlf_daten_neu);
					system("cls");
					}while(i<120 && eingabebefehl !='x');

}

void eingabe_student(student stud[120], int positions){							//Eingabe der Studentendaten
			
		
			printf("\n-------------------------------------------------------------------------------\n");
			
			printf("Matrikelnummer:");
			scanf("%s", &stud[positions].matr);
			fflush(stdin);
			
			printf("Vorname:");
			scanf("%s", &stud[positions].vorname); 
			fflush(stdin);
	
			printf("Nachname:");
			scanf("%s", &stud[positions].nachname);
			fflush(stdin);

			printf("Startjahr des Studiums:");
			scanf("%s", &stud[positions].startdatum);
			fflush(stdin);

			printf("Strasse:");
			scanf("%s", &stud[positions].strasse);
			fflush(stdin);

			printf("Hausnummer:");
			scanf("%s", &stud[positions].hausnr);
			fflush(stdin);

			printf("Postleitzahl:");
			scanf("%s", &stud[positions].plz);
			fflush(stdin);

			printf("Wohnort: ");
			scanf("%s", &stud[positions].ort);
			fflush(stdin);

			printf("Telefonnummer Mobil: ");
			scanf("%s", &stud[positions].telmobil);
			fflush(stdin);

			printf("Telefonnummer Festnetz:");
			scanf("%s", &stud[positions].telfest);
			fflush(stdin);

			printf("Mailadresse:");
			scanf("%s", &stud[positions].mail);
			fflush(stdin);

			printf("Name der Firma:");
			scanf("%s", &stud[positions].firma);
			fflush(stdin);

			printf("Vorname des Betreuers: ");
			scanf("%s", &stud[positions].betreuervor);
			fflush(stdin);

			printf("Nachname des Betreuers: ");
			scanf("%s", &stud[positions].betreuernach);
			fflush(stdin);
	
}

void eingabe_firma(firma f[120], int positionf){												//Eingabe der Firmendaten
			
			printf("\n-------------------------------------------------------------------------------\n");
			
			printf("Firmenname: ");
			scanf("%s", &f[positionf].firma);
			fflush(stdin);

			printf("Strasse der Firma: ");
			scanf("%s", &f[positionf].strasse);
			fflush(stdin);

			printf("Hausnummer der Firma: ");
			scanf("%s", &f[positionf].hausnr);
			fflush(stdin);

			printf("Postleitzahl der Firma: ");
			scanf("%s", &f[positionf].plz);
			fflush(stdin);

			printf("Ort der Firma: ");
			scanf("%s", &f[positionf].ort);
			fflush(stdin);

			printf("Vorname des Ansprechpartners: ");
			scanf("%s", &f[positionf].vorname);
			fflush(stdin);

			printf("Nachname des Ansprechpartners: ");
			scanf("%s", &f[positionf].nachname);
			fflush(stdin);

			printf("Position des Ansprechpartners: ");
			scanf("%s", &f[positionf].position);
			fflush(stdin);

			printf("Handynummer des Ansprechpartners: ");
			scanf("%s", &f[positionf].telmobil);
			fflush(stdin);

			printf("Festnetznummer des Ansprechpartners: ");
			scanf("%s", &f[positionf].telfest);
			fflush(stdin);

			printf("Mailadresse des Ansprechpartners: ");
			scanf("%s", &f[positionf].mail);
			fflush(stdin);
			
}

void bearbeiten_student(student stud[120]){								//Bearbeiten der Studentendaten
	int nr_datensatz;
	system("cls");
	printf("\n-------------------------------------------------------------------------------\n");
	printf("Geben sie bitte die Nummer des Datensatzes ein, den sie bearbeiten wollen:");
	printf("\n-------------------------------------------------------------------------------\n");
	scanf("%i", &nr_datensatz);																					//Abfrage, welcher Datensatz bearbeitet werden soll
	system("cls");

			printf("\n-------------------------------------------------------------------------------\n");

			printf("Matrikelnummer:");
			scanf("%s", &stud[nr_datensatz].matr);
			fflush(stdin);

			printf("Vorname:");
			scanf("%s", &stud[nr_datensatz].vorname); 
			fflush(stdin);
	
			printf("Nachname:");
			scanf("%s", &stud[nr_datensatz].nachname);
			fflush(stdin);

			printf("Startjahr ihres Studiums:");
			scanf("%s", &stud[nr_datensatz].startdatum);
			fflush(stdin);

			printf("Strasse:");
			scanf("%s", &stud[nr_datensatz].strasse);
			fflush(stdin);

			printf("Hausnummer:");
			scanf("%s", &stud[nr_datensatz].hausnr);
			fflush(stdin);

			printf("Postleitzahl:");
			scanf("%s", &stud[nr_datensatz].plz);
			fflush(stdin);

			printf("Wohnort: ");
			scanf("%s", &stud[nr_datensatz].ort);
			fflush(stdin);

			printf("Telefonnummer Mobil: ");
			scanf("%s", &stud[nr_datensatz].telmobil);
			fflush(stdin);

			printf("Telefonnummer Festnetz:");
			scanf("%s", &stud[nr_datensatz].telfest);
			fflush(stdin);

			printf("Mailadresse:");
			scanf("%s", &stud[nr_datensatz].mail);
			fflush(stdin);

			printf("Name der Firma:");
			scanf("%s", &stud[nr_datensatz].firma);
			fflush(stdin);

			printf("Vorname des Betreuers: ");
			scanf("%s", &stud[nr_datensatz].betreuervor);
			fflush(stdin);

			printf("Nachname des Betreuers: ");
			scanf("%s", &stud[nr_datensatz].betreuernach);
			fflush(stdin);
}

void bearbeiten_firma(firma f[120]){							//Bearbeiten der Firmendaten
	
	int nr_datensatz;
	system("cls");

	printf("\n-------------------------------------------------------------------------------\n");
	printf("Geben sie bitte die Nummer des Datensatzes ein, den sie bearbeiten wollen:");
	printf("\n-------------------------------------------------------------------------------\n");

	scanf("%i", &nr_datensatz);									//Abfrage, welcher Datensatz bearbeitet werden soll
	system("cls");
		
			printf("\n-------------------------------------------------------------------------------\n");

			printf("Name der Firma: ");
			scanf("%s", &f[nr_datensatz].firma);
			fflush(stdin);

			printf("Strasse der Firma: ");
			scanf("%s", &f[nr_datensatz].strasse);
			fflush(stdin);

			printf("Hausnummer der Firma: ");
			scanf("%s", &f[nr_datensatz].hausnr);
			fflush(stdin);

			printf("Postleitzahl der Firma: ");
			scanf("%s", &f[nr_datensatz].plz);
			fflush(stdin);

			printf("Ort der Firma: ");
			scanf("%s", &f[nr_datensatz].ort);
			fflush(stdin);

			printf("Vorname des Ansprechpartners: ");
			scanf("%s", &f[nr_datensatz].vorname);
			fflush(stdin);

			printf("Nachname des Ansprechpartners: ");
			scanf("%s", &f[nr_datensatz].nachname);
			fflush(stdin);

			printf("Position des Ansprechpartners: ");
			scanf("%s", &f[nr_datensatz].position);
			fflush(stdin);

			printf("Handynummer des Ansprechpartners: ");
			scanf("%s", &f[nr_datensatz].telmobil);
			fflush(stdin);

			printf("Festnetznummer des Ansprechpartners: ");
			scanf("%s", &f[nr_datensatz].telfest);
			fflush(stdin);

			printf("Mailadresse des Ansprechpartners: ");
			scanf("%s", &f[nr_datensatz].mail);
			fflush(stdin);
}
	
void bearbeiten(student stud[120], firma f[120], int i){					//Struktur der Bearbeitungsfunktion

	char bearbeitungsbefehl;
	do{
					
					printf("\n-------------------------------------------------------------------------------\n");
					printf(" s .... Bearbeiten der Studentendaten\n");
					printf(" f .... Bearbeiten der Firmendaten\n");
					printf(" x .... Zurueck ins Hauptmenue ");
					printf("\n-------------------------------------------------------------------------------\n");
					scanf("%c", &bearbeitungsbefehl);										//Auswahl, ob Studenten- oder Firmendaten bearbeitet werden sollen
					fflush(stdin);
					system("cls");

					switch(bearbeitungsbefehl){
						case 's':	bearbeiten_student(stud);								//Studenten bearbeiten
									char speicherabfrage1;
									printf("\n-------------------------------------------------------------------------------\n");
									printf(" 's' .................. Geänderten Datensatz speichern\n");
									printf(" 'beliebige Taste' .... Geänderten Datensatz verwerfen\n");
									printf("\n-------------------------------------------------------------------------------\n");
									scanf("%c", &speicherabfrage1);							//Abfrage, ob gespeichert werden soll
									fflush(stdin);
									system("cls");
									switch(speicherabfrage1){
										case 's':	speichern_student(stud);
													printf("\n-------------------------------------------------------------------------------\n");
													printf(" Die Aenderungen wurden gespeichert.");	
													printf("\n-------------------------------------------------------------------------------\n");
													break;
										default:	printf("\n-------------------------------------------------------------------------------\n");
													printf(" Die Aenderungen wurden verworfen.");	
													printf("\n-------------------------------------------------------------------------------\n");
													break;
									}
									break;
						case 'f':	bearbeiten_firma(f);									//Praxispartner bearbeiten
									char speicherabfrage2;
									printf("\n-------------------------------------------------------------------------------\n");
									printf(" 's' .................. Geänderten Datensatz speichern\n");
									printf(" 'beliebige Taste' .... Geänderten Datensatz verwerfen\n");
									printf("\n-------------------------------------------------------------------------------\n");
									scanf("%c", &speicherabfrage2);							//Abfrage, ob gespeichert werden soll
									fflush(stdin);
									system("cls");
									switch(speicherabfrage2){
										case 's':	speichern_firma(f);
													printf("\n-------------------------------------------------------------------------------\n");
													printf(" Die Aenderungen wurden gespeichert.");	
													printf("\n-------------------------------------------------------------------------------\n");
													break;
										default:	printf("\n-------------------------------------------------------------------------------\n");
													printf(" Die Aenderungen wurden verworfen.");	
													printf("\n-------------------------------------------------------------------------------\n");
													break;
									}
									break;
						case 'x':	break;
						default:	printf("Falsche Eingabe. Bitte erneut versuchen");	
									break;
					}}while(i<120 && bearbeitungsbefehl !='x');
					system("cls");
}

void datensatz_löschen(student stud[120], int positions) {
 

	
	FILE * anzahls_daten_alt;												//Einlesen der Anzahl der vorhandenen Studentendatensätze
	anzahls_daten_alt = fopen("anzahls.txt", "r+");
	fscanf(anzahls_daten_alt, "%i", &positions);
	fclose(anzahls_daten_alt);
	
	FILE * student_einlesen;												//Einlesen der Studentendatensätze
	student_einlesen = fopen("studenten.bin" , "rb");
	fread(stud, sizeof(student), 120, student_einlesen);
	fclose(student_einlesen);
	
	int i;
	char bestätigung;

	system("cls");

	printf("\n-------------------------------------------------------------------------------\n");
	printf("Bitte geben sie die Nummer des Datensatzes ein, den sie loeschen wollen.");
	printf("\n-------------------------------------------------------------------------------\n");

	scanf("%i", &i);														//Auswählen, welcher Datensatz gelöscht werden soll
	fflush(stdin); 

	printf("\n-------------------------------------------------------------------------------\n");
	printf("Sind Sie sicher, dass Sie den Studenten %s %s wirklich loeschen wollen?\n", stud[i].vorname, stud[i].nachname);
	printf(" e .................. Datensatz entfernen\n");
	printf(" Beliebige Taste .... Datensatz behalten\n");
	printf("\n-------------------------------------------------------------------------------\n");
	scanf("%c", &bestätigung);												//Abfrage, ob ausgewählter Student wirklich gelöscht werden soll
	fflush(stdin);

	switch (bestätigung){
		case 'e':	i=i+1;
					for (i; i<=positions;i++){
						strcpy(stud[i-1].matr, stud[i].matr);
						strcpy(stud[i-1].vorname, stud[i].vorname);
						strcpy(stud[i-1].nachname, stud[i].nachname);
			 			strcpy(stud[i-1].startdatum, stud[i].startdatum);
						strcpy(stud[i-1].strasse, stud[i].strasse);
						strcpy(stud[i-1].hausnr, stud[i].hausnr);
						strcpy(stud[i-1].plz, stud[i].plz);
						strcpy(stud[i-1].ort, stud[i].ort);
						strcpy(stud[i-1].telmobil, stud[i].telmobil);
						strcpy(stud[i-1].telfest, stud[i].telfest);
						strcpy(stud[i-1].mail, stud[i].mail);
						strcpy(stud[i-1].firma, stud[i].firma);
						strcpy(stud[i-1].betreuervor, stud[i].betreuervor);
						strcpy(stud[i-1].betreuernach, stud[i].betreuernach);
					}
					
						FILE * student_speichern;										//Speichern der neuen Studentendaten
						student_speichern = fopen("studenten.bin", "wb"); 
						fwrite(stud, sizeof(student), 120 , student_speichern);
						fclose(student_speichern);
						
						positions = positions-1;										//Anzahl der gespeicherten Studentendatensätze um 1 verringern
		
						FILE * anzahls_daten_neu;										//Anzahl der gespeicherten Studentendatensätze neu schreiben
						anzahls_daten_neu = fopen("anzahls.txt", "w+");
						fprintf(anzahls_daten_neu, "%i", positions);
						fclose(anzahls_daten_neu);

					printf("\n-------------------------------------------------------------------------------\n");
					printf("Sie haben den Datensatz erfolgreich geloescht! Beliebige Taste druecken, \num zurueck ins Hauptmenue zu gelangen.");
					printf("\n-------------------------------------------------------------------------------\n");
					fflush(stdin);
					getch();
					break;
    default:		printf("Das Loeschen war leider nicht erfolgreich!");
					break;
	 }}
  
void student_suchen(student stud[120]){
	
	char suchbefehl;
	char matr1[20];
	char vorname1[20];
	char nachname1[20];
	char firma1[30];
	
	int positions;								//Einlesen der Anzahl der gespeicherten Studentendaten
	FILE * anzahls_daten_alt;
	anzahls_daten_alt = fopen("anzahls.txt", "r+");
	fscanf(anzahls_daten_alt, "%i", &positions);
	fclose(anzahls_daten_alt);

	FILE * student_einlesen;					//Einlesen der Studentendaten
	student_einlesen = fopen("studenten.bin" , "rb");
	fread(stud, sizeof(student), 120, student_einlesen);
	fclose(student_einlesen);

	printf("\n-------------------------------------------------------------------------------\n");
	printf(" Wonach moechten sie suchen?\n");
	printf(" m .... Matrikelnummer\n");
	printf(" v .... Vorname\n");
	printf(" n .... Nachname\n");
	printf(" f .... Praxispartner\n");
	printf("\n-------------------------------------------------------------------------------\n");
	scanf("%c", &suchbefehl);
	system("cls");

	switch(suchbefehl){																												//Abfrage, wonach gesucht werden soll
	case 'm':		printf("\n-------------------------------------------------------------------------------\n");
					printf(" Bitte die gesuchte Matrikelnummer eingeben und mit Enter bestaetigen.");
					printf("\n-------------------------------------------------------------------------------\n");
					scanf("%s", &matr1);
					fflush(stdin);

					for(int i=0; i<positions; i++){
						if (strcmp(matr1, stud[i].matr) == 0 ) {
						printf("\nDatensatz %i \nMatrikelnummer: %s \nVor- und Nachname: %s %s\nStartjahr: %s\nStrasse und Hausnummer: %s %s \nPLZ und Wohnort: %s %s \nMobilfunknummer: %s \nFestnetznummer: %s  \nMailadresse: %s \nFirmenname: %s \nVorname des Betreuers: %s \nNachname des Betreuers: %s\n", i, stud[i].matr, stud[i].vorname, stud[i].nachname, stud[i].startdatum, stud[i].strasse, stud[i].hausnr, stud[i].plz, stud[i].ort, stud[i].telmobil, stud[i].telfest, stud[i].mail, stud[i].firma, stud[i].betreuervor, stud[i].betreuernach);
	
						}}
					printf("\n-------------------------------------------------------------------------------\n");
					printf(" Beliebige Taste druecken, um zurueck ins Hauptmenue zu gelangen");
					printf("\n-------------------------------------------------------------------------------\n");
					getch();
					break;		

	case 'v':		printf("\n-------------------------------------------------------------------------------\n");
					printf(" Bitte den gesuchten Vornamen eingeben und mit Enter bestaetigen.");
					printf("\n-------------------------------------------------------------------------------\n");
					scanf("%s", &vorname1);
					fflush(stdin);

					for(int i=0; i<positions; i++){
						if (strcmp(vorname1, stud[i].vorname) == 0 ) {
						printf("\nDatensatz %i \nMatrikelnummer: %s \nVor- und Nachname: %s %s\nStartjahr: %s\nStrasse und Hausnummer: %s %s \nPLZ und Wohnort: %s %s \nMobilfunknummer: %s \nFestnetznummer: %s  \nMailadresse: %s \nFirmenname: %s \nVorname des Betreuers: %s \nNachname des Betreuers: %s\n", i, stud[i].matr, stud[i].vorname, stud[i].nachname, stud[i].startdatum, stud[i].strasse, stud[i].hausnr, stud[i].plz, stud[i].ort, stud[i].telmobil, stud[i].telfest, stud[i].mail, stud[i].firma, stud[i].betreuervor, stud[i].betreuernach);
						}}
					printf("\n-------------------------------------------------------------------------------\n");
					printf(" Beliebige Taste druecken, um zurueck ins Hauptmenue zu gelangen");
					printf("\n-------------------------------------------------------------------------------\n");
					getch();
					break;	

	case 'n':		printf("\n-------------------------------------------------------------------------------\n");
					printf(" Bitte den gesuchten Nachnamen eingeben und mit Enter bestaetigen.");
					printf("\n-------------------------------------------------------------------------------\n");
					scanf("%s", &nachname1);
					fflush(stdin);

					for(int i=0; i<positions; i++){
						if (strcmp(nachname1, stud[i].nachname) == 0 ) {
						printf("\nDatensatz %i \nMatrikelnummer: %s \nVor- und Nachname: %s %s\nStartjahr: %s\nStrasse und Hausnummer: %s %s \nPLZ und Wohnort: %s %s \nMobilfunknummer: %s \nFestnetznummer: %s  \nMailadresse: %s \nFirmenname: %s \nVorname des Betreuers: %s \nNachname des Betreuers: %s\n", i, stud[i].matr, stud[i].vorname, stud[i].nachname, stud[i].startdatum, stud[i].strasse, stud[i].hausnr, stud[i].plz, stud[i].ort, stud[i].telmobil, stud[i].telfest, stud[i].mail, stud[i].firma, stud[i].betreuervor, stud[i].betreuernach);
						}}
					printf("\n-------------------------------------------------------------------------------\n");
					printf(" Beliebige Taste druecken, um zurueck ins Hauptmenue zu gelangen");
					printf("\n-------------------------------------------------------------------------------\n");
					getch();
					break;	

	case 'f':		printf("\n-------------------------------------------------------------------------------\n");
					printf(" Bitte den gesuchten Firmennamen eingeben und mit Enter bestaetigen.");
					printf("\n-------------------------------------------------------------------------------\n");
					scanf("%s", &firma1);
					fflush(stdin);

					for(int i=0; i<positions; i++){
						if (strcmp(firma1, stud[i].firma) == 0 ) {
						printf("\nDatensatz %i \nMatrikelnummer: %s \nVor- und Nachname: %s %s\nStartjahr: %s\nStrasse und Hausnummer: %s %s \nPLZ und Wohnort: %s %s \nMobilfunknummer: %s \nFestnetznummer: %s  \nMailadresse: %s \nFirmenname: %s \nVorname des Betreuers: %s \nNachname des Betreuers: %s\n", i, stud[i].matr, stud[i].vorname, stud[i].nachname, stud[i].startdatum, stud[i].strasse, stud[i].hausnr, stud[i].plz, stud[i].ort, stud[i].telmobil, stud[i].telfest, stud[i].mail, stud[i].firma, stud[i].betreuervor, stud[i].betreuernach);
						}}
					printf("\n-------------------------------------------------------------------------------\n");
					printf(" Beliebige Taste druecken, um zurueck ins Hauptmenue zu gelangen");
					printf("\n-------------------------------------------------------------------------------\n");
					getch();
					break;	
	default:		break;
		
}}

void speichern_student(student stud[120]){

	FILE * student_speichern;
	student_speichern = fopen("studenten.bin", "wb"); 
	fwrite(stud, sizeof(student), 120 , student_speichern);
	fclose(student_speichern);
}

void speichern_firma(firma f[120]){
	
	FILE* firma_speichern;
	firma_speichern = fopen("firma.bin", "wb");
	fwrite(f, sizeof(firma), 120, firma_speichern);
	fclose(firma_speichern);
}

void einlesen_student(student stud[120]){									


	FILE * student_einlesen;
	student_einlesen = fopen("studenten.bin" , "rb");
	fread(stud, sizeof(student), 120, student_einlesen);
	fclose(student_einlesen);

}


void einlesen_firma(firma f[120]){									

	FILE * firma_einlesen;
	firma_einlesen=fopen("firma.bin" , "rb");
	fread(f, sizeof(firma), 120, firma_einlesen);
	fclose(firma_einlesen);
	
}

void menu(char *befehl){

	system("cls");
	printf("\n-------------------------------------------------------------------------------\n");
	printf(" e .... Eingabe neuer Datensatz\n");
	printf(" a .... Ausgabe vorhandener Dateien\n");
	printf(" s .... Daten suchen\n");
	printf(" c .... Datensatz bearbeiten\n");
	printf(" l .... Datensatz loeschen\n");
	printf(" b .... Programm Beenden\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf("Eingabe :  ");

	scanf("%c", &*befehl);
	fflush(stdin);
	system("cls");
}


