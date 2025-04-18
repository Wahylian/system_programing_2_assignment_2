<h1> Project 2 - System Programing 2</h1>
<h3> By: Ido Ron <br/>
 ID: 215312729</h3>

<h2> This Project Includes: </h2>

### **Features**

1.  **A [Main](main.cpp) file which allows you to run a basic demo of the operators that can be used on the SquareMat class objects**<br/>
    The file will showcase the following:
    * Arithmetic Operations on Matrices
    * Unary Minus Operator
    * Increase and Decrease Operators 
    * Transpose Unary Operator
    * Accessing Specific Values in a Matrix
    * Comparison Operators
    * Determinant Unary Operator
    * Compound Arithmetic Operations on Matrices
    * An output Operator
2. **A [Tests](Tests) folder** which runs tests on the operators of the Matrix.
3. **A [MAKEFILE](Makefile)** allowing to run the following commands: <br/>
    * **make Main** <br/>
    Which creates a Main executable file that runs the main.cpp file.
    * **make valgrind** <br/>
    Which runs the Main exectuable with Valgrind to check for Memory Leaks.
    * **make test** <br/>
    Which creates a test executable file that runs all the test files in the project.
    * **make valgrind-test** <br/>
    Which runs the test executable file with Valgrind to check for Memory Leaks (Some of the tests are built to check for Mmemory Leaks).
    * **make clean** <br/>
    Which removes all object and executable files from the project.
4. **A [General Helpers](generalHelpers.cpp) file** that has some functions that were of use in the matrix class but are not related to it.
