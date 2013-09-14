//Attemp #1
//from	2013-09-14 17:30
//to   2013-09-14 17:35
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if(matrix.size()&&matrix[0].size()){
            int n=matrix.size(),m=matrix[0].size();
            vector<vector<bool> > visited(n,vector<bool>(m,false));
            int x=0,y=-1,dir=0;
            for(int i=0;i<n*m;++i){
                int xx=x+dx[dir],yy=y+dy[dir];
                if(xx<0||xx>=n||yy<0||yy>=m||visited[xx][yy]){
                    dir=(dir+1)%4;
                    xx=x+dx[dir];  yy=y+dy[dir];
                }
                ans.push_back(matrix[xx][yy]);
                visited[xx][yy]=true;
                x=xx; y=yy;
            }
        }
        return ans;
    }
};
