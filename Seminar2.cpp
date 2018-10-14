/*
Seminar 2 POO: 

strlen - determina lungimea unui sir de caractere
strcpy - copiaza un sir de care de la o sursa catre o destinatie specificata.
cin.ignore(); - extrage si elimina secventa de caractere de la nivelul operatorului de intrare (fie consola fie fisier)
cin.getline - extrage sirurile de caractere pana cand se trece pe un rand nou.

*/

#include<iostream>
using namespace std; 

struct Hotel {
	int id;
	char* nume;
	char adresa[60];
	bool deschis;
	unsigned int nr_camere;
	float* preturi;
};

void initializareHotel(Hotel* hotel);
void afisareHotel(Hotel hotel);
void modificaNumeHotel(Hotel& hotel, char* numeNou);

int main() {

	Hotel hotel; 
	initializareHotel(&hotel);
	afisareHotel(hotel);

	Hotel* hotel2 = &hotel;
	afisareHotel(*hotel2);

	char nume[50];
	cout << "Nume nou: ";
	cin.ignore();
	cin.getline(nume,50);

	modificaNumeHotel(hotel, nume);
	afisareHotel(hotel);

	return 0;
}

void initializareHotel(Hotel* hotel) {

	cout << "Initializare hotel: " << endl;
	
	cout << "Id: ";
	cin >> hotel->id;
	
	cout << "Nume: ";
	char buf[50];
	cin.ignore();
	cin.getline(buf, 50);
	hotel->nume = new char[strlen(buf) + 1];
	strcpy(hotel->nume, buf);

	cout << "Adresa: ";
	cin.ignore();
	cin.getline(hotel->adresa, 60);

	cout << "Deschis? 0-Nu, 1-Da ";
	cin >> hotel->deschis;

	cout << "Numarul de camere: ";
	cin >> hotel->nr_camere;

	hotel->preturi = new float[hotel->nr_camere];
	for (int i = 0; i < hotel->nr_camere; i++) {
		cout << "Pretul pentru camera " << i + 1 << ": ";
		cin >> hotel->preturi[i];
	}
}

void afisareHotel(Hotel hotel) {
	
	cout << "Afisare hotel: " << endl;
	cout << "Id: " << hotel.id << endl;
	cout << "Nume: " << hotel.nume << endl;
	cout << "Adresa: " << hotel.adresa << endl;
	
	if (hotel.deschis == true) {
		cout << "Hotelul este deschis." << endl;
	}
	else {
		cout << "Hotelul este inchis." << endl;
	}

	cout << "Numarul de camere: " << hotel.nr_camere << endl;
	
	for (int i = 0; i < hotel.nr_camere; i++) {
		cout << "Pretul camerei " << i + 1 << " este de: " << hotel.preturi[i] << endl;
	}
}

void modificaNumeHotel(Hotel& hotel, char* numeNou) {

	if (hotel.nume != NULL) {
		delete[] hotel.nume;
	}

	hotel.nume = new char[strlen(numeNou) + 1];
	strcpy(hotel.nume, numeNou);
}