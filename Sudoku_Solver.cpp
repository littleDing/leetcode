//Attemp #1
//from	2013-09-20 12:06
//to   2013-09-20 11:57
//failed before small AC: CE*2 + RTE* + WA
//failed before large AC: None

class Solution {
    vector<vector<bool> > usedRow,usedCol,usedGrid;
    vector<pair<int,int> > cells;
    bool dfs(int k,vector<vector<char> > &board){
        if(k==cells.size()) return true;
        else {
            int x=cells[k].first,y=cells[k].second;
            int grid=x/3*3+y/3;
            for(int i=0;i<9;++i){
                if(!usedRow[x][i]&&!usedCol[y][i]&&!usedGrid[grid][i]){
                    board[x][y]='1'+i;
                    usedRow[x][i]=usedCol[y][i]=usedGrid[grid][i]=true;
                    if(dfs(k+1,board)) return true;
                    usedRow[x][i]=usedCol[y][i]=usedGrid[grid][i]=false;
                }
            }
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        usedRow.assign(9,vector<bool>(9,false));
        usedCol.assign(9,vector<bool>(9,false));
        usedGrid.assign(9,vector<bool>(9,false));
        cells.clear();
        for(int x=0;x<9;++x){
            for(int y=0;y<9;++y){
                if(board[x][y]=='.') {
                    cells.push_back(pair<int,int>(x,y));
                }else{
                    int grid=x/3*3+y/3;
                    int i=board[x][y]-'1';
                    usedRow[x][i]=usedCol[y][i]=usedGrid[grid][i]=true;
                }
            }
        }
        dfs(0,board);
    }
};
