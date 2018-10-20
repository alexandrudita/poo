/*
1. Clasa
	O clasa reprezinta un tip abstract de date, ce incorporeaza atribute si functii.
	Faciliteaza reutilizarea codului.
	class Nume_Clasa
	{
		tip_acces:
		atribute;
		functii membre;
		
		tip_acces:
		atribute;
		functii membre;
	};
		1.1. Atribute / date membre / variabile de instanta
		Valorile lor reprezinta starea unui obiect.
		Prin prisma incapsularii, sunt definite in zona privata si sunt accesate prin intermediul metodelor publice.
		1.2. Metode / functii membre
		Definesc comportamentul/interfata unui obiect.
		Sunt accesibile din afara clasei.
		Apelul/Invocarea unei metode este echivalent cu transmiterea unui mesaj.
		1.3. Tip de acces
		Descrie tipul de acces la atributele si metodele clasei.
			1.3.1. Private (Implicit, pus de compilator)
			Permite accesul doar din interiorul clasei.
			1.3.2. Protected
			Permite accesul din interiorul clasei si din interiorul claselor derivate.
			1.3.3. Public
			Permite accesul din interiorul clasei si din afara ei.
2. Obiectul
	Obiectul este o instanta a clasei / o variabila de tipul clasei. Reprezinta ceva concret.
3. Pointerul this
	Pointer special care contine adresa obiectului care apeleaza metoda.
	Accesibil din orice functie membra a clasei, permite referirea obiectului curent.
	Pointer constant transmis implicit tuturor metodelor membre clasei.
4. Constructor
	Aloca spatiu pentru obiect si initializeaza atributele acestuia.
	Are numele clasei, nu prezinta tip returnat si poate avea oricati parametri.
	NU au tip returnat explicit deoarece returneaza implicit adresa zonei de memorie rezervata obiectului construit.
	Pot exista oricate versiuni (supraincarcari).
		4.1. Constructor fara parametri (implicit)
		Creat de catre compilator daca nu exista nici un constructor.
		4.2. Constructor cu unul sau mai multi parametri
		4.3. Constructor cu valori implicite
5. Destructor
	Metoda apelata la "distrugerea" unui obiect, pentru a elibera memoria alocata pentru atribute. 
	Pentru atributele alocate dinamic in functiile constructor este OBLIGATORIU dezalocarea lor in destructor. 
	In caz contrar programul genereaza memory leaks.
	Poate exista maxim unul.
	Generat implicit de catre compilator. 
	Se apeleaza implicit inainte de terminarea programului pentru toate obiectele definite.
	Se apeleaza explicit (prin delete) la pointeri la obiecte.
	Are numele clasei precedat de simbolul ~, nu prezinta tip returnat si nu are parametri.
	NU are tip returnat explicit deoarece returneaza implicit void.
*/
#include<iostream>
using namespace std;

class Hotel {
//default este pus private
private:
	int id;
	char* nume;
	char adresa[60];
	bool deschis;
	unsigned int nr_camere;
	float* preturi;
public:
	Hotel();// constructor default
	Hotel(int v_id, char* v_nume);//constructor cu mai multi param
	~Hotel();//destructor
	void afisare();
};

int main() {
	//constructor default
	//variabila normala
	Hotel h1;
	h1.afisare();
	//variabila pointer
	Hotel* h2 = new Hotel();
	h2->afisare();
	delete h2;
	//constructor mai multi param
	//variabila normala
	char* variab = new char[strlen("Constr variab normala")+1];
	strcpy(variab,"Constr variab normala");
	Hotel h3(1,variab);
	h3.afisare();
	//pointer
	Hotel* h4 = new Hotel(2, variab);
	h4->afisare();
	delete h4;
	return 0;
}

Hotel::Hotel() { //Hotel::Hotel(Hotel* this)- dispunere memorie
	this->id = -1;
	this->nume = new char[strlen("Anonim") + 1];
	strcpy(this->nume, "Anonim");
	strcpy(this->adresa, "Anonim");
	this->deschis = false;
	this->nr_camere = 0;
	this->preturi = NULL;
}

Hotel::Hotel(int v_id, char* v_nume) {//Hotel::Hotel(Hotel* this, int v_id, char* v_nume);
	this->id = v_id;
	if (v_nume != NULL) {
		this->nume = new char[strlen(v_nume) + 1];
		strcpy(this->nume, v_nume);
	}
	strcpy(this->adresa, "Anonim");
	this->deschis = false;
	this->nr_camere = 0;
	this->preturi = NULL;
}

void Hotel::afisare() {
	cout << "Afisare hotel: " << endl;
	cout << "Id: " << this->id << endl;
	cout << "Nume: " << this->nume << endl;
	cout << "Adresa: " << this->adresa << endl;
	if (this->deschis == true) {
		cout << "Deschis" << endl;
	}
	else {
		cout << "Inchis" << endl;
	}
	cout << "Numarul de camere: " 
		<< this->nr_camere << endl;
	if (this->preturi != NULL) {//constructor default alocat cu NULL
		for (int i = 0; i < this->nr_camere; i++) {
			cout << "Pretul camerei " 
				<< i + 1 
				<< " este " 
				<< this->preturi[i] << endl;
		}
	}
}

Hotel::~Hotel() {
	cout << "Apel destructor" << endl;
	if (this->nume != NULL) {
		delete[] this->nume;
	} 

	if (this->preturi != NULL) {
		delete[] this->preturi;
	}
}