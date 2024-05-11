#include <iostream>
#include <list>
#include "clase.hpp"

using namespace std;



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

    list<Produs*> produse; // retinem pointerii de produse intr-o lista pentru a-i sterge ulterior
    if (input == 1)
        magazin.autentificare();
    else if (input == 2) {
        Magazin::creareCont(contNou);
        magazin.setNumeCont(contNou.getNumeUtilizator());
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
            magazin.detaliiCont();
        else if (input == 2) {
            Produs *p_nou = new Produs; // alocare dinamica pentru fiecare produs,
            produse.push_back(p_nou); // inseram pointerul in lista
            Magazin::adaugaProdus(p_nou); // apelam metoda
        } else if (input == 3)
            magazin.cumpara();
        else if (input == 4) break;
    } while (input != 4);

    // eliberam memoria pentru produsele create dinamic
    for (Produs *produs : produse) {
        if (produs != NULL)
            delete produs;
    }
    return 0;
}
