// ***************************************************
// Projekt:		Parkhaus ZH Nord AP-M404 ITB1c
// Name:		besart jashari
// Datum:		10.01.2023
// ***************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;

// Funktionen
void Zeit_und_Datum(int *vTag, int *vMonat, int *vJahr, int *vStunde, int *vMinute);
void menu();
int PGR_Starten(int *Parkhaus);
int einstellungen(int *Parkhaus, int *vStunde);


// Hauptfunktion
int main(){

	//Beispiel: Systemdatum und Zeit auslesen.------------------------------------------
	int Tag, Monat, Jahr, Stunde, Minute;
	Zeit_und_Datum(&Tag, &Monat, &Jahr, &Stunde, &Minute);
	if(Minute < 10){
	cout << Tag << "." << Monat << "." << Jahr << " - " << Stunde << ":0" << Minute;
	cout << endl;
	}
	else{
	cout << Tag << "." << Monat << "." << Jahr << " - " << Stunde << ":" << Minute;
	cout << endl;
}












	int auswahl_menu = 1;
	int Parkhaus[50];
	
	for(int i = 0; i < 45; i++){
		Parkhaus[i] = 0;//1 ist belegt und 0 ist leer!!
	}
	for(int i = 45; i < 50; i++){
		Parkhaus[i] = 1;
	}

//HauptProgramm Schlaufe
	do{
	menu();
	cin >> auswahl_menu;
	system("CLS");	//-
	
	switch(auswahl_menu){
		case 1 : Parkhaus[0] = PGR_Starten(&Parkhaus[0]);
		system("PAUSE");
		break;
		case 2 : einstellungen(&Parkhaus[0], &Stunde);
		system("PAUSE");
		break;
	//	case 0 : return 0;
	}
}while(auswahl_menu > 0);//Schlaufen ende!!!!!!!!!!!!!!!!!!!!!!!
	






 cout << endl;
 system("PAUSE");
 return 0;
}


// Funktion Zeitstempel
void Zeit_und_Datum(int *vTag, int *vMonat, int *vJahr, int *vStunde, int *vMinute)
{
    time_t Zeitstempel;
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);
    *vTag = nun->tm_mday;
    *vMonat = nun->tm_mon+1;
    *vJahr = nun->tm_year+1900;
    *vStunde = nun->tm_hour;
    *vMinute = nun->tm_min;
    
}


//Menü

void menu(){
	
	cout << "Willkommen\n------------------\n";
	cout << "1 = Prg Starten\n2 = Einstellungen\n0 = Beenden\n\n";
}
//STart FUNKTION---------------------------------------------------------FUNKTION START-----------------------------------------------
int PGR_Starten(int *Parkhaus){
	cout << "PRG STarten\n---------------\n";

	
		int ende = 1;
	
		char ampel[6] = {"ROT"};
		int auswahl;
			do{
		int x = 0;	
				for(int j = 0; j < 50; j++){
					if(Parkhaus[j] < 1){
					x++;
				}
			}

	if (x > 0){														//Erste anzeige... freie PLätze.
				cout << "Freie Platze: "<< x << endl<< endl;
				if(x > 0){
				char ampel[6] = {"Gruen"};
				cout << " Ampel: " << ampel << endl;
				cout << "Beleuchtung: 100%" << endl << "----------------------------\n";
		 }
		cout << "Auswahl: \n 1 = Einfahren\n 2 = Wegfahren\n 0 = Beenden\n\n ---------------------------\n Ihre Auswahl: ";
			cin >> auswahl;
			cout << "--------------------------\n";
			
			

			switch(auswahl)
			{
				case 1 : //Hier Fahren die Leute ins Parkhaus rein. wir inkrementieren das array Parkhaus
				for(int e; e < 50; e++){
					if(Parkhaus[e] == 0){
					
						Parkhaus[e] = 1;
						x + 1;
						cout << "Sie Konnen einfahren\n\n--------------------------\n\n";
						Sleep(450);
						system("CLS");
						break;
						}					
					}
			
				break;
				case 2 : //Hier Fahren die Leute aus dem Parkhaus raus.
				for(int e; e < 50; e++){
				if(Parkhaus[e] == 1){				
						Parkhaus[e] = 0;
						Sleep(450);
						system("CLS");
						break;
						}					
					}
				
				 cout << "Auf wiedersehen\n\n\n";
				 x--;
				break;
				case 0 : ende = 0;
			}

	}
	else{//Keine Parkplätze mehr
		cout << "Keine Freien Parkplätze mehr. good bye";
		ende = 0;
	}

	
	
	
}while(ende > 0);//ende der SCHlaufe des Hauptprogramms.
	
	
	system("PAUSE");
	system("CLS");
	
	return Parkhaus[0]; //Eigendlich müsste hier Parkhaus Returnt werden.
	
}


//einstellungen------------------------------------FUNKTION EINSTELLUNGEN----------------------------------------------------
int einstellungen(int *Parkhaus, int *vStunde){
	int menu;
	int zahler = 0;
		for(int x = 0; x < 50; x++){
			if(Parkhaus[x] > 0){
				++zahler;
			}
		}
	
	
	do{
	
	cout << "Einstellungen\n-----------------\n";
	cout << "1 = Belegte Besucher-Parkplätze\n";
	cout << "2 = Total Vermietete-Parkplätze\n";
	cout << "3 = Belegte Besucher-Parkplätze\n";
	cout << "4 = Parkhausbeleuchtung in %\n";
	cout << "0 = Einstellungen beenden\n\n";
	
	cin >> menu;
	
	switch(menu){
		case 1: system("CLS"); 
		cout << "Totale Besucher-Parkplätze = 50" << endl;
		system("PAUSE");
		break;
		case 2: system("CLS");
		cout << "Total Vermietete-Parkplätze: ";
		cout << zahler << endl;
		system("PAUSE");
		break;
		case 3: system("CLS");
		cout << "Belegte Besucher-Parkplätze = "<< 50 - zahler << endl;
		system("PAUSE");
		break;
		case 4: system("CLS");
		
		if(*vStunde < 6){
			cout << "\n 100%\n";
		}
		else if(*vStunde > 20){
			cout << "\n 100%\n";
		}
		system("PAUSE");
		break;
	}
	system("CLS");
	
}while(menu > 0);
	return 0;
	
}
