//Attemp #1
//from 	2013-7-27 22:50
//to	2013-7-27 23:19
//failed before small AC: CE*0 + RTE*0 + WA*1
//failed before large AC: None


class Solution {
    struct Checker{
       bool ok[9];
       Checker(){ reset(); }
       void reset(){for(int i=0;i<9;++i) ok[i]=true;}
       bool set(int i){ 
           if(ok[i]){ ok[i]=false; return true; }
           else return false;   
       }
    };
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        Checker checker;
        for(int i=0;i<9;++i){
            //check rows
            checker.reset();
            for(int j=0;j<9;++j){
                char ch = board[i][j];
                if(ch!='.' && !checker.set(ch-'1')) return false;
            }
            //check columns
            checker.reset();
            for(int j=0;j<9;++j){
                char ch = board[j][i];
                if(ch!='.' && !checker.set(ch-'1')) return false;
            }
        }
        //check blocks
        for(int x=0;x<9;x+=3){
            for(int y=0;y<9;y+=3){
                checker.reset();
                for(int i=0;i<3;++i){
                    for(int j=0;j<3;++j){
                        char ch = board[x+i][y+j];
                        if(ch!='.' && !checker.set(ch-'1')) return false;
                    }
                }
            } 
        }
        return true;
    }
};
