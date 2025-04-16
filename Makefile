# rido1607@gmail.com
CXX=clang++
CXXFLAGS=-Wall -Werror -std=c++2a 

# object files for the data structures
OBJS_DS = matrix.o generalHelpers.o

MAIN_OBJ = main.o $(OBJS)

# object files for the test files
TEST_OBJ = tests/test.o matrix.o generalHelpers.o tests/testGeneralMatrixFunctions.o tests/testArithmeticOperations.o \
	tests/testIncrAndDecrOperations.o tests/testComparisonOperations.o tests/testCompoundOperations.o

# valgrind flags, taken from course site, folder 02-classes-constructors-destructors: the makefile in the valgrind folder
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99 

# creates the main executable
Main: $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o Main $(MAIN_OBJ)

# turns the specified cpp file into an object file with the same name
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: Main
	valgrind $(VALGRIND_FLAGS) ./Main

# creates a test executable for the test files
test: $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o test $(TEST_OBJ)

# checks for memory leaks during the tests
valgrind-test: test
	valgrind $(VALGRIND_FLAGS) ./test

clean:
	rm -f *.o tests/*.o Main test

.PHONY: clean 