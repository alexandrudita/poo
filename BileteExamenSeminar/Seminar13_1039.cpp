
#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

enum TIP_REPETITIE {
	ZILNICA,
	SAPTAMANALA,
	LUNARA,
};

class Activitate {
private:
	const int id;
	char* denumire;
	int durata;
	TIP_REPETITIE periodicitate;
	static int nr_activitati;
public:
	Activitate() :id(nr_activitati++) {
		denumire = new char[strlen("na") + 1];
		strcpy(denumire, "na");
		durata = 0;
		periodicitate = LUNARA;
	}


	Activitate(char* v_denumire, int v_durata, TIP_REPETITIE v_periodicitate):id(nr_activitati++) {


		if (v_denumire!=NULL) {
			denumire = new char[strlen(v_denumire) + 1];
			strcpy(denumire, v_denumire);

		}
		else {
			denumire = new char[strlen("na") + 1];
			strcpy(denumire, "na");
		}

		durata = v_durata;
		periodicitate = v_periodicitate;



	}


	~Activitate() {

		if (denumire) {
			delete[] denumire;
		}

	}

	Activitate(const Activitate &copie):id(copie.id) {
		this->denumire = new char[strlen(copie.denumire) + 1];
		strcpy(this->denumire, copie.denumire);
		this->durata = copie.durata;
		this->nr_activitati = copie.nr_activitati;
	}
	Activitate &operator=(const Activitate &copie) {
		delete[] this->denumire;
		this->denumire = new char[strlen(copie.denumire) + 1];
		strcpy(this->denumire, copie.denumire);
		this->durata = copie.durata;
		this->nr_activitati = copie.nr_activitati;
		return *this;
	}

	string getPeriodicitate() {
		switch (periodicitate){
		case ZILNICA: return "zilnica";
		case SAPTAMANALA: return "saptamanala";
		default: return "lunara";
		}

	}

	friend ostream& operator<<(ostream& out, Activitate& a) {
		out << "Afisare Activitate:" << endl;
		out << "Id: " << a.id<<endl;
		out << "Denumire: " << a.denumire<<endl;
		out << "Durata: " << a.durata<<endl;
		out << "Periodicitate: " << a.getPeriodicitate()<<endl;
		return out;
	}

	friend istream& operator>>(istream& in, Activitate& a) {
		cout << "Citire Activitate:" << endl;
		cout << "Denumire: ";
		char buf[50];
		in.getline(buf,50);
		delete[] a.denumire;
		a.denumire = new char[strlen(buf) + 1];
		strcpy(a.denumire, buf);
		cout << "Durata: ";
		in >> a.durata;
		cout << "Periodicitate: (0-zilnica, 1-saptamanala, !0,1-lunara)";
		int per;
		in >> per;
		switch (per) {
		case 0: a.periodicitate = ZILNICA; break;
		case 1: a.periodicitate = SAPTAMANALA; break;
		default: a.periodicitate = LUNARA;
		}
		return in;
	}

	Activitate& operator+=(int v_durata) {
		if (v_durata > 0 && durata + v_durata < 366) {
			durata += v_durata;
		}
		return *this;
	}

	bool operator!() {
		if (periodicitate == LUNARA)return true;
		else return false;
	}

	friend bool operator==(Activitate a1, Activitate a2 )
	{
		if(a1.id==a2.id && a1.durata==a2.durata)
		{
			return true;
		}
		else {
			return false;
		}
}

	void setDurata(int v_durata)
	{
		if (this->durata > 0)
		{
			this->durata = v_durata;
		}
		else
		{
			durata = 0;
		}
	}

};

int Activitate::nr_activitati = 0;

int main()
{
	char txt[50];
	strcpy(txt, "Definire echipa");
	Activitate a1(txt, 10, ZILNICA);
	Activitate a2 = a1;
	cout << a1;
	cin >> a2;
	cout << a2;

	a1 += 12;
	cout << a1;

	cout << !a1;
	a1.setDurata(2);
	a2.setDurata(2);
	cout <<"cele doua obiecte sunt egale ?" <<(a1 == a2);
}

