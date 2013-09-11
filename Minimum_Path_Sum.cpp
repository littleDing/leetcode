//Attemp #1
//from	2013-09-12 02:03
//to   2013-09-12 02:08
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!grid.size()||!grid[0].size()) return 0;
        int n=grid.size(),m=grid[0].size();
        for(int i=1;i<n;++i)
            grid[i][0]+=grid[i-1][0];
        for(int j=1;j<m;++j)
            grid[0][j]+=grid[0][j-1];
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[n-1][m-1];
    }
};
