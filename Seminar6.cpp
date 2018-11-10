#include "pch.h";
#include<iostream>
#include<string>

using namespace std;

class Produs {

private:
	const int id;
	string nume;
	float pret;
	char unitateMasura[10];
	static int nr_produse;

public:
	Produs();
	Produs(string nume, float pret, char unitateMasura[10]);
	Produs(const Produs& copie);
	~Produs();
	int getId();
	void setNume(string v_nume);
	string getNume();
	void setPret(float v_pret);
	float getPret();
	void setUnitateMasura(char v_unitateMasura[10]);
	char* getUnitateMasura();
	Produs& operator=(const Produs& produs);
	friend ostream& operator<<(ostream& out, Produs& produs);
	friend istream& operator>>(istream& in, Produs& produs);

	//metoda statica
	static int getNrProduse();
	//operator -
	//obiectul este primul
	Produs operator-(float discount);
	//obiectul este al doilea
	friend Produs operator-(float discount, Produs& produs);
	//supraincarcare ++ post si pre incrementare
	//preincrementare ++y
	Produs& operator++();
	//postincrementare y++
	Produs operator++(int);
	//operator cast
	operator int();
	//operator +=
	Produs& operator+=(const Produs& produs);
};

int Produs::nr_produse = 0;

int main() {

	Produs p1;
	cout << p1;

	Produs* p2 = new Produs();
	cout << *p2;
	cin >> *p2;
	cout << *p2;

	Produs p3 = *p2;
	cout << p3;

	char unit[10] = "KM";
	Produs p4("Alex", 12.2, unit);
	cout << p4;
	p4 = p1;
	cout << p4;

	Produs p5;
	Produs p6;

	p5.setPret(10);
	p6.setPret(11);

	Produs p7;
	p7 = p6 - 1.5F;
	cout << p7;
	p7 = 2.0f - p5;
	cout << p7;

	p7 = p5++;
	cout << p7;
	p7 = ++p5;
	cout << p7;

	p5 += p7;
	cout << p5;

	int id = p6;
	cout << "cast id: " << id << endl;
	return 0;
}

Produs::Produs() :id(Produs::nr_produse++) {
	this->nume = "Anonim";
	this->pret = 0;
	strcpy(this->unitateMasura, "Anonim");
}

Produs::Produs(string v_nume, float v_pret, char v_unitateMasura[10]) :id(Produs::nr_produse++) {
	if (v_nume.length() > 0) {
		this->nume = v_nume;
	}
	else {
		this->nume = "Anonim";
	}

	if (v_pret > 0) {
		this->pret = v_pret;
	}
	else {
		this->pret = 0;
	}

	if (v_unitateMasura != NULL) {
		strcpy(this->unitateMasura, v_unitateMasura);
	}
	else {
		strcpy(this->unitateMasura, "Anonim");
	}
}

Produs::Produs(const Produs& copie) :id(Produs::nr_produse++) {
	this->nume = copie.nume;
	this->pret = copie.pret;
	strcpy(this->unitateMasura, copie.unitateMasura);
}

Produs& Produs::operator=(const Produs& produs) {
	this->nume = produs.nume;
	strcpy(this->unitateMasura, produs.unitateMasura);
	this->pret = produs.pret;

	return *this;
}

ostream& operator<<(ostream& out, Produs& produs) {

	out << "Afisare produs" << endl;
	out << "Id: " << produs.id << endl;
	out << "Nume: " << produs.nume << endl;
	out << "Pret: " << produs.pret << endl;
	out << "Unitate masura: " << produs.unitateMasura << endl;

	return out;
}

istream& operator>>(istream& in, Produs& produs) {
	cout << "Citeste produs" << endl;
	cout << "Nume: ";
	char buf[50];
	in.getline(buf, 50);
	produs.nume = buf;
	cout << "Pret: ";
	in >> produs.pret;
	cout << "Unitate de masura: ";
	in.ignore();
	in.getline(produs.unitateMasura, 10);

	return in;
}

int Produs::getNrProduse() {
	return Produs::nr_produse;
}
//obiectul este primul
Produs Produs::operator-(float discount) {
	Produs copie = *this;
	if (discount > 0) {
		copie.pret -= discount;
	}

	return copie;
}
//obiectul este al doilea
Produs operator-(float discount, Produs& produs) {
	Produs copie = produs;
	if (discount > 0) {
		copie.pret = discount - copie.pret;
	}

	return copie;
}
//supraincarcare ++ post si pre incrementare
//preincrementare ++y
Produs& Produs::operator++() {
	this->pret++;
	return *this;
}
//postincrementare y++
Produs Produs::operator++(int) {
	Produs copie = *this;
	this->pret++;

	return copie;
}
//operator cast
Produs::operator int() {
	return this->id;
}
//operator +=
Produs& Produs::operator+=(const Produs& produs) {
	this->pret += produs.pret;

	return *this;
}

Produs::~Produs() {
	this->nume.clear();
}

int Produs::getId() {
	return this->id;
}

void Produs::setNume(string v_nume) {
	if (v_nume.length() > 0) {
		this->nume = v_nume;
	}
}

string Produs::getNume() {
	return this->nume;
}

void Produs::setPret(float v_pret) {
	if (v_pret > 0) {
		this->pret = v_pret;
	}
}

float Produs::getPret() {
	return this->pret;
}

void Produs::setUnitateMasura(char v_unitateMasura[10]) {
	if (v_unitateMasura != NULL) {
		strcpy(this->unitateMasura, v_unitateMasura);
	}
}

char* Produs::getUnitateMasura() {
	return this->unitateMasura;
}
