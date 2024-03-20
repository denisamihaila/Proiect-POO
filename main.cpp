#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

//un fel de Vinted doar cu haine pentru femei
class Produs {
private:
    string numeProdus;
    string culoare;
    string marime; //XS, S, M, L, XL
    float pret;
    int id; //unic pentru fiecare produs
    static int IDprodus;
    static map <int, Produs*> produse;
public:
    //getteri
    string getNumeProdus()
    {
        return numeProdus;
    }
    string getCuloare()
    {
        return culoare;
    }
    string getMarime()
    {
        return marime;
    }
    float getPret()
    {
        return pret;
    }
    int getID()
    {
        return id;
    }
    //setteri
    void setNumeProdus(string numeProdus)
    {
        if (numeProdus.size() > 0)
            this->numeProdus = numeProdus;
        else
            cout << "Numele produsului trebuie să aibă minim un caracter" << endl;
    }
    void setCuloare(string culoare)
    {
        if (culoare.size() > 0)
            this->culoare = culoare;
        else
            cout << "Culoarea produsului trebuie să aibă minim un caracter" << endl;
    }
    void setMarime(string marime)
    {
        if (marime.size() > 0)
            this->marime = marime;
        else
            cout << "Produsul trebuie să aibă o mărime disponibilă" << endl;
    }
    void setPret(float pret)
    {
        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Prețul produsului nu poate fi un număr negativ" << endl;
    }
    //constructor fara parametri
    Produs()
    {
        this->numeProdus = "-";
        this->culoare = "-";
        this->marime = "-";
        this->pret = 0;
        this->id = IDprodus++;
        produse[id] = this;
    }
    //constructor cu parametri
    Produs(string numeProdus, string culoare, string marime, float pret)
    {
        if (numeProdus.size() > 0)
            this->numeProdus = numeProdus;
        else
            cout << "Numele produsului trebuie să aibă minim un caracter" << endl;

        if (culoare.size() > 0)
            this->culoare = culoare;
        else
            cout << "Culoarea produsului trebuie să aibă minim un caracter" << endl;

        if (marime.size() > 0)
            this->marime = marime;
        else
            cout << "Produsul trebuie să aibă minim o mărime disponibilă" << endl;

        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Prețul produsului nu poate fi un număr negativ" << endl;

        this->id = IDprodus++;
        produse[id] = this;
    }
    //constructor de copiere
    Produs(const Produs& p)
    {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = IDprodus++;
        produse[id] = this;
    }
    //supraincarcare operator=
    Produs operator=(const Produs& p)
    {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = IDprodus++;
        produse[id] = this;
        return *this;
    }
    //destructor
    ~Produs()
    {
        produse.erase(id);
    }

    friend istream& operator>>(istream& f, Produs& p)
    {
        f >> p.numeProdus >> p.culoare >> p.marime >> p.pret;
        return f;
    }

    friend ostream& operator<<(ostream& g, Produs& p)
    {
        g << p.getNumeProdus() << " " << p.getCuloare() << " " << p.getMarime() << p.getPret() << " " << endl;
        return g;
    }
    static map <int, Produs*> obtineProdusele() {
        return produse;
    }
};

int Produs::IDprodus=0;
map <int, Produs*> Produs::produse;

class Utilizator {
    string numeUtilizator;
    string email;
    string parola;
    int id; //unic pentru fiecare utilizator
    static int IDutilizator;
    static map<int, Utilizator*> utilizatori;

public:
    //getteri
    string getNumeUtilizator()
    {
        return numeUtilizator;
    }
    string getEmail()
    {
        return email;
    }
    string getParola()
    {
        return parola;
    }
    int getID()
    {
        return id;
    }
    //setteri
    void setNumeUtilizator(string numeUtilizator)
    {
        if(numeUtilizator.size() > 0)
            this->numeUtilizator = numeUtilizator;
        else
            cout << "Numele utilizatorului trebuie să aibă minim un caracter" << endl;
    }
    void setEmail(string email)
    {
        if(email.size() > 0)
            this->email = email;
        else
            cout << "Emailul trebuie să aibă minim un caracter" << endl;
    }
    void setParola(string parola)
    {
        if(parola.size() > 0)
            this->parola = parola;
        else
            cout << "Parola trebuie să aibă minim un caracter" << endl;
    }
    //constructor fara parametri
    Utilizator()
    {
        this->numeUtilizator = "-";
        this->email = "-";
        this->parola = "-";
        this->id = IDutilizator++;
        utilizatori[id] = this;
    }
    //constructor cu parametri
    Utilizator(string numeUtilizator, string email, string parola)
    {
        if(numeUtilizator.size() > 0)
            this->numeUtilizator = numeUtilizator;
        else
            cout << "Numele utilizatorului trebuie să aibă minim un caracter" << endl;

        if(email.size() > 0)
            this->email = email;
        else
            cout << "Emailul trebuie să aibă minim un caracter" << endl;

        if(parola.size() > 0)
            this->parola = parola;
        else
            cout << "Parola trebuie să aibă minim un caracter" << endl;

        this->id = IDutilizator++;
        utilizatori[id] = this;
    }
    //constructor de copiere
    Utilizator(const Utilizator& u)
    {
        this->numeUtilizator = u.numeUtilizator;
        this->email = u.email;
        this->parola = u.parola;
        this->id = IDutilizator++;
        utilizatori[id] = this;
    }
    //supraincarcare operator=
    Utilizator operator=(const Utilizator& u)
    {
        this->numeUtilizator = u.numeUtilizator;
        this->email = u.email;
        this->parola = u.parola;
        this->id = IDutilizator++;
        utilizatori[id] = this;
        return *this;
    }
    //destructor
    ~Utilizator()
    {
        utilizatori.erase(id); //posibil sa fie nevoie sa pun this->id;
    }
    static map<int, Utilizator*> obtineUtilizatorii() {
        return utilizatori;
    }
    friend istream& operator>>(istream& f, Utilizator& u)
    {
        f >> u.numeUtilizator >> u.email >> u.parola;
        return f;
    }
};
int Utilizator::IDutilizator=0;
map<int, Utilizator*> utilizatori;
class Comanda{

};

class Inceput{
    //daca introducem 0, vrem sa adaugam produse
    //daca introducem 1, vrem sa cumparam produse
};
int main() {


    return 0;
}
