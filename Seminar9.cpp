/**

Seminar 9:

Mostenire

O clasa (subclasa, copil, derivata) mosteneste toate atributele
si metodele unei alte clase (superclasa, parinte, de baza) sau
ale mai multor clase. Relatie de tipul IS A.
class Baza {
};

class Derivata: [tip_derivare] Baza{
};
Unde tip_derivare stabileste modul de modificare a accesului la
membrii clasei de baza din clasa derivata. Implicit e private.

Observatii:
1) Fiecare constructor este responsabil strict de zona clasei
pe care o reprezinta.
Constructorii din clasa derivata apeleaza constructorii din
clasa de baza.
2) Fiecare destructor e responsabil de eliberarea propriilor
resurse (alocate prin constructor).
Se apeleaza incepand de jos in sus in ierarhie (cei de clasa
derivata, cei din clasa de baza).

Relatie 'has a'
- o clasa are ca si atribute tipuri de alte clase.

Functie virtual - acele functii care se pot suprascrie in orice clasa care deriva din clasa de baza.
-functiile virtual sunt apelate de compilator la executie, fata de celelalte care se apeleaza la compilare

*/


#include "pch.h";
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Concurent {
protected:
	char* nume;
	unsigned int numar;
	unsigned int nr_jurati;
	float* note;

public:
	Concurent();
	Concurent(char* v_nume, unsigned int v_numar, unsigned int v_nr_jurati, float* v_note);
	Concurent(const Concurent& concurent);
	Concurent& operator=(const Concurent& concurent);
	~Concurent();
	//operator de afisare 
	friend ostream& operator<<(ostream& out, Concurent concurent);
	//getteri
	char* getNume();
	unsigned int getNumar();
	unsigned int getNrJurati();
	float* getNote();

	//oper scriere citire fisier -ex fisier txt
	friend ifstream& operator>>(ifstream& in, Concurent& concurent);
	friend ofstream& operator<<(ofstream& out, Concurent& concurent);

	//metoda virtuala
	virtual void afisare();

};

//salvare fisier binar
void salvareFisierBinar(char* nume_fisier, Concurent* concurenti, int nr_concurenti);

//incarcare fisier binar
Concurent* incarcareDinFisierBinar(char* nume_fisier, int &nr_concurenti);

class Gimnast : public Concurent { //clasa Gimnast se afla in relatie de tip is-a
private:
	string aparat;

public:
	Gimnast();
	Gimnast(string v_aparat, char* v_nume, unsigned int v_numar, unsigned int v_nr_jurati, float* v_note);
	~Gimnast();
	Gimnast(const Gimnast& copie);
	Gimnast& operator=(const Gimnast& g);
	string getAparat();
	void setAparat(string v_aparat);
	friend ostream& operator<<(ostream& out, Gimnast& g);

	void afisare();
};

int main() {

	Concurent c1;
	char nume[50];
	strcpy(nume, "Popescu Ion");
	float note[2] = { 8.7,10.0 };
	Concurent c2(nume, 2, 2, note);

	Concurent concurenti[2] = { c1,c2 };

	ofstream fisierOut;
	fisierOut.open("concurenti.txt", ofstream::out);

	for (int i = 0; i < 2; i++) {
		fisierOut << concurenti[i];
	}

	fisierOut.close();


	ifstream fisierIn;
	fisierIn.open("concurenti.txt", ifstream::in);

	cout << "Citire fisier text" << endl;
	if (fisierIn.is_open()) {
		while (!fisierIn.eof()) {
			Concurent temp;
			fisierIn >> temp;
			cout << temp;
		}
	}

	fisierIn.close();

	char nume_fisier_binar[50];
	strcpy(nume_fisier_binar, "concurent.dat");
	int nr_concurenti = 2;
	salvareFisierBinar(nume_fisier_binar, concurenti, nr_concurenti);
	nr_concurenti = 0;
	Concurent* concurenti2 = incarcareDinFisierBinar(nume_fisier_binar, nr_concurenti);
	cout << "Afisare fisier binar" << endl;
	for (int i = 0; i < nr_concurenti; i++) {
		cout << concurenti2[i];
	}

	Gimnast g1;
	cout << g1;

	g1.setAparat("Barna");
	cout << g1.getAparat() << endl;

	Gimnast g2("Barna", nume, 12, 2, note);
	cout << g2;
	cout << g2.getNume() << endl;

	Concurent c3 = g2;
	cout << c3;

	Gimnast g3 = g2;
	cout << g3;
	g1 = g2;
	cout << g1;

	c2.afisare();
	g3.afisare();

	return 0;
}

Concurent::Concurent() {
	this->nume = new char[strlen("Anonim") + 1];
	strcpy(this->nume, "Anonim");
	this->numar = 0;
	this->nr_jurati = 0;
	this->note = NULL;
}
Concurent::Concurent(char* v_nume, unsigned int v_nr_concurs, unsigned int v_nr_jurati, float* v_note) {
	if (v_nume != NULL) {
		this->nume = new char[strlen(v_nume) + 1];
		strcpy(this->nume, v_nume);
	}
	else {
		this->nume = new char[strlen("NAN") + 1];
		strcpy(this->nume, "NAN");
	}

	this->numar = v_nr_concurs;
	this->nr_jurati = v_nr_jurati;
	if (this->nr_jurati > 0 && v_note != NULL) {

		this->note = new float[v_nr_jurati];

		for (int i = 0; i < this->nr_jurati; i++) {
			this->note[i] = v_note[i];
		}
	}
}

Concurent::Concurent(const Concurent& concurent) {

	this->nume = new char[strlen(concurent.nume) + 1];
	strcpy(this->nume, concurent.nume);

	this->numar = concurent.numar;
	this->nr_jurati = concurent.nr_jurati;
	this->note = new float[nr_jurati];
	for (int i = 0; i < this->nr_jurati; i++) {
		this->note[i] = concurent.note[i];
	}
}

Concurent& Concurent::operator=(const Concurent& concurent) {

	if (this->nume != NULL) {
		delete[] this->nume;
	}

	this->nume = new char[strlen(concurent.nume) + 1];
	strcpy(this->nume, concurent.nume);

	this->numar = concurent.numar;
	this->nr_jurati = concurent.nr_jurati;

	if (this->note != NULL) {
		delete[] this->note;
	}
	this->note = new float[nr_jurati];
	for (int i = 0; i < this->nr_jurati; i++) {
		this->note[i] = concurent.note[i];
	}

	return *this;
}

Concurent::~Concurent() {
	cout << "Apel destructor" << endl;

	if (this->nume != NULL) {
		delete[] this->nume;
	}
	if (this->note != NULL && this->nr_jurati > 0) {
		delete[] this->note;
	}
}

ostream& operator<<(ostream& out, Concurent concurent) {

	out << "Nume: " << concurent.nume << endl;
	out << "Numar concurs: " << concurent.numar << endl;
	out << "Numar de jurati: " << concurent.nr_jurati << endl;
	out << "Note: " << endl;
	for (int i = 0; i < concurent.nr_jurati; i++) {
		out << "nota " << (i + 1) << ": " << concurent.note[i] << endl;
	}

	return out;
}

void Concurent::afisare() {
	cout << "Afisarea unui concurent" << endl;
	cout << *this;
}

char* Concurent::getNume() {
	return this->nume;
}

unsigned int Concurent::getNumar() {
	return this->numar;
}

unsigned int Concurent::getNrJurati() {
	return this->nr_jurati;
}

float* Concurent::getNote() {
	return this->note;
}

ifstream& operator>>(ifstream& in, Concurent& concurent) {
	char buffer[50];
	in.getline(buffer, 50);
	if (concurent.nume != NULL) {
		delete[] concurent.nume;
	}
	concurent.nume = new char[strlen(buffer) + 1];
	strcpy(concurent.nume, buffer);
	in >> concurent.numar;
	in >> concurent.nr_jurati;
	if (concurent.note != NULL) {
		delete[] concurent.note;
	}

	if (concurent.nr_jurati > 0) {
		concurent.note = new float[concurent.nr_jurati];

		for (int i = 0; i < concurent.nr_jurati; i++) {
			in >> concurent.note[i];
		}
	}

	in.ignore();

	return in;
}

ofstream& operator<<(ofstream& out, Concurent& concurent) {
	out << concurent.nume << endl;
	out << concurent.numar << endl;
	out << concurent.nr_jurati << endl;
	if (concurent.note != NULL && concurent.nr_jurati > 0) {
		for (int i = 0; i < concurent.nr_jurati; i++) {
			out << concurent.note[i];
			if (i < concurent.nr_jurati - 1) {
				out << endl;
			}
		}
	}

	return out;
}

void salvareFisierBinar(char* nume_fisier, Concurent* concurenti, int nr_concurenti) {
	if (nume_fisier == NULL || concurenti == NULL || nr_concurenti == 0) {
		cout << "datele de intrare nu sunt valide" << endl;
	}
	else {
		ofstream fisier;
		fisier.open(nume_fisier, ofstream::out | ofstream::binary);
		if (fisier.is_open()) {
			//nr_concurenti
			fisier.write((char*)&nr_concurenti, sizeof(int));
			for (int i = 0; i < nr_concurenti; i++) {
				//scriere nume concurent
				//trebuie scrisa lungimea atributului nume + valoare + dimensiunea ocupata 
				int lungime = strlen(concurenti[i].getNume()) + 1;
				fisier.write((char*)&lungime, sizeof(int));
				fisier.write(concurenti[i].getNume(), lungime * sizeof(char));
				//numar concurs
				unsigned int numar = concurenti[i].getNumar();
				fisier.write((char*)&numar, sizeof(unsigned int));
				//numar jurati
				unsigned int nr_jurati = concurenti[i].getNrJurati();
				fisier.write((char*)&nr_jurati, sizeof(unsigned int));
				//note
				for (int j = 0; j < concurenti[i].getNrJurati(); j++) {
					fisier.write((char*)&concurenti[i].getNote()[j], sizeof(float));
				}
			}
			fisier.close();
		}
		else {
			cout << "Fisierul nu s-a putut deschide" << endl;
		}
	}
}
Concurent* incarcareDinFisierBinar(char* nume_fisier, int &nr_concurenti) {
	if (nume_fisier == NULL) {
		cout << "Numele fisierului este null" << endl;
		return NULL;
	}
	else {
		Concurent* concurenti = NULL;
		ifstream fisier;
		fisier.open(nume_fisier, ifstream::in | ifstream::binary);
		if (fisier.is_open()) {
			//numar concurenti
			fisier.read((char*)&nr_concurenti, sizeof(int));
			concurenti = new Concurent[nr_concurenti];
			for (int i = 0; i < nr_concurenti; i++) {
				//lungime nume + nume;
				int lungime = 0;
				fisier.read((char*)&lungime, sizeof(int));
				char nume[50];
				fisier.read(nume, lungime * sizeof(char));
				//numar concurs
				unsigned int numar;
				fisier.read((char*)&numar, sizeof(unsigned int));
				//numar jurati
				unsigned int nr_jurati;
				fisier.read((char*)&nr_jurati, sizeof(unsigned int));
				//note
				float* note = new float[nr_jurati];
				for (int j = 0; j < nr_jurati; j++) {
					fisier.read((char*)&note[j], sizeof(float));
				}

				concurenti[i] = Concurent(nume, numar, nr_jurati, note);
			}
			fisier.close();
		}
		else {
			cout << "Fisierul nu s-a putut deschide" << endl;
		}
		return concurenti;
	}
}

Gimnast::Gimnast() :Concurent() {
	this->aparat = "Anonim";
}

Gimnast::Gimnast(string v_aparat, char* v_nume,
	unsigned int v_numar,
	unsigned int v_nr_jurati, float* v_note) : Concurent(v_nume, v_numar, v_nr_jurati, v_note) {
	if (v_aparat.length() > 0) {
		this->aparat = v_aparat;
	}
	else {
		this->aparat = "Anonim";
	}
}

Gimnast::~Gimnast() {
}

Gimnast::Gimnast(const Gimnast& copie) :Concurent(copie) {
	this->aparat = copie.aparat;
}

Gimnast& Gimnast::operator=(const Gimnast& g) {

	this->aparat = g.aparat;
	delete[] this->nume;
	this->nume = new char[strlen(g.nume) + 1];
	strcpy(this->nume, g.nume);
	this->numar = g.numar;
	if (this->note != NULL && this->nr_jurati > 0) {
		delete[] this->note;
	}

	this->nr_jurati = g.nr_jurati;
	if (g.note != NULL && g.nr_jurati > 0) {
		this->note = new float[this->nr_jurati];
		for (int i = 0; i < g.nr_jurati; i++) {
			this->note[i] = g.note[i];
		}
	}

	return *this;
}

string Gimnast::getAparat() {
	return this->aparat;
}
void Gimnast::setAparat(string v_aparat) {
	if (v_aparat.length() > 0) {
		this->aparat = v_aparat;
	}
	else {
		this->aparat = "Anonim";
	}
}

ostream& operator<<(ostream& out, Gimnast& g) {
	out << "Aparat: " << g.aparat << endl;
	out << (Concurent)g;
	return out;
}

void Gimnast::afisare() {
	cout << "Afisarea unui gimnast" << endl;
	cout << *this;
}

