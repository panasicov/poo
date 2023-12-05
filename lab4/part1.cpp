#include <iostream>
#include <string>

// Clasa de bază abstractă Senzor
class Senzor {
protected:
    std::string unitateMasura;

public:
    // Constructor implicit
    Senzor() : unitateMasura("") {}

    // Constructor cu parametri
    Senzor(const std::string& unitate) : unitateMasura(unitate) {}

    // Destructor virtual
    virtual ~Senzor() {}

    // Metoda virtuală pură pentru citirea datelor despre starea mediului înconjurător
    virtual void citesteDate() = 0;

    // Metoda virtuală pură pentru afișarea datelor
    virtual void afiseazaDate() const = 0;

    // Supraîncărcarea fluxului de intrare
    friend std::istream& operator>>(std::istream& is, Senzor& senzor) {
        senzor.citesteDate();
        return is;
    }

    // Supraîncărcarea fluxului de ieșire
    friend std::ostream& operator<<(std::ostream& os, const Senzor& senzor) {
        os << "Unitate de masura: " << senzor.unitateMasura << std::endl;
        senzor.afiseazaDate();
        return os;
    }

    // Constructor de copiere
    Senzor(const Senzor& other) : unitateMasura(other.unitateMasura) {}

    // Operator de atribuire
    Senzor& operator=(const Senzor& other) {
        if (this != &other) {
            unitateMasura = other.unitateMasura;
        }
        return *this;
    }
};

// Clasa SenzorTemperatura derivată din Senzor
class SenzorTemperatura : public Senzor {
private:
    double temperatura; // Unitate de măsură: grade Celsius

public:
    // Constructor implicit
    SenzorTemperatura() : Senzor("Celsius"), temperatura(0.0) {}

    // Constructor cu parametri
    SenzorTemperatura(double temp) : Senzor("Celsius"), temperatura(temp) {}

    // Metoda pentru citirea datelor despre temperatura
    void citesteDate() override {
        std::cout << "Introduceti temperatura (Celsius): ";
        std::cin >> temperatura;
    }

    // Metoda pentru afișarea datelor despre temperatura
    void afiseazaDate() const override {
        std::cout << "Temperatura: " << temperatura << " " << unitateMasura << std::endl;
    }
};

// Clasa SenzorUmiditate derivată din Senzor
class SenzorUmiditate : public Senzor {
private:
    double umiditate; // Unitate de măsură: procente

public:
    // Constructor implicit
    SenzorUmiditate() : Senzor("Procente"), umiditate(0.0) {}

    // Constructor cu parametri
    SenzorUmiditate(double umid) : Senzor("Procente"), umiditate(umid) {}

    // Metoda pentru citirea datelor despre umiditate
    void citesteDate() override {
        std::cout << "Introduceti umiditatea (%): ";
        std::cin >> umiditate;
    }

    // Metoda pentru afișarea datelor despre umiditate
    void afiseazaDate() const override {
        std::cout << "Umiditate: " << umiditate << " " << unitateMasura << std::endl;
    }
};

// Clasa SenzorVitezaVantului derivată din Senzor
class SenzorVitezaVantului : public Senzor {
private:
    double vitezaVantului; // Unitate de măsură: metri pe secundă

public:
    // Constructor implicit
    SenzorVitezaVantului() : Senzor("m/s"), vitezaVantului(0.0) {}

    // Constructor cu parametri
    SenzorVitezaVantului(double viteza) : Senzor("m/s"), vitezaVantului(viteza) {}

    // Metoda pentru citirea datelor despre viteza vântului
    void citesteDate() override {
        std::cout << "Introduceti viteza vantului (m/s): ";
        std::cin >> vitezaVantului;
    }

    // Metoda pentru afișarea datelor despre viteza vântului
    void afiseazaDate() const override {
        std::cout << "Viteza vantului: " << vitezaVantului << " " << unitateMasura << std::endl;
    }
};

int main() {
    // Testare
    SenzorTemperatura senzorTemp;
    SenzorUmiditate senzorUmid;
    SenzorVitezaVantului senzorVant;

    std::cout << "Citire date pentru senzorul de temperatura:" << std::endl;
    std::cin >> senzorTemp;

    std::cout << "Citire date pentru senzorul de umiditate:" << std::endl;
    std::cin >> senzorUmid;

    std::cout << "Citire date pentru senzorul de viteza a vantului:" << std::endl;
    std::cin >> senzorVant;

    std::cout << std::endl << "Afisare date pentru senzorul de temperatura:" << std::endl;
    std::cout << senzorTemp << std::endl;

    std::cout << "Afisare date pentru senzorul de umiditate:" << std::endl;
    std::cout << senzorUmid << std::endl;

    std::cout << "Afisare date pentru senzorul de viteza a vantului:" << std::endl;
    std::cout << senzorVant << std::endl;

    return 0;
}
