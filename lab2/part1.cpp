#include <iostream>
#include <cstring>

class Group {
private:
    char *groupCode; // codul grupei
    char *specialization; // specialitatea
    int numberOfStudents; // numărul de studenți
    char *curator; // curatorul grupei
    int studyYear; // anul de studii

public:
    // Constructori
    Group() {
        groupCode = nullptr;
        specialization = nullptr;
        numberOfStudents = 0;
        curator = nullptr;
        studyYear = 1; // Implicit, anul de studii începe de la 1
    }

    Group(const char *code, const char *spec, int numStudents, const char *cur, int year) {
        groupCode = new char[strlen(code) + 1];
        strcpy(groupCode, code);

        specialization = new char[strlen(spec) + 1];
        strcpy(specialization, spec);

        numberOfStudents = numStudents;

        curator = new char[strlen(cur) + 1];
        strcpy(curator, cur);

        studyYear = year;
    }

    // Funcția pentru schimbarea curatorului
    void changeCurator(const char *newCurator) {
        delete[] curator;
        curator = new char[strlen(newCurator) + 1];
        strcpy(curator, newCurator);
    }

    // Funcția pentru schimbarea numărului de studenți
    void changeNumberOfStudents(int newNumber) {
        numberOfStudents = newNumber;
    }

    // Funcția pentru setarea anului de studii
    void setStudyYear(int newYear) {
        if (newYear > 0 && newYear <= 5) {
            studyYear = newYear;
        } else {
            std::cout << "Anul de studii trebuie sa fie intre 1 si 5." << std::endl;
        }
    }

    void displayGroupInfo() {
        std::cout << "Codul grupei: " << groupCode << std::endl;
        std::cout << "Specialitatea: " << specialization << std::endl;
        std::cout << "Numarul de studenti: " << numberOfStudents << std::endl;
        std::cout << "Curatorul grupei: " << curator << std::endl;
        std::cout << "Anul de studii: " << studyYear << std::endl;
    }


    // Destructor
    ~Group() {
        delete[] groupCode;
        delete[] specialization;
        delete[] curator;
    }
};

int main() {
    Group myGroup("G1", "Informatica", 25, "Prof. Popescu", 2);

    myGroup.changeCurator("Prof. Ionescu");

    myGroup.changeNumberOfStudents(30);

    myGroup.setStudyYear(3);

    myGroup.displayGroupInfo();

    return 0;
}
