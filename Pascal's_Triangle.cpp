//Attemp #1
//from 	2013-7-28 10:24
//to	2013-7-28 10:30
//failed before small AC: CE*0 + RTE*0 + WA*0
//failed before large AC: None

class Solution {
    vector<vector<int>> ans;
    void add_on(int k){
        ans[k].resize(k+1);
        ans[k][0]=ans[k][k]=1;
        for(int i=1;i<k;++i){
            ans[k][i] = ans[k-1][i-1] + ans[k-1][i];    
        }
    }
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.resize(numRows);
        for(int i=0;i<numRows;++i)
            add_on(i);
        return ans;
    }
};
