#include "pch.h";
#include <iostream>
#include<string>
using namespace std;

template<typename T>
bool compara(T a, T b) {
	return a == b;
}

template<typename T>
T scadere(T a, T b) {
	return a - b;
}

enum TipBursa {
	MERIT,
	STUDIU,
	SOCIALA,
};

template<typename T>
class Bursa {
private:
	TipBursa tip;
	unsigned int nr_persoane;
	T* persoane;
public:
	Bursa() {
		this->tip = NULL;
		this->nr_persoane = 0;
		this->persoane = NULL;
	}
	Bursa(TipBursa v_tip, unsigned int v_nr_persoane, T* v_persoane) {
		this->tip = v_tip;
		this->nr_persoane = v_nr_persoane;

		if (v_persoane != NULL) {
			this->persoane = new T[this->nr_persoane];

			for (int i = 0; i < this->nr_persoane; i++) {
				this->persoane[i] = v_persoane[i];
			}
		}
		else {
			this->persoane = NULL;
		}
	}
	Bursa(const Bursa& sursa) {
		this->tip = sursa.tip;
		this->nr_persoane = sursa.nr_persoane;

		if (sursa.persoane != NULL) {
			this->persoane = new T[this->nr_persoane];
			for (int i = 0; i < this->nr_persoane; i++) {
				this->persoane[i] = sursa.persoane[i];
			}
		}
		else {
			this->persoane = NULL;
		}
	}
	Bursa& operator=(const Bursa& sursa) {

		if (this->persoane != NULL) {
			delete[] this->persoane;
		}

		this->tip = sursa.tip;
		this->nr_persoane = sursa.nr_persoane;

		if (sursa.persoane != NULL) {
			this->persoane = new T[this->nr_persoane];
			for (int i = 0; i < this->nr_persoane; i++) {
				this->persoane[i] = sursa.persoane[i];
			}
		}
		else {
			this->persoane = NULL;
		}

		return *this;
	}
	~Bursa() {
		if (this->persoane != NULL) {
			delete[] this->persoane;
		}
	}

	string getTipAsString() {
		switch (this->tip) {
		case SOCIALA:
			return "social";
		case STUDIU:
			return "studiu";
		default:
			return "merit";
		}
	}

	friend ostream& operator<<(ostream& out, Bursa bursa) {
		cout << "Afiseaza bursa: " << endl;

		cout << "Tip: " << bursa.getTipAsString() << endl;
		cout << bursa.nr_persoane << " persoane iau bursa: " << endl;

		if (bursa.persoane != NULL) {
			for (int i = 0; i < bursa.nr_persoane; i++) {
				cout << bursa.persoane[i] << endl;
			}
		}

		return out;
	}
	bool operator==(Bursa bursa) {
		return (this->tip == bursa.tip && this->nr_persoane == bursa.nr_persoane);
	}
};

class Student {
private:
	string nume;
public:
	Student() {
		this->nume =  "Anonim";
	}

	Student(string v_nume) {
		if (v_nume.length()>0) {
			this->nume=v_nume;
		}
		else {
			this->nume = "Anonim";
		}
	}

	Student(const Student& sursa) {
		this->nume = sursa.nume;
	}

	Student& operator=(const Student& sursa) {
		this->nume = sursa.nume;

		return *this;
	}

	friend ostream& operator<<(ostream& out, Student student) {

		cout << "Student: " << endl;
		cout << "Nume: " << student.nume << endl;

		return out;
	}
};

class Companie {
private:
	string cui;

public:
	Companie() {
		this->cui = "Anonim";
	}
	Companie(string v_cui) {
		if (v_cui.length() > 0) {
			this->cui = v_cui;
		}
		else {
			this->cui = "Anonim";
		}
	}

	Companie(const Companie& sursa) {
		this->cui = sursa.cui;
	}

	Companie& operator=(const Companie& sursa) {
		this->cui = sursa.cui;
		return *this;
	}

	friend ostream& operator<<(ostream& out, Companie companie) {

		cout << "Companie: " << endl;
		cout << "CUI: " << companie.cui << endl;

		return out;
	}
};

void main() {
	int a = 2;
	int b = 2;
	if (compara<int>(a, b) == true) {
		cout << "A este egal cu b" << endl;
	}
	else {
		cout << "A este diferit de b" << endl;
	}

	string x = "Alex";
	string y = "Alex";

	if (compara<string>(x, y) == true) {
		cout << "Au acelasi nume" << endl;
	}
	else {
		cout << "Au nume diferite" << endl;
	}
	float f1 = 5.0;
	float f2 = 3.0;
	float rezultat = scadere<float>(f1, f2);

	cout << "Rezultatul scaderii a doua valori de tip float: " << rezultat << endl;

	Student studenti[2] = { Student("Popescu Marian"), Student("Ionescu Maria") };
	Companie companii[2] = { Companie("212sssd"), Companie("asda122") };

	Bursa<Student> b1(MERIT, 2, studenti);
	Bursa<Companie> c1(SOCIALA, 2, companii);

	cout << b1 << endl;
	cout << c1 << endl;

	Bursa<Student> b2(SOCIALA, 2, studenti);

	bool rez = compara<Bursa<Student>>(b1, b2);

	if (rez == true) {
		cout << "Bursele sunt egale" << endl;
	}
	else {
		cout << "Bursele nu sunt egale" << endl;
	}
}