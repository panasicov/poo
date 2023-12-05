#include <iostream>
#include <vector>

// Clasa Senzor
class Senzor {
protected:
    std::string unitateMasura;

public:
    // Constructor
    Senzor(const std::string& unitate) : unitateMasura(unitate) {}

    // Metoda pentru citirea datelor
    void citesteDate() {
        std::cout << "Introduceti valoarea pentru senzor (" << unitateMasura << "): ";
        std::cin >> valoare;
    }

    // Metoda pentru afisarea datelor
    void afiseazaDate() const {
        std::cout << "Valoare senzor: " << valoare << " " << unitateMasura << std::endl;
    }

private:
    double valoare;
};

// Clasa GeneratorValori pentru generarea de valori pentru senzori
class GeneratorValori {
public:
    // Metoda pentru generarea unei valori aleatoare
    double genereazaValoare() const {
        return rand() % 100 + 1; // Generare valoare între 1 și 100 (doar pentru exemplu)
    }
};

// Clasa DispozitivColectare
class DispozitivColectare {
private:
    std::vector<Senzor> senzori;

public:
    // Constructor
    DispozitivColectare() {
        // Adaugare senzori la dispozitiv
        senzori.push_back(Senzor("Temperatura"));
        senzori.push_back(Senzor("Umiditate"));
        senzori.push_back(Senzor("Viteza Vantului"));
    }

    // Metoda pentru citirea datelor de la senzori
    void citesteDate() {
        GeneratorValori generator;

        for (auto& senzor : senzori) {
            senzor.citesteDate(); // Citirea directă de la utilizator (pentru exemplu)
            // Daca doriti citirea valorilor generate aleatoriu:
            // senzor.setValoare(generator.genereazaValoare());
        }
    }

    // Metoda pentru afisarea datelor de la senzori
    void afiseazaDate() const {
        for (const auto& senzor : senzori) {
            senzor.afiseazaDate();
        }
    }
};

int main() {
    // Testare
    DispozitivColectare dispozitiv;

    std::cout << "Citire date pentru senzori:" << std::endl;
    dispozitiv.citesteDate();

    std::cout << std::endl << "Afisare date pentru senzori:" << std::endl;
    dispozitiv.afiseazaDate();

    return 0;
}
