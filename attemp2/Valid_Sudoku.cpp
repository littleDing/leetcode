//Attemp #2
//from	2013-09-20 12:07
//to   2013-09-20 12:22
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
    vector<vector<bool> > usedRow,usedCol,usedGrid;
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        usedRow.assign(9,vector<bool>(9,false));
        usedCol.assign(9,vector<bool>(9,false));
        usedGrid.assign(9,vector<bool>(9,false));
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                int g=i/3*3+j/3;
                char ch=board[i][j];
                if(ch=='.') continue;
                int k=ch-'1';
                if(usedRow[i][k]||usedCol[j][k]||usedGrid[g][k]) return false;
                usedRow[i][k]=usedCol[j][k]=usedGrid[g][k]=true;
            }
        }
        return true;
    }
};
