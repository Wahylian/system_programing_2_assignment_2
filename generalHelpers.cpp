#include "generalHelpers.hpp"
float fmod(float num, int scalar){
    // based on the implementation of fmod in the standard math library
    if(scalar == 0)
        throw std::runtime_error{"Division by 0"};
    
    float tquot = num / scalar;
    int int_tquot = (int)tquot; // casting to int

    // if tqout is negative and the int version is smaller than the original adds 1 to it to round it towards 0
    if(tquot < 0 && int_tquot<tquot)
        int_tquot+=1;
    // if tqout is positive and the int version is bigger than the original removes 1 from it to round it towards 0
    else if(tquot > 0 && int_tquot>tquot)
        int_tquot-=1;
    
    return num - int_tquot * scalar;
}

float power(float num, int scalar){
    // num to the power of 0 is 1
    if(scalar == 0)
        return 1;
    
    float res = 1;
    for(int i=0; i<scalar; i++)
        res *= num;
    
    return res;
}