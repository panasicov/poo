#include <iostream>
#include <cstring>

class String {
private:
    char* data;

public:
    // Constructor
    String(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Operator de atribuire
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Operator de adunare
    friend String operator+(const String& str1, const String& str2) {
        String result(str1);
        result += str2;
        return result;
    }

    // Operator de atribuire +=
    String& operator+=(const String& other) {
        char* temp = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        delete[] data;
        data = temp;
        return *this;
    }

    // Operator de comparare ==
    bool operator==(const String& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Operator de comparare !=
    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    // Operator de comparare <
    bool operator<(const String& other) const {
        return strcmp(data, other.data) < 0;
    }

    // Operator de comparare >
    bool operator>(const String& other) const {
        return strcmp(data, other.data) > 0;
    }

    // Operator de acces []
    char& operator[](int index) {
        return data[index];
    }

    // Operator de iesire <<
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    // Operator de intrare >>
    friend std::istream& operator>>(std::istream& is, String& str) {
        char buffer[1000];
        is >> buffer;
        str = buffer;
        return is;
    }
};

int main() {
    // Testare
    String s1 = "Hello";
    String s2 = "World";

    String s3 = s1 + s2;
    std::cout << "Concatenation: " << s3 << std::endl;

    String s4;
    std::cout << "Enter a string: ";
    std::cin >> s4;
    std::cout << "You entered: " << s4 << std::endl;

    if (s1 == s2) {
        std::cout << "s1 is equal to s2" << std::endl;
    } else {
        std::cout << "s1 is not equal to s2" << std::endl;
    }

    if (s1 < s2) {
        std::cout << "s1 is less than s2" << std::endl;
    } else {
        std::cout << "s1 is not less than s2" << std::endl;
    }

    s1[0] = 'h';
    std::cout << "Updated s1: " << s1 << std::endl;

    return 0;
}
