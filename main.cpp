#include <iostream>
#include <list>
#include "clase.hpp"

using namespace std;

int main() {

    Catalog<shared_ptr<Produs>> catalog;
    auto p1 = make_shared<Produs>("rochie", "neagra", "XS", 79);
    auto p2 = make_shared<Produs>("blugi", "albastri", "L", 120);
    auto p3 = make_shared<Produs>("bluza", "rosie", "M", 47);
    auto p4 = make_shared<Produs>("fusta", "verde", "S", 38);
    auto p5 = make_shared<Produs>("bluza", "mov", "XL", 40);
    auto p6 = make_shared<Produs>("pantaloni", "albi", "S", 89);
    auto p7 = make_shared<Produs>("palarie", "maro", "ONE-SIZE", 34);
    auto p8 = make_shared<Haina>("geaca", "alba", "M", 72, "denim");

    catalog.adaugaProdus(p1);
    catalog.adaugaProdus(p2);
    catalog.adaugaProdus(p3);
    catalog.adaugaProdus(p4);
    catalog.adaugaProdus(p5);
    catalog.adaugaProdus(p6);
    catalog.adaugaProdus(p7);
    catalog.adaugaProdus(p8);

    Produs::initProduse(p1);
    Produs::initProduse(p2);
    Produs::initProduse(p3);
    Produs::initProduse(p4);
    Produs::initProduse(p5);
    Produs::initProduse(p6);
    Produs::initProduse(p7);
    Produs::initProduse(p8);

    ProdusFactory* hainaFactory = new HainaFactory();
    shared_ptr<Produs> haina = hainaFactory->createProdus("pulover", "mov", "L", 80);
    catalog.adaugaProdus(haina);
    Produs::initProduse(haina);

    //upcasting
    shared_ptr<Produs> p10 = make_shared<Haina>("tricou", "gri", "XS", 15, "bumbac");
    catalog.adaugaProdus(p10);
    Produs::initProduse(p10);

    auto u1 = make_shared<Utilizator>("deni", "mihaila denisa", "denisa.mihaila@s.unibuc.ro", "123", 420);
    auto u2 = make_shared<Utilizator>("andrei", "popa andrei", "andrei.popa@s.unibuc.ro", "parola", 357);
    auto u3 = make_shared<Utilizator>("alexia", "pascu alexia", "alexia.pascu@s.unibuc.ro", "zoo", 248);
    auto u4 = make_shared<Utilizator>("mircea", "popescu mircea", "mircea.popescu@s.unibuc.ro", "masini", 100);

    Utilizator::initUtilizatori(u1);
    Utilizator::initUtilizatori(u2);
    Utilizator::initUtilizatori(u3);
    Utilizator::initUtilizatori(u4);

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ VINTED ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << endl << endl;

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ TIP UTILIZATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " --> Apasati tasta 1, urmata de Enter, daca va logati ca si client " << endl;
    cout << " --> Apasati tasta 2, urmata de Enter, daca va logati ca si vanzator" << endl;
    cout << " --> ";
    int tip;
    cin >> tip;
    //upcasting
    unique_ptr<Magazin> magazin = nullptr;
    if (tip == 1)
        magazin = make_unique<MagazinClient>();
    else if (tip == 2)
        magazin = make_unique<MagazinVanzator>();

    if (magazin != nullptr) {
        for (const auto& produs : catalog.getProduse()) {
            magazin->adaugaProdus(produs);
        }

        LogIn* login = LogIn::getInstance();
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ INREGISTRARE UTILIZATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " --> Apasati tasta 1, urmata de Enter, daca aveti deja cont " << endl;
        cout << " --> Apasati tasta 2, urmata de Enter, pentru a va crea contul de utilizator " << endl;
        cout << " --> ";

        int input;
        cin >> input;

        Utilizator contNou;

        if (input == 1) {
            login->autentificare();
            magazin->setNumeCont(login->getNumeCont());
        }
        else if (input == 2) {
            login->creareCont(contNou);
            magazin->setNumeCont(contNou.getNumeUtilizator());
        }
        do {
            cout << endl;
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
            {
                magazin->detaliiCont();
                if (tip == 1) cout << " TIP UTILIZATOR: CLIENT" << endl;
                else if (tip == 2) cout << " TIP UTILIZATOR: VANZATOR" << endl;
            }
            else if (input == 2)
            {
                if (tip == 1) cout << "Nu aveti permisiunea sa adaugati produse";
                else if (tip == 2)
                {
                    auto p_nou = make_shared<Produs>();
                    magazin->adaugaProdus(p_nou);
                }
            }
            else if (input == 3)
            {
                if (tip == 1) magazin->cumpara();
                else { magazin->afisareCatalog();
                    cout << endl << "Nu aveti permisiunea de a cumpara produse"; }
            }
            else if (input == 4) break;

        } while (input != 4);

    }
    delete hainaFactory;
    return 0;
}
