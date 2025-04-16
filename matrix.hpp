#pragma once
#include <iostream>
#include "generalHelpers.hpp"
class SquareMat{
    private:

    // nested class of a row in a matrix, since this class will only be used inside the square matrix
    class MatrixRow{
        private:
        int n; // the length of the row
        float *row; // the pointer to the row
        
        private:
        // sets the values of the row
        void setValues(int n, float *row);

        // getting the pointer to the row
        float *getRow(){return row;}

        public:
        // default constructor
        MatrixRow();
    
        // constructor of row
        MatrixRow(int n, float *row);
    
        // returns a reference to the value at index j in the row
        float& operator[] (int j);
    
        // returns the value at index j in the row
        float operator[] (int j) const;

        // declaring SquareMat as a friend class to allow it to set the values of matrix row
        friend class SquareMat;
    };

    MatrixRow *p_matrix; // a pointer to the matrix
    int n; // the size of the matrix

    // creates a matrix without row i and column j
    SquareMat reduceMat(int i, int j) const;

    public:
    // constructor
    SquareMat(int size); 

    // copy constructor
    SquareMat(const SquareMat &matrix);

    // destructor
    ~SquareMat();

    #pragma region getters
    int size() const{return this->n;}
    #pragma endregion




    #pragma region matrixOperations




    #pragma region arithmeticOperations
    // adds the other matrix to this matrix and returns their addition
    friend SquareMat operator+ (const SquareMat &matrix, const SquareMat &other_matrix);

    // subtracts the other matrix from this matrix and returns their subtraction
    friend SquareMat operator- (const SquareMat &matrix, const SquareMat &other_matrix);

    // multiplies this matrix by the other matrix and returns their multiplication
    friend SquareMat operator* (const SquareMat &matrix, const SquareMat &other_matrix);

    // multiplies this matrix by a scalar
    friend SquareMat operator* (const SquareMat &matrix, float scalar);

    // multiplies a scalar by this matrix
    friend SquareMat operator* (float scalar, const SquareMat &matrix){return matrix*scalar;}

    // mutliples value i,j in this matrix by value i,j in the other matrix
    friend SquareMat operator% (const SquareMat &matrix, const SquareMat &other_matrix);

    // does a modulo operation on each of this matrix's values
    friend SquareMat operator% (const SquareMat &matrix, int scalar);

    // divides this matrix by a scalar
    friend SquareMat operator/ (const SquareMat &matrix, float scalar);

    // squares the matrix by itself n times
    friend SquareMat operator^ (const SquareMat &matrix, int n);


    #pragma endregion



    

    #pragma region incrs&Decrs

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

    // gets a reference to row i of the matrix
    MatrixRow& operator[] (int i);

    // gets a const reference to row i of the matrix
    const MatrixRow& operator[] (int i) const;

    // assignment operator
    SquareMat& operator= (const SquareMat &other_matrix);

    // forcing the operator= to only accept another matrix
    template <typename T>
    SquareMat& operator= (const T& val) = delete; // this is to stop a case where someone attempts to assign a non matrix value into a matrix

    #pragma endregion




    #pragma region compareOperations

    // returns true if the sum of values in this matrix is equal
    // to the sum of values in the other matrix, else false
    friend bool operator== (const SquareMat &matrix, const SquareMat &other_matrix);

    // returns true if the sum of values in this matrix is not equal 
    // to the sum of balues in the other matrix, else false
    friend bool operator!= (const SquareMat &matrix, const SquareMat &other_matrix);

    // returns true if the sum of values in this matrix is bigger or equal to 
    // the sum of values in the other matrix, else false
    friend bool operator>= (const SquareMat &matrix, const SquareMat &other_matrix);

    // returns true if the sum of values in this matrix is smaller or equal to
    // the sum of values in the other matrix, else false
    friend bool operator<= (const SquareMat &matrix, const SquareMat &other_matrix);

    // returns true if the sum of values in this matrix is bigger than
    // the sum of values in the other matrix, else false
    friend bool operator> (const SquareMat &matrix, const SquareMat &other_matrix);

    // returns true if the sum of values in this matrix is smaller than
    // the sum of values in the other matrix, else false
    friend bool operator< (const SquareMat &matrix, const SquareMat &other_matrix);

    #pragma endregion


    // calculates the determinant of the matrix
    double operator!() const;


    #pragma region compoundOperations

    // adds other matrix to this matrix
    void operator+= (const SquareMat &other_matrix);

    // removes other matrix to this matrix
    void operator-= (const SquareMat &other_matrix);

    // multiplies this matrix by the other matrix
    void operator*= (const SquareMat &other_matrix);

    // multiples this matrix by a scalar
    void operator*= (float scalar);

    // divides this matrix by a scalar
    void operator/= (float scalar);

    // multiplies value i,j in this matrix by value i,j in the other matrix
    void operator%= (const SquareMat &other_matrix);

    // does a modulo operation on each of the values in this matrix
    void operator%= (int scalar);

    #pragma endregion


    // prints the matrix in a logical way
    friend std::ostream& operator<< (std::ostream &output, const SquareMat &matrix);

    #pragma endregion
};