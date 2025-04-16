#include "doctest.h"
#include "../matrix.hpp"

TEST_CASE("Test =="){
    SUBCASE("Exact Same Matrix"){
        SquareMat mat = SquareMat(3);
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                mat[i][j] = 3*i +j;
        CHECK(mat == mat);
    }
    SUBCASE("Different Matrices Same Sum"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num;
            }
        }
        // both matrices have equal sums
        CHECK(mat1 == mat2);
    }
    SUBCASE("Not Equal Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num+1;
            }
        }
        // the matrices have different sums
        CHECK(!(mat1 == mat2));
    }
    SUBCASE("Differently Sized Matrices"){
        SquareMat mat1 = SquareMat(5);
        SquareMat mat2 = SquareMat(3);
        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                mat1[i][j] = mat1.size()*i +j;

        for(int i=0; i<mat2.size(); i++)
            for(int j=0; j<mat2.size(); j++)
                mat2[i][j] = mat2.size()*i +j;

        // mat1 is bigger than mat2
        CHECK(!(mat1 == mat2));
    }
}

TEST_CASE("Test !="){
    SUBCASE("Exact Same Matrix"){
        SquareMat mat = SquareMat(3);
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat.size(); j++)
                mat[i][j] = 3*i +j;
        CHECK(!(mat != mat));
    }
    SUBCASE("Different Matrices Same Sum"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num;
            }
        }
        // both matrices have equal sums
        CHECK(!(mat1 != mat2));
    }
    SUBCASE("Not Equal Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num+1;
            }
        }
        // the matrices have different sums
        CHECK(mat1 != mat2);
    }
    SUBCASE("Differently Sized Matrices"){
        SquareMat mat1 = SquareMat(5);
        SquareMat mat2 = SquareMat(3);
        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                mat1[i][j] = mat1.size()*i +j;

        for(int i=0; i<mat2.size(); i++)
            for(int j=0; j<mat2.size(); j++)
                mat2[i][j] = mat2.size()*i +j;

        // mat1 is bigger than mat2
        CHECK(mat1 != mat2);
    }
}

TEST_CASE("Test >="){
    SUBCASE("Equal Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num;
            }
        }
        // both matrices have equal sums
        CHECK(mat1 >= mat2);
    }
    SUBCASE("Bigger Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num+1;
                mat2[j][i] = num;
            }
        }
        // mat1 has a bigger sum than mat2
        CHECK(mat1 >= mat2);
    }
    SUBCASE("Smaller Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num+1;
            }
        }
        // mat1 has a smaller sum than mat2
        CHECK(!(mat1 >= mat2));
    }
    SUBCASE("Differently Sized Matrices"){
        SquareMat mat1 = SquareMat(5);
        SquareMat mat2 = SquareMat(3);
        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                mat1[i][j] = mat1.size()*i +j;

        for(int i=0; i<mat2.size(); i++)
            for(int j=0; j<mat2.size(); j++)
                mat2[i][j] = mat2.size()*i +j;

        // mat1 is bigger than mat2
        CHECK(mat1 >= mat2);
    }
}

TEST_CASE("Test <="){
    SUBCASE("Equal Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num;
            }
        }
        // both matrices have equal sums
        CHECK(mat1 <= mat2);
    }
    SUBCASE("Bigger Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num+1;
                mat2[j][i] = num;
            }
        }
        // mat1 has a bigger sum than mat2
        CHECK(!(mat1 <= mat2));
    }
    SUBCASE("Smaller Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num+1;
            }
        }
        // mat1 has a smaller sum than mat2
        CHECK(mat1 <= mat2);
    }
    SUBCASE("Differently Sized Matrices"){
        SquareMat mat1 = SquareMat(5);
        SquareMat mat2 = SquareMat(3);
        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                mat1[i][j] = mat1.size()*i +j;

        for(int i=0; i<mat2.size(); i++)
            for(int j=0; j<mat2.size(); j++)
                mat2[i][j] = mat2.size()*i +j;

        // mat1 is bigger than mat2
        CHECK(!(mat1 <= mat2));
    }
}

TEST_CASE("Test >"){
    SUBCASE("Equal Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num;
            }
        }
        // both matrices have equal sums
        CHECK(!(mat1 > mat2));
    }
    SUBCASE("Bigger Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num+1;
                mat2[j][i] = num;
            }
        }
        // mat1 has a bigger sum than mat2
        CHECK(mat1 > mat2);
    }
    SUBCASE("Smaller Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num+1;
            }
        }
        // mat1 has a smaller sum than mat2
        CHECK(!(mat1 > mat2));
    }
    SUBCASE("Differently Sized Matrices"){
        SquareMat mat1 = SquareMat(5);
        SquareMat mat2 = SquareMat(3);
        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                mat1[i][j] = mat1.size()*i +j;

        for(int i=0; i<mat2.size(); i++)
            for(int j=0; j<mat2.size(); j++)
                mat2[i][j] = mat2.size()*i +j;

        // mat1 is bigger than mat2
        CHECK(mat1 > mat2);
    }
}

TEST_CASE("Test <"){
    SUBCASE("Equal Matrices"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num;
            }
        }
        // both matrices have equal sums
        CHECK(!(mat1 < mat2));
    }
    SUBCASE("Bigger Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num+1;
                mat2[j][i] = num;
            }
        }
        // mat1 has a bigger sum than mat2
        CHECK(!(mat1 < mat2));
    }
    SUBCASE("Smaller Matrix"){
        SquareMat mat1 = SquareMat(3);
        SquareMat mat2 = SquareMat(3);
        for(int i=0; i<mat1.size(); i++){
            for(int j=0; j<mat1.size(); j++){
                int num = 3*i +j;
                // placing the values at different indeces 
                mat1[i][j] = num;
                mat2[j][i] = num+1;
            }
        }
        // mat1 has a smaller sum than mat2
        CHECK(mat1 < mat2);
    }
    SUBCASE("Differently Sized Matrices"){
        SquareMat mat1 = SquareMat(5);
        SquareMat mat2 = SquareMat(3);
        // sets values to the matrices
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat1.size(); j++)
                mat1[i][j] = mat1.size()*i +j;

        for(int i=0; i<mat2.size(); i++)
            for(int j=0; j<mat2.size(); j++)
                mat2[i][j] = mat2.size()*i +j;

        // mat1 is bigger than mat2
        CHECK(!(mat1 < mat2));
    }
}