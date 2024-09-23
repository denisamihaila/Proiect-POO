# Magazin Online - Vinted
Un proiect foarte drag mie, inspirat din aplicația Vinted

## Descriere
Aceasta este o aplicație de tip magazin online, unde orice utilizator poate ori să își vândă hainele pe care nu le mai folosește, ori să cumpere hainele altor persoane.

## Funcționalități
- Te poți conecta cu un cont deja existent
- Îți poți crea un cont nou
- Te poți conecta ori ca și client, ori ca și vânzător, iar în funcție de asta ai acces la anumite funcționalități
- Poți să vezi detaliile contului tău: numele de utilizator, nume, prenume, email, parola, buget
- Magazinul are un stoc de produse cu următoarele atribute: numele produsului, culoarea, mărimea, prețul și un ID unic
- Poți adăuga oricâte produse noi în magazin, spre vânzare
- Poți vizualiza toate produsele disponibile în magazin
- Poți plasa oricâte comenzi, în limita bugetului
- Dacă nu ai un buget suficient pentru a cumpăra toate produsele pe care le-ai adăugat în coș, comanda nu va putea fi realizată
- Dacă ai un buget suficient, comanda va fi plasată și ți se va scădea din bugetul personal totalul de plată
- Poți ieși din aplicație apăsând o tastă anume
- La comenzile de peste 200 de lei, beneficiați de o reducere de 20%

## Implementare

Logica principală este conținută în fișierul `main.cpp`, care creează instanțe ale claselor `Produs` și `Haina`, gestionează autentificarea utilizatorilor prin `LogIn` și procesează interacțiunile clienților și ale vânzătorilor cu magazinul folosind polimorfism. Acțiunile specifice clienților includ navigarea articolelor, adăugarea lor în coș și achiziționarea. Acțiunile specifice vânzătorilor constau în adăugarea unor noi produse în catalog. Interfața bazată pe meniu îndrumă utilizatorul printr-o serie de opțiuni.

### Clase Utilizate
- `Produs`: Definirea atributelor și metodelor unui produs, inclusiv constructori, setteri, getteri și supraincărcarea operatorilor de I/O.
- `Haina`: Moștenește din `Produs`, reprezentând articole vestimentare cu un atribut adăugat pentru material.
- `Utilizator`: Gestionează datele utilizatorului cum ar fi numele de utilizator, informațiile personale, email-ul, parola și bugetul.
- `LogIn`: Se ocupă de procesele de logare și creare a conturilor utilizatorilor.
- `Magazin`, `MagazinClient`, `MagazinVanzator`: Clase abstracte și derivate ce încapsulează funcționalitățile diferite ale magazinului în funcție de tipul de utilizator (client sau vânzător).
- `MagazinAdmin`: Alcătuiește moștenirea în diamant, alături de cele 3 clase de mai sus. Vine cu o funcționalitate în plus - cea de a șterge produse. De asemenea, funcția cumpără() avea două implementări diferite în cele 2 clase pe care le moștenește direct, așa că a fost nevoie să se menționeze care implementare să fie apelată.

### Curățarea Memoriei
Aplicația alocă dinamic memorie pentru produse și utilizează pointeri inteligenți pentru eliberarea automată la terminarea executării, asigurând astfel absența scurgerilor de memorie.

### Am mai implementat: 
# Design patterns
Singleton: LogIn
Factory Method Pattern: ProdusFactory, HainaFactory
Strategy Pattern: PretStrategy, PretStandardStrategy, PretReducereStrategy
# Clasa sablon
class Catalog
# Functie sablon
void printCollection()
# STL
string, map, vector, list
# Functii din biblioteca algorithm
find, find_if, remove_if, move
# Smart Pointers
shared_ptr: produs, haina, catalog
unique_ptr<PretStrategy> strategy; unique_ptr<LogIn> instance
