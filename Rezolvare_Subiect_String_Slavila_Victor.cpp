#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class GrupDeSocializare
{
private:
	const int idUnic;
	char denumire[50];
	unsigned int nrMesaje;
	string* mesaje;
public:
	 static  char* numeAplicatie;
	 GrupDeSocializare();
	 GrupDeSocializare(int v_idUnic);
	 friend ostream& operator<<(ostream& ies, GrupDeSocializare obiect);
	 char* getDenumire();
	 GrupDeSocializare(int v_idUnic, char v_denumire[50], unsigned int v_nrMesaje, string* v_mesaje);
	 int getNrMesaje();
	 ~GrupDeSocializare();
	 GrupDeSocializare(const GrupDeSocializare& sursa);
	 int getIdUnic();
	 int getDimensiuneCelMaiLungMesaj();
	 GrupDeSocializare& operator=(const GrupDeSocializare& obiect);
	 void setMesaje(int noua_dim, string* v_mesaje);
	 string& operator[](int index);
	 explicit operator string();
	 bool operator==(GrupDeSocializare grup);

    
};
char* GrupDeSocializare::numeAplicatie = NULL;




int main()
{
	GrupDeSocializare g1;
	cout << g1.getDenumire();

	string mesaje[]{ "Salutare tuturor","Sal","Ce faceti?" };
	
	char variab[50];
	strcpy(variab, "Grupa 1099");
	GrupDeSocializare g2(102, variab, 3, mesaje);
	cout << endl << g2.getNrMesaje();
	
	GrupDeSocializare g3 = g2;
	cout << endl << g3.getIdUnic();

	g1 = g3;
	cout << endl << g1.getDimensiuneCelMaiLungMesaj();
	
	string mesajeNoi[]{ "Avem test la POO?","Cand?" };
	g3.setMesaje(2, mesaje);

	char variab2[50];
	strcpy(variab2, "WhatsUp");
	GrupDeSocializare::numeAplicatie = variab2;
	cout << g1;

	g3[1] = "Nevermind";
	cout << endl << g3;

	cout << "Denumire grup: " + (string)g3;


	if (g1 == g3)
		cout << endl << "Grupurile au aceeasi denumire";
	else
		cout << endl << "Grupurile au denumiri diferite";

	

	
    return 0;
}

GrupDeSocializare::GrupDeSocializare() : idUnic(100)
{
	strcpy(this->denumire, "Grup Nou");
	this->nrMesaje = 0;
	this->mesaje = NULL;
}
GrupDeSocializare::GrupDeSocializare(int v_idUnic) : idUnic(v_idUnic)
{
	strcpy(this->denumire, "Grup Nou");
	this->nrMesaje = 0;
	this->mesaje = NULL;
}

ostream& operator<<(ostream& ies, GrupDeSocializare obiect)
{
	ies << endl;
	ies << "Afisare obiect: " << endl;
	ies << "Id : " << obiect.idUnic << endl;
	ies << "Denumire: " << obiect.denumire << endl;
	ies << "Numar mesaje: " << obiect.nrMesaje << endl;
	if (obiect.mesaje != NULL && obiect.nrMesaje > 0)
	{
		for (int i = 0; i < obiect.nrMesaje; i++)
		{
			ies << "Mesajul de pe pozitia " << i + 1 << " este " << obiect.mesaje[i] << endl;
		}
	}
	return ies;
}

char* GrupDeSocializare::getDenumire()
{
	return this->denumire;
}

GrupDeSocializare::GrupDeSocializare(int v_idUnic, char v_denumire[50], unsigned int v_nrMesaje, string* v_mesaje) :idUnic(v_idUnic)
{
	strcpy(this->denumire, v_denumire);
	this->nrMesaje = v_nrMesaje;
	if (v_mesaje != NULL && this->nrMesaje > 0)
	{
		this->mesaje = new string[this->nrMesaje];
		for (int i = 0; i < this->nrMesaje; i++)
		{
			this->mesaje[i] = v_mesaje[i];
		}
	}
}

int GrupDeSocializare::getNrMesaje()
{
	return this->nrMesaje;
}

GrupDeSocializare::~GrupDeSocializare()
{
	if (this->mesaje != NULL)
	{
		delete[] this->mesaje;
	}
}

GrupDeSocializare::GrupDeSocializare(const GrupDeSocializare& sursa) : idUnic(sursa.idUnic)
{
	if (sursa.denumire != NULL)
	{
		strcpy(this->denumire, sursa.denumire);
	}
	this->nrMesaje = sursa.nrMesaje;
	if (sursa.mesaje != NULL && this->nrMesaje > 0)
	{
		this->mesaje = new string[this->nrMesaje];
		for (int i = 0; i < this->nrMesaje; i++)
		{
			this->mesaje[i] = sursa.mesaje[i];
		}
	}
}

int GrupDeSocializare::getIdUnic()
{
	return this->idUnic + 1;
}

int GrupDeSocializare::getDimensiuneCelMaiLungMesaj()
{
	int index = 0;
	int max = mesaje[index].length();
	for (int i = 1; i < this->nrMesaje; i++)
	{
		if (mesaje[i].length() > max)
		{
			max = mesaje[i].length();
			index = i;
	    }
	}
	return mesaje[index].length();
}

GrupDeSocializare& GrupDeSocializare::operator=(const GrupDeSocializare& obiect)
{
	if (obiect.denumire != NULL)
	{
		strcpy(this->denumire, obiect.denumire);
	}
	this->nrMesaje = obiect.nrMesaje;
	if (this->mesaje != NULL)
	{
		delete[] this->mesaje;
	}
	if (obiect.mesaje != NULL && obiect.nrMesaje)
	{
		this->mesaje = new string[this->nrMesaje];
		for (int i = 0; i < this->nrMesaje; i++)
		{
			this->mesaje[i] = obiect.mesaje[i];
		}
	}
	return *this;
}

void GrupDeSocializare::setMesaje(int noua_dim, string* v_mesaje)
{
	if (noua_dim > 0)
	{
		this->nrMesaje = noua_dim;
		if (this->mesaje != NULL)
		{
			delete[] this->mesaje;
		}
		this->mesaje = new string[noua_dim];
		for (int i = 0; i < this->nrMesaje; i++)
		{
			this->mesaje[i] = v_mesaje[i];
		}
	}
	else
	{
		cout << "Nu ai dat dimensiunea corecta!";
	}
}

string& GrupDeSocializare::operator[](int index)
{
	if (index > 0 && index < this->nrMesaje && this->mesaje != NULL)
	{
		return this->mesaje[index];
	}
}

GrupDeSocializare::operator string()
{
	return this->denumire;
}

bool GrupDeSocializare::operator==(GrupDeSocializare grup)
{
	if (strcmp(this->denumire, grup.denumire) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}