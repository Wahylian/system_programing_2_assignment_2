class MatrixRow{
    private:
    int n; // the length of the row
    int *row; // the pointer to the row

    public:
    MatrixRow(int n, int *row):
    n{n},
    row{row}
    { }

    // returns a reference to the value at index j in the row
    int& operator[] (int j);
};