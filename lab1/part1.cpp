#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Firma {
    string denumire;
    string formaOrganizare;
    string adresa;
    int anFondare;
};

void setareDate(Firma* firma) {
    cout << "Introduceti denumirea firmei: ";
    cin.ignore();
    getline(cin, firma->denumire);

    cout << "Introduceti forma de organizare: ";
    getline(cin, firma->formaOrganizare);

    cout << "Introduceti adresa: ";
    getline(cin, firma->adresa);

    cout << "Introduceti anul fondarii: ";
    cin >> firma->anFondare;

    cout << endl;
}

void modificareDate(Firma* firma) {
    int optiune;
    cout << "Alegeti ce camp doriti sa modificati:" << endl;
    cout << "1. Denumire" << endl;
    cout << "2. Forma de organizare" << endl;
    cout << "3. Adresa" << endl;
    cout << "4. Anul fondarii" << endl;
    cout << "Optiune: ";
    cin >> optiune;

    switch (optiune) {
        case 1:
            cout << "Introduceti noua denumire: ";
            cin.ignore();
            getline(cin, firma->denumire);
            break;
        case 2:
            cout << "Introduceti noua forma de organizare: ";
            cin.ignore();
            getline(cin, firma->formaOrganizare);
            break;
        case 3:
            cout << "Introduceti noua adresa: ";
            cin.ignore();
            getline(cin, firma->adresa);
            break;
        case 4:
            cout << "Introduceti noul an de fondare: ";
            cin >> firma->anFondare;
            break;
        default:
            cout << "Optiune invalida." << endl;
    }
}

bool comparareDupaAnFondare(const Firma& firma1, const Firma& firma2) {
    return firma1.anFondare < firma2.anFondare;
}

void cautaFirma(const vector<Firma>& firme, int criteriu) {
    if (criteriu < 1 || criteriu > 4) {
        cout << "Criteriu de cautare invalid." << endl;
        return;
    }

    string valoareCautata;
    cout << "Introduceti valoarea cautata: ";
    cin.ignore();
    getline(cin, valoareCautata);

    for (const Firma& firma : firme) {
        if (criteriu == 1 && firma.denumire == valoareCautata) {
            cout << "Firma gasita: " << endl;
            cout << "Denumire: " << firma.denumire << endl;
            cout << "Forma de organizare: " << firma.formaOrganizare << endl;
            cout << "Adresa: " << firma.adresa << endl;
            cout << "Anul fondarii: " << firma.anFondare << endl;
        } else if (criteriu == 2 && firma.formaOrganizare == valoareCautata) {
            cout << "Firma gasita: " << endl;
            cout << "Denumire: " << firma.denumire << endl;
            cout << "Forma de organizare: " << firma.formaOrganizare << endl;
            cout << "Adresa: " << firma.adresa << endl;
            cout << "Anul fondarii: " << firma.anFondare << endl;
        } else if (criteriu == 3 && firma.adresa == valoareCautata) {
            cout << "Firma gasita: " << endl;
            cout << "Denumire: " << firma.denumire << endl;
            cout << "Forma de organizare: " << firma.formaOrganizare << endl;
            cout << "Adresa: " << firma.adresa << endl;
            cout << "Anul fondarii: " << firma.anFondare << endl;
        } else if (criteriu == 4 && firma.anFondare == stoi(valoareCautata)) {
            cout << "Firma gasita: " << endl;
            cout << "Denumire: " << firma.denumire << endl;
            cout << "Forma de organizare: " << firma.formaOrganizare << endl;
            cout << "Adresa: " << firma.adresa << endl;
            cout << "Anul fondarii: " << firma.anFondare << endl;
        }
    }
}

int main() {
    int numarFirme;
    cout << "Cate firme aveti nevoie? ";
    cin >> numarFirme;

    vector<Firma> firme;

    for (int i = 0; i < numarFirme; i++) {
        Firma firma;
        setareDate(&firma);
        firme.push_back(firma);
    }

    int optiuneSortare;
    cout << "Doriti sa sortati firmele dupa anul fondarii? (1 - Da, 0 - Nu): ";
    cin >> optiuneSortare;

    if (optiuneSortare) {
        sort(firme.begin(), firme.end(), comparareDupaAnFondare);

        cout << "Firmele sortate dupa anul fondarii:" << endl;
        for (const Firma& firma : firme) {
            cout << "Denumire: " << firma.denumire << ", Anul fondarii: " << firma.anFondare << endl;
        }
    }

    int optiune;
    do {
        cout << "Doriti sa faceti modificari asupra firmelor? (1 - Da, 0 - Nu): ";
        cin >> optiune;

        if (optiune) {
            int indexFirma;
            cout << "Introduceti indexul firmei pe care doriti sa o modificati: ";
            cin >> indexFirma;

            if (indexFirma >= 0 && indexFirma < numarFirme) {
                modificareDate(&firme[indexFirma]);
            } else {
                cout << "Indexul invalid." << endl;
            }
        }
    } while (optiune);

    int optiuneCautare;
    do {
        cout << "Doriti sa cautati o firma? (1 - Da, 0 - Nu): ";
        cin >> optiuneCautare;

        if (optiuneCautare) {
            int criteriu;
            cout << "Alegeti criteriul de cautare:" << endl;
            cout << "1. Denumire" << endl;
            cout << "2. Forma de organizare" << endl;
            cout << "3. Adresa" << endl;
            cout << "4. Anul fondarii" << endl;
            cout << "Optiune: ";
            cin >> criteriu;
            cautaFirma(firme, criteriu);
        }
    } while (optiuneCautare);

    return 0;
}
