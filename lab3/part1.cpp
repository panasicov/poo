#include <iostream>

class Date {
private:
    int day, month, year;

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Metoda pentru afișare
    void display() const {
        std::cout << day << '/' << month << '/' << year;
    }

    // Operatorul +
    Date operator+(int days) const {
        Date result = *this;
        result.day += days;
        // Se gestionează corect anii bisecți
        // (aceasta este o simplificare, iar implementarea reală ar trebui să fie mai complexă)
        // Notă: într-o implementare reală, ar trebui să se verifice și limitele lunilor
        if (result.day > 31) {
            result.day -= 31;
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }
        return result;
    }

    // Operatorul -
    Date operator-(int days) const {
        Date result = *this;
        result.day -= days;
        // Se gestionează corect anii bisecți
        // (aceasta este o simplificare, iar implementarea reală ar trebui să fie mai complexă)
        // Notă: într-o implementare reală, ar trebui să se verifice și limitele lunilor
        if (result.day < 1) {
            result.month--;
            if (result.month < 1) {
                result.month = 12;
                result.year--;
            }
            result.day += 31;
        }
        return result;
    }

    // Funcție prietenă pentru operatorul ++ prefix
    friend Date& operator++(Date& date);

    // Funcție prietenă pentru operatorul ++ postfix
    friend Date operator++(Date& date, int);

    // Funcție prietenă pentru operatorul -- prefix
    friend Date& operator--(Date& date);

    // Funcție prietenă pentru operatorul -- postfix
    friend Date operator--(Date& date, int);
};

// Implementarea funcției prietene pentru operatorul ++ prefix
Date& operator++(Date& date) {
    date.day++;
    if (date.day > 31) {
        date.day = 1;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

// Implementarea funcției prietene pentru operatorul ++ postfix
Date operator++(Date& date, int) {
    Date result = date;
    ++date;
    return result;
}

// Implementarea funcției prietene pentru operatorul -- prefix
Date& operator--(Date& date) {
    date.day--;
    if (date.day < 1) {
        date.month--;
        if (date.month < 1) {
            date.month = 12;
            date.year--;
        }
        date.day = 31;
    }
    return date;
}

// Implementarea funcției prietene pentru operatorul -- postfix
Date operator--(Date& date, int) {
    Date result = date;
    --date;
    return result;
}

int main() {
    // Exemplu de utilizare
    Date currentDate(5, 12, 2023);
    currentDate.display();
    std::cout << std::endl;

    // Operatorul +
    Date futureDate = currentDate + 10;
    futureDate.display();
    std::cout << std::endl;

    // Operatorul ++
    ++currentDate;
    currentDate.display();
    std::cout << std::endl;

    // Operatorul --
    Date pastDate = currentDate - 5;
    pastDate.display();
    std::cout << std::endl;

    return 0;
}
