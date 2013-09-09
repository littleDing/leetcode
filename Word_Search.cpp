//Attemp #1
//from	2013-09-09 08:27
//to   2013-09-09 08:49
//failed before small AC: CE* + RTE*1 + WA*2
//failed before large AC: None

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
class Solution {
    vector<vector<bool> > used;
    int xmax,ymax;
    bool ok(const vector<vector<char> > &board, int x, int y, 
            const string &word, int from){
        if(from>=word.length()) return true;
        if(from==word.length()-1) return board[x][y]==word[from];
        if(board[x][y]!=word[from]) return false;
        used[x][y]=true;
        for(int i=0;i<4;++i){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&xx<xmax&&yy>=0&&yy<ymax && !used[xx][yy] && ok(board,xx,yy,word,from+1) ){
                return true;
            }
        }
        used[x][y]=false;
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!board.size()||!board[0].size()) return false;
        xmax=board.size();
        ymax=board[0].size();
        used.assign(xmax,vector<bool>(ymax,false));
        for(int x=0;x<xmax;++x){
            for(int y=0;y<ymax;++y){
                if(ok(board,x,y,word,0)) return true;
            }
        }
        return false;
    }
};
