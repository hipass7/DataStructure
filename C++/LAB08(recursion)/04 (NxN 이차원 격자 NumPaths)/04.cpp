#include <iostream>
using namespace std;


int NumPaths(int row, int col, int n) {
    if ((row==n)||(col==n))
        return 1;
    else
        return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);

}

const int MAX_ROWS = 5;
const int MAX_COLS = 5;
static int mat[MAX_ROWS][MAX_COLS];



int NumPaths_C(int row,int col,int n){
    if (mat[row][col] == -1) {
        if ((row == n) || (col == n)) {
            mat[row][col] = 1;
            return 1;
        }
            
        else {
            mat[row][col] = NumPaths_C(row + 1, col, n) + NumPaths_C(row, col + 1, n);
            return mat[row][col];
        }
    }
    else
        return mat[row][col];
}

int main(){
    for (int i = 1; i < MAX_ROWS; i++)
        for (int j = 1; j < MAX_COLS; j++)
            mat[i][j] = -1;

    cout << NumPaths(1, 1, 3) << endl;
    cout << NumPaths_C(1, 1, 3) << endl;

    for (int i = 3; i > 0; i--) {

        for (int j = 1; j < 4; j++) {

            cout << mat[i][j] << " ";

        }

        cout << '\n';
    }
}
