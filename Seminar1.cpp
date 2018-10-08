/*
Seminar 1 POO:

- iostream: header care include standardele de intrare/iesire
- std: namespace care contine majoritatea identificatorilor necesari pentru dezvoltarea aplicatiilor c++; 
       este libraria standard din C++.
- namespace: spatiul de nume este utilizat pentru a diferentia functiile, clasele, variabilele etc., 
             care au acelas nume, dar care se afla in librarii diferite.
- cout: standard output
- pointer: reprezinta o adresa de memorie
- referinta: este un alias al unei variabile existente. 
             este asemanatoare cu pointer-ul

referinta vs ponter:
- pointerul poate sa fie void
- o referinta creata nu mai poate fi folosita pe o alta variabila.
- referinta nu poate fi null
- referinta trebuie initializata la declarare
*/

#include<iostream>
using namespace std;

void interschimbare1(int x, int y);
void interschimbare2(int* x, int* y);
void interschimbare3(int* x, int* y);
void interschimbare4(int& x, int& y);

void main() {

	//std::cout<<"First comment"<<std::endl;

	cout << "Size of int " << sizeof(int) << endl;
	int x = 10;

	int* p; //declarare pointer. Declarare generica a unui pointer: Type* pointer_name
	p = &x; //initializare pointer cu adresa unei variabile normale. '&' - operator adresa

	int& ref = *p;//declarare+initializare referinta. Declarare generica a unei referinte: Type& ref_name

	cout << "Valoare x: " << x << endl;
	cout << "Adresa x: " << &x << endl;
	cout << "Adresa p: " << p << endl;
	cout << "Valoare p: " << *p << endl;// afisare valoare de la adresa indicata de pointer. Preluarea valorii dintr-un pointer se face cu ajutorul operatorului '*'

	int x1 = 10;
	int x2 = 15;

	cout << "Initial state:" << endl;

	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;

	int temp = x1;
	x1 = x2;
	x2 = temp;

	cout << "Interchimbare interna" << endl;
	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;

	cout << "Interschimbare 1" << endl;
	interschimbare1(x1, x2);
	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;

	cout << "Interschimbare 2" << endl;
	interschimbare2(&x1, &x2);
	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;

	cout << "Interschimbare 3" << endl;
	interschimbare3(&x1, &x2);
	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;

	cout << "Interschimbare 4" << endl;
	interschimbare4(x1, x2);
	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;
}

void interschimbare1(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void interschimbare2(int*x, int*y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void interschimbare3(int*x, int*y) {
	int* temp = x;
	x = y;
	y = temp;
}

void interschimbare4(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}