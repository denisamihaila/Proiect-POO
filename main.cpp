#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//un fel de Vinted doar cu haine pentru femei
class Produs {
private:
    string numeProdus;
    string culoare;
    vector<char> marimi; //XS, S, M, L, XL
    float pret;
    int stoc;
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
    vector<char> getMarimi()
    {
        return marimi;
    }
    float getPret()
    {
        return pret;
    }
    int getStoc()
    {
        return stoc;
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
    void setMarimi(vector<char> marimi)
    {
        if (marimi.size() > 0)
            this->marimi = marimi;
        else
            cout << "Produsul trebuie să aibă minim o mărime disponibilă" << endl;
    }
    void setPret(float pret)
    {
        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Prețul produsului nu poate fi un număr negativ" << endl;
    }
    void setStoc(int stoc)
    {
        if(stoc >= 0)
            this->stoc = stoc;
        else
            cout << "Stocul produsului nu poate fi un număr negativ" << endl;
    }
    //constructor fara parametri
    Produs()
    {
        this->numeProdus = "";
        this->culoare = "";
        this->marimi = {};
        this->pret = 0;
        this->stoc = 0;
    }
    //constructor cu parametri
    Produs(string numeProdus, string culoare, vector<char> marimi, float pret, int stoc)
    {
        if (numeProdus.size() > 0)
            this->numeProdus = numeProdus;
        else
            cout << "Numele produsului trebuie să aibă minim un caracter" << endl;

        if (culoare.size() > 0)
            this->culoare = culoare;
        else
            cout << "Culoarea produsului trebuie să aibă minim un caracter" << endl;

        if (marimi.size() > 0)
            this->marimi = marimi;
        else
            cout << "Produsul trebuie să aibă minim o mărime disponibilă" << endl;

        if (pret >= 0)
            this->pret = pret;
        else
            cout << "Prețul produsului nu poate fi un număr negativ" << endl;

        if(stoc >= 0)
            this->stoc = stoc;
        else
            cout << "Stocul produsului nu poate fi un număr negativ" << endl;
    }
    //constructor de copiere
    Produs(const Produs& p)
    {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marimi = p.marimi;
        this->pret = p.pret;
        this->stoc = p.stoc;
    }
    //supraincarcare operator =
    Produs operator=(const Produs& p)
    {
        this->numeProdus = p.numeProdus;
        this->culoare = p.culoare;
        this->marimi = p.marimi;
        this->pret = p.pret;
        this->stoc = p.stoc;
        return *this;
    }
    //destructor
    ~Produs()
    {}

    friend ifstream& operator>>(ifstream& f, Produs& p);

    friend ofstream& operator<<(ofstream& g, Produs& p)
    {
        g << p.getNumeProdus() << " " << p.getCuloare() << " ";
        for(auto& marime : p.getMarimi())
        {
            g << marime << " ";
        }
        g << p.getPret() << " " << p.getStoc() << endl;
        return g;
    }
};

int main() {

    return 0;
}
