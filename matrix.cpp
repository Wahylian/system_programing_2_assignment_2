#include "matrix.hpp"

#pragma region matrixRow
SquareMat::MatrixRow::MatrixRow():
n{},
row{nullptr}
{}

SquareMat::MatrixRow::MatrixRow(int n, float *row):
n{n},
row{row}
{ }

void SquareMat::MatrixRow::setValues(int n, float *row){
    this->n = n;
    this->row = row;
}

float& SquareMat::MatrixRow::operator[] (int j){
    if(j < 0 || j >= this->n)
        throw std::out_of_range{"index out of range"};
    return (this->row)[j];
}

float SquareMat::MatrixRow::operator[] (int j) const{
    if(j < 0 || j >= this->n)
        throw std::out_of_range{"index out of range"};
    return (this->row)[j];
}
#pragma endregion




#pragma region ctors&dtors
SquareMat::SquareMat(int size):
p_matrix{nullptr},
n{size}
{
    // checks that n is a positive number
    if(n < 0)
        throw std::invalid_argument{"the matrix must have a positive size"};

    // creates an array of n rows
    this->p_matrix = new MatrixRow[this->n];

    // initializes each row of the matrix
    for(int i=0; i<this->n; i++)
        // sets the default row of size n as the row of the matrix
        (this->p_matrix)[i].setValues(this->n, new float[this->n]{0});
}

SquareMat::SquareMat(const SquareMat &matrix):
p_matrix{nullptr},
n{matrix.size()}
{   
    // checks that n is a positive number
    if(n < 0)
        throw std::invalid_argument{"the matrix must have a positive size"};

    // creates an array of n rows
    this->p_matrix = new MatrixRow[this->n];

    // initializes each row of the matrix
    for(int i=0; i<this->n; i++){
        // sets the default row of size n as the row of the matrix
        (this->p_matrix)[i].setValues(this->n, new float[this->n]{0});

        // copies over each of the values in matrix to this matrix
        for(int j=0; j<this->n; j++)
            (this->p_matrix)[i][j] = matrix[i][j];
    }
}

SquareMat::~SquareMat(){
    // goes over each row of the matrix
    for(int i=0; i<this->n; i++){
        // saves a pointer to each row
        float *temp = (this->p_matrix)[i].getRow();
        // sets the pointer of this row to nullptr
        (this->p_matrix)[i].setValues(0, nullptr);

        // deletes the row
        delete[] temp;
    }

    // deleting the matrix
    delete[] this->p_matrix;
}
#pragma endregion




#pragma region arithmeticOperations

SquareMat operator+ (const SquareMat &matrix, const SquareMat &other_matrix){
    // if the matrix and other_matrix are of different sizes throws an error
    if(matrix.size() != other_matrix.size())
        throw std::invalid_argument{"other_matrix of incorrect size"};

    // creates a matrix of size n
    SquareMat mat = SquareMat(matrix.size());

    // for each value i,j in matrix and other matrix
    // adds them up and inserts them into index i,j in mat
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            mat[i][j] = matrix[i][j] + other_matrix[i][j];
        }
    }

    // returns the new matrix
    return mat;
}

SquareMat operator- (const SquareMat &matrix, const SquareMat &other_matrix){
    // if the matrix and other_matrix are of different sizes throws an error
    if(matrix.size() != other_matrix.size())
        throw std::invalid_argument{"other_matrix of incorrect size"};
    
    // creates a matrix of size n
    SquareMat mat = SquareMat(matrix.size());

    // for each value i,j in matrix and other matrix
    // subtracts the value i,j in the other matrix from the value i,j in matrix
    // and inserts the result to mat
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j < mat.size(); j++){
            mat[i][j] = matrix[i][j] - other_matrix[i][j];
        }
    }

    // returns the new matrix
    return mat;
}

SquareMat operator* (const SquareMat &matrix, const SquareMat &other_matrix){
    // if the matrix and other_matrix are of different sizes throws an error
    if(matrix.size() != other_matrix.size())
        throw std::invalid_argument{"other_matrix of incorrect size"};
    
    // creates a matrix of size n
    SquareMat mat = SquareMat(matrix.size());

    // based on the matrix multiplication formula:
    // mat[i][j] = sum over k=0 to n of (this_matrix[i][k] * other_matrix[k][j])

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            float sum = 0;
            for(int k=0; k<matrix.size(); k++){
                // adds the multiplication of this_matrix[i][k] * other_matrix[k][j] to sum
                sum += matrix[i][k] * other_matrix[k][j];
            }
            // asserts mat[i][j] to sum
            mat[i][j] = sum;
        }
    }

    // returns the new matrix
    return mat;
}

SquareMat operator* (const SquareMat &matrix, float scalar){
    // creates a new matrix with the same size
    SquareMat mat = SquareMat(matrix.size());

    // for each value of matrix, multiplies it by scalar and copies the result
    // into the appropriate index
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            mat[i][j] = matrix[i][j] * scalar;

    // returns the new matrix
    return mat;
}

SquareMat operator% (const SquareMat &matrix, const SquareMat &other_matrix){
    // if the matrix and other_matrix are of different sizes throws an error
    if(matrix.size() != other_matrix.size())
        throw std::invalid_argument{"other_matrix of incorrect size"};

    // creates a new matrix with the same size
    SquareMat mat = SquareMat(matrix.size());

    // multiplies value [i][j] in matrix by the corrisponding value in the other matrix
    // and saves it into mat
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            mat[i][j] = matrix[i][j] * other_matrix[i][j];

    // returns the new matrix
    return mat;
}

SquareMat operator% (const SquareMat &matrix, int scalar){
    // if the scalar is 0 throw an error
    if(scalar == 0)
        throw std::runtime_error{"division by 0"};
    
    // creates a new matrix with the same size
    SquareMat mat = SquareMat(matrix.size());

    // mods value [i][j] in matrix by the scalar
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            mat[i][j] = fmod(matrix[i][j], scalar);

    // returns the new matrix
    return mat;
}

SquareMat operator/ (const SquareMat &matrix, float scalar){
    // if the scalar is 0 throw an error
    if(scalar == 0.0f)
        throw std::runtime_error{"division by 0"};
    
    // creates a new matrix with the same size
    SquareMat mat = SquareMat(matrix.size());

    // divides value [i][j] in matrix by the scalar
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            mat[i][j] = matrix[i][j] / scalar;

    // returns the new matrix
    return mat;
}

SquareMat operator^ (const SquareMat &matrix, int n){
    if(n < 0)
        throw std::invalid_argument{"cannot raise matrix to a negative power"};

    SquareMat mat = SquareMat(matrix.size());
    // turns mat into the identity matrix of the appropriate size
    for(int i =0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            if(i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }

    // multiplies mat by this matrix n times
    for(int i=0; i<n; i++){
        mat = mat*matrix;
    }

    
    // return the new matrix
    return mat;
}

#pragma endregion




#pragma region incrs&Decrs

SquareMat& SquareMat::operator++ (){
    // adds 1 to each of the values in this matrix
    for(int i=0; i<this->n; i++)
        for(int j=0; j<this->n; j++)
            (this->p_matrix)[i][j]++; // increases by 1
    // return a pointer to this matrix
    return *this;
}

SquareMat SquareMat::operator++ (int dummy_flag_for_postfix_increment){
    // copies this matrix
    SquareMat copy = *this;
    // increments this matrix
    ++(*this);
    // returns copy
    return copy;
}

SquareMat& SquareMat::operator-- (){
    // removes 1 to each of the values in this matrix
    for(int i=0; i<this->n; i++)
        for(int j=0; j<this->n; j++)
            (this->p_matrix)[i][j]--; // decreases by 1
    // returns a pointer to this matrix
    return *this;
}

SquareMat SquareMat::operator-- (int dummy_flag_for_postfix_decrement){
    // copies this matrix
    SquareMat copy = *this;
    // decrements this matrix
    --(*this);
    // returns copy
    return copy;
}

#pragma endregion




#pragma region compareOperations
bool operator== (const SquareMat &matrix, const SquareMat &other_matrix){
    // the matrices are equal if the sum of their values are equal
    float sum1 = 0;

    // calculates the sums of matrix and other matrix
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            sum1 += matrix[i][j];
    
    float sum2 = 0;

    for(int i=0; i<other_matrix.size(); i++)
        for(int j=0; j<other_matrix.size(); j++)
            sum2 += other_matrix[i][j];

    // if the sums are equal the matrices are equal
    return sum1 == sum2;
}

bool operator!= (const SquareMat &matrix, const SquareMat &other_matrix){
    return !(matrix == other_matrix);
}

bool operator>= (const SquareMat &matrix, const SquareMat &other_matrix){
    // matrix >= other_matrix occurs when
    // the sum of values of matrix is bigger or equal to the sum of values in other matrix

    float sum1 = 0;

    // calculates the sums of matrix and other matrix
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            sum1 += matrix[i][j];
    
    float sum2 = 0;

    for(int i=0; i<other_matrix.size(); i++)
        for(int j=0; j<other_matrix.size(); j++)
            sum2 += other_matrix[i][j];

    // if the sums are equal the matrices are equal
    return sum1 >= sum2;
}

bool operator<= (const SquareMat &matrix, const SquareMat &other_matrix){
    // matrix <= other_matrix occurs when
    // the sum of values of matrix is smaller or equal to the sum of values in other matrix

    float sum1 = 0;

    // calculates the sums of matrix and other matrix
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            sum1 += matrix[i][j];
    
    float sum2 = 0;

    for(int i=0; i<other_matrix.size(); i++)
        for(int j=0; j<other_matrix.size(); j++)
            sum2 += other_matrix[i][j];

    // if the sums are equal the matrices are equal
    return sum1 <= sum2;
}

bool operator> (const SquareMat &matrix, const SquareMat &other_matrix){
    // matrix > other_matrix occurs when
    // the sum of values of matrix is bigger to the sum of values in other matrix

    float sum1 = 0;

    // calculates the sums of matrix and other matrix
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            sum1 += matrix[i][j];
    
    float sum2 = 0;

    for(int i=0; i<other_matrix.size(); i++)
        for(int j=0; j<other_matrix.size(); j++)
            sum2 += other_matrix[i][j];

    // if the sums are equal the matrices are equal
    return sum1 > sum2;
}

bool operator< (const SquareMat &matrix, const SquareMat &other_matrix){
    // matrix < other_matrix occurs when
    // the sum of values of matrix is smaller to the sum of values in other matrix

    float sum1 = 0;

    // calculates the sums of matrix and other matrix
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix.size(); j++)
            sum1 += matrix[i][j];
    
    float sum2 = 0;

    for(int i=0; i<other_matrix.size(); i++)
        for(int j=0; j<other_matrix.size(); j++)
            sum2 += other_matrix[i][j];

    // if the sums are equal the matrices are equal
    return sum1 < sum2;
}

#pragma endregion

double SquareMat::operator!() const{
    // the deteminant of a 0x0 matrix is 0
    if(this->size() == 0)
        return 0;

    // the determinant of a 1x1 matrix is the value in the matrix
    if(this->size() == 1)
        return (this->p_matrix)[0][0];

    // calculating the determinant over column 0
    double det = 0;
    for(int i=0; i<this->size(); i++){
        // create the matrix without row i and column 0
        SquareMat reduceMat = this->reduceMat(i, 0);

        det += power(-1, i) * (this->p_matrix)[i][0] * (!reduceMat);
    }

    // returns the determinant of this matrix
    return det;
}

#pragma region compoundOperations

void SquareMat::operator+= (const SquareMat &other_matrix){
    (*this) = (*this) + other_matrix;
}

void SquareMat::operator-= (const SquareMat &other_matrix){
    (*this) = (*this) - other_matrix;
}

void SquareMat::operator*= (const SquareMat &other_matrix){
    (*this) = (*this) * other_matrix;
}

void SquareMat::operator*= (float scalar){
    (*this) = (*this) * scalar;
}

void SquareMat::operator/= (float scalar){
    (*this) = (*this) / scalar;
}

void SquareMat::operator%= (const SquareMat &other_matrix){
    (*this) = (*this) % other_matrix;
}

void SquareMat::operator%= (int scalar){
    (*this) = (*this) % scalar;
}

#pragma endregion




#pragma region matrixChanges 

void SquareMat::operator~ (){
    for(int i=0; i<this->n; i++){
        for(int j=i; j<this->n; j++){
            // replaces the values between i,j and j,i
            float temp = (*this)[i][j];
            (*this)[i][j] = (*this)[j][i];
            (*this)[j][i] = temp;
        }
    }
}

SquareMat::MatrixRow& SquareMat::operator[] (int i){
    if(i<0 || i>=this->n)
        throw std::out_of_range{"index out of range"};

    return this->p_matrix[i];
}

const SquareMat::MatrixRow& SquareMat::operator[] (int i) const{
    if(i<0 || i>=this->n)
    throw std::out_of_range{"index out of range"};

    return this->p_matrix[i];
}

SquareMat& SquareMat::operator= (const SquareMat &other_matrix){
    // if this matrix and the other matrix are the same, return this matrix
    if(this == &other_matrix)
        return *this;
    
    // else, this matrix needs to be deleted 
    // goes over each row of the matrix
    for(int i=0; i<this->n; i++){
        // saves a pointer to each row
        float *temp = (this->p_matrix)[i].getRow();
        // sets the pointer of this row to nullptr
        (this->p_matrix)[i].setValues(0, nullptr);

        // deletes the row
        delete[] temp;
    }

    // deleting the matrix
    delete[] this->p_matrix;

    // and copy over the values from the other matrix
    // copy the size of the matrix
    this->n = other_matrix.n;

    // creates enough rows
    this->p_matrix = new MatrixRow[this->n];
    for(int i=0; i<this->n; i++){
        // creates the array at the i-th row, and initializes its values to 0
        (this->p_matrix)[i].setValues(this->n, new float[this->n]{0});
        for(int j=0; j<this->n; j++){
            // copies the values over
            (this->p_matrix)[i][j] = other_matrix[i][j];
        }
    }
    
    // return the matrix
    return *this;
}

#pragma endregion

SquareMat SquareMat::reduceMat(int i, int j) const{
    SquareMat reduceMat = SquareMat(this->size() - 1);

    for(int k=0; k<this->size(); k++){
        for(int l=0; l<this->size(); l++){
            if(k != i && l != j){
                int index = k;
                int jndex = l;
                // moves the index correctly
                if(k < i)
                    index = k;
                else
                    index = k - 1;
                // moves the jndex correctly
                if(l < j)
                    jndex = l;
                else    
                    jndex = l - 1;
                
                // copies the value at k,l to index,jndex in reduceMat
                reduceMat[index][jndex] = (this->p_matrix)[k][l];
            }   
        }
    }    
    // return the reduceMat
    return reduceMat;
}

std::ostream& operator<< (std::ostream &output, const SquareMat &matrix){
    // goes over each value in the matrix
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            // adds the value i,j to the output
            output << matrix[i][j] << " ";
        }
        // goes down a line
        output << "\n";
    }

    return output;
}