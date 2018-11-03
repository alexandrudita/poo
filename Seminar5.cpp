///*Seminar 5 POO:
//
//supraincarcarea operatorilor - prespune atribuirea unor comportamente diferite pentru functii deja existente.
//
//operator = : -copiaza informatiile dintr - o zona de memorie initializata in alta zona de memorie tot initializata.
//operator >> (citire) : -permite citirea obiectelor de la tastatura
//						- este functie friend (permite utilizarea atributelor private inafara clasei)
//						- nu au this.
//						- au 2 param de intrare. istream si obiect
//operator << (afisare) : -permite afisarea la consola a atributelor unui obiect
//						- este functie friend.
//						- nu au this.
//						- au 2 parametri de intrare. ostream si obiect
//operatori care nu pot fi supraincarcati: ::, .*, ., ? :*/
//
#include "pch.h"
//#include<iostream>
//using namespace std;
//
//class Hotel {
//	//default este pus private
//private:
//	const int id;
//	char* nume;
//	char adresa[60];
//	bool deschis;
//	unsigned int nr_camere;
//	float* preturi;
//	static int nr_total;
//public:
//	Hotel();// constructor default
//	Hotel(int v_id, char* v_nume, bool v_deschis = true);//constructor cu mai multi param
//	Hotel(int v_id, char* v_nume, char v_adresa[60], bool v_deschis, int v_nr_camere, float* v_preturi);
//	Hotel(const Hotel& copie);
//	~Hotel();//destructor
//	void afisare();
//	//setter si getter
//	void setNume(char* v_nume);
//	char* getNume();
//	//operator =
//	Hotel& operator=(const Hotel& hotel);
//	//operator >>
//	friend ostream& operator<<(ostream& out, Hotel hotel);
//	//operator <<
//	friend istream& operator>>(istream& in, Hotel& hotel);
//};
//
//int Hotel::nr_total = 0;
//
//int main() {
//	//constructor default
//	//variabila normala
//	Hotel h1;
//	h1.afisare();
//	//variabila pointer
//	Hotel* h2 = new Hotel();
//	h2->afisare();
//	delete h2;
//	//constructor mai multi param
//	//variabila normala
//	char* variab = new char[strlen("Constr variab normala") + 1];
//	strcpy(variab, "Constr variab normala");
//	Hotel h3(1, variab);
//	h3.afisare();
//	//pointer
//	Hotel* h4 = new Hotel(2, variab, false);
//	h4->afisare();
//
//	Hotel h5 = h3;
//	h5.afisare();
//
//	cout << "Numarul total de hoteluri existente: " << Hotel::getNrTotal() << endl;
//
//	Hotel h6;
//	h6.afisare();
//	h6 = *h4;
//	h6.afisare();
//
//	cin >> h6;
//	cout << h6;
//
//	delete h4;
//
//	return 0;
//}
//
//Hotel::Hotel() :id(-1) { //Hotel::Hotel(Hotel* this)- dispunere memorie
//	//this->id = -1;
//	this->nume = new char[strlen("Anonim") + 1];
//	strcpy(this->nume, "Anonim");
//	strcpy(this->adresa, "Anonim");
//	this->deschis = false;
//	this->nr_camere = 0;
//	this->preturi = NULL;
//
//	Hotel::nr_total++;
//}
//
//Hotel::Hotel(int v_id, char* v_nume, bool v_deschis) :id(v_id) {//Hotel::Hotel(Hotel* this, int v_id, char* v_nume);
//	//this->id = v_id;
//	if (v_nume != NULL) {
//		this->nume = new char[strlen(v_nume) + 1];
//		strcpy(this->nume, v_nume);
//	}
//	strcpy(this->adresa, "Anonim");
//	this->deschis = v_deschis;
//	this->nr_camere = 0;
//	this->preturi = NULL;
//
//	Hotel::nr_total++;
//}
//
//Hotel::Hotel(int v_id, char* v_nume, char v_adresa[60],
//	bool v_deschis, int v_nr_camere, float* v_preturi) :id(v_id) {
//
//	//this->id = v_id;
//	if (v_nume != NULL) {
//		this->nume = new char[strlen(v_nume) + 1];
//		strcpy(this->nume, v_nume);
//	}
//
//	if (v_adresa != NULL) {
//		strcpy(this->adresa, v_adresa);
//	}
//
//	this->deschis = v_deschis;
//	this->nr_camere = v_nr_camere;
//
//	if (v_preturi != NULL) {
//		this->preturi = new float[this->nr_camere];
//		for (int i = 0; i < this->nr_camere; i++) {
//			this->preturi[i] = v_preturi[i];
//		}
//	}
//
//	Hotel::nr_total++;
//}
//
//Hotel::Hotel(const Hotel& copie) :id(copie.id) { //:id(copie.id) {
//	if (copie.nume != NULL) {
//		this->nume = new char[strlen(copie.nume) + 1];
//		strcpy(this->nume, copie.nume);
//	}
//	if (copie.adresa != NULL) {
//		strcpy(this->adresa, copie.adresa);
//	}
//
//	this->deschis = copie.deschis;
//	this->nr_camere = copie.nr_camere;
//	if (copie.preturi != NULL) {
//		this->preturi = new float[this->nr_camere];
//		for (int i = 0; i < this->nr_camere; i++) {
//			this->preturi[i] = copie.preturi[i];
//		}
//	}
//}
//
//void Hotel::afisare() {
//	cout << "Afisare hotel: " << endl;
//	cout << "Id: " << this->id << endl;
//	cout << "Nume: " << this->nume << endl;
//	cout << "Adresa: " << this->adresa << endl;
//	if (this->deschis == true) {
//		cout << "Deschis" << endl;
//	}
//	else {
//		cout << "Inchis" << endl;
//	}
//	cout << "Numarul de camere: "
//		<< this->nr_camere << endl;
//	if (this->preturi != NULL) {//constructor default alocat cu NULL
//		for (int i = 0; i < this->nr_camere; i++) {
//			cout << "Pretul camerei "
//				<< i + 1
//				<< " este "
//				<< this->preturi[i] << endl;
//		}
//	}
//}
//
//void Hotel::setNume(char* v_nume) {
//	if (this->nume != NULL) {
//		delete[]this->nume;
//	}
//	if (v_nume != NULL) {
//		this->nume = new char[strlen(v_nume) + 1];
//		strcpy(this->nume, v_nume);
//	}
//}
//
//char* Hotel::getNume() {
//	return this->nume;
//}
//
//Hotel::~Hotel() {
//	cout << "Apel destructor" << endl;
//	if (this->nume != NULL) {
//		delete[] this->nume;
//	}
//
//	if (this->preturi != NULL) {
//		delete[] this->preturi;
//	}
//
//	Hotel::nr_total--;
//}
//
//
//Hotel& Hotel::operator=(const Hotel& copie) {
//
//	if (this->nume != NULL) {
//		delete[] this->nume;
//	}
//
//	if (copie.nume != NULL) {
//		this->nume = new char[strlen(copie.nume) + 1];
//		strcpy(this->nume, copie.nume);
//	}
//
//	if (copie.adresa != NULL) {
//		strcpy(this->adresa, copie.adresa);
//	}
//
//	this->deschis = copie.deschis;
//	this->nr_camere = copie.nr_camere;
//
//	if (this->preturi != NULL) {
//		delete[] this->preturi;
//	}
//
//	if (copie.preturi != NULL) {
//		this->preturi = new float[this->nr_camere];
//		for (int i = 0; i < this->nr_camere; i++) {
//			this->preturi[i] = copie.preturi[i];
//		}
//	}
//
//	return *this;
//}
//
//ostream& operator<<(ostream& out, Hotel hotel) {
//	out << "Afisare hotel" << endl;
//
//	out << "Id: " << hotel.id << endl;
//	out << "Nume: " << hotel.nume << endl;
//	out << "Adresa: " << hotel.adresa << endl;
//	if (hotel.deschis == true) {
//		out << "Hotelul este deschis" << endl;
//	}
//	else {
//		out << "Hotelul este inchis" << endl;
//	}
//
//	out << "Numarul de camere: " << hotel.nr_camere << endl;
//	if (hotel.preturi != NULL) {
//		for (int i = 0; i < hotel.nr_camere; i++) {
//			out << "Pretul camerei " << i + 1 << " este " << hotel.preturi[i] << endl;
//		}
//	}
//
//	return out;
//}
//
//istream& operator>>(istream& in, Hotel& hotel) {
//	cout << "Citire hotel" << endl;
//
//	cout << "Nume: ";
//	char buf[50];
//	in.getline(buf, 50);
//	if (hotel.nume != NULL) {
//		delete[] hotel.nume;
//	}
//
//	hotel.nume = new char[strlen(buf) + 1];
//	strcpy(hotel.nume, buf);
//	cout << "Adresa: ";
//	in.getline(hotel.adresa, 60);
//	cout << "Deschis? 1-Da/0-NU";
//	in >> hotel.deschis;
//	cout << "Numarul de camere: ";
//	in >> hotel.nr_camere;
//	if (hotel.preturi != NULL) {
//		delete[] hotel.preturi;
//	}
//
//	hotel.preturi = new float[hotel.nr_camere];
//	for (int i = 0; i < hotel.nr_camere; i++) {
//		cout << "Pretul camerei " << i + 1 << " este: ";
//		in >> hotel.preturi[i];
//	}
//
//	return in;
//}