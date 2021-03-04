#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//header function//

class Matrix {
    friend istream& operator>>(istream& input, Matrix& matrix);
    friend ostream& operator<<(ostream& output,  Matrix& matrix); 
    friend Matrix operator+(Matrix A, Matrix B);
    friend Matrix operator-(Matrix A, Matrix B);
    friend Matrix operator*(Matrix A, Matrix B);

    private: 
        int rows;
        int cols;
        double **matrix;

    public:
        Matrix(int, int);
        Matrix();
        ~Matrix();
        void operator=(const Matrix&);
        void fillMatrix();
        void displayMatrix();
        void subtract(Matrix, Matrix);
        void add(Matrix, Matrix);
        void multiply(Matrix, Matrix);
        void transpose(Matrix);
        double determinant();

};

#endif