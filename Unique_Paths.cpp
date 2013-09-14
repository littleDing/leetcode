//Attemp #1
//from	2013-09-14 11:05
//to   2013-09-14 11:11
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0||n==0) return 0;
        vector<vector<int> > ways(m,vector<int>(n,0));
        for(int i=0;i<m;++i) ways[i][0]=1;
        for(int j=0;j<n;++j) ways[0][j]=1;
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                ways[i][j]=ways[i-1][j]+ways[i][j-1];
            }
        }
        return ways[m-1][n-1];
    }
};
