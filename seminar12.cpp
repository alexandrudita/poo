#include "pch.h";
#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std;

class RestantierException :public exception {
public:
	string mesaj() {
		return "Media este mai mica decat 5";
	}
};

class Student {
private:
	string nume;
	float media;

public:
	Student(string v_nume, float v_media);
	Student(const Student& copie);
	void setNume(string v_nume);
	void setMedia(float v_media);
	string getNume();
	float getMedia();

	friend ostream& operator<<(ostream& out, Student s);
	bool operator<(Student& s);
};

bool sortareStudenti(Student& s1, Student& s2) {
	return s1 < s2;
}
void main() {

	Student s1("Popescu Daniel", 8.70);
	try {
		s1.setNume("");
		s1.setNume("Maria");
	}
	catch (string nume_exceptie) {
		cout << "Modificarea numelui nu este permisa. Mesaj: " << nume_exceptie << endl;
	}
	catch (...) {
		cout << "Alta exceptie" << endl;
	}

	try {
		s1.setMedia(7);
		cout << s1.getMedia() << endl;
		s1.setMedia(-1);
	}
	catch (float media) {
		cout << "Media introdusa este invalida. Intervalul corect (0-10]. Valoare primita: " << media << endl;
	}
	catch (...) {
		cout << "Alta exceptie" << endl;
	}

	Student s2("Ionescu Daniela", 4.75);
	Student s3("Irsuc George", 10.0);

	Student v1[3] = { s1,s2,s3 };

	for (int i = 0; i < 3; i++) {
		try {
			cout << v1[i].getNume() << " are media ";
			if (v1[i].getMedia() < 5) {
				throw new RestantierException();
			}
			else {
				cout << v1[i].getMedia() << endl;
			}
		}
		catch (RestantierException* res) {
			cout << res->mesaj() << endl;
		}
	}

	vector<int> vect;//int* vect;
	vect.push_back(1);//int vect[2] = {1,2}
	vect.push_back(2);
	vect.pop_back();

	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << endl;
	}

	list<int> l;
	l.push_front(1);
	l.push_back(3);
	l.push_front(100);

	list<int>::iterator it;//int* it -pointer de tip int

	for (it = l.begin(); it != l.end(); it++) {
		cout << *it << endl;
	}
	l.sort();
	for (it = l.begin(); it != l.end(); it++) {
		cout << *it << endl;
	}
	l.reverse();
	for (it = l.begin(); it != l.end(); it++) {
		cout << *it << endl;
	}

	list<int> l2;

	l2.assign(4, 3);//construieste o lista de dimensiune 4, toate elementele au valoarea 3
	cout << "Afisare assign 1 " << endl;
	for (it = l2.begin(); it != l2.end(); it++) {
		cout << *it << endl;
	}
	//copiere date dintr-o lista in alta
	l2.assign(l.begin(), l.end());
	cout << "Afisare assign 2 " << endl;
	for (it = l2.begin(); it != l2.end(); it++) {
		cout << *it << endl;
	}

	//adaugare valoare pe o pozitie anume intr o lista. se realizeaza cu ajutorul iteratorului
	cout << "lista inainte de modificare. adaugare pe o pozitie anume" << endl;
	l2.push_back(4);
	for (it = l2.begin(); it != l2.end(); it++) {
		cout << *it << endl;
	}
	it = l2.begin();
	advance(it, 2);
	//l2.assign(l.begin(), l.end()); - copiere pozitie 1 la final
	//l2.assign(it, l.end()); - copiere pozitie 2 la final
	l2.insert(it, 30);
	cout << "lista dupa modificare. adaugare pe o pozitie anume" << endl;
	for (it = l2.begin(); it != l2.end(); it++) {
		cout << *it << endl;
	}
	//map
	map<int, string> persoane;
	persoane[1] = "Popescu Marian";
	persoane[2] = "Ionescu Daniela";
	persoane.insert(make_pair(3, "Gogu Mihai"));//persoane[3] = "Gogu Mihai";
	persoane[4] = "Popescu Marian";
	//persoane[1] = "Popescu Marian2";

	map<int, string>::reverse_iterator it2;

	for (it2 = persoane.rbegin(); it2 != persoane.rend(); it2++) {
		cout << it2->first << " " << it2->second << endl;
		//it2->first - cheia din mapa
		//it2->second - valoarea din mapa
	}


	set<string> angajati;
	angajati.insert("Popescu Marian");
	angajati.insert("Popescu Marian");// valoare == cu ce exista in set
	angajati.insert("Popescu Victor");
	//set<Persoane> persoane; Persoane p1; persoane.insert(p1); persoane.insert(p1);
	set<string>::iterator it3;

	for (it3 = angajati.begin(); it3 != angajati.end(); it3++) {
		cout << *it3 << endl;
	}

	list<Student> studenti2;

	Student s4 = s1;
	s4.setMedia(6);
	studenti2.push_back(s1);
	studenti2.push_back(s2);
	studenti2.push_back(s3);
	studenti2.push_back(s4);

	studenti2.sort(sortareStudenti);

	list<Student>::iterator it4;

	for (it4 = studenti2.begin(); it4 != studenti2.end(); it4++) {
		cout << *it4;
	}


}

Student::Student(string v_nume, float v_media) {
	if (v_nume.length() > 3)
	{
		this->nume = v_nume;
	}
	else {
		this->nume = "Anonim";
	}

	if (v_media > 0 && v_media <= 10) {
		this->media = v_media;
	}
	else {
		this->media = 0;
	}
}

Student::Student(const Student& copie) {
	this->nume = copie.nume;
	this->media = copie.media;
}

string Student::getNume() {
	return this->nume;
}

float Student::getMedia() {
	return this->media;
}

ostream& operator<<(ostream& out, Student s) {
	out << "Afisare student" << endl;
	out << "Nume: " << s.nume << endl;
	out << "Media: " << s.media << endl;

	return out;
}

bool Student::operator<(Student& s) {
	return this->media < s.media;
}

//adaugare exceptii pe setter

void Student::setNume(string v_nume) {
	if (v_nume.length() > 3) {
		this->nume = v_nume;
	}
	else {
		throw string("nume introdus este invalid");
	}
}

void Student::setMedia(float v_media) {
	if (v_media > 0 && v_media <= 10) {
		this->media = v_media;
	}
	else {
		throw v_media;
	}
}