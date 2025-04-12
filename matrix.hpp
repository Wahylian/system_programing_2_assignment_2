#include "row.hpp"
#include <iostream>
class SquareMat{
    private:
    int **p_matrix; // a pointer to the matrix
    int n; // the size of the matrix

    public:
    // constructor
    SquareMat(int size); 

    // copy constructor
    SquareMat(const SquareMat& mat);

    // destructor
    ~SquareMat();

    #pragma region matrixOperations




    #pragma region arithmeticOperations
    // adds the other matrix to this matrix and returns their addition
    SquareMat operator+ (const SquareMat& other_matrix) const;

    // subtracts the other matrix from this matrix and returns their subtraction
    SquareMat operator- (const SquareMat& other_matrix) const;

    // multiplies this matrix by the other matrix and returns their multiplication
    SquareMat operator* (const SquareMat& other_matrix) const;

    // multiplies this matrix by a scalar
    friend SquareMat operator* (const SquareMat& matrix, double scalar);

    // mutliples value i,j in this matrix by value i,j in the other matrix
    SquareMat operator% (const SquareMat& matrix) const;

    // does a modulo operation on each of this matrix's values
    SquareMat operator% (int scalar) const;

    // divides this matrix by a scalar
    SquareMat operator/ (double scalar) const;

    // squares the matrix by itself n times
    SquareMat operator^ (int n) const;


    #pragma endregion



    

    #pragma region incs&Decs

    // prefix increment
    SquareMat& operator++ ();

    // postfix increment
    SquareMat operator++ (int dummy_flag_for_postfix_increment);

    // prefix decrement
    SquareMat& operator-- ();

    // postfix decrement
    SquareMat operator-- (int dummy_flag_for_postfix_decrement);

    #pragma endregion




    #pragma region matrixChanges

    // transposes the matrix;
    void operator~ ();

    // gets row i of the matrix
    MatrixRow operator[] (int i);

    #pragma endregion




    #pragma region compareOperations

    // returns true if the sum of values in this matrix is equal
    // to the sum of values in the other matrix, else false
    bool operator== (const SquareMat& other_matrix) const;

    // returns true if the sum of values in this matrix is not equal 
    // to the sum of balues in the other matrix, else false
    bool operator!= (const SquareMat& other_matrix) const;

    // returns true if the sum of values in this matrix is bigger or equal to 
    // the sum of values in the other matrix, else false
    bool operator>= (const SquareMat& other_matrix) const;

    // returns true if the sum of values in this matrix is smaller or equal to
    // the sum of values in the other matrix, else false
    bool operator<= (const SquareMat& other_matrix) const {return other_matrix >= *this;}

    // returns true if the sum of values in this matrix is bigger than
    // the sum of values in the other matrix, else false
    bool operator> (const SquareMat& other_matrix) const;

    // returns true if the sum of values in this matrix is smaller than
    // the sum of values in the other matrix, else false
    bool operator< (const SquareMat& other_matrix) const;

    #pragma endregion


    // calculates the determinant of the matrix
    double operator!() const;


    #pragma region combinedPlacement

    // adds other matrix to this matrix
    void operator+= (const SquareMat& other_matrix);

    // removes other matrix to this matrix
    void operator-= (const SquareMat& other_matrix);

    // multiplies this matrix by the other matrix
    void operator*= (const SquareMat& other_matrix);

    // multiples this matrix by a scalar
    void operator*= (double scalar);

    // multiplies value i,j in this matrix by value i,j in the other matrix
    void operator%= (const SquareMat& other_matrix);

    // does a modulo operation on each of the values in this matrix
    void operator%= (int scalar);

    #pragma endregion


    // prints the matrix in a logical way
    friend std::ostream& operator<< (std::ostream& output, const SquareMat& matrix);

    #pragma endregion
};