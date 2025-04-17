#include "doctest.h"
#include "../matrix.hpp"
using namespace Matrix;

TEST_CASE("Test Constructors"){
    SUBCASE("Constructor"){
        SUBCASE("Legal Construction"){
            SUBCASE("Constructing a matrix with a Positive Size"){
                CHECK_NOTHROW(SquareMat(3));
    
                SquareMat matrix = SquareMat(3);
                // check that the size of the matrix is 3
                CHECK(matrix.size() == 3);
            }
            SUBCASE("Constructing the 0 matrix"){
                CHECK_NOTHROW(SquareMat(0));

                SquareMat matrix = SquareMat(0);
                // check that the size of the matrix is 0
                CHECK(matrix.size() == 0);
            }
        }
        SUBCASE("Illegal Construction"){
            CHECK_THROWS(SquareMat(-4)); // a matrix of a negative size is not allowed
        }
        
    }
    SUBCASE("Copy Constructor"){
        SUBCASE("Positive Size"){
            // create a matrix
            SquareMat mat1 = SquareMat(3);

            // attempt to copy 
            CHECK_NOTHROW(SquareMat temp_mat(mat1));

            // copies the matrix
            SquareMat mat2 = SquareMat(mat1);
        
            // checks that they are stored in different addresses
            CHECK(&mat1 != &mat2);

            // checks that the matrices are the same size
            CHECK(mat1.size() == mat2.size());
        
        
            for(int i=0; i<mat1.size(); i++){
                // check that the rows are different objects
                CHECK(&mat1[i] != &mat2[i]);

                // checks that all the values in the matrices were copied over
                for(int j=0; j<mat1.size(); j++)
                    CHECK(mat1[i][j] == mat2[i][j]);
            }
        }
        SUBCASE("0 Size"){
            // create a matrix
            SquareMat mat1 = SquareMat(0);

            // attempt to copy 
            CHECK_NOTHROW(SquareMat temp_mat(mat1));

            // copies the matrix
            SquareMat mat2 = SquareMat(mat1);
        
            // checks that they are stored in different addresses
            CHECK(&mat1 != &mat2);

            // checks that the matrices are the same size
            CHECK(mat1.size() == mat2.size());
        
        
            for(int i=0; i<mat1.size(); i++){
                // check that the rows are different objects
                CHECK(&mat1[i] != &mat2[i]);

                // checks that all the values in the matrices were copied over
                for(int j=0; j<mat1.size(); j++)
                    CHECK(mat1[i][j] == mat2[i][j]);
            }
        }
        
    }
}

TEST_CASE("Test Accessing values in the matrix"){
    SUBCASE("Inserting a Value"){
        // create a matrix of size 3x3
        SquareMat mat = SquareMat(3);

        // checks all values are 0s
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                CHECK(mat[i][j] == 0);
            }
        }

        // inserting new values to the matrix
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = 3*i+j+1;
            }
        }

        // checking the new values are correct
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                CHECK(mat[i][j] == 3*i+j+1);
            }
        }
    }
    SUBCASE("Getting Values from a const Matrix"){
        // create a matrix of size 3x3
        SquareMat mat = SquareMat(3);
        // sets values of matrix
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = 3*i+j+1;
            }
        }

        // creates a const version of the matrix
        const SquareMat constMat = SquareMat(mat);
        for(int i=0; i<constMat.size(); i++){
            for(int j=0; j<constMat.size(); j++){
                CHECK(constMat[i][j] == 3*i+j+1); // check that the values are correct
                // as this throws a compilation error
                // the attempt to change the value at [i][j] will be written as a comment
                // constMat[i][j] = 42;
                // this shows that the value is not changeable
            }
        }

    }
}

TEST_CASE("Test Negative Matrix"){
    SUBCASE("Matrix of Positive Values"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);
        // sets values of the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                int num = 3*i +j +1;
                mat[i][j] = num;
                expected[i][j] = -num;
            }
        // gets the negative matrix
        SquareMat minusMat = -mat;
        // checks that the values are the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(minusMat[i][j] == expected[i][j]);

        // checks that the original wasn't changed
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == -expected[i][j]);
    }
    SUBCASE("Matrix of Negative Values"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);
        // sets values of the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                int num = 3*i +j +1;
                mat[i][j] = -num;
                expected[i][j] = num;
            }
        // gets the negative matrix
        SquareMat minusMat = -mat;
        // checks that the values are the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(minusMat[i][j] == expected[i][j]); 

        // checks that the original wasn't changed
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == -expected[i][j]);    
    }
    SUBCASE("Mixed Values Matrix"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);
        // sets values of the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                int num = 3*i +j +1;
                mat[i][j] = power(-1, i)*num;
                expected[i][j] = -power(-1, i)*num;
            }
        // gets the negative matrix
        SquareMat minusMat = -mat;
        // checks that the values are the expected values
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(minusMat[i][j] == expected[i][j]);

        // checks that the original wasn't changed
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == -expected[i][j]);
    }
}

TEST_CASE("Test Transpose"){
    SUBCASE("Positive Size"){
        SquareMat mat = SquareMat(3);
        // sets values to mat
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = 3*i+j+1;
            }
        }
    
        // creates a the expected transposed matrix
        SquareMat tam = SquareMat(3);
        for(int i=0; i<tam.size(); i++){
            for(int j=0; j<tam.size(); j++){
                tam[j][i] = 3*i+j+1;
            }
        }
    
        // transposes mat
        SquareMat transposed = ~mat;
    
        // checks that all the values in mat and tam are the same
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                CHECK(transposed[i][j] == tam[i][j]);
            }
        }
        
        // checks that the original wasn't changed
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == tam[j][i]); 
    }
    SUBCASE("Size 0"){
        SquareMat mat = SquareMat(0);
        // sets values to mat
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = 3*i+j+1;
            }
        }
    
        // creates a the expected transposed matrix
        SquareMat tam = SquareMat(3);
        for(int i=0; i<tam.size(); i++){
            for(int j=0; j<tam.size(); j++){
                tam[j][i] = 3*i+j+1;
            }
        }
    
        // transposes mat
        SquareMat transposed = ~mat;
    
        // checks that all the values in mat and tam are the same
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                CHECK(transposed[i][j] == tam[i][j]);
            }
        }

        // checks that the original wasn't changed
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == tam[j][i]); 
    }
}

TEST_CASE("Test Determinant"){
    SUBCASE("Positive Size"){
        SUBCASE("Identity Matrix Determinant"){
            SquareMat mat = SquareMat(3);
            // creating the identity matrix
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    if(i == j)
                        mat[i][j] = 1;
                    else
                        mat[i][j] = 0;
                }

            // the determinant of the identity matrix is equal to 1
            CHECK(!mat == 1);
        }
        SUBCASE("Triangle Matrix"){ 
            SUBCASE("Top Triangle Matrix"){
                SquareMat mat = SquareMat(3);
                int num = 1;

                // creating a top triangle matrix
                for(int i=0; i<mat.size(); i++){
                    for(int j=0; j<mat.size(); j++){
                        if(i <= j){
                            if(i == j)
                                num *= mat.size() * i + j + 1;
                            mat[i][j] = mat.size() * i + j + 1;
                        }
                        else
                            mat[i][j] = 0;
                    }
                }

                // the determinant of triangle matrix is equal to the multiplication to the values on the diagonal
                CHECK(!mat == num);
            }
            SUBCASE("Bottom Triangle Matrix"){
                SquareMat mat = SquareMat(3);
                int num = 1;

                // creating a top triangle matrix
                for(int i=0; i<mat.size(); i++){
                    for(int j=0; j<mat.size(); j++){
                        if(i >= j){
                            if(i == j)
                                num *= mat.size() * i + j + 1;
                            mat[i][j] = mat.size() * i + j + 1;
                        }
                        else
                            mat[i][j] = 0;
                    }
                }

                // the determinant of triangle matrix is equal to the multiplication to the values on the diagonal
                CHECK(!mat == num);
            }
        }
        SUBCASE("An Invertable Matrix"){
            SquareMat mat = SquareMat(3);
            // setting the values for the matrix
            mat[0][0] = 2;
            mat[0][1] = 1;
            mat[0][2] = 3;
            mat[1][0] = 0;
            mat[1][1] = -1;
            mat[1][2] = 4;
            mat[2][0] = 5;
            mat[2][1] = 2;
            mat[2][2] = 1;

            // mat is an invertable matrix and it's determinant is therfore not equal to 0
            // it is equal to (in this case 17)
            CHECK(!mat == 17);
        }
        SUBCASE("A Non-Invertable Matrix"){
            SquareMat mat = SquareMat(3);
            // setting the values for the matrix
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++)
                    mat[i][j] = mat.size() * i + j + 1;
            
            // this matrix is not invertable and so it's determinant is equal to 0
            CHECK(!mat == 0);
        }
    }
    SUBCASE("0 Size"){
        SquareMat mat = SquareMat(0);
        // the determinant of a size 0 matrix is 0
        CHECK(!mat == 0);
    }
}

TEST_CASE("Test Print"){
    SUBCASE("Positive Size"){
        // this is a test to show that the matrix is printed out correctly
        SUBCASE("print initial matrix"){
            SquareMat mat = SquareMat(3);
            std::cout << "intialized matrix:" << std::endl;
            std::cout << mat;
        }

        SUBCASE("print changed matrix"){
            SquareMat mat = SquareMat(3);
            // sets values to mat
            for(int i=0; i<mat.size(); i++){
                for(int j=0; j<mat.size(); j++){
                    mat[i][j] = 3*i+j+1;
                }
            }
            std::cout << "changed matrix:" << std::endl;
            std::cout << mat;
        }
    }
    SUBCASE("0 Size"){
        SquareMat mat = SquareMat(0);
        std::cout << "0 sized matrix:" << std::endl;
        std::cout << mat;
    }

}