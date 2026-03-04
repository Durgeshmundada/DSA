class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sol(board);
        return;
    }
    bool sol(vector<vector<char>>& board){
        for (int r = 0; r <9; r++) {
          for (int c =0; c < 9; c++) {
            if(board[r][c]=='.'){
            for(char i='1';i<='9';i++){
            if (solv(board,r,c,i)) {
               board[r][c]=i;
               if(sol(board)){
                return true;
               }
               board[r][c]='.';
            }
            }
            return false;
            }
          }
        }
        return true;
    }
    bool solv(vector<vector<char>>& board,int row, int col,char num){
         for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;   
            if (board[i][col] == num) return false;   
        }
       int startRow = (row / 3) * 3;
       int startCol = (col / 3) * 3;
       for (int r = startRow; r < startRow + 3; r++) {
          for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c]==num) {
            return false;
            }
          }
        }
        return true;
    }
};