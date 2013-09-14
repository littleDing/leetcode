//Attemp #1
//from	2013-09-14 11:38
//to   2013-09-14 11:53
//failed before small AC: CE* + RTE* + WA*2
//failed before large AC: None

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0) return 0;
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int> > ways(n,vector<int>(m,0));
        ways[0][0]=1-obstacleGrid[0][0];
        for(int i=1;i<n;++i) ways[i][0]=(1-obstacleGrid[i][0])*ways[i-1][0];
        for(int j=1;j<m;++j) ways[0][j]=(1-obstacleGrid[0][j])*ways[0][j-1];
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(obstacleGrid[i][j]==0)
                    ways[i][j]=ways[i-1][j]+ways[i][j-1];
            }
        }
        return ways[n-1][m-1];
    }
};
