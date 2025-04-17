#include <iostream>
#include "matrix.hpp"
using namespace Matrix;

int main(){
    // create multiple matrices
    SquareMat mat1 = SquareMat(3); // matrix [9 ... 1]
    SquareMat mat2 = SquareMat(3); // matrix [1 ... 9]
    SquareMat mat3 = SquareMat(3); // matrix of only 1s
    SquareMat mat4 = SquareMat(3); // matrix of (-1)^i * num^2
    SquareMat mat5 = SquareMat(3); // the identity matrix

    std::cout<<"Setting Values to Multiple Matrices..."<<std::endl;
    // setting values to the matrices
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int num = 3*i+j+1;
            mat1[i][j] = 10 - num;
            mat2[i][j] = num;
            mat3[i][j] = 1;
            mat4[i][j] = power(-1, i)*power(num,2); // (-1)^i * num^2 
            if(i == j) mat5[i][j] = 1;
            else mat5[i][j] = 0;
        }
    }

    // printing the 5 base matrices
    std::cout<<"The 5 Base Matrices:"<<std::endl;
    std::cout<<"mat1:"<<std::endl<<mat1<<std::endl;
    std::cout<<"mat2:"<<std::endl<<mat2<<std::endl;
    std::cout<<"mat3:"<<std::endl<<mat3<<std::endl;
    std::cout<<"mat4:"<<std::endl<<mat4<<std::endl;
    std::cout<<"mat5:"<<std::endl<<mat5<<std::endl;

    // adding matrices
    std::cout<<"mat2+mat3="<<std::endl<<mat2+mat3<<std::endl;
    // subtracting matrices
    std::cout<<"mat2-mat4="<<std::endl<<mat2-mat4<<std::endl;
    // turning the values of a matrix
    std::cout<<"-mat4"<<std::endl<<-mat4<<std::endl;
    std::cout<<"--mat4 (returning to orignal matrix)"<<std::endl<<mat4<<std::endl;
    // multiplying matrices
    std::cout<<"mat1*mat5="<<std::endl<<mat1*mat5<<std::endl;
    // multiplying matrix by scalar
    std::cout<<"mat3*5="<<std::endl<<mat3*5<<std::endl;
    // multiplying scalar by matrix
    std::cout<<"2*mat2="<<std::endl<<2*mat2<<std::endl;
    // multiplying matrices by value
    std::cout<<"mat1%mat4="<<std::endl<<mat1%mat4<<std::endl;
    // modulo on a matrix
    std::cout<<"mat1%2="<<std::endl<<mat1%2<<std::endl;
    // division by a scalar
    std::cout<<"mat5/7="<<std::endl<<mat5/7<<std::endl;
    // raising to a power
    std::cout<<"mat2^3="<<std::endl<<(mat2^3)<<std::endl; 
    // prefix addition
    std::cout<<"++mat4="<<std::endl<<++mat4<<std::endl;
    // prefix removal
    std::cout<<"--mat4="<<std::endl<<--mat4<<std::endl;
    // postfix addition
    std::cout<<"mat2++="<<std::endl<<mat2++<<std::endl;
    std::cout<<"mat2="<<std::endl<<mat2<<std::endl;
    // postfix removal
    std::cout<<"mat2--="<<std::endl<<mat2--<<std::endl;
    std::cout<<"mat2="<<std::endl<<mat2<<std::endl;
    // transpose
    std::cout<<"~mat1="<<std::endl<<~mat1<<std::endl;
    // getting a specific value in a matrix
    std::cout<<"mat3[1][0]="<<std::endl<<mat3[1][0]<<std::endl;
    // checking equals
    std::cout<<"mat1==mat2="<<std::endl<<(mat1==mat2)<<std::endl;
    // checking not equals
    std::cout<<"mat1!=mat5="<<std::endl<<(mat1!=mat5)<<std::endl;
    // checking bigger or equal to
    std::cout<<"mat2>=mat5="<<std::endl<<(mat2>=mat5)<<std::endl;
    // checking smaller or equal to
    std::cout<<"mat1<=mat2="<<std::endl<<(mat1<=mat2)<<std::endl;
    // checking bigger than
    std::cout<<"mat4>mat5="<<std::endl<<(mat4>mat5)<<std::endl;
    // checking smaller than
    std::cout<<"mat3<mat1="<<std::endl<<(mat3<mat1)<<std::endl;
    // calculating the determinant
    std::cout<<"!mat3="<<std::endl<<!mat3<<std::endl;
    // compound addition
    mat1+=mat3;
    std::cout<<"mat1+=mat3="<<std::endl<<mat1<<std::endl;
    // compound subtraction
    mat1-=mat3;
    std::cout<<"mat1-=mat3="<<std::endl<<mat1<<std::endl;  
    // compound matrix multiplication
    mat4*=mat4;
    std::cout<<"mat4*=mat4="<<std::endl<<mat4<<std::endl;
    // compound multiplication by scalar
    mat2*=7;
    std::cout<<"mat2*=7="<<std::endl<<mat2<<std::endl;
    // compound division
    mat2/=7;
    std::cout<<"mat2/=7="<<std::endl<<mat2<<std::endl;
    // compound by value matrix multiplication
    mat1%=mat2;
    std::cout<<"mat1%=mat2="<<std::endl<<mat1<<std::endl;
    // compound modulo
    mat2%=3;
    std::cout<<"mat2%=3="<<std::endl<<mat2<<std::endl;
}