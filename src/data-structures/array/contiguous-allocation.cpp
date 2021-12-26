#include <iostream>

using namespace std;

class Matrix {
    int row, col;
    int *block;
    // 123
   public:
    Matrix(int row, int col) {
        this->row = row;
        this->col = col;
        this->block = new int[row*col];
    }
    ~Matrix() { delete[] block; }
    int getRow() { return row; }
    int getCol() { return col; }

    int &at(int iRow, int iCol) {
        //TODO
        return *(this->block + iRow*this->col+iCol);
    }
};

// []

void contiguousAllocationClass() {
    Matrix matrix(2, 3);
    // Test
    int count = 0;
    for (int iRow = 0; iRow < matrix.getRow(); iRow++) {
        for (int iCol = 0; iCol < matrix.getCol(); iCol++) {
            matrix.at(iRow, iCol) = ++count;
        }
    }
    for (int iRow = 0; iRow < matrix.getRow(); iRow++) {
        for (int iCol = 0; iCol < matrix.getCol(); iCol++) {
            cout << matrix.at(iRow, iCol) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void contiguousAllocationPointer() {
    int row = 3, col = 4;
    int **arr;
    // TODO: Allocate one contigous block
    /*
    int a[3][4] <=> 3 times int [4]
    Case 1:
        arr = new int*[row];
        for(int i=0;i<row;i++){
            arr[i] = new int[col]; 
        }
    => fragmentation: cause 3times int[4] in different place.
    */
    // Case 2:
    //allocate row*col blocks -> set index
    arr =new int*[row];
    *arr = new int[row*col];
    for(int i=1;i<row;i++){
        arr[i] = *arr+i*col;
        // arr[i] = arr[i-1] + col;
    }

    // Test
    int count = 0;
    for (int iRow = 0; iRow < row; iRow++) {
        for (int iCol = 0; iCol < col; iCol++) {
            arr[iRow][iCol] = ++count;
        }
    }
    for (int iRow = 0; iRow < row; iRow++) {
        for (int iCol = 0; iCol < col; iCol++) {
            cout << arr[iRow][iCol] << " ";
        }
        cout << "\n";
    }
    // delete 2 time and assign arr = NULL to avoid daling reference
    delete[] *arr;
    delete[] arr;
    arr=NULL;
}

int main() {
    // contiguousAllocationClass();
    contiguousAllocationPointer();

    return 0;
}
