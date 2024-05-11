#include <iostream>
#include <list>
#include "clase.hpp"

using namespace std;

int main() {

    Produs p1("rochie", "neagra", "XS", 79);
    Produs p2("blugi", "albastri", "L", 120);
    Produs p3("bluza", "rosie", "M", 47);
    Produs p4("fusta", "verde", "S", 38);
    Produs p5("bluza", "mov", "XL", 40);
    Produs p6("pantaloni", "albi", "S", 89);
    Produs p7("palarie", "maro", "ONE-SIZE", 34);
    Haina p8("geaca", "alba", "M", 72, "denim");
    Produs* p9 = new Haina("tricou", "gri", "XS", 15, "bumbac");
    MagazinVanzator::puneProdusul(p9);

    Utilizator u1("deni", "mihaila denisa", "denisa.mihaila@s.unibuc.ro", "123", 420);
    Utilizator u2("andrei", "popa andrei", "andrei.popa@s.unibuc.ro", "parola", 357);
    Utilizator u3("alexia", "pascu alexia", "alexia.pascu@s.unibuc.ro", "zoo", 248);
    Utilizator u4("mircea", "popescu mircea", "mircea.popescu@s.unibuc.ro", "masini", 100);

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ VINTED ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << endl<<endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ TIP UTILIZATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " --> Apasati tasta 1, urmata de Enter, daca va logati ca si client " << endl;
    cout << " --> Apasati tasta 2, urmata de Enter, daca va logati ca si vanzator" << endl;
    cout << " --> ";
    int tip;
    cin >> tip;
    Magazin* magazin = nullptr;
    if(tip == 1)
        magazin = new MagazinClient();
    else if(tip == 2)
        magazin = new MagazinVanzator();

    if(magazin != nullptr) {
        LogIn login;
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ INREGISTRARE UTILIZATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << " --> Apasati tasta 1, urmata de Enter, daca aveti deja cont " << endl;
        cout << " --> Apasati tasta 2, urmata de Enter, pentru a va crea contul de utilizator " << endl;
        cout << " --> ";

        int input;
        cin >> input;

        Utilizator contNou;

        list<Produs *> produse; // retinem pointerii de produse intr-o lista pentru a-i sterge ulterior
        if (input == 1) {
            login.autentificare();
            magazin->setNumeCont(login.getNumeCont());
        } else if (input == 2) {
            login.creareCont(contNou);
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
                if(tip == 1) cout << " TIP UTILIZATOR: CLIENT" << endl;
                else if(tip == 2) cout << " TIP UTILIZATOR: VANZATOR" << endl;
            }
            else if (input == 2)
            {
                if(tip == 1) cout << "Nu aveti permisiunea sa adaugati produse";
                else
                {auto *p_nou = new Produs; // alocare dinamica pentru fiecare produs,
                produse.push_back(p_nou); // inseram pointerul in lista
                MagazinVanzator::adaugaProdus(p_nou);} // apelam metoda
            }
            else if (input == 3)
            {
                if(tip == 1) magazin->cumpara();
                else { magazin->afisareCatalog();
                    cout << endl << "Nu aveti permisiunea de a cumpara produse";}
            }
            else if (input == 4) break;

        } while (input != 4);

        // eliberam memoria pentru produsele create dinamic
        for (Produs *produs: produse) {
            delete produs;
        }
        delete magazin;
    }
    return 0;
}
