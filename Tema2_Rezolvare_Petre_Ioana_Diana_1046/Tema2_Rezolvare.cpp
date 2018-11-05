#include <bits/stdc++.h>
using namespace std;

class Comanda{
private:
    int     id;
    int     masini_disponibile;
    int    *putere_motor;
    string  denumire;
    bool    disponibilitate_Ro;
    float  *pret_masinidisp;
    float pret_total_comanda;
    static const int consum_mediu_default = 25;
    int consum_mediu;

public:
    static int nr_obiecte;

    Comanda(); // def const
    Comanda(int id, int masini_disponibile, int *putere_motor, string denumire, bool disponibilitate_Ro, float *pret_masinidisp, int consum_mediu,float pret_total_comanda);
    Comanda(int id, int masini_disponibile, float *pret_masinidisp, int consum_mediu);
    ~Comanda();
    Comanda(const Comanda &copie); // copy const

    void afisare();

    //Functiile get
    int getID();
    int getMD();
    int *getHP();
    string getDen();
    bool getDisp();
    float *getPR();
    int getConsum();
    float getPR_total();


    //Functiile set
    void setId(int id);
    void setMD(int masini_disponibile);
    void setHP(int *putere_motor);
    void setDen(string denumire);
    void setDisp(bool disp);
    void setPR(float *pret_masinidisp);
    void setConsum(int consum);
    //void setConsum(int consum);

    //cin >>
    friend istream &operator >> (istream &in, Comanda &comanda);

};

int Comanda:: nr_obiecte = 0;

int main() {

    /*Comanda m1;
    m1.afisare();

   Comanda m2(10, 2, new int[2]{35,40}, "Suzuki", true, new float[2]{12000, 15000}, 20, 250000);
   m2.afisare();

    //////////////////////
    cout << "\n\nFunctiile de get: ";
    cout << "\n" << m2.getID() << endl;
    cout << m2.getMD() << endl;
    cout << m2.getHP() << endl; // adresa
    cout << m2.getDen() << endl;
    cout << m2.getDisp() << endl;
    cout << m2.getPR() << endl; // adresa
    cout << m2.getConsum() << endl;
    ///////////////////////

    Comanda m3;
    m3.afisare();
    cout << "\n\nFunctii de set:";
    m3.setId(3);
    m3.setMD(4);
    m3.setHP(new int[4]{13,14,15,16});
    m3.setDen("Daewoo");
    m3.setDisp(false);
    m3.setPR(new float[4]{800,850,860,890});
    m3.afisare();
    ///////////////////////

    Comanda *m4 = new Comanda[4];
    int j = 4;
    for(int i = 0; i < 4; i++){

        m4[i].setId(j++);
        m4[i].setMD(2);
        m4[i].setPR(new float[2]{101.0f * j, 110.0f * j});

        float medie_aritmetica = 0.0f;
        for(int k = 0; k < m4[i].getMD(); k ++){
            medie_aritmetica += m4[i].getPR()[k];
        }

        m4[i].afisare();
        cout << "\n\tMedia aritmetica a preturilor este: " << medie_aritmetica / m4[i].getMD();

    }

    Comanda test;
    test = m1;
    test.afisare();*/

    int nr_comenzi, i;
    float medie_pret_comenzi = 0;

    cout << "Nr de comenzi introduse: "; cin >> nr_comenzi;

    Comanda *comenzi = new Comanda[nr_comenzi];

    for(i = 0; i < nr_comenzi; i++){
        cout << "\n\nComanda " << i + 1 << ": ";
        cin >> comenzi[i];
        medie_pret_comenzi += comenzi[i].getPR_total();
        //comenzi[i].afisare();
    }


    cout << "\n\n\tMedia aritmetica a preturilor pentru cele " << nr_comenzi << " comenzi este: " << medie_pret_comenzi / nr_comenzi;
    cout << "\n\n\tNr obiecte: " << Comanda ::nr_obiecte;

    delete [] comenzi;
    //delete [] m4;
    return 0;
}

Comanda ::Comanda() {
    this -> id = -1;
    this -> masini_disponibile = 0;
    this -> putere_motor = NULL;
    this -> denumire = " /";
    this -> disponibilitate_Ro = false;
    this -> pret_masinidisp = NULL;
    this -> consum_mediu = this -> consum_mediu_default;
    this -> pret_total_comanda = 0;

    Comanda ::nr_obiecte ++;

}

Comanda ::Comanda(int id, int masini_disponibile, float *pret_masinidisp, int consum_mediu):consum_mediu(consum_mediu) {
    int i;
    this-> id = id;
    this-> masini_disponibile = masini_disponibile;

    if (pret_masinidisp != NULL) {
        this -> pret_masinidisp = new float[this -> masini_disponibile];
        for (i = 0; i < this -> masini_disponibile; i++)
            this -> pret_masinidisp[i] = pret_masinidisp[i];
    }
}

Comanda ::Comanda(int id, int masini_disponibile, int *putere_motor, string denumire, bool disponibilitate_Ro,
                float *pret_masinidisp, int consum_mediu, float pret_total_comanda): consum_mediu(consum_mediu) {
    int i;

    this -> id = id;
    this -> masini_disponibile = masini_disponibile;

    if(putere_motor != NULL) {
        this->putere_motor = new int[this->masini_disponibile];
        for (i = 0; i < this->masini_disponibile; i++)
            this->putere_motor[i] = putere_motor[i];
    }

    this -> denumire = denumire;

    this -> disponibilitate_Ro = disponibilitate_Ro;

    if(pret_masinidisp != NULL) {
        this->pret_masinidisp = new float[this -> masini_disponibile];
        for (i = 0; i < this-> masini_disponibile; i++)
            this->pret_masinidisp[i] = pret_masinidisp[i];
    }
    this -> pret_total_comanda = pret_total_comanda;

    Comanda ::nr_obiecte ++;

}
Comanda ::Comanda(const Comanda &copie):consum_mediu(copie.consum_mediu) {
    int i;
    this -> id = copie.id;
    this -> masini_disponibile = copie.masini_disponibile;

    if(copie.putere_motor != NULL){
        this -> putere_motor = new int[copie.masini_disponibile];
        for(i = 0; i < this -> masini_disponibile; i++)
            this -> putere_motor[i] = copie.putere_motor[i];
    }

    this -> denumire = copie.denumire;
    this -> disponibilitate_Ro = copie.disponibilitate_Ro;

    if(copie.pret_masinidisp != NULL){
        this -> pret_masinidisp = new float[copie.masini_disponibile];
        for(i = 0; i < copie.masini_disponibile; i++)
            this -> pret_masinidisp[i] = copie.pret_masinidisp[i];
    }
    this -> pret_total_comanda = copie.pret_total_comanda;

    Comanda ::nr_obiecte++;
}


void Comanda::afisare() {
    cout << "\n\n\tAfisare comanda: ";

    cout << "\nId: " << this -> id;
    cout << "\nMasini disponibile: " << this -> masini_disponibile;

    if(this -> putere_motor != NULL) {
        for (int i = 0; i < this->masini_disponibile; i++) {
            cout << "\nPuterea masinii " << i + 1 << " este: " << putere_motor[i] << " KW";
        }
    }

    cout << "\nDenumire firma: " << this -> denumire;

    if(this -> disponibilitate_Ro)
        cout << "\nMasina este disponibila in Romania";
    else
        cout << "\nMasina nu este disponibila in Romania";

    if(this -> pret_masinidisp != NULL) {
        for (int i = 0; i < this->masini_disponibile; i++) {
            cout << "\nPretul pentru masina " << i + 1 << " este: " << this->pret_masinidisp[i] << " euro";
        }
    }
    cout << "\nPretul total al comenzii:  " << this -> pret_total_comanda;
    cout << "\nConsumul mediu pentru firma " << this -> denumire << " este: " << this -> consum_mediu;
}

//getts
int Comanda ::getID() {
    return  this -> id;
}

int Comanda ::getMD() {
    return this -> masini_disponibile;
}

int *Comanda ::getHP(){
    return this -> putere_motor;
}

string Comanda ::getDen() {
    return this -> denumire;
}

bool Comanda ::getDisp() {
    return this -> disponibilitate_Ro;
}

float *Comanda ::getPR() {
    return this -> pret_masinidisp;
}

int Comanda ::getConsum() {
    return this -> consum_mediu;
}

float Comanda ::getPR_total() {
    return this -> pret_total_comanda;
}
//

//setts
void Comanda ::setId(int id) {
    if(id > 0)
    this -> id = id;
}

void Comanda ::setMD(int masini_disponibile) {
    if(masini_disponibile > 0)
    this -> masini_disponibile = masini_disponibile;
}

void Comanda ::setHP(int *putere_motor) {
    if(this -> putere_motor != NULL)
        delete [] this -> putere_motor;

    if(putere_motor != NULL){
        this -> putere_motor = new int[this -> masini_disponibile];
        for(int i = 0; i < this -> masini_disponibile; i++)
            this -> putere_motor[i] = putere_motor[i];
    }
}

void Comanda ::setDen(string denumire) {
    this -> denumire = denumire;
}

void Comanda ::setDisp(bool disp) {
    this -> disponibilitate_Ro = disp;
}

void Comanda ::setPR(float *pret_masinidisp) {
    if(this -> pret_masinidisp != NULL)
        delete [] this -> pret_masinidisp;

    if(pret_masinidisp != NULL){
        this -> pret_masinidisp = new float[this -> masini_disponibile];
        for(int i = 0; i < this -> masini_disponibile; i++)
            this -> pret_masinidisp[i] = pret_masinidisp[i];
    }
}

void Comanda ::setConsum(int consum) {
    if(consum > 0)
    this -> consum_mediu = consum;
}

//cin >>
istream &operator >> (istream &in, Comanda &comanda){
    int i;
    cout << "\n\n\tCitire comanda: ";

    cout << "\nIntroduceti ID'ul: "; in >> comanda.id;
    cout << "Introdduceti nr de masini: "; in >> comanda.masini_disponibile;


    if(comanda.putere_motor != NULL)
        delete[] comanda.putere_motor;

    comanda.putere_motor = new int[comanda.masini_disponibile];
    for(i = 0; i < comanda.masini_disponibile; i++){
        cout << "Puterea motorului pentru masina " << i + 1 << ": ";
        in >> comanda.putere_motor[i];
    }

    cout << "Denumire firma: "; in >> comanda.denumire;
    cout << "Este disponibila? 1-Da/0-Nu: ";
    in >> comanda.disponibilitate_Ro;

    if(comanda.pret_masinidisp != NULL)
        delete[] comanda.pret_masinidisp;

    comanda.pret_masinidisp = new float[comanda.masini_disponibile];
    for(i = 0; i < comanda.masini_disponibile; i++){
        cout << "Pretul pentru masina: " << i + 1 << ": ";
        in >> comanda.pret_masinidisp[i];
    }

    cout << "Consumul mediu al masinilor: ";
    in >> comanda.consum_mediu;
    cout << "Pretul total al comenzii este: ";
    in >> comanda.pret_total_comanda;

    return in;

}


Comanda ::~Comanda() {
    cout << "\n\tApel destructor :(";

    if(this -> putere_motor != NULL)
        delete [] this -> putere_motor;

    if(this -> pret_masinidisp != NULL)
        delete [] pret_masinidisp;


    Comanda ::nr_obiecte --;
}