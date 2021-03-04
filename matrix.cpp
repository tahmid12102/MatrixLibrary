#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Constructors

Matrix::Matrix(int r, int c){
    rows = r;
    cols = c;
    matrix = new double * [rows];
    for (int i = 0; i < rows; i++){
        matrix[i] = new double [cols];
    }
}

Matrix::Matrix(){
    rows = 0;
    cols = 0;
}

//Destructor

Matrix::~Matrix(){
    for (int i = 0; i < rows; i++){
        if (matrix[i]){
            delete [] matrix[i];
            matrix[i] = NULL;  
        }
    }
}

//Assignment Operator Overload

void Matrix::operator=(const Matrix &m){
    rows = m.rows;
    cols = m.cols;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

//Matrix Functions

//Nested loop to fill matrix values.
void Matrix::fillMatrix(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << "Enter value for (" << i << "," << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

//Nested loop to print matrix to command line.
void Matrix::displayMatrix(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << setw(5) <<  matrix[i][j];
        }
    cout << endl;
    }
}

//Nested loop to computer difference between two matrices taken as parameters.
void Matrix::subtract(Matrix A, Matrix B){
    for (int i = 0; i < A.rows; i++){
        for (int j = 0; j < A.cols; j++){
            matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }
    }
}

//Nested loop to compute sum between two matrices taken as parameters.
void Matrix::add(Matrix A, Matrix B){
    for (int i = 0; i < A.rows; i++){
        for (int j = 0; j < A.cols; j++){
            matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }
}

//Triple nested loop to compute product between two matrices taken as parameters.
void Matrix::multiply(Matrix A, Matrix B){
    for (int i = 0; i < A.rows; i++){
        for (int j = 0; j < B.cols; j++){
            for (int k = 0; k < A.cols; k++){
                matrix[i][j] = matrix[i][j] + (A.matrix[i][k] * B.matrix[k][j]);
            }
        }
    }
}

//Nested loop to compute transpose of a matrix taken as a parameter.
void Matrix::transpose(Matrix A){
    for (int i = 0; i < A.rows; i++){
        for (int j = 0; j < A.cols; j++){
            matrix[j][i] = A.matrix[i][j];
        }
    }
}

//Nested loops and recursion used to computer determinant of a matrix.
double Matrix::determinant(){
    double det = 0.0;
    int dim = rows;
    Matrix A(dim-1,dim-1);
    

    if (dim == 2) { //2x2 case
        return ((matrix[0][0] * matrix [1][1]) - (matrix[0][1] * matrix [1][0]));
    }
    else { // Non 2x2 case
        for (int c = 0; c < dim; c++)
        {
            int subi = 0; //submatrix's i value
            for (int i = 1; i < dim; i++)
            {
                int subj = 0; //submatrix's j value
                for (int j = 0; j < dim; j++)
                {
                    if (j == c){
                        continue;
                    }
                    A.matrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, c) * matrix[0][c] * A.determinant()); //Recursive function call until 2x2 case is reached.
        }
    }
    //Destructor to deallocate memory before returning determinant.
    A.~Matrix();
    return det; 
}


//Matrix Operator Overloads

//Input and output stream operator overloads for matrix class objects.
istream& operator>>(istream& input, Matrix& matrix) {

    matrix.fillMatrix();

    return input;
}

ostream& operator<<(ostream& output,  Matrix& matrix) {

    matrix.displayMatrix();

    return output;
}

//Addition, subtraction, and mulitplication operator overload for matrix class objects.
Matrix operator-(Matrix A, Matrix B){
    Matrix C(A.rows,B.cols);
    C.subtract(A,B);
    return C;
}

Matrix operator+(Matrix A, Matrix B){
    Matrix C(A.rows, B.cols);
    C.add(A,B);
    return C;
}

Matrix operator*(Matrix A, Matrix B){
    Matrix C(A.rows, B.cols);
    C.multiply(A,B);
    return C;

}