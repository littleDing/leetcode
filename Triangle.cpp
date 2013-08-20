//Attemp #1
//from 	2013-8-21 00:44
//to	2013-8-21 00:50
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=triangle.size();
        if(n==0) return 0;
        vector<int> ans(n);
        for(int i=0;i<n;++i) ans[i]=triangle[n-1][i];
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                ans[j]=min(ans[j],ans[j+1])+triangle[i][j];
            }
        }
        return ans[0];
    }
};
