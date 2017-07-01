typedef struct{
		char matr[20];
		char vorname[20];
		char nachname[20];
		char startdatum[20];
		//Adresse
		char strasse[20];
		char hausnr[20];
		char plz[20];
		char ort[20];
		char telmobil[20];
		char telfest[20];
		char mail [40];
		char firma [30];
		char betreuervor[20];
		char betreuernach[20];
	}student;

typedef struct{
		//Firmenadresse
		char firma[30];
		char strasse[20];
		char hausnr[20];
		char plz[20];
		char ort[20];
		//Ansprechpartner
		char vorname[20];
		char nachname[20];
		char position[20];
		char telmobil[20];
		char telfest[20];
		char mail[40];
}firma;


extern void ausgabeauswahl(student stud[120], firma f[120], int i);
extern void ausgabe_student(student stud[120], int positions);
extern void ausgabe_firma(firma f[120], int positionf);


extern void eingabeauswahl(student stud[120], firma f[120], int i);
extern void eingabe_student(student stud[120], int positions);
extern void eingabe_firma(firma f[120], int positionf);

extern void bearbeiten(student stud[120], firma f[120], int i);
extern void bearbeiten_student(student stud[120]);
extern void bearbeiten_firma(firma f[120]);

extern void datensatz_löschen(student stud[120], int positions);

extern void student_suchen(student stud[120]);

extern void speichern_student(student stud[120]);
extern void speichern_firma(firma f[120]);

extern void einlesen_student(student stud[120]);
extern void einlesen_firma(firma f[120]);

extern void menu(char *befehl);