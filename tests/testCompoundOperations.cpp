#include "doctest.h"
#include "../matrix.hpp"

TEST_CASE("Test Addition Compound"){
    SUBCASE("Addition of Different Sizes"){
        // adding 2 matrices of different sizes throws an error
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1+=mat2);
    }
    SUBCASE("Addition of Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = mat1.size() * i + j + 1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        }
        SquareMat expected = mat1+mat2; 

        // saving the address of mat1
        void *address = &mat1;

        // adds mat2 to mat1
        CHECK_NOTHROW(mat1+=mat2);

        // checks that the address didn't change
        CHECK(&mat1 == address);

        // checking the values in mat1 are equal to the expected values
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                CHECK(mat1[i][j] == expected[i][j]);
    }
}

TEST_CASE("Test Subtraction Compound"){
    SUBCASE("Subtraction of Different Sizes"){
        // subtracting 2 matrices of different sizes throws an error
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1-=mat2);
    }
    SUBCASE("Subtraction of Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = mat1.size() * i + j + 1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        }
        SquareMat expected = mat1-mat2;

        // saving the address of mat1
        void *address = &mat1;

        // subtracts mat2 from mat1
        CHECK_NOTHROW(mat1-=mat2);

        // checks that the address didn't change
        CHECK(&mat1 == address);

        // checking the values in mat1 are equal to the expected values
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                CHECK(mat1[i][j] == expected[i][j]);
    }
}

TEST_CASE("Test Matrix Multiplication Compound"){
    SUBCASE("Matrix Multiplication of Different Sizes"){
        // matrix multiplication of 2 matrices of different sizes throws an error
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1*=mat2);
    }
    SUBCASE("Matrix Multiplication of Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = mat1.size() * i + j + 1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        }
        SquareMat expected = mat1*mat2;

        // saving the address of mat1
        void *address = &mat1;

        // multiplies mat1 by mat2
        CHECK_NOTHROW(mat1*=mat2);

        // checks that the address didn't change
        CHECK(&mat1 == address);

        // checking the values in mat1 are equal to the expected values
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                CHECK(mat1[i][j] == expected[i][j]);
    }
}

TEST_CASE("Test Multiplication by a Scalar Compound"){
    SUBCASE("Multiplies by Zero"){
        SquareMat mat = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = mat.size() * i + j + 1;
            }
        }
        SquareMat expected = mat*0;

        // saving the address of mat
        void *address = &mat;

        // multiplies mat by 0
        CHECK_NOTHROW(mat*=0);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
    SUBCASE("Multiply by a Negative Scalar"){
        SquareMat mat = SquareMat(3);

        float scalar = -5;

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                int num = mat.size() * i + j + 1;
                mat[i][j] = num;
            }
        }
        SquareMat expected = mat*scalar;

        // saving the address of mat
        void *address = &mat;

        // multiplies mat by the scalar
        CHECK_NOTHROW(mat*=scalar);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
    SUBCASE("Multiply by a Positive Scalar"){
        SquareMat mat = SquareMat(3);

        float scalar = 5;

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                int num = mat.size() * i + j + 1;
                mat[i][j] = num;
            }
        }
        SquareMat expected = mat*scalar;

        // saving the address of mat
        void *address = &mat;

        // multiplies mat by the scalar
        CHECK_NOTHROW(mat*=scalar);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
}

TEST_CASE("Test Division by a Scalar Compound"){
    SUBCASE("Division by Zero"){
        SquareMat mat = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = mat.size() * i + j + 1;
            }
        }
        // division by zero is not allowed
        CHECK_THROWS(mat/=0);
    }
    SUBCASE("Division by a Negative Scalar"){
        SquareMat mat = SquareMat(3);

        float scalar = -5;

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                int num = mat.size() * i + j + 1;
                mat[i][j] = num;
            }
        }
        SquareMat expected = mat/scalar;

        // saving the address of mat
        void *address = &mat;

        // divides mat by the scalar
        CHECK_NOTHROW(mat/=scalar);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
    SUBCASE("Division by a Positive Scalar"){
        SquareMat mat = SquareMat(3);

        float scalar = 5;

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                int num = mat.size() * i + j + 1;
                mat[i][j] = num;
            }
        }
        SquareMat expected = mat/scalar;

        // saving the address of mat
        void *address = &mat;

        // divides mat by the scalar
        CHECK_NOTHROW(mat/=scalar);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
}

TEST_CASE("Test Multiplication (%) Compound"){
    SUBCASE("Multiplication of Different Sizes"){
        // multiplication of 2 matrices of different sizes throws an error
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1%=mat2);
    }
    SUBCASE("Multiplication of Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = mat1.size() * i + j + 1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        }
        SquareMat expected = mat1%mat2;

        // saving the address of mat1
        void *address = &mat1;

        // multiplies mat1 by mat2
        CHECK_NOTHROW(mat1%=mat2);

        // checks that the address didn't change
        CHECK(&mat1 == address);

        // checking the values in mat1 are equal to the expected values
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                CHECK(mat1[i][j] == expected[i][j]);
    }
}

TEST_CASE("Test Modulo Compound"){
    SUBCASE("Modulo Zero"){
        SquareMat mat = SquareMat(3);

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = mat.size() * i + j + 1;
            }
        }
        // mosulo zero is not allowed
        CHECK_THROWS(mat%=0);
    }
    SUBCASE("Modulo of a Negative Scalar"){
        SquareMat mat = SquareMat(3);

        float scalar = -5;

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                int num = mat.size() * i + j + 1;
                mat[i][j] = num;
            }
        }
        SquareMat expected = mat%scalar;

        // saving the address of mat
        void *address = &mat;

        // modulo mat by the scalar
        CHECK_NOTHROW(mat%=scalar);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
    SUBCASE("Modulo of a Positive Scalar"){
        SquareMat mat = SquareMat(3);

        float scalar = 5;

        // setting values to the matrices
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                int num = mat.size() * i + j + 1;
                mat[i][j] = num;
            }
        }
        SquareMat expected = mat%scalar;

        // saving the address of mat
        void *address = &mat;

        // modulo mat by the scalar
        CHECK_NOTHROW(mat%=scalar);

        // checks that the address didn't change
        CHECK(&mat == address);

        // checking the values in mat are equal to the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == expected[i][j]);
    }
}