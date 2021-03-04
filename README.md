## Abstract

This project is a matrix library that includes the following operations: addition, subtraction, multiplication, determinant, and transpose. The project makes use of many programming concepts such as nested loops, 2D arrays, dynamic memory allocation, classes and objects, and operator overloading. A header file is used for declarations and a makefile to compile/recompile the code. There are two main code files: matrix.cpp and main.cpp.  matrix.cpp contains constructors, destructors, methods, and operator overloads of the matrix library. main.cpp contains the main method to call matrix.cpp's constructors/destructors and methods to allow the user to perform matrix operations from the command line using the matrix library.

## API

### matrix.cpp

**Matrix(int int)** - Constructor with 2 parameters, number of rows and columns.

**Matrix()** - Constructor with 0 parameters.

**~Matrix();** - Destructor to deallocate memory used by 2d array.

**void fillMatrix()** - Prompts user to enter values for 2d array.

**void displayMatrix()** - Prints 2d array to command line.

**void subtract(Matrix, Matrix)** - Computes difference between two input matrix parameters.

**void add(Matrix, Matrix)** - Computes sum between two input matrix parameters.

**void multiply(Matrix, Matrix)** - Computes product between two input matrix parameters.

**void transpose(Matrix)** - Computes transpose of input matrix parameter.

**double determinant()** - Computes determinant of matrix.

**istream& operator>>(istream& input, Matrix& matrix)** - Input stream operator overload.

**ostream& operator<<(ostream& output,  Matrix& matrix)** - Output stream operator overload.

**void operator=(const Matrix&)** - Assignment operator overload.

**Matrix operator-(Matrix, Matrix)** - Subtraction operator overload.

**Matrix operator+(Matrix, Matrix)** - Addition operator overload.

**Matrix operator*(Matrix, Matrix)** - Multiplication operator overload.

### main.cpp

**void rowColSelector(int, int&, int&, int&, int&)** - Takes user's operation choice as an input parameter and prompts user to enter dimensions of matrices, returning error if invalid dimensions are entered depending on selected operation.

**int main()** - Main method to call matrix.cpp's constructors/destructors and methods to allow user to perform matrix operations from command line using matrix library.

## Comments/Potential Improvements

Improvements include removing the 10 row/column limitation upon the user along with updating the matrix multiplication operation from the slower O(n^3) brute force algorithm to Strassen's O(n^2.8) algorithm. Adding an inverse operation would further expand the library.
