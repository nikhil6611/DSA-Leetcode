class Solution {
public:
    bool check(vector<vector<char>>& board, int row,int col,char i){
        for(int j=0;j<9;j++){
            if(board[row][j]==i)
                return false;
        }
        for(int j=0;j<9;j++){
            if(board[j][col]==i){
                return false;
            }
        }
        int startrow=(row/3)*3;
        int startcol=(col/3)*3;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                if(board[startrow+r][startcol+c]==i){
                    return false;
                }
            }
        }
        return true;
    }
    bool solver(vector<vector<char>>& board, int row,int col){
        if(row==9){
            return true;
        }
        int nextrow=row;
        int nextcol = col+1;
        if(nextcol==9){
            nextrow = row+1;
            nextcol=0;
        }
        
        if(board[row][col]!='.'){
            return solver(board,nextrow,nextcol);
        }
        else{
            for(char i='1';i<='9';i++){
                if(check(board,row,col,i)){
                    board[row][col]=i;
                    if(solver(board,nextrow,nextcol)){
                        return true;
                    }
                    board[row][col]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};