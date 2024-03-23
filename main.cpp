#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "clase.hpp"

using namespace std;

class Produs {
private:
    string numeProdus;
    string culoare;
    string marime; //XS, S, M, L, XL
    float pret;
    int id; //unic pentru fiecare produs
    static int IDprodus;
    static map<int, Produs *> produse; //key = id
public:
    //getteri
    string getNumeProdus() const {
        return numeProdus;
    }

    string getCuloare() const {
        return culoare;
    }

    string getMarime() const {
        return marime;
    }

    float getPret() const {
        return pret;
    }

    int getID() const {
        return id;
    }

    //setteri
    void setNumeProdus(string const &numeProd) {
        if (!numeProd.empty()) {
            this->numeProdus = numeProd;
        } else
            cout << "Numele produsului trebuie să aibă minim un caracter" << endl;
    }

    void setCuloare(string const &culoareP) {
        if (!culoareP.empty())
            this->culoare = culoareP;
        else
            cout << "Culoarea produsului trebuie să aibă minim un caracter" << endl;
    }

    void setMarime(string const &marimeP) {
        if (!marimeP.empty())
            this->marime = marimeP;
        else
            cout << "Produsul trebuie să aibă o mărime disponibilă" << endl;
    }

    void setPret(float const &pretP) {
        if (pretP >= 0)
            this->pret = pretP;
        else
            cout << "Prețul produsului nu poate fi un număr negativ" << endl;
    }

    //constructor fara parametri
    Produs() {
        this->numeProdus = "-";
        this->culoare = "-";
        this->marime = "-";
        this->pret = 0;
        this->id = IDprodus++;
        produse[this->id] = this;
    }

    //constructor cu parametri
    Produs(string const &numeProdus, string const &culoare, string const &marime, float const &pret) {
        if (!numeProdus.empty())
            this->numeProdus = numeProdus;
        else
            cout << "Numele produsului trebuie sa aiba minim un caracter" << endl;

        if (!culoare.empty())
            this->culoare = culoare;
        else
            cout << "Culoarea produsului trebuie sa aiba minim un caracter" << endl;

        if (!marime.empty())
            this->marime = marime;
        else
            cout << "Produsul trebuie sa aiba o marime disponibila" << endl;

        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Pretul produsului trebuie sa fie un numar pozitiv" << endl;

        this->id = IDprodus++;
        produse[id] = this;
    }

    /*//constructor de copiere
    Produs(const Produs &p) {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = IDprodus++;
        produse[id] = this;
    }

    //supraincarcare operator=
    Produs &operator=(const Produs &p) {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = IDprodus++;
        produse[id] = this;
        return *this;
    }*/

    //destructor
    ~Produs() = default;

    friend istream &operator>>(istream &in, Produs &p) {
        in >> p.numeProdus >> p.culoare >> p.marime >> p.pret;
        return in;
    }

    friend ostream &operator<<(ostream &out, Produs *p) {
        out << "ID:" << p->getID() << ". " << p->getNumeProdus() << " " << p->getCuloare() << " " << p->getMarime()
            << " " << p->getPret() << " lei " << endl;
        return out;
    }

    friend class Magazin;

    friend class Comanda;
};

int Produs::IDprodus = 1;
map<int, Produs *> Produs::produse;

class Utilizator {
    string numeUtilizator;
    string nume;
    string email;
    string parola;
    float buget;
    static map<string, Utilizator *> utilizatori; //key = numeUtilizator  -  unic pt fiecare utilizator

public:
    //getteri
    string getNumeUtilizator() const {
        return numeUtilizator;
    }

    string getNume() const {
        return nume;
    }

    string getEmail() const {
        return email;
    }

    string getParola() const {
        return parola;
    }

    float getBuget() const {
        return buget;
    }

    //setteri
    void setNumeUtilizator(string const &nume_utilizator) {
        if (!nume_utilizator.empty())
            this->numeUtilizator = nume_utilizator;
        else
            cout << "Numele utilizatorului trebuie sa aiba minim un caracter" << endl;
    }

    void setNume(string const &Nume) {
        if (!Nume.empty())
            this->nume = Nume;
        else
            cout << "Numele trebuie sa aiba minim un caracter" << endl;
    }

    void setEmail(string const &Email) {
        if (!Email.empty())
            this->email = Email;
        else
            cout << "Emailul trebuie sa aiba minim un caracter" << endl;
    }

    void setParola(string const &Parola) {
        if (!Parola.empty())
            this->parola = Parola;
        else
            cout << "Parola trebuie sa aiba minim un caracter" << endl;
    }

    void setBuget(float const &Buget) {
        if(Buget >= 0)
            this->buget = Buget;
        else
            cout << "Bugetul trebuie sa fie un numar pozitiv!" << endl;
    }

    //constructor fara parametri
    Utilizator() {
        this->numeUtilizator = "-";
        this->nume = "-";
        this->email = "-";
        this->parola = "-";
        this->buget = 0.0;
        utilizatori[numeUtilizator] = this;
    }

    //constructor cu parametri
    Utilizator(string const &numeUtilizator, string const &nume, string const &email, string const &parola,
               float const &buget) {
        if (!numeUtilizator.empty())
            this->numeUtilizator = numeUtilizator;
        else
            cout << "Numele utilizatorului trebuie sa aiba minim un caracter" << endl;

        if (!nume.empty())
            this->nume = nume;
        else
            cout << "Numele trebuie sa aiba minim un caracter" << endl;

        if (!email.empty())
            this->email = email;
        else
            cout << "Emailul trebuie sa aiba minim un caracter" << endl;

        if (!parola.empty())
            this->parola = parola;
        else
            cout << "Parola trebuie sa aiba minim un caracter" << endl;

        if(buget >= 0)
            this->buget = buget;
        else
            cout << "Bugetul trebuie sa fie un numar pozitiv!" << endl;

        utilizatori[numeUtilizator] = this;

    }

    //constructor de copiere
    Utilizator(const Utilizator &u) {
        this->numeUtilizator = u.numeUtilizator;
        this->nume = u.nume;
        this->email = u.email;
        this->parola = u.parola;
        this->buget = u.buget;
        utilizatori[numeUtilizator] = this;
    }

    //supraincarcare operator=
    Utilizator &operator=(const Utilizator &u) {
        this->numeUtilizator = u.numeUtilizator;
        this->nume = u.nume;
        this->email = u.email;
        this->parola = u.parola;
        this->buget = u.buget;
        utilizatori[numeUtilizator] = this;
        return *this;
    }

    //destructor
    ~Utilizator() {
        utilizatori.erase(numeUtilizator);
    }

    friend istream &operator>>(istream &f, Utilizator &u) {
        f >> u.numeUtilizator >> u.nume >> u.email >> u.parola >> u.buget;
        return f;
    }

    friend class Magazin;

    friend class Comanda;

};

map<string, Utilizator *> Utilizator::utilizatori;

class Comanda {
private:
    int nrProduse;
    string numeUtilizator;
    float pretTotal;
    vector<int> produseComandate; //id-urile produselor comandate
public:
    Comanda() {
        this->nrProduse = 0;
        this->numeUtilizator = "-";
        this->pretTotal = 0;
        this->produseComandate = {};
    }

    ~Comanda() = default;

    friend class Magazin;

};

class Magazin {
private:
    string numeCont;
public:
    //setter
    void setNumeCont (string const& numecont){
        this->numeCont = numecont;
    }
    void autentificare() {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ AUTENTIFICARE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " Intruduceti numele de utilizator: ";
        string numeIntrodus;
        cin >> numeIntrodus;
        if (!(Utilizator::utilizatori.find(numeIntrodus) != Utilizator::utilizatori.end())) {
            do {
                cout << "Nu exista acest nume de utilizator. Va rugam sa incercati din nou: ";
                cin >> numeIntrodus;
            } while (!(Utilizator::utilizatori.find(numeIntrodus) != Utilizator::utilizatori.end()));
        }
        if (Utilizator::utilizatori.find(numeIntrodus) != Utilizator::utilizatori.end()) //exista username-ul
        {
            cout << "Introduceti parola: ";
            string parolaIntrodusa;
            cin >> parolaIntrodusa;
            if (Utilizator::utilizatori[numeIntrodus]->getParola() != parolaIntrodusa)
                do {
                    cout << "Parola incorecta. Va rugam reintroduceti parola: ";
                    cin >> parolaIntrodusa;
                } while (Utilizator::utilizatori[numeIntrodus]->getParola() != parolaIntrodusa);
            if (Utilizator::utilizatori[numeIntrodus]->getParola() == parolaIntrodusa) {
                this->numeCont = numeIntrodus;
                cout << "V-ati conectat cu succes!\n";
            }
        }

    }

    static void creareCont(Utilizator contNou) {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CREARE CONT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " Intruduceti un nume de utilizator: ";
        string numeUtilizator;
        cin >> numeUtilizator;
        if (Utilizator::utilizatori.find(numeUtilizator) != Utilizator::utilizatori.end())
            //daca exista deja numele de utilizator, alegem altul
            do {
                cout << "Numele de utilizator ales este deja inregistrat. Va rugam sa alegeti altul: ";
                cin >> numeUtilizator;
            } while (Utilizator::utilizatori.find(numeUtilizator) != Utilizator::utilizatori.end());
        //this->numeCont = numeUtilizator;
        contNou.setNumeUtilizator(numeUtilizator);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DATE PERSONALE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " NUME: ";
        string numeFamilie;
        cin >> numeFamilie;
        cout << "PRENUME: ";
        string prenume;
        cin >> prenume;    //sa imi suprascriu functia de citire cu tot cu mesaje
        string nume;
        nume = numeFamilie + " " + prenume;
        contNou.setNume(nume);
        cout << "EMAIL: ";
        string email;
        cin >> email;
        contNou.setEmail(email);
        cout << "PAROLA: ";
        string parola;
        cin >> parola;
        contNou.setParola(parola);
        cout << "BUGET: ";
        float buget;
        cin >> buget;
        contNou.setBuget(buget);
        cout << "Felicitari! V-ati creat noul cont." << endl;
        Utilizator::utilizatori[contNou.getNumeUtilizator()] = &contNou;
    }

    void detaliiCont() {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ DETALII CONT ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << "NUME UTILIZATOR: " << Utilizator::utilizatori[this->numeCont]->getNumeUtilizator() << endl;
        cout << "NUME SI PRENUME: " << Utilizator::utilizatori[this->numeCont]->getNume() << endl;
        cout << "EMAIL: " << Utilizator::utilizatori[this->numeCont]->getEmail() << endl;
        cout << "PAROLA: " << Utilizator::utilizatori[this->numeCont]->getParola() << endl;
        cout << "BUGET: " << Utilizator::utilizatori[this->numeCont]->getBuget() << endl;

    }

    static void adaugaProdus(Produs produsNou) {
        cout << "NUME PRODUS: ";
        string numeProdus;
        cin >> numeProdus;
        produsNou.setNumeProdus(numeProdus);
        cout << "CULOARE: ";
        string culoareProdus;
        cin >> culoareProdus;
        produsNou.setCuloare(culoareProdus);
        cout << "MARIME: ";
        string marimeProdus;
        cin >> marimeProdus;
        produsNou.setMarime(marimeProdus);
        cout << "PRET: ";
        float pretProdus;
        cin >> pretProdus;
        produsNou.setPret(pretProdus);
        cout << "PRODUS ADAUGAT!\n";
        Produs::produse[produsNou.getID()] = &produsNou;
    }

    void cumpara() {
        Comanda comanda;
        comanda.numeUtilizator = numeCont;
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ CATALOG ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        for (const auto &pair: Produs::produse) {
            Produs *ptr = pair.second;
            cout << ptr;
        }
        cout << " CATE PRODUSE DORITI SA ACHIZITIONATI? ";
        cin >> comanda.nrProduse;
        if (comanda.nrProduse > 0) {
            int id;
            float suma = 0;
            for (int i = 0; i < comanda.nrProduse; i++) {
                cout << "INTRODUCETI ID-UL PRODUSULUI PENTRU A IL ADAUGA IN COS: ";
                cin >> id;
                comanda.produseComandate.push_back(id);
                cout << "PRODUS ADAUGAT IN COS!" << endl;
                suma += Produs::produse[id]->getPret();

            }
            if (Utilizator::utilizatori[numeCont]->getBuget() >= suma) {
                comanda.pretTotal = suma;
                for (int i = 0; i <= comanda.produseComandate.size(); i++)
                    Produs::produse.erase(comanda.produseComandate[i]);
                cout << "TOTALUL DE PLATA: " << comanda.pretTotal << endl;
                float bugetCurent = Utilizator::utilizatori[numeCont]->getBuget();
                bugetCurent -= comanda.pretTotal;
                Utilizator::utilizatori[numeCont]->setBuget(bugetCurent);
            } else
                cout << "FONDURI INSUFICIENTE SARACULE\n";
        }


    }

    //constructor fara parametri
    Magazin() {
        this->numeCont = "-";
    }

    friend class Comanda;
};


int main() {
    Magazin magazin;

    Produs p1("rochie", "neagra", "XS", 79);
    Produs p2("blugi", "albastri", "L", 120);
    Produs p3("bluza", "rosie", "M", 47);
    Produs p4("fusta", "verde", "S", 38);
    Produs p5("bluza", "mov", "XL", 40);
    Produs p6("pantaloni", "albi", "S", 89);
    Produs p7("palarie", "maro", "ONE-SIZE", 34);

    Utilizator u1("deni", "mihaila denisa", "denisa.mihaila@s.unibuc.ro", "123", 420);
    Utilizator u2("andrei", "popa andrei", "andrei.popa@s.unibuc.ro", "parola", 357);
    Utilizator u3("alexia", "pascu alexia", "alexia.pascu@s.unibuc.ro", "zoo", 248);
    Utilizator u4("mircea", "popescu mircea", "mircea.popescu@s.unibuc.ro", "masini", 100);

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ VINTED ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << endl;

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ INREGISTRARE UTILIZATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " --> Apasati tasta 1, urmata de Enter, daca aveti deja cont " << endl;
    cout << " --> Apasati tasta 2, urmata de Enter, pentru a va crea contul de utilizator " << endl;
    cout << " --> ";

    int input;
    cin >> input;

    Utilizator contNou;

    if (input == 1)
        magazin.autentificare();
    else if (input == 2) {
        Magazin::creareCont(contNou);
        magazin.setNumeCont(contNou.getNumeUtilizator());
    }
    do {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENIU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << endl;
        cout << " --> VIZUALIZARE DETALII CONT: TASTA 1, URMATA DE ENTER " << endl;
        cout << " --> ADAUGARE PRODUS: TASTA 2, URMATA DE ENTER " << endl;
        cout << " --> CUMPARA: TASTA 3, URMATA DE ENTER " << endl;
        cout << " --> INCHIDE APLICATIA: TASTA 4, URMATA DE ENTER " << endl;
        cout << " --> ";
        cin >> input;

        if (input == 1)
            magazin.detaliiCont();
        else if (input == 2) {
            Produs p_nou;
            Magazin::adaugaProdus(p_nou);
        } else if (input == 3)
            magazin.cumpara();
        else if (input == 4) break;
    } while (input != 4);
    return 0;
}
