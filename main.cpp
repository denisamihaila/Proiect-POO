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
    static int currentID;
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
        this->id = currentID++;
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

        this->id = currentID++;
        produse[id] = this;
    }
    //constructor de copiere
    Produs(const Produs& p)
    {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = currentID++;
        produse[id] = this;
    }
    //supraincarcare operator=
    Produs operator=(const Produs& p)
    {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marime = p.marime;
        this->pret = p.pret;
        this->id = currentID++;
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
int Produs::currentID=0;
map <int, Produs*> Produs::produse;
class Utilizator {

};

class Comanda{

};


int main() {

    /*Produs p1("rochie", "negru", "XS", 57);
    cout<<p1.getNumeProdus()<<" "<<p1.getCuloare();*/
    return 0;
}
