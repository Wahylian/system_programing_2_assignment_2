#include "doctest.h"
#include "../matrix.hpp"
using namespace Matrix;

TEST_CASE("Test Addition"){
    SUBCASE("Test Valid Addition"){
        SUBCASE("Only Positive Values"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);
            SquareMat expected = SquareMat(3);
    
            // adds values to mat1 and mat2
            for(int i=0; i < mat1.size(); i++){
                for(int j=0; j < mat1.size(); j++){
                    int num = 3*i+j+1;
    
                    // add linear values to mat1 
                    mat1[i][j] = num;
                    // add square values to mat2
                    mat2[i][j] = num*num;
    
                    // setting the expected value
                    expected[i][j] = num*(1 + num);
                }
            }
    
            // checks that the addition of mat1 and mat2 is not throwing errors
            CHECK_NOTHROW(mat1+mat2);
    
            SquareMat addition = mat1 + mat2;
            // checks that the addition is the expected size
            CHECK(addition.size() == expected.size());
    
            // checks that the values in addition are the expected values
            for(int i=0; i<addition.size(); i++){
                for(int j=0; j<addition.size(); j++){
                    CHECK(addition[i][j] == expected[i][j]);
                }
            }
        }
        SUBCASE("Both Negative and Positive"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);
            SquareMat expected = SquareMat(3);
    
            // adds values to mat1 and mat2
            for(int i=0; i < mat1.size(); i++){
                for(int j=0; j < mat1.size(); j++){
                    int num = 3*i+j+1;
    
                    // add linear values to mat1 
                    mat1[i][j] = -num;
                    // add square values to mat2
                    mat2[i][j] = num*num;
    
                    // setting the expected value
                    expected[i][j] = num*(-1 + num);
                }
            }
    
            // checks that the addition of mat1 and mat2 is not throwing errors
            CHECK_NOTHROW(mat1+mat2);
    
            SquareMat addition = mat1 + mat2;
            // checks that the addition is the expected size
            CHECK(addition.size() == expected.size());
    
            // checks that the values in addition are the expected values
            for(int i=0; i<addition.size(); i++){
                for(int j=0; j<addition.size(); j++){
                    CHECK(addition[i][j] == expected[i][j]);
                }
            }
        }
    }
    SUBCASE("Test Invalid Addition"){
        // attempting to add 2 matrices of different sizes
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1+mat2);
    }
}

TEST_CASE("Test Subtraction"){
    SUBCASE("Test Valid Subtraction"){
        SUBCASE("Only Positive Values"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);
            SquareMat expected = SquareMat(3);
    
            // adds values to mat1 and mat2
            for(int i=0; i < mat1.size(); i++){
                for(int j=0; j < mat1.size(); j++){
                    int num = 3*i+j+1;
    
                    // add linear values to mat1 
                    mat1[i][j] = num;
                    // add square values to mat2
                    mat2[i][j] = num*num;
    
                    // setting the expected value
                    expected[i][j] = num*(1 - num);
                }
            }
    
            // checks that the subtraction of mat1 and mat2 is not throwing errors
            CHECK_NOTHROW(mat1-mat2);
    
            SquareMat subtraction = mat1 - mat2;
            // checks that the subtraction is the expected size
            CHECK(subtraction.size() == expected.size());
    
            // checks that the values in subtraction are the expected values
            for(int i=0; i<subtraction.size(); i++){
                for(int j=0; j<subtraction.size(); j++){
                    CHECK(subtraction[i][j] == expected[i][j]);
                }
            }
        }
        SUBCASE("Both Negative and Positive"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);
            SquareMat expected = SquareMat(3);
    
            // adds values to mat1 and mat2
            for(int i=0; i < mat1.size(); i++){
                for(int j=0; j < mat1.size(); j++){
                    int num = 3*i+j+1;
    
                    // add linear values to mat1 
                    mat1[i][j] = -num;
                    // add square values to mat2
                    mat2[i][j] = num*num;
    
                    // setting the expected value
                    expected[i][j] = num*(-1 - num);
                }
            }
    
            // checks that the subtraction of mat1 and mat2 is not throwing errors
            CHECK_NOTHROW(mat1-mat2);
    
            SquareMat subtraction = mat1 - mat2;
            // checks that the subtraction is the expected size
            CHECK(subtraction.size() == expected.size());
    
            // checks that the values in subtraction are the expected values
            for(int i=0; i<subtraction.size(); i++){
                for(int j=0; j<subtraction.size(); j++){
                    CHECK(subtraction[i][j] == expected[i][j]);
                }
            }
        }
    }
    SUBCASE("Test Invalid Subtraction"){
        // attempting to subtract 2 matrices of different sizes
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1-mat2);
    }
}

TEST_CASE("Test Matrix Multiplication"){
    SUBCASE("Test Valid Multiplication"){
        SUBCASE("Multiply by the Identity Matrix"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);
            SquareMat expected = SquareMat(3);

            // sets the values for the matrices
            for(int i=0; i < mat1.size(); i++){
                for(int j=0; j < mat1.size(); j++){
                    int num = 3*i+j+1;
    
                    // add linear values to mat1 
                    mat1[i][j] = num;
                    
                    // if i==j set mat2 value to 1 else 0
                    if(i==j)
                        mat2[i][j] = 1;
                    else
                        mat2[i][j] = 0;
    
                    // setting the expected value
                    expected[i][j] = num;
                }
            }
            
            // checks that the multiplication of mat1 and mat2 is not throwing errors
            CHECK_NOTHROW(mat1*mat2);
    
            SquareMat multiplication = mat1 * mat2;
            // checks that the multiplication is the expected size
            CHECK(multiplication.size() == expected.size());
    
            // checks that the values in multiplication are the expected values
            for(int i=0; i<multiplication.size(); i++){
                for(int j=0; j<multiplication.size(); j++){
                    CHECK(multiplication[i][j] == expected[i][j]);
                }
            }

        }
        SUBCASE("Multiply a Matrix by it's Inverse"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);
            SquareMat expected = SquareMat(3);

            // sets the values for the matrices
            mat1[0][0] = 2;
            mat1[0][1] = 1;
            mat1[0][2] = 1;
            mat1[1][0] = 1;
            mat1[1][1] = 3;
            mat1[1][2] = 2;
            mat1[2][0] = 1;
            mat1[2][1] = 0;
            mat1[2][2] = 0;

            mat2[0][0] = 0;
            mat2[0][1] = 0;
            mat2[0][2] = 1;
            mat2[1][0] = -2;
            mat2[1][1] = 1;
            mat2[1][2] = 3;
            mat2[2][0] = 3;
            mat2[2][1] = -1;
            mat2[2][2] = -5;

            for(int i=0; i<expected.size(); i++){
                for(int j=0; j<expected.size(); j++){
                    if(i==j)
                        expected[i][j] = 1;
                    else    
                        expected[i][j] = 0;
                }
            }

            // checks that the multiplication of mat1 and mat2 is not throwing errors
            CHECK_NOTHROW(mat1*mat2);
    
            SquareMat multiplication = mat1 * mat2;
            // checks that the multiplication is the expected size
            CHECK(multiplication.size() == expected.size());
    
            // checks that the values in multiplication are the expected values
            for(int i=0; i<multiplication.size(); i++){
                for(int j=0; j<multiplication.size(); j++){
                    CHECK(multiplication[i][j] == expected[i][j]);
                }
            }
        }
    }
    SUBCASE("Test Invalid Multiplication"){
        // attempting to multiply 2 matrices of different sizes
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1*mat2);
    }
    SUBCASE("Test Commutativity"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i + j + 1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        
        SquareMat mult1 = mat1*mat2;
        SquareMat mult2 = mat2*mat1;

        // check that there is no commutativity
        bool thereIsADiff = false;
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                if(mult1[i][j] != mult2[i][j])
                    thereIsADiff = true;
            }
        }

        CHECK(thereIsADiff);
    }
}

TEST_CASE("Test Multiply By Scalar"){
    SUBCASE("mat*scalar"){
        SUBCASE("Mutliply by a Positive Scalar"){
            SquareMat mat = SquareMat(3);
            SquareMat expected = SquareMat(3);

            float scalar = 1.5;

            // sets values into the matrices
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    float num = 3*i + j + 1;
                    mat[i][j] = num;
                    expected[i][j] = num * scalar;
                }
            
            SquareMat res = mat*scalar;

            // checks that res is equal to expected in every index
            for(int i=0; i<expected.size(); i++)
                for(int j=0; j<expected.size(); j++)
                    CHECK(expected[i][j] == res[i][j]);
        }
        SUBCASE("Multiply by a Negative Scalar"){
            SquareMat mat = SquareMat(3);
            SquareMat expected = SquareMat(3);

            float scalar = -1.5;

            // sets values into the matrices
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    float num = 3*i + j + 1;
                    mat[i][j] = num;
                    expected[i][j] = num * scalar;
                }
            
            SquareMat res = mat*scalar;

            // checks that res is equal to expected in every index
            for(int i=0; i<expected.size(); i++)
                for(int j=0; j<expected.size(); j++)
                    CHECK(expected[i][j] == res[i][j]);
        }
        SUBCASE("Multiply by Zero"){
            SquareMat mat = SquareMat(3);
            SquareMat expected = SquareMat(3); 
    
            // sets values into the matrices
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    mat[i][j] = 3*i + j + 1;
                    expected[i][j] = 0;
                }
            
            SquareMat res = mat*0;

            // checks that res is equal to expected in every index
            for(int i=0; i<expected.size(); i++)
                for(int j=0; j<expected.size(); j++)
                    CHECK(expected[i][j] == res[i][j]);
        }
    }
    SUBCASE("scalar*mat"){
        SUBCASE("Mutliply by a Positive Scalar"){
            SquareMat mat = SquareMat(3);
            SquareMat expected = SquareMat(3);

            float scalar = 1.5;

            // sets values into the matrices
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    float num = 3*i + j + 1;
                    mat[i][j] = num;
                    expected[i][j] = num * scalar;
                }
            
            SquareMat res = scalar*mat;

            // checks that res is equal to expected in every index
            for(int i=0; i<expected.size(); i++)
                for(int j=0; j<expected.size(); j++)
                    CHECK(expected[i][j] == res[i][j]);
        }
        SUBCASE("Multiply by a Negative Scalar"){
            SquareMat mat = SquareMat(3);
            SquareMat expected = SquareMat(3);

            float scalar = -1.5;

            // sets values into the matrices
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    float num = 3*i + j + 1;
                    mat[i][j] = num;
                    expected[i][j] = num * scalar;
                }
            
            SquareMat res = scalar*mat;

            // checks that res is equal to expected in every index
            for(int i=0; i<expected.size(); i++)
                for(int j=0; j<expected.size(); j++)
                    CHECK(expected[i][j] == res[i][j]);
        }
        SUBCASE("Multiply by Zero"){
            SquareMat mat = SquareMat(3);
            SquareMat expected = SquareMat(3); 
    
            // sets values into the matrices
            for(int i=0; i<mat.size(); i++)
                for(int j=0; j<mat.size(); j++){
                    mat[i][j] = 3*i + j + 1;
                    expected[i][j] = 0;
                }
            
            SquareMat res = 0*mat;

            // checks that res is equal to expected in every index
            for(int i=0; i<expected.size(); i++)
                for(int j=0; j<expected.size(); j++)
                    CHECK(expected[i][j] == res[i][j]);
        }
    }
    SUBCASE("Test Commutativity"){
        SquareMat mat = SquareMat(3);
        float scalar = 1.5;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
            }
        
        SquareMat res1 = scalar*mat;
        SquareMat res2 = mat*scalar;

        // checks that res1 is equal to res2 in every index
        for(int i=0; i<res1.size(); i++)
            for(int j=0; j<res1.size(); j++)
                CHECK(res1[i][j] == res2[i][j]);
    }
}

TEST_CASE("Test Matrix Multiplication(%)"){
    SUBCASE("Test Valid Multiplication"){
        SUBCASE("Only Positive Values"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);

            SquareMat expected = SquareMat(3);

            for(int i=0; i<mat1.size(); i++){
                for(int j=0; j<mat1.size(); j++){
                    int num = 3*i + j + 1;
                    mat1[i][j] = num;
                    mat2[i][j] = num * num;
                    
                    // calculating the expected value of index i,j
                    expected[i][j] = num*num*num;
                }
            }

            SquareMat res = mat1%mat2;
            for(int i=0; i<res.size(); i++)
                for(int j=0; j<res.size(); j++)
                    CHECK(res[i][j] == expected[i][j]);
        }
        SUBCASE("Positive and Negative Values"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);

            SquareMat expected = SquareMat(3);

            for(int i=0; i<mat1.size(); i++){
                for(int j=0; j<mat1.size(); j++){
                    int num = 3*i + j + 1;
                    mat1[i][j] = -num;
                    mat2[i][j] = num * num;
                    
                    // calculating the expected value of index i,j
                    expected[i][j] = -num*num*num;
                }
            }

            SquareMat res = mat1%mat2;
            for(int i=0; i<res.size(); i++)
                for(int j=0; j<res.size(); j++)
                    CHECK(res[i][j] == expected[i][j]);
        }
        SUBCASE("Only Negative Values"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);

            SquareMat expected = SquareMat(3);

            for(int i=0; i<mat1.size(); i++){
                for(int j=0; j<mat1.size(); j++){
                    int num = 3*i + j + 1;
                    mat1[i][j] = -num;
                    mat2[i][j] = -num * num;
                    
                    // calculating the expected value of index i,j
                    expected[i][j] = num*num*num;
                }
            }

            SquareMat res = mat1%mat2;
            for(int i=0; i<res.size(); i++)
                for(int j=0; j<res.size(); j++)
                    CHECK(res[i][j] == expected[i][j]);
        }
        SUBCASE("All Values are Zero (In Second Matrix)"){
            SquareMat mat1 = SquareMat(3);
            SquareMat mat2 = SquareMat(3);

            SquareMat expected = SquareMat(3);

            // sets values for all matrices
            for(int i=0; i<mat1.size(); i++){
                for(int j=0; j<mat1.size(); j++){
                    mat1[i][j] = 3*i + j + 1;
                    mat2[i][j] = 0;
                    expected[i][j] = 0;
                }
            }

            // check the multiplication doesn't throw an error
            CHECK_NOTHROW(mat1%mat2);

            SquareMat res = mat1%mat2;
        }
    }
    SUBCASE("Test Invalid Multiplication"){
        // attempting to multiply 2 matrices of different sizes
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(5);
        CHECK_THROWS(mat1%mat2);
    }
    SUBCASE("Test Commutativity"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i + j + 1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        
        // check that there is commutativity
        SquareMat mult1 = mat1%mat2;
        SquareMat mult2 = mat2%mat1;

        // check that there is no commutativity
        bool thereIsADiff = false;
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                if(mult1[i][j] != mult2[i][j])
                    thereIsADiff = true;
            }
        }

        CHECK(!thereIsADiff);
    }
}

TEST_CASE("Test Modulo Operation"){
    SUBCASE("Modulo by a Positive Scalar (|Scalar| > 1)"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        int scalar = 2;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
                expected[i][j] = fmod(num, scalar);
            }
            
        SquareMat res = mat%scalar;

        // checks that res is equal to expected in every index
        for(int i=0; i<expected.size(); i++)
            for(int j=0; j<expected.size(); j++)
                CHECK(expected[i][j] == res[i][j]);
    }
    SUBCASE("Modulo by a Negative Scalar (|Scalar| > 1)"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        int scalar = -2;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
                expected[i][j] = fmod(num, scalar);
            }
            
        SquareMat res = mat%scalar;

        // checks that res is equal to expected in every index
        for(int i=0; i<expected.size(); i++)
            for(int j=0; j<expected.size(); j++)
                CHECK(expected[i][j] == res[i][j]);
    }
    SUBCASE("Modulo by Zero"){
        SquareMat mat = SquareMat(3);
        
        // sets values into the matrix
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = 3*i + j + 1;
            }
        // check that an error is thrown upon attempt to modulo by 0
        CHECK_THROWS(mat%0);
    }
}

TEST_CASE("Test Division of Matrix by a Scalar"){
    SUBCASE("Division by a Positive Scalar (|Scalar| > 1)"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        float scalar = 1.5;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
                expected[i][j] = num / scalar;
            }
            
        SquareMat res = mat/scalar;

        // checks that res is equal to expected in every index
        for(int i=0; i<expected.size(); i++)
            for(int j=0; j<expected.size(); j++)
                CHECK(expected[i][j] == res[i][j]);
    }
    SUBCASE("Division by a Negative Scalar (|Scalar| > 1)"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        float scalar = -1.5;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
                expected[i][j] = num / scalar;
            }
            
        SquareMat res = mat/scalar;

        // checks that res is equal to expected in every index
        for(int i=0; i<expected.size(); i++)
            for(int j=0; j<expected.size(); j++)
                CHECK(expected[i][j] == res[i][j]);
    }
    SUBCASE("Division by a Positive Scalar (0 < |Scalar| < 1)"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        float scalar = 0.5;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
                expected[i][j] = num / scalar;
            }
            
        SquareMat res = mat/scalar;

        // checks that res is equal to expected in every index
        for(int i=0; i<expected.size(); i++)
            for(int j=0; j<expected.size(); j++)
                CHECK(expected[i][j] == res[i][j]);
    }
    SUBCASE("Division by a Negative Scalar (0 < |Scalar| < 1)"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        float scalar = -0.5;

        // sets values into the matrices
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                float num = 3*i + j + 1;
                mat[i][j] = num;
                expected[i][j] = num / scalar;
            }
            
        SquareMat res = mat/scalar;

        // checks that res is equal to expected in every index
        for(int i=0; i<expected.size(); i++)
            for(int j=0; j<expected.size(); j++)
                CHECK(expected[i][j] == res[i][j]);
    }
    SUBCASE("Division by Zero"){
        SquareMat mat = SquareMat(3);
        
        // sets values into the matrix
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++){
                mat[i][j] = 3*i + j + 1;
            }
        // check that an error is thrown upon attempt to divide by 0
        CHECK_THROWS(mat/0);
    }
}

TEST_CASE("Test Raising a Matrix to the Power of an Integer"){
    SUBCASE("Raising to the Power of an Integer Bigger than One"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        // sets the values for the matrices
        for(int i=0; i < mat.size(); i++){
            for(int j=0; j < mat.size(); j++){
                int num = 3*i+j+1;

                mat[i][j] = num;
                expected[i][j] = num;
            }
        }
        expected = mat*mat*mat*mat*mat;

        SquareMat res = mat^5;

        // checks that res is equal to the expected matrix
        for(int i=0; i<res.size(); i++)
            for(int j=0; j<res.size(); j++)
                CHECK(res[i][j] == expected[i][j]);
    }
    SUBCASE("Raising to the Power of One"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        // sets the values for the matrices
        for(int i=0; i < mat.size(); i++){
            for(int j=0; j < mat.size(); j++){
                int num = 3*i+j+1;

                mat[i][j] = num;
                expected[i][j] = num;
            }
        }

        // a matrix to the power of 1 is the original matrix
        SquareMat res = mat^1;

        // checks that res is equal to the expected matrix
        for(int i=0; i<res.size(); i++)
            for(int j=0; j<res.size(); j++)
                CHECK(res[i][j] == expected[i][j]);
    }
    SUBCASE("Raising to the Power of Zero"){
        SquareMat mat = SquareMat(3);
        SquareMat expected = SquareMat(3);

        // sets the values for the matrices
        for(int i=0; i < mat.size(); i++){
            for(int j=0; j < mat.size(); j++){
                int num = 3*i+j+1;

                mat[i][j] = num;
                
                // if i==j set expected value to 1 else 0
                if(i==j)
                    expected[i][j] = 1;
                else
                    expected[i][j] = 0;
            }
        }

        // a matrix to the power of 0 is the identity matrix
        SquareMat res = mat^0;

        // checks that res is equal to the expected matrix
        for(int i=0; i<res.size(); i++)
            for(int j=0; j<res.size(); j++)
                CHECK(res[i][j] == expected[i][j]);
    }
    SUBCASE("Raising to a Negative Integer"){
        SquareMat mat = SquareMat(3);

        int scalar = -5;

        // raising to a negative power throws an error
        CHECK_THROWS(mat^scalar);
    }
}

TEST_CASE("Test Assignment Operator"){
    SUBCASE("Assignment to Self"){
        SquareMat mat = SquareMat(3);
        void *address = &mat;

        // sets values to mat
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                mat[i][j] = 3*i +j+1;
        // saves a copy of this matrix
        SquareMat copy = SquareMat(mat);

        // assigns mat to itself
        mat.operator=(mat);

        // check that mat still points to the same address
        CHECK(address == &mat);

        // checks that the values remained the same
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                CHECK(mat[i][j] == copy[i][j]);
    }
    SUBCASE("Assignment to a Different Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);

        // sets values to matrices
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j+1;
                mat1[i][j] = num;
                mat2[i][j] = num*num;
            }
        }
        // saves the address to mat2
        void *address = &mat2;

        // assigns mat1 to mat2
        mat2 = mat1;

        // checks that the address of mat2 remain the same
        CHECK(address == &mat2);

        // checks that the address of mat2 is not equal to that of mat1
        CHECK(address != &mat1);

        // checks that the values of mat2 are equal to those of mat1
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                CHECK(mat1[i][j] == mat2[i][j]);
    }
}