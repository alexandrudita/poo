#include "pch.h";
#include<iostream>
#include<string>

using namespace std;

class Apartament {

private:
	string adresa;
	char proprietar[50];
	const unsigned int an_constructie;
	double pret;
	unsigned int numar_camere;
	float* suprafete_camere;
public:
	Apartament();
	Apartament(string v_adresa, char v_proprietar[50], unsigned int v_an_constructie, double v_pret, unsigned int v_numar_camere, float* v_suprafete_camere);
	Apartament(const Apartament& copie);
	~Apartament();
	Apartament& operator=(const Apartament& apartament);
	friend ostream& operator<<(ostream& out, Apartament a);
	friend istream& operator>>(istream& in, Apartament& a);


	//operator functie
	float operator()();
	//operator index
	float& operator[](int index);
	//operator negatie
	bool operator!();
	//operator == 
	bool operator==(Apartament apartament);
	// cast explicit
	explicit operator double();
};

int main() {

	float s[3] = { 15.4, 12, 9.8 };

	char prop[50];
	strcpy(prop, "Prop");

	Apartament a("Ap", prop, 2018, 120000, 3, s);

	cout << a;
	float suprafata = a();
	cout << "Suprafata totala: " << suprafata << endl;
	cout << "Suprafata camerei 2: " << a[1] << endl;
	Apartament a1;
	cout << "a1 are camere: " << !a1 << endl;
	cout << "a1 == a " << (a1 == a) << endl;

	double pret = (double)a;

	cout << "Pret: " << pret << endl;

	return 0;
}

Apartament::Apartament() :an_constructie(0) {
	this->adresa = "Anonim";
	this->numar_camere = 0;
	strcpy(this->proprietar, "Anonim");
	this->pret = 0;
	this->suprafete_camere = NULL;
}

Apartament::Apartament(string v_adresa, char v_proprietar[50],
	unsigned int v_an_constructie, double v_pret, unsigned int v_numar_camere,
	float* v_suprafete_camere) :an_constructie(v_an_constructie) {
	if (v_adresa.length() > 0) {
		this->adresa = v_adresa;
	}
	else {
		this->adresa = "Anonim";
	}

	if (v_proprietar != NULL) {
		strcpy(this->proprietar, v_proprietar);
	}
	else {
		strcpy(this->proprietar, "Anonim");
	}

	this->pret = v_pret;
	this->numar_camere = v_numar_camere;
	if (v_suprafete_camere != NULL) {
		this->suprafete_camere = new float[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete_camere[i] = v_suprafete_camere[i];
		}
	}
}

Apartament::Apartament(const Apartament& copie) :an_constructie(copie.an_constructie) {

	this->adresa = copie.adresa;
	strcpy(this->proprietar, copie.proprietar);
	this->pret = copie.pret;
	this->numar_camere = copie.numar_camere;
	if (copie.suprafete_camere != NULL) {
		this->suprafete_camere = new float[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete_camere[i] = copie.suprafete_camere[i];
		}
	}
}

Apartament& Apartament::operator=(const Apartament& apartament) {

	this->adresa = apartament.adresa;
	strcpy(this->proprietar, apartament.proprietar);
	this->pret = apartament.pret;
	this->numar_camere = apartament.numar_camere;

	if (this->suprafete_camere != NULL) {
		delete[] this->suprafete_camere;
	}

	if (apartament.suprafete_camere != NULL) {
		this->suprafete_camere = new float[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete_camere[i] = apartament.suprafete_camere[i];
		}
	}

	return *this;
}

Apartament::~Apartament() {
	if (this->suprafete_camere != NULL && this->numar_camere > 0) {
		delete[] this->suprafete_camere;
	}
}

ostream& operator<<(ostream& out, Apartament a) {
	out << "Afisare apartament" << endl;
	out << "Adresa: " << a.adresa << endl;
	out << "Proprietar: " << a.proprietar << endl;
	out << "Pret: " << a.pret << endl;
	out << "An constructie: " << a.an_constructie << endl;
	out << "Numar de camere: " << a.numar_camere << endl;
	if (a.suprafete_camere != NULL && a.numar_camere > 0) {
		for (int i = 0; i < a.numar_camere; i++) {
			out << "Suprafata camerei " << i + 1 << " este " << a.suprafete_camere[i] << endl;
		}
	}

	return out;
}

istream& operator>>(istream& in, Apartament& a) {
	cout << "Initializare apartament " << endl;

	cout << "Adresa: ";
	char buf[50];
	in.getline(buf, 50);
	a.adresa = buf;
	cout << "Proprietar: ";
	in.getline(a.proprietar, 50);
	cout << "Pret: ";
	in >> a.pret;
	cout << "Numar camere: ";
	in >> a.numar_camere;
	if (a.suprafete_camere != NULL) {
		delete[] a.suprafete_camere;
	}

	if (a.numar_camere > 0) {
		a.suprafete_camere = new float[a.numar_camere];
		for (int i = 0; i < a.numar_camere; i++) {
			cout << "Suprafata camerei " << i + 1 << " este: ";
			in >> a.suprafete_camere[i];
		}
	}
	else {
		a.suprafete_camere = NULL;
	}

	return in;
}

float Apartament::operator()() {

	float suprafata_totala = 0;

	if (this->suprafete_camere != NULL && this->numar_camere > 0) {
		for (int i = 0; i < this->numar_camere; i++) {
			suprafata_totala += this->suprafete_camere[i];
		}
	}

	return suprafata_totala;
}

float Apartament::operator[](int index) {
	if (index >= 0 && index < this->numar_camere && this->suprafete_camere != NULL) {
		return this->suprafete_camere[index];
	}

	return -1;
}

bool Apartament::operator!() {

	if (this->suprafete_camere == NULL) {
		return false;
	}
	else {
		return true;
	}
}

bool Apartament::operator==(Apartament apartament) {
	if (strcmp(this->proprietar, apartament.proprietar) == 0) {
		return true;
	}
	else {
		return false;
	}
}

Apartament::operator double() {
	return this->pret;
}
