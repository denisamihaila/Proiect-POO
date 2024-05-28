#ifndef clase
#define clase

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Exceptie : public exception {
private:
    string mesaj;
public:
    explicit Exceptie(const string& message) : mesaj(message) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

template <typename T>
void printCollection(const T& collection) {
    for (const auto& item : collection) {
        cout << item;
    }
}

class Produs : public enable_shared_from_this<Produs> {
private:
    string numeProdus;
    string culoare;
    string marime; //XS, S, M, L, XL
    float pret{};
protected:
    int id; //unic pentru fiecare produs
    static int IDprodus;
    static map<int, shared_ptr<Produs>> produse; //key = id produs
    //polimorfism
    virtual void updateMarime() { cout << "Modificam marimea produsului cu id-ul " << id << endl; };
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
    void setNumeProdus(string const& numeProd) {
        if (numeProd.empty())
            throw Exceptie("Numele produsului trebuie sa aiba minim un caracter");
        this->numeProdus = numeProd;
    }

    void setCuloare(string const& culoareP) {
        if (culoareP.empty())
            throw Exceptie("Culoarea produsului trebuie sa aiba minim un caracter");
        this->culoare = culoareP;
    }

    void setMarime(string const& marimeP) {
        if (marimeP.empty())
            throw Exceptie("Produsul trebuie sa aiba o marime disponibila");
        this->marime = marimeP;
    }

    void setPret(float const& pretP) {
        if (pretP < 0)
            throw Exceptie("Pretul produsului trebuie sa fie un numar pozitiv");
        this->pret = pretP;
    }

    //constructor fara parametri
    Produs() {
        this->numeProdus = "-";
        this->culoare = "-";
        this->marime = "-";
        this->pret = 0;
        this->id = IDprodus++;
    }

    //constructor cu parametri
    Produs(string const& numeProdus, string const& culoare, string const& marime, float const& pret) {
        try {
            setNumeProdus(numeProdus);
            setCuloare(culoare);
            setMarime(marime);
            setPret(pret);
            this->id = IDprodus++;
        }
        catch (const Exceptie& e) {
            cerr << "Nu s-a putut crea produsul: " << e.what() << endl;
        }
    }

    //constructor de copiere
    Produs(const Produs& p)  : enable_shared_from_this(p) {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = IDprodus++;
    }

    //destructor
    virtual ~Produs() = default;

    friend istream& operator>>(istream& in, Produs& p) {
        in >> p.numeProdus >> p.culoare >> p.marime >> p.pret;
        return in;
    }

    friend ostream& operator<<(ostream& out, const shared_ptr<Produs>& p) {
        out << " ID:" << p->getID() << ". " << p->getNumeProdus() << " " << p->getCuloare() << " " << p->getMarime()
            << " " << p->getPret() << " lei " << endl;
        return out;
    }

    friend class Magazin;
    friend class Comanda;
    friend class MagazinVanzator;
    friend class MagazinClient;
    friend class MagazinAdmin;

    static void initProduse(const shared_ptr<Produs>& p) {
        produse[p->getID()] = p;
    }
};

class Haina : public Produs {
private:
    string material;
public:
    Haina(string const& numeProdus, string const& culoare, string const& marime, float const& pret, string const& material) :
            Produs(numeProdus, culoare, marime, pret), material(material) {
    }
    string getMaterial() { return material; }
    friend ostream& operator<<(ostream& out, const shared_ptr<Haina>& p) {
        out << " ID:" << p->getID() << ". " << p->getNumeProdus() << " " << p->getMaterial() << " " << p->getCuloare() << " " << p->getMarime()
            << " " << p->getPret() << " lei " << endl;
        return out;
    }
    //polimorfism runtime(dinamic) - functie virtuala
    void updateMarime() override {
        string nouaMarime;
        cin >> nouaMarime;
        this->setMarime(nouaMarime);
    };
    //polimorfism compile-time(static) - supraincarcarea functiilor
    static void updateMarime(const shared_ptr<Haina>& haina) {
        string nouaMarime;
        cin >> nouaMarime;
        haina->setMarime(nouaMarime);
    };
};

int Produs::IDprodus = 1;
map<int, shared_ptr<Produs>> Produs::produse;

//Factory Method Pattern
class ProdusFactory {
public:
    virtual shared_ptr<Produs> createProdus(string const& numeProdus, string const& culoare, string const& marime, float const& pret) = 0;
    virtual ~ProdusFactory() = default;
};

class HainaFactory : public ProdusFactory {
public:
    shared_ptr<Produs> createProdus(string const& numeProdus, string const& culoare, string const& marime, float const& pret) override {
        return make_shared<Haina>(numeProdus, culoare, marime, pret, "material implicit");
    }
};


class Utilizator : public enable_shared_from_this<Utilizator> {
    string numeUtilizator;
    string nume;
    string email;
    string parola;
    float buget;
    static map<string, shared_ptr<Utilizator>> utilizatori; //key = numeUtilizator  -  unic pt fiecare utilizator

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
    void setNumeUtilizator(string const& nume_utilizator) {
        if (nume_utilizator.empty())
            throw Exceptie("Numele utilizatorului trebuie sa aiba minim un caracter");
        this->numeUtilizator = nume_utilizator;
    }

    void setNume(string const& Nume) {
        if (Nume.empty())
            throw Exceptie("Numele trebuie sa aiba minim un caracter");
        this->nume = Nume;
    }

    void setEmail(string const& Email) {
        if (Email.empty())
            throw Exceptie("Emailul trebuie sa aiba minim un caracter");
        this->email = Email;
    }

    void setParola(string const& Parola) {
        if (Parola.empty())
            throw Exceptie("Parola trebuie sa aiba minim un caracter");
        this->parola = Parola;
    }

    void setBuget(float const& Buget) {
        if (Buget < 0)
            throw Exceptie("Bugetul trebuie sa fie un numar pozitiv!\n");
        this->buget = Buget;
    }

    //constructor fara parametri
    Utilizator() {
        this->numeUtilizator = "-";
        this->nume = "-";
        this->email = "-";
        this->parola = "-";
        this->buget = 0.0;
    }

    //constructor cu parametri
    Utilizator(string const& numeUtilizator, string const& nume, string const& email, string const& parola,
               float const& buget) {
        if (numeUtilizator.empty())
            throw Exceptie("Numele utilizatorului trebuie sa aiba minim un caracter");
        if (nume.empty())
            throw Exceptie("Numele trebuie sa aiba minim un caracter");
        if (email.empty())
            throw Exceptie("Emailul trebuie sa aiba minim un caracter");
        if (parola.empty())
            throw Exceptie("Parola trebuie sa aiba minim un caracter");
        if (buget < 0)
            throw Exceptie("Bugetul trebuie sa fie un numar pozitiv!");
        this->numeUtilizator = numeUtilizator;
        this->nume = nume;
        this->email = email;
        this->parola = parola;
        this->buget = buget;
    }

    //constructor de copiere
    Utilizator(const Utilizator& u)  : enable_shared_from_this(u) {
        this->numeUtilizator = u.numeUtilizator;
        this->nume = u.nume;
        this->email = u.email;
        this->parola = u.parola;
        this->buget = u.buget;
    }

    //supraincarcare operator=
    Utilizator& operator=(const Utilizator& u) {
        this->numeUtilizator = u.numeUtilizator;
        this->nume = u.nume;
        this->email = u.email;
        this->parola = u.parola;
        this->buget = u.buget;
        return *this;
    }

    //destructor
    ~Utilizator() {
        utilizatori.erase(numeUtilizator);
    }

    friend istream& operator>>(istream& f, Utilizator& u) {
        f >> u.numeUtilizator >> u.nume >> u.email >> u.parola >> u.buget;
        return f;
    }

    friend ostream& operator<<(ostream& out, const shared_ptr<Utilizator>& u) {
        out << " NUME UTILIZATOR: " << u->getNumeUtilizator() << endl;
        out << " NUME SI PRENUME: " << u->getNume() << endl;
        out << " EMAIL: " << u->getEmail() << endl;
        out << " PAROLA: " << u->getParola() << endl;
        out << " BUGET: " << u->getBuget() << endl;
        return out;
    }

    friend class Magazin;
    friend class LogIn;
    friend class MagazinVanzator;
    friend class MagazinClient;

    static void initUtilizatori(const shared_ptr<Utilizator>& u) {
        utilizatori[u->getNumeUtilizator()] = u;
    }
};

map<string, shared_ptr<Utilizator>> Utilizator::utilizatori;

//Strategy Pattern
class PretStrategy {
public:
    virtual float calculeazaPretFinal(float pret) = 0;
    virtual ~PretStrategy() = default;
};

class PretStandardStrategy : public PretStrategy {
public:
    float calculeazaPretFinal(float pret) override {
        return pret;
    }
};

class PretReducereStrategy : public PretStrategy {
public:
    float calculeazaPretFinal(float pret) override {
        return pret >= 200 ? pret * 0.8f : pret;
    }
};

class Comanda {
private:
    int nrProduse;
    string numeUtilizator;
    float pretTotal;
    vector<int> produseComandate; //id-urile produselor comandate
    unique_ptr<PretStrategy> strategy;
public:

    Comanda() : nrProduse(0), numeUtilizator("-"), pretTotal(0), strategy(new PretStandardStrategy()) {
        this->produseComandate = {};
    }

    ~Comanda() = default;

    void setStrategy(unique_ptr<PretStrategy> s) {
        strategy = move(s);
    }

    float getPretTotal() {
        if (strategy) {
            return strategy->calculeazaPretFinal(pretTotal);
        }
        else {
            throw logic_error("Strategia de preț nu a fost setată.");
        }
    }

    void adaugaProdusInComanda(const shared_ptr<Produs>& produs) {
        if (produs) {
            produseComandate.push_back(produs->getID());
            pretTotal += produs->getPret();
        }
    }

    friend ostream& operator<<(ostream& out, Comanda* c) {
        out << " Numar de produse: " << c->nrProduse << endl;
        out << " Numele utilizatorului: " << c->numeUtilizator << endl;
        out << " Pret total: " << c->getPretTotal() << endl;
        return out;
    }

    friend class Magazin;
    friend class MagazinVanzator;
    friend class MagazinClient;

};

//Singleton Pattern
class LogIn {
private:
    static unique_ptr<LogIn> instance;
    string numeCont;
    LogIn() {}

public:
    static LogIn* getInstance() {
        if (instance == nullptr) {
            instance = unique_ptr<LogIn>(new LogIn());
        }
        return instance.get();
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
                cout << " V-ati conectat cu succes!\n";
            }
        }
        numeCont = numeIntrodus;
    }

    void creareCont(Utilizator contNou) {
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
        contNou.setNumeUtilizator(numeUtilizator);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DATE PERSONALE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " NUME: ";
        string numeFamilie;
        cin >> numeFamilie;
        cout << "PRENUME: ";
        string prenume;
        cin >> prenume;
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
        Utilizator::utilizatori[contNou.getNumeUtilizator()] = make_shared<Utilizator>(contNou);
        numeCont = numeUtilizator;
    }
    //getter nume cont
    string getNumeCont() {
        return numeCont;
    }
};

unique_ptr<LogIn> LogIn::instance = nullptr;

template<typename T>
class Catalog {
private:
    vector<T> produse;
public:
    void adaugaProdus(const T& produs) {
        produse.push_back(produs);
    }

    void stergeProdus(int id) {
        produse.erase(remove_if(produse.begin(), produse.end(),
                                [id](const T& produs) { return produs->getID() == id; }), produse.end());
    }

    void afisareCatalog() const {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CATALOG ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        printCollection(produse);
    }

    T cautaProdus(int id) {
        auto it = find_if(produse.begin(), produse.end(),
                          [id](const T& produs) { return produs->getID() == id; });
        if (it != produse.end()) {
            return *it;
        }
        return nullptr;
    }

    const vector<T>& getProduse() const {
        return produse;
    }
};

class Magazin {
protected:
    string numeCont;
    Catalog<shared_ptr<Produs>> catalog;
public:
    //polimorfism runtime(dinamic)
    virtual void cumpara() = 0;
    //setter
    void setNumeCont(string const& numecont) {
        this->numeCont = numecont;
    }

    void afisareCatalog() const {
        catalog.afisareCatalog();
    }

    void detaliiCont() {
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DETALII CONT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << Utilizator::utilizatori[this->numeCont];
    }

    void adaugaProdus(const shared_ptr<Produs>& produs) {
        catalog.adaugaProdus(produs);
    }

    shared_ptr<Produs> cautaProdus(int id) {
        return catalog.cautaProdus(id);
    }

    void stergeProdus(int id) {
        catalog.stergeProdus(id);
    }

    const Catalog<shared_ptr<Produs>>& getCatalog() const {
        return catalog;
    }

    //constructor fara parametri
    Magazin() {
        this->numeCont = "-";
    }

    virtual ~Magazin() {
        this->numeCont = "";
    }

    friend ostream& operator<<(ostream& out, Magazin* m) {
        out << " Numele utilizatorului conectat: " << m->numeCont;
        out << "\n Produse disponibile: \n";
        m->afisareCatalog();
        return out;
    }

    friend class Comanda;
};

class MagazinClient : virtual public Magazin {
public:
    MagazinClient() {
        this->numeCont = "-";
    }

    ~MagazinClient() override {
        this->numeCont = "";
    }
    //polimorfism runtime(dinamic)
    void cumpara() override {
        Comanda comanda;
        comanda.numeUtilizator = numeCont;
        afisareCatalog();
        cout << "\n ~~~~~~~~LA CUMPARATURILE DE PESTE 200 DE LEI BENEFICIATI DE 20% REDUCERE~~~~~~~~\n\n";
        cout << " CATE PRODUSE DORITI SA ACHIZITIONATI? ";
        cin >> comanda.nrProduse;
        cout << endl;
        if (comanda.nrProduse > 0) {
            int id;
            for (int i = 0; i < comanda.nrProduse; i++) {
                cout << " INTRODUCETI ID-UL PRODUSULUI PENTRU A IL ADAUGA IN COS: ";
                cin >> id;
                shared_ptr<Produs> produs = catalog.cautaProdus(id);
                if (produs != nullptr) {
                    comanda.adaugaProdusInComanda(produs);
                    cout << "PRODUS ADAUGAT IN COS!" << endl;
                }
                else {
                    cout << "ID INVALID! PRODUSUL NU EXISTA." << endl;
                }
            }
            if (comanda.pretTotal >= 200) {
                comanda.setStrategy(make_unique<PretReducereStrategy>());
            }
            else {
                comanda.setStrategy(make_unique<PretStandardStrategy>());
            }
            float suma = comanda.getPretTotal();
            if (Utilizator::utilizatori[numeCont]->getBuget() >= suma) {
                for (int idProdus : comanda.produseComandate) {
                    stergeProdus(idProdus);
                }
                cout << "\n TOTALUL DE PLATA: " << suma << endl;
                cout << " Comanda a fost efectuata." << endl;
                float bugetCurent = Utilizator::utilizatori[numeCont]->getBuget();
                bugetCurent -= suma;
                Utilizator::utilizatori[numeCont]->setBuget(bugetCurent);
            }
            else {
                cout << "\n FONDURI INSUFICIENTE. COMANDA NU A PUTUT FI PLASATA :( \n";
            }
        }

    }

};

class MagazinVanzator : virtual public Magazin {
public:
    MagazinVanzator() {
        this->numeCont = "-";
    }

    ~MagazinVanzator() override {
        this->numeCont = "";
    }
    //polimorfism runtime(dinamic)
    void cumpara() override {
        cout << endl << "Vanzatorul nu poate cumpara produse";
    }
    void adaugaProdus(const shared_ptr<Produs>& produsNou) {
        try
        {
            cout << "NUME PRODUS: ";
            string numeProdus;
            cin >> numeProdus;
            produsNou->setNumeProdus(numeProdus);
            cout << "CULOARE: ";
            string culoareProdus;
            cin >> culoareProdus;
            produsNou->setCuloare(culoareProdus);
            cout << "MARIME: ";
            string marimeProdus;
            cin >> marimeProdus;
            produsNou->setMarime(marimeProdus);
            cout << "PRET: ";
            float pretProdus;
            cin >> pretProdus;
            produsNou->setPret(pretProdus);
            catalog.adaugaProdus(produsNou);
            cout << "PRODUS ADAUGAT!\n";
        }
        catch (const Exceptie& e) {
            cerr << "Nu s-a putut adauga produsul: " << e.what() << endl;
        }
    }

};

class MagazinAdmin : virtual public MagazinVanzator, virtual public MagazinClient {
public:
    void cumpara() override {
        MagazinClient::cumpara();
    }
    MagazinAdmin() {
        this->numeCont = "-";
    }
    ~MagazinAdmin() override {
        this->numeCont = "";
    }
    void stergeProdus(int id) {
        catalog.stergeProdus(id);
    }
};

#endif
