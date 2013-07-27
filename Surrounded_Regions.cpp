//Attemp #1
//from 	2013-7-27 10:32
//to	2013-7-27 10:53
//failed before small AC: CE*1 + RTE*0 + WA*0
//failed before large AC: None

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
class Solution {
    struct node{
        int x,y;
        node(int _x,int _y):x(_x),y(_y){
            
        }
    };
    int n,m;
    void bfs(int x,int y,char from,char to,vector<vector<char>> &board){
        if(board[x][y]!=from) return ;
        board[x][y] = to;
        node now(x,y);
        queue<node> qqq; qqq.push(now);
        while(!qqq.empty()){
            now = qqq.front(); qqq.pop();
            for(int i=0;i<4;++i){
                node next(now.x+dx[i],now.y+dy[i]);
                if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m){
                    if(board[next.x][next.y]==from){
                        board[next.x][next.y] = to;
                        qqq.push(next);
                    }
                }
            }
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size()==0||board[0].size()==0) return ;
        n=board.size(); m=board[0].size();
        //bfs boundaries first to mark 'O's to 'o'
        for(int i=0;i<n;++i){
            bfs(i,0,'O','o',board);
            bfs(i,m-1,'O','o',board);
        }
        for(int j=0;j<m;++j){
            bfs(0,j,'O','o',board);
            bfs(n-1,j,'O','o',board);
        }
        //mark remaining 'O's
        for(int i=1;i+1<n;++i){
            for(int j=1;j+1<m;++j){
                bfs(i,j,'O','X',board);
            }
        }
        //recover the 'o's to 'O'
        for(int i=0;i<n;++i){
            bfs(i,0,'o','O',board);
            bfs(i,m-1,'o','O',board);
        }
        for(int j=0;j<m;++j){
            bfs(0,j,'o','O',board);
            bfs(n-1,j,'o','O',board);
        }
    }
};
