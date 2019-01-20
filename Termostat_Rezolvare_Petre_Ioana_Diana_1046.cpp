// Termostat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include<map>
using namespace std;

class Termo {
private:
	char *eticheta;
	float temp_citita;
	float temp_dorita;
	friend class BiTermo;

public:
	virtual float tempMedieCitita() { return 0; }

	float get_temp_citita() {
		return this->temp_citita;
	}

	char* get_eticheta() {
		return this->eticheta;
	}

	float get_temp_dorita() {
		return this->temp_dorita;
	}

	void set_eticheta(char *new_eti) {
		if (this->eticheta != NULL)
			delete[] this->eticheta;

		if (new_eti != NULL) {
			this->eticheta = new char[strlen(new_eti) + 1];
				strcpy(this->eticheta, new_eti);
		}
		else {
			this->eticheta = new char[strlen("Anonim") + 1];
			strcpy(this->eticheta, "Anonim");
		}
	}

	void set_temp_dorita(float t_d) {
		this->temp_dorita = t_d;
	}

	void set_temp_citita(float t_c) {
		this->temp_citita = t_c;
	}

	void set_eticheta(const char *eti_noua) {
		if (this->eticheta != NULL)
			delete[] this->eticheta;

		if (eti_noua != NULL) {
			this->eticheta = new char[strlen(eti_noua) + 1];
			strcpy(this->eticheta, eti_noua);
		}
	}

	Termo() {
		this->eticheta = new char[strlen("Anonim") + 1];
		strcpy(this->eticheta, "Anonim");

		this->temp_citita = 0;
		this->temp_dorita = 0;
	}

	Termo(const char *v_eticheta, float v_temp_citita, float v_temp_dorita) {
		if (v_eticheta != NULL) {
			this->eticheta = new char[strlen(v_eticheta) + 1];
			strcpy(this->eticheta, v_eticheta);
		}
		else {
			this->eticheta = new char[strlen("Anonim") + 1];
			strcpy(this->eticheta, "Anonim");
		}

		this->temp_citita = v_temp_citita;
		this->temp_dorita = v_temp_dorita;
	}

	Termo(const Termo &copie) {
		if (copie.eticheta != NULL) {
			this->eticheta = new char[strlen(copie.eticheta) + 1];
			strcpy(this->eticheta, copie.eticheta);
		}
		else {
			this->eticheta = new char[strlen("Anonim") + 1];
			strcpy(this->eticheta, "Anonim");
		}

		this->temp_citita = copie.temp_citita;
		this->temp_dorita = copie.temp_dorita;
	}

	Termo &operator=(const Termo &copie) {
		if (this->eticheta != NULL)
			delete[] this->eticheta;

		if (copie.eticheta != NULL) {
			this->eticheta = new char[strlen(copie.eticheta) + 1];
			strcpy(this->eticheta, copie.eticheta);
		}
		else {
			this->eticheta = new char[strlen("Anonim") + 1];
			strcpy(this->eticheta, "Anonim");
		}

		this->temp_citita = copie.temp_citita;
		this->temp_dorita = copie.temp_dorita;
		
		return *this;
	}

	friend ostream &operator<<(ostream &out, Termo &termo) {
		out << "\n\n\tAfisare termostat";
		out << "\nEticheta: " << termo.eticheta;
		out << "\nCaldura citita: " << termo.temp_citita;
		out << "\nCaldura dorita: " << termo.temp_dorita;

		return out;
	}

	Termo &operator--() {
		this->temp_dorita--;
		return *this;
	}

	friend istream &operator>>(istream &in, Termo &termo) {
		cout << "\n\n\tCitire obiect de tipul termostat";
		cout << "\nIntroduceti eticheta: "; char eti[50]; in.get();
		in.getline(eti, 50);

		if (termo.eticheta != NULL)
			delete[] termo.eticheta;

		termo.eticheta = new char[strlen(eti) + 1];
		strcpy(termo.eticheta, eti);
		

		cout << "Temperatura citita: "; in >> termo.temp_citita;
		cout << "Temperatura dorita: "; in >> termo.temp_dorita;

		return in;
	}

	~Termo() {
		if (this->eticheta != NULL)
			delete[] this->eticheta;
		//cout << "\n\nDistrus :(";
	}
};

class BiTermo : public Termo {
private:
	float temp_pardoseala;

public:
	virtual float tempMedieCitita() {
		return (this->temp_pardoseala + get_temp_citita());
	}

	BiTermo() : Termo() {
		this->temp_pardoseala = 0;
	}

	BiTermo(const Termo &termo) {//constructor care preia un obiect termo!!!
		this->temp_pardoseala = 0;
		this->temp_citita = termo.temp_citita;
		this->temp_dorita = termo.temp_dorita;

		this->eticheta = new char[strlen(termo.eticheta) + 1];
		strcpy(this->eticheta, termo.eticheta);
	}

	BiTermo(const BiTermo &copie) {//copy const pt bitermo!!!!!
		this->temp_pardoseala = copie.temp_pardoseala;
		this->temp_dorita = copie.temp_dorita;
		this->temp_citita = copie.temp_citita;
		
		this->eticheta = new char[strlen(copie.eticheta) + 1];
		strcpy(this->eticheta, copie.eticheta);
	}

	/*BiTermo &operator=(const BiTermo &copie) {
		this->temp_pardoseala = copie.temp_pardoseala;
		this->temp_dorita = copie.temp_dorita;
		this->temp_citita = copie.temp_citita;

		if (this->eticheta != NULL)
			delete[] this->eticheta;

		this->eticheta = new char[strlen(copie.eticheta) + 1];
		strcpy(this->eticheta, copie.eticheta);

		return *this;
	}*/

	friend ifstream &operator>>(ifstream &fin, BiTermo &btermo) {
		fin >> btermo.temp_pardoseala;
		fin.ignore(256, '\n'); /// !!!!!!!!!!!

		char buf[255];
		fin.getline(buf, 255);
		btermo.set_eticheta(buf);
		//fin.ignore(256, '\n');

		float t_d, t_c;
		fin >> t_c;
		btermo.set_temp_citita(t_c);

		fin >> t_d;
		btermo.set_temp_dorita(t_d);		

		return fin;
	}

	friend ostream &operator<<(ostream &out, BiTermo &b) {
		out << b.temp_pardoseala << " ";
		out << b.get_eticheta() << " ";
		out << b.get_temp_citita() << " ";
		out << b.get_temp_dorita() << endl;

		return out;
	}

	friend map<string, BiTermo> &operator+=(map<string, BiTermo> &mp, BiTermo &bt) { 
		//mp.insert(pair<string, BiTermo>(bt.get_eticheta(), bt));
		mp[bt.get_eticheta()] = bt;

		return mp;
	}
	
};

class UCC {
private:
	string locatie;
	int nr_termostate;
	vector<Termo> multime;

public:
	UCC() {
		this->locatie = "anonim";
		this->nr_termostate = 0;
		this->multime = vector<Termo>();
	}

	UCC(string v_locatie, int v_nr_termostate, vector<Termo> v_multime) {
		if (v_locatie.length() > 0)
			this->locatie = v_locatie;
		else
			this->locatie = "Anonim";

		if (v_nr_termostate > 0 && v_nr_termostate <= 12)
			this->nr_termostate = v_nr_termostate;

		this->multime = v_multime;
	}

	UCC(const UCC &copie) {
		if (copie.locatie.length() > 0)
			this->locatie = copie.locatie;
		else
			this->locatie = "anonim";

		this->nr_termostate = copie.nr_termostate;
		this->multime = copie.multime;
	}

	UCC &operator=(const UCC &copie) {
		if (copie.locatie.length() > 0)
			this->locatie = copie.locatie;
		else
			this->locatie = "anonim";

		this->nr_termostate = copie.nr_termostate;
		this->multime = copie.multime;

		return *this;
	}

	friend ostream &operator<<(ostream &out, UCC &ucc) {
		out << "\n\n\tAfisare UCC";
		out << "\nLocatie: " << ucc.locatie;
		out << "\nNr termostate: " << ucc.nr_termostate;
		out << "\n\tMultimea de termostate:";

		for (int i = 0; i < ucc.multime.size(); i++)
			out << ucc.multime[i] << endl;

		return out;
	}

	UCC &operator +=(int nr_t) {
		if (this->nr_termostate + nr_t <= 12) {
			this->nr_termostate += nr_t;
			multime.push_back(Termo());
			multime.push_back(Termo());
		}
		else
			cout << "\n\tNu se mai pot adauga termostate. Nr maxim este 12!";
		
		return *this;
	}

	friend istream &operator>>(istream &in, UCC &ucc) {
		cout << "\n\n\tCitire UCC:";
		cout << "\nLocatia: "; getline(in, ucc.locatie);
		cout << "Nr de termostate, trebuie sa fie maxim 12: "; int nrt;
		in >> nrt;
		if (nrt <= 12)
			ucc.nr_termostate = nrt;
		else {
			cout << "\nNr de termostate gresit";
			ucc.nr_termostate = 0;
		}

		for (int i = 0; i < ucc.nr_termostate; i++) {
			Termo t;
			cin >> t;
			ucc.multime.push_back(t);
		}
		
		return in;
	}

	friend ifstream &operator>>(ifstream &fin, UCC &ucc) {//citire din fisier txt
		getline(fin, ucc.locatie);

		int nrt;
		fin >> nrt;

		if (nrt <= 12)
			ucc.nr_termostate = nrt;
		else {
			cout << "\nNu se poate, prea multe termostate";
			ucc.nr_termostate = 0;
		}

		for (int i = 0; i < ucc.nr_termostate; i++) {
			Termo t;
			fin >> t;
			ucc.multime.push_back(t);
		}

		return fin;
	}

	friend ofstream &operator<<(ofstream &out, UCC &ucc) {//scriere in fisier txt
		out << ucc.locatie << " ";
		out << ucc.nr_termostate; 
		
		if (ucc.multime.size() > 0) {
			for (int i = 0; i < ucc.multime.size(); i++)
				out << ucc.multime[i];
			out << endl;
		}
		return out;
	}

};

/*void operator+=(map<string, BiTermo> &mp, BiTermo &bt) { ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	mp.insert(pair<string, BiTermo>(bt.get_eticheta(), bt));
}*/


int main()
{
	Termo t1("dormitor 1", 22.5, 23.5);
	Termo t2 = t1;
	Termo t3;
	t3 = t1;
	t3.set_eticheta("bucatarie");

	vector <Termo> tx1;
	tx1.push_back(t1);
	tx1.push_back(t2);
	tx1.push_back(t3);

	vector <Termo> tx2;
	tx2.push_back(t1);
	tx2.push_back(t2);
	tx2.push_back(t3);

	string uu1 = "etaj 1";
	string uu2 = "etaj 2";

	UCC u1(uu1, 3, tx1);
	UCC u2(uu2, 3, tx2);
	UCC u3(u2);
	UCC u4;
	u4 = u1;

	cout << t3;
	cout << u2;
	
	--t1;
	//cout << t1;
	u2 += 2;
	

	//Termo t4;
	//cin >> t4;
	//cout << t4;

	/*UCC u4;
	cin >> u4;
	cout << u4;

	ofstream fisierOUT;
	fisierOUT.open("ucc.txt", ofstream::out);

	fisierOUT << u4;
	fisierOUT.close();*/

	ifstream fisierIN;
	fisierIN.open("ucc_citire.txt", ifstream::in);

	UCC temp;
	if (fisierIN.is_open()) {
		fisierIN >> temp;
		cout << temp;
	}
	fisierIN.close();

	/*cout << "\nCitire din fisier txt: ";
	if (fisierIN.is_open()) {
		while (!fisierIN.eof()) {
			UCC temp;
			fisierIN >> temp;
			cout << temp;
		}
	}*/

	Termo *pt = &t1;
	cout << pt->tempMedieCitita() << endl;

	BiTermo t5 = t3;
	pt = &t5;
	cout << pt->tempMedieCitita() << endl;


	map<string, BiTermo> btMap;

	ifstream FisierIN;
	FisierIN.open("btMap.txt", ifstream::in);

	//map<string, BiTermo> testmap;
	
	//cout << "\ncitire din fisier txt: " << endl;
	if (FisierIN.is_open()) {
		while (!FisierIN.eof()) {
			BiTermo bt;
			FisierIN >> bt;
			btMap += bt;
			//cout << bt;

			//testmap.insert(pair<string, BiTermo>(bt.get_eticheta(), bt));

		}
	}FisierIN.close();

	map<string, BiTermo> ::iterator it;
	//for (it = testmap.begin(); it != testmap.end(); it++)
		//cout << it->first << " => " << it->second << endl;

	cout << "\nAfisare elemente btMap: \n";
	for (it = btMap.begin(); it != btMap.end(); it++) {
		cout << it->first << " => " << it->second;		
	}

	float tempmedie = 0;
	int nr_dormitoare = 0;
	string dormitor = "dormitor";
	cout << "\nTemperatura medie a dormitoarelor: ";
	for (it = btMap.begin(); it != btMap.end(); it++) {
		if (it->first == dormitor) {
			tempmedie += (it->second).tempMedieCitita();
			nr_dormitoare++;
		}
	}
	cout << tempmedie / nr_dormitoare;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
