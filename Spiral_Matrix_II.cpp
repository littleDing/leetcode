//Attemp #1
//from	2013-09-14 12:46
//to   2013-09-14 12:52
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(n,vector<int>(n,0));
        int x=0,y=-1,dir=0;
        for(int i=1;i<=n*n;++i){
            int xx=x+dx[dir],yy=y+dy[dir];
            if(xx<0||xx>=n||yy<0||yy>=n||ans[xx][yy]!=0){
                dir = (dir+1)%4;
                xx=x+dx[dir],yy=y+dy[dir];
            }
            ans[xx][yy]=i;
            x=xx; y=yy;
        }
        return ans;
    }
};
