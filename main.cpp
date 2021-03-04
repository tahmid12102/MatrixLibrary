#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


//Functions

/*Function takes user's operation choice as input and prompts user to enter dimensions of matrices, 
returning error if invalid dimensions are entered depeneding on selected operation.*/

void rowColSelector(int choice, int &rows1, int &cols1, int &rows2, int &cols2){
    //Addition & subtraction
    if (choice == 1 || choice == 2){
        label:
            cout << "Select number of rows and columns for matrix 1: " << endl;
            cout << "Rows of matrix 1: ";
            cin >> rows1;
            cout << "Columns of matrix 1: ";
            cin >> cols1;
            cout << "Select number of rows and columns for matrix 2: " << endl;
            cout << "Rows of matrix 2: ";
            cin >> rows2;
            cout << "Columns of matrix 2: ";
            cin >> cols2;
            if (rows1 != rows2 || cols1 != cols2){
                cout << "Invalid dimensions. Rows and columns of first matrix must equal second matrix." << endl;
                goto label;
            }
            if (rows1<1 || rows2<1 || cols1< 1 || cols2<1 || rows1>10 || rows2>10 || cols1>10 || cols2>10){
                cout << "Invalid dimensions. Rows and columns must be greater than 0 and less than or equal to 10." << endl;
                goto label;
            }
    //Multiplication
    } else if (choice == 3){
        label1:
            cout << "Select number of rows and columns for matrix 1: " << endl;
            cout << "Rows of matrix 1: ";
            cin >> rows1;
            cout << "Columns of matrix 1: ";
            cin >> cols1;
            cout << "Select number of rows and columns for matrix 2: " << endl;
            cout << "Rows of matrix 2: ";
            cin >> rows2;
            cout << "Columns of matrix 2: ";
            cin >> cols2;
            if (cols1 != rows2){
                cout << "Invalid dimensions. Columns of first matrix must equal rows of second matrix." << endl;
                goto label1;
            }
            if (rows1<1 || rows2<1 || cols1< 1 || cols2<1 || rows1>10 || rows2>10 || cols1>10 || cols2>10){
                cout << "Invalid dimensions. Rows and columns must be greater than 0 and less than or equal to 10." << endl;
                goto label1;
            }
    //Determinant
    } else if (choice == 4){
        label2:
            cout << "Select number of rows and columns for matrix: " << endl;
            cout << "Rows: ";
            cin >> rows1;
            cout << "Columns: ";
            cin >> cols1;
            if (rows1 != cols1){
                cout << "Invalid dimensions. Rows and columns must be equal to one another." << endl;
                goto label2;
            }
            if (rows1<1 || cols1< 1 || rows1>10 || cols1>10){
                cout << "Invalid dimensions. Rows and columns must be greater than 0 and less than or equal to 10." << endl;
                goto label2;
            }
    //Transpose
    } else {
        label3:
            cout << "Select number of rows and columns for matrix: " << endl;
            cout << "Rows: ";
            cin >> rows1;
            cout << "Columns: ";
            cin >> cols1;
            if (rows1<1 || cols1< 1 || rows1>10 || cols1>10){
                cout << "Invalid dimensions. Rows and columns must be greater than 0 and less than or equal to 10." << endl;
                goto label3;
            }
    }
}

int main(){

int choice;
int rows1;
int cols1;
int rows2;
int cols2;

label:
    //Simple menu to have user choose desired matrix operation to perform.
    cout << "0. Exit" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Determinant" << endl;
    cout << "5. Transpose" << endl;
    cout << "Choose a matrix operation: ";
    cin >> choice;

    //Exit
    if (choice == 0){
        return 0;
    //If the selected choice is out of bounds, an error is returned and prompts user to reselect.
    } else if (choice > 5 || choice < 0){
        cout << "Invalid choice. Try again." << endl;
        goto label;
    } else{
        //rowColSelector function used to prompt user to enter dimensions of matrices.
        rowColSelector(choice,rows1,cols1,rows2,cols2);
        switch(choice){
            //Addition
            case 1: {
                //2 matrices are created and prompts user to enter values.
                Matrix A(rows1,cols1);
                cout << "Enter values for first matrix: " << endl;
                cin >> A;
                cout << "The first matrix is: " << endl;
                cout << A;
                Matrix B(rows2,cols2);
                cout << "Enter values for second matrix: " << endl;
                cin >> B;
                cout << "The second matrix is: " << endl;
                cout << B;
                //Addition operation is performed and set equal to third matrix and printed to command line.
                Matrix C(rows1, cols1);
                C = A + B;
                cout << "Sum of two matrices is: " << endl;
                cout << C;
                //Destructor used on all 3 matrices to deallocate memory for future matrix operations.
                A.~Matrix();
                B.~Matrix();
                C.~Matrix();
                break;
            }
            //Subtraction
            case 2:{
                //Exactly the same as case 1 except difference of 2 matrices is performed.
                Matrix A(rows1,cols1);
                cout << "Enter values for first matrix: " << endl;
                cin >> A;
                cout << "The first matrix is: " << endl;
                cout << A;
                Matrix B(rows2,cols2);
                cout << "Enter values for second matrix: " << endl;
                cin >> B;
                cout << "The second matrix is: " << endl;
                cout << B;
                Matrix C = A - B;
                cout << "Difference of two matrices is: " << endl;
                cout << C;
                A.~Matrix();
                B.~Matrix();
                C.~Matrix();
                break;
            }
            //Multiplication
            case 3: {
                //Exactly the same as case 1 except product of 2 matrices is performed.
                Matrix A(rows1, cols1);
                cout << "Enter the values of the first matrix: " << endl;
                cin >> A;
                cout << " The first matrix is: " << endl;
                cout << A;
                Matrix B(rows2, cols2);
                cout << "Enter the values of the second matrix: " << endl;
                cin >> B;
                cout << " The second matrix is: " << endl;
                cout << B;
                Matrix C = A * B;
                cout << "The product of the two matrices is: " << endl;
                cout << C;
                A.~Matrix();
                B.~Matrix();
                C.~Matrix();
                break;
            }
            //Determinant
            case 4: {
                //Matrix is created and prompts user to enter values.
                Matrix A (rows1, cols1);
                cout << "Enter the values of the matrix: " << endl;
                cin >> A;
                cout << "The matrix is: " << endl;
                cout << A;
                //Determinant of entered matrix is performed and printed to command line.
                cout << "Determinant of matrix is: " << A.determinant() << endl;
                //Destructor used to deallocate memory for future matrix operations.
                A.~Matrix();
                break;
            }
            case 5: {
                //Exactly the same as case 4 except the transpose of the matrix is performed.
                Matrix A (rows1, cols1);
                cout << "Enter the values of the matrix: " << endl;
                cin >> A;
                cout << "The matrix is: \n" << A << endl;
                Matrix B (cols1, rows1);
                B.transpose(A);
                cout << "The transpose of the matrix is: \n" << B << endl;
                A.~Matrix();
                B.~Matrix();
                break;
            }
        }
    }
    //Prompts user to choose to do another operation. Otherwise, program exits with code 0.
    cout << "Would you like to do another operation? 1 for Yes, otherwise No: ";
    cin >> choice;
    if (choice == 1){
        cout << endl;
        goto label;
    } else {
        return 0;
    }
}
