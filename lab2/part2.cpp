#include <iostream>
#include <cstring>

class Matrix {
private:
    char* data;
    int rows;
    int cols;
    int errorCode;

public:
    // Constructor cu doi parametri pentru o matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        data = new char[rows * cols];
        if (data == nullptr) {
            errorCode = -1; // Cod de eroare pentru insuficiență de memorie
        } else {
            memset(data, 0, rows * cols * sizeof(char)); // Inițializare cu zero
        }
    }

    // Funcție membru pentru returnarea valorii unui element
    char getValue(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            errorCode = -2; // Cod de eroare pentru depășirea limitelor matricei
            return -1; // Valoare de eroare
        }
        return data[i * cols + j];
    }

    // Funcție membru pentru setarea valorii unui element
    void setValue(int i, int j, char value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            errorCode = -2; // Cod de eroare pentru depășirea limitelor matricei
            return;
        }
        data[i * cols + j] = value;
    }

    void display() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << static_cast<int>(data[i * cols + j]) << " "; // Afiseaza valoarea elementului
        }
        std::cout << std::endl;
        }
    }

    // Funcție pentru adunarea a două matrice
    Matrix add(Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            errorCode = -3; // Cod de eroare pentru dimensiuni incompatibile
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // Funcție pentru scăderea a două matrice
    Matrix subtract(Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            errorCode = -3; // Cod de eroare pentru dimensiuni incompatibile
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // Funcție pentru înmulțirea unei matrice cu alta
    Matrix multiply(Matrix &other) {
        if (cols != other.rows) {
            errorCode = -3; // Cod de eroare pentru dimensiuni incompatibile
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i * result.cols + j] += this->data[i * cols + k] * other.data[k * other.cols + j];
                }
            }
        }
        return result;
    }

    // Funcție pentru înmulțirea unei matrice cu un număr
    Matrix multiplyByScalar(int scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = this->data[i] * scalar;
        }
        return result;
    }

    // Funcție pentru a obține codul de eroare
    int getErrorCode() {
        return errorCode;
    }
};

int main() {
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);

    matrix1.setValue(0, 0, 1);
    matrix1.setValue(0, 1, 2);
    matrix1.setValue(1, 0, 3);
    matrix1.setValue(1, 1, 4);

    matrix2.setValue(0, 0, 5);
    matrix2.setValue(0, 1, 6);
    matrix2.setValue(1, 0, 7);
    matrix2.setValue(1, 1, 8);

    Matrix sum = matrix1.add(matrix2);
    sum.display();
    std::cout << "\n";

    Matrix difference = matrix1.subtract(matrix2);
    difference.display();
    std::cout << "\n";

    Matrix product = matrix1.multiply(matrix2);
    product.display();
    std::cout << "\n";

    Matrix scalarProduct = matrix1.multiplyByScalar(3);
    scalarProduct.display();
    std::cout << "\n";

    return 0;
}
