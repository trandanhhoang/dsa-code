#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;
// closed tour, last move  = first move + 1 move(8ways)
// CONDITION OPEN TOUR: 3 condition
// m và n đều là lẻ
// m = 1, 2, hoặc 4; n khác 1
// m = 3 và n = 4, 6, hoặc 8

#define ROW 10
#define COL 3
// |  1|   |   |   |   |
// | 12|   |   |   |   |
// |   |   |   |   |   |
// |   |   |   |   |   |
// |   |   |   |   |   |
void print(vector<vector<int>> board,int row,int col){
    for(int i=0;i<row;i++){
        cout<<"|";
        for(int j = 0 ;j < col;j++){
            cout<<setw(2)<<board[i][j]<<"|";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

int w_row[] = {-2,-1,1,2,2,1,-1,-2};
int w_col[] = {1,2,2,1,-1,-2,-2,-1};
int first_row = 0, fisrt_col = 0;

void knightTour(vector<vector<int>> &board, int i_place, int i_row,int i_col){
    // finish tour
    if(i_place > ROW*COL){
        //conditon CLOSE TOUR
        for(int i=0;i<8;i++){
            if(i_row == first_row + w_row[i] && i_col == fisrt_col + w_col[i]){
                print(board,ROW,COL);
            }
        }
        //no need conditon with OPEN TOUR
        // print(board,ROW,COL);
        return;
    }
    // tour ++ with 8 ways to move
    for(int i=0;i<8;i++){
        int i_test_row = i_row, i_test_col = i_col;
        i_test_row+=w_row[i];
        i_test_col+=w_col[i];
        if(i_test_row >= ROW || i_test_col >= COL||i_test_row < 0 ||i_test_col<0){
            continue;
        }
        //check
        if(board[i_test_row][i_test_col] == 0){
            board[i_test_row][i_test_col] = i_place;
            knightTour(board,i_place+1,i_test_row,i_test_col);
            board[i_test_row][i_test_col] = 0;
        }
    }

}

int main(){
    vector<vector<int>> board(ROW);
    for(int i = 0; i < ROW ;i++){
        vector<int> new_vector(COL);
        board[i] = new_vector;
    }
    
    board[first_row][fisrt_col] = 1;

    knightTour(board,2,first_row,fisrt_col);
}
