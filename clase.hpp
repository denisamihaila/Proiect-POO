#ifndef clase
#define clase

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>

#define assertm(exp, msg) assert(((void)msg, exp))

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
        assertm(!numeProd.empty(), "Numele produsului trebuie sa aiba minim un caracter");
        this->numeProdus = numeProd;
    }

    void setCuloare(string const &culoareP) {
        assertm(!culoareP.empty(), "Culoarea produsului trebuie sa aiba minim un caracter");
        this->culoare = culoareP;
    }

    void setMarime(string const &marimeP) {
        assertm(!marimeP.empty(), "Produsul trebuie sa aiba o marime disponibila");
        this->marime = marimeP;
    }

    void setPret(float const &pretP) {
        assertm(pretP >= 0, "Pretul produsului trebuie sa fie un numar pozitiv");
        this->pret = pretP;
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
        assertm(!numeProdus.empty(), "Numele produsului trebuie sa aiba minim un caracter");
        assertm(!culoare.empty(), "Culoarea produsului trebuie sa aiba minim un caracter");
        assertm(!marime.empty(), "Produsul trebuie sa aiba o marime disponibila");
        assertm(pret >= 0, "Pretul produsului trebuie sa fie un numar pozitiv");
        this->numeProdus = numeProdus;
        this->culoare = culoare;
        this->marime = marime;
        this->pret = pret;
        this->id = IDprodus++;
        produse[id] = this;
    }

    /*
    //constructor de copiere
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
        out << " ID:" << p->getID() << ". " << p->getNumeProdus() << " " << p->getCuloare() << " " << p->getMarime()
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
        assertm(!nume_utilizator.empty(), "Numele utilizatorului trebuie sa aiba minim un caracter");
        this->numeUtilizator = nume_utilizator;
    }

    void setNume(string const &Nume) {
        assertm(!Nume.empty(), "Numele trebuie sa aiba minim un caracter");
        this->nume = Nume;
    }

    void setEmail(string const &Email) {
        assertm(!Email.empty(), "Emailul trebuie sa aiba minim un caracter");
        this->email = Email;
    }

    void setParola(string const &Parola) {
        assertm(!Parola.empty(), "Parola trebuie sa aiba minim un caracter");
        this->parola = Parola;
    }

    void setBuget(float const &Buget) {
        assertm(Buget >= 0, "Bugetul trebuie sa fie un numar pozitiv!\n");
        this->buget = Buget;
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
        assertm (!numeUtilizator.empty(), "Numele utilizatorului trebuie sa aiba minim un caracter");
        assertm (!nume.empty(), "Numele trebuie sa aiba minim un caracter");
        assertm (!email.empty(), "Emailul trebuie sa aiba minim un caracter");
        assertm (!parola.empty(), "Parola trebuie sa aiba minim un caracter");
        assertm (buget >= 0, "Bugetul trebuie sa fie un numar pozitiv!");
        this->numeUtilizator = numeUtilizator;
        this->nume = nume;
        this->email = email;
        this->parola = parola;
        this->buget = buget;

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

    friend ostream &operator<<(ostream &out, Utilizator *u) {
        out << " NUME UTILIZATOR: " << u->getNumeUtilizator() << endl;
        out << " NUME SI PRENUME: " << u->getNume() << endl;
        out << " EMAIL: " << u->getEmail() << endl;
        out << " PAROLA: " << u->getParola() << endl;
        out << " BUGET: " << u->getBuget() << endl;
        return out;
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

    friend ostream &operator<<(ostream &out, Comanda *c) {
        out << " Numar de produse: " << c->nrProduse << endl;
        out << " Numele utilizatorului: " << c->numeUtilizator << endl;
        out << " Pret total: " << c->pretTotal << endl;
        return out;
    }

    friend class Magazin;

};

class Magazin {
private:
    string numeCont;
public:
    //setter
    void setNumeCont(string const &numecont) {
        this->numeCont = numecont;
    }

    void autentificare() {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ AUTENTIFICARE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " Intruduceti numele de utilizator: ";
        string numeIntrodus;
        cin >> numeIntrodus;
        cout << endl;
        if (!(Utilizator::utilizatori.find(numeIntrodus) != Utilizator::utilizatori.end())) {
            do {
                cout << " Nu exista acest nume de utilizator. Va rugam sa incercati din nou: ";
                cin >> numeIntrodus;
                cout << endl;
            } while (!(Utilizator::utilizatori.find(numeIntrodus) != Utilizator::utilizatori.end()));
        }
        if (Utilizator::utilizatori.find(numeIntrodus) != Utilizator::utilizatori.end()) //exista username-ul
        {
            cout << " Introduceti parola: ";
            string parolaIntrodusa;
            cin >> parolaIntrodusa;
            cout << endl;
            if (Utilizator::utilizatori[numeIntrodus]->getParola() != parolaIntrodusa)
                do {
                    cout << " Parola incorecta. Va rugam reintroduceti parola: ";
                    cin >> parolaIntrodusa;
                    cout << endl;
                } while (Utilizator::utilizatori[numeIntrodus]->getParola() != parolaIntrodusa);
            if (Utilizator::utilizatori[numeIntrodus]->getParola() == parolaIntrodusa) {
                this->numeCont = numeIntrodus;
                cout << " V-ati conectat cu succes!\n";
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
                cout << endl;
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
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DETALII CONT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << Utilizator::utilizatori[this->numeCont];

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
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CATALOG ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        for (const auto &pair: Produs::produse) {
            Produs *ptr = pair.second;
            cout << ptr;
        }
        cout << "\n ~~~~~~~~LA CUMPARATURILE DE PESTE 200 DE LEI BENEFICIATI DE 20% REDUCERE~~~~~~~~\n\n";
        cout << " CATE PRODUSE DORITI SA ACHIZITIONATI? ";
        cin >> comanda.nrProduse;
        cout << endl;
        if (comanda.nrProduse > 0) {
            int id;
            float suma = 0;
            for (int i = 0; i < comanda.nrProduse; i++) {
                cout << " INTRODUCETI ID-UL PRODUSULUI PENTRU A IL ADAUGA IN COS: ";
                cin >> id;
                comanda.produseComandate.push_back(id);
                cout << "PRODUS ADAUGAT IN COS!" << endl;
                suma += Produs::produse[id]->getPret();

            }
            if (suma >= 200)
                suma = float(suma * 0.8);
            if (Utilizator::utilizatori[numeCont]->getBuget() >= suma) {
                comanda.pretTotal = suma;
                for (int i = 0; i <= comanda.produseComandate.size(); i++)
                    Produs::produse.erase(comanda.produseComandate[i]);
                cout << "\n TOTALUL DE PLATA: " << comanda.pretTotal << endl;
                cout << " Comanda a fost efectuata." << endl;
                float bugetCurent = Utilizator::utilizatori[numeCont]->getBuget();
                bugetCurent -= comanda.pretTotal;
                Utilizator::utilizatori[numeCont]->setBuget(bugetCurent);
            } else
                cout << "FONDURI INSUFICIENTE :((( \n";
        }

    }

    //constructor fara parametri
    Magazin() {
        this->numeCont = "-";
    }

    ~Magazin() {
        this->numeCont = "";
    }

    friend ostream &operator<<(ostream &out, Magazin *m) {
        out << " Numele utilizatorului conectat: " << m->numeCont;
        out << "\n Produse disponibile: \n";
        for (const auto &pair: Produs::produse) {
            Produs *ptr = pair.second;
            out << ptr;
        }
        return out;
    }

    friend class Comanda;
};


#endif

