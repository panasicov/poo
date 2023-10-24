#include <iostream>
using namespace std;

struct Vector {
    int* elements;
    int size;
};

void initializare(Vector &v, int size) {
    v.size = size;
    v.elements = new int[size];
}

void elimina(Vector &v) {
    delete[] v.elements;
}

void resize(Vector &v, int new_size) {
    int* element_nou = new int[new_size];
    int minSize = (new_size < v.size) ? new_size : v.size;

    for (int i = 0; i < minSize; i++) {
        element_nou[i] = v.elements[i];
    }

    delete[] v.elements;
    v.elements = element_nou;
    v.size = new_size;
}

int &at(Vector &v, int index) {
    return v.elements[index];
}

int suma_elemente_pare(Vector &v) {
    int sum = 0;
    for (int i = 0; i < v.size; i++) {
        if (v.elements[i] % 2 == 0) {
            sum += v.elements[i];
        }
    }
    return sum;
}

int main() {
    int size1, size2;
    cout << "Introduceti dimensiunea primului vector: ";
    cin >> size1;

    Vector vec1, vec2;
    initializare(vec1, size1);

    cout << "Introduceti elementele primului vector: ";
    for (int i = 0; i < vec1.size; i++) {
        cin >> vec1.elements[i];
    }

    cout << "Introduceti dimensiunea celui de-al doilea vector: ";
    cin >> size2;

    initializare(vec2, size2);

    cout << "Introduceti elementele celui de-al doilea vector: ";
    for (int i = 0; i < vec2.size; i++) {
        cin >> vec2.elements[i];
    }

    if (vec1.size == vec2.size) {
        for (int i = 0; i < vec1.size; i++) {
            vec1.elements[i] += vec2.elements[i];
        }
        cout << "Rezultatul adunarii celor doi vectori: ";
        for (int i = 0; i < vec1.size; i++) {
            cout << vec1.elements[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Vectorii au dimensiuni diferite, nu pot fi adunați." << endl;
    }

    elimina(vec1);
    elimina(vec2);

    return 0;
}
