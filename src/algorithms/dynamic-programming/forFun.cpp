#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

    bool myCheck(vector<int> chain,int indexCell,int col){
        if(chain.empty()){
            return true;
        }
        int lastIndex = chain.back();
        if(abs(lastIndex - indexCell)==1 || abs(lastIndex - indexCell) == col){
            return true;
        }
        return false;
    }

    bool helper(vector<vector<char>>& board,unordered_map<char,vector<int>> letters, string word,int col,int row){
        vector<vector<int>> chains;
        bool flag = true;
        for(auto letter: word){
            int check = 0;
            for(auto indexCell: letters[letter]){
                if(flag){
                    vector<int> chainTemp{indexCell};
                    chains.push_back(chainTemp);
                    check++;
                }
                else{
                    for(auto chain: chains){
                        // neu +-1 +- col cai top. thi oke
                        if(myCheck(chain,indexCell,col)){
                            chain.push_back(indexCell);
                            check++;
                        }
                    }
                }
            }
            if(check == 0) return false;
            flag = false;
        }
        return true;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>result;
        int row = board.size();
        int col = board[0].size();
        unordered_map<char,vector<int>> letters;

        for(int iRow = 0;iRow<row;iRow++){
            for(int iCol = 0;iCol<col;iCol++){
                letters[board[iRow][iCol]].push_back(iRow*row+iCol);
            }
        }

        for(auto word: words){
            if(helper(board,letters,word,col,row)){
                result.push_back(word);
            }
        }
        return result;
    }

int main(){
    vector<vector<char>> board{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','r','v'}};
    vector<string> words{"oath","eat","hoang"};
    vector<string> results = findWords(board,words);
    for(auto result:results){
        cout<<result;
    }
}
