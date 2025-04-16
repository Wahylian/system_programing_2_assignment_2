#include "doctest.h"
#include "../matrix.hpp"

TEST_CASE("Test Prefix Increment"){
    SquareMat mat = SquareMat(3);
    SquareMat expected = SquareMat(3);

    // sets values to matrices
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++){
            int num = 3*i + j;
            mat[i][j] = num;
            expected[i][j] = num + 1;
        }
    
    // check that mat[i][j] != expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] != expected[i][j]);    

    // check that mat != expected
    CHECK(mat != expected);

    // check that ++mat == expected
    CHECK(++mat == expected);

    // check that mat[i][j] == expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] == expected[i][j]);
}

TEST_CASE("Test Postfix Increment"){
    SquareMat mat = SquareMat(3);
    SquareMat expected = SquareMat(3);

    // sets values to matrices
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++){
            int num = 3*i + j;
            mat[i][j] = num;
            expected[i][j] = num + 1;
        }
    
    // check that mat[i][j] != expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] != expected[i][j]);    

    // check that mat++ != expected
    CHECK(mat++ != expected);

    // check that mat == expected
    CHECK(mat == expected);

    // check that mat[i][j] == expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] == expected[i][j]);
}

TEST_CASE("Test Prefix Decrement"){
    SquareMat mat = SquareMat(3);
    SquareMat expected = SquareMat(3);

    // sets values to matrices
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++){
            int num = 3*i + j;
            mat[i][j] = num + 1;
            expected[i][j] = num;
        }
    
    // check that mat[i][j] != expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] != expected[i][j]);    

    // check that mat != expected
    CHECK(mat != expected);

    // check that --mat == expected
    CHECK(--mat == expected);

    // check that mat[i][j] == expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] == expected[i][j]);
}

TEST_CASE("Test Postfix Decrement"){
    SquareMat mat = SquareMat(3);
    SquareMat expected = SquareMat(3);

    // sets values to matrices
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++){
            int num = 3*i + j;
            mat[i][j] = num + 1;
            expected[i][j] = num;
        }
    
    // check that mat[i][j] != expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] != expected[i][j]);    

    // check that mat-- != expected
    CHECK(mat-- != expected);

    // check that mat == expected
    CHECK(mat == expected);

    // check that mat[i][j] == expected[i][j]
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat.size(); j++)
            CHECK(mat[i][j] == expected[i][j]);
}