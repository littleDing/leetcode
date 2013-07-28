//Attemp #1
//from 	2013-7-28 10:33
//to	2013-7-28 10:39
//failed before small AC: CE* + RTE*1 + WA*1
//failed before large AC: None

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans[2];
        int current=1;
        for(int k=0;k<=rowIndex;++k){
            current = 1-current;
            ans[current].resize(k+1);
            int before = 1-current;
            ans[current][0]=ans[current][k]=1;
            for(int i=1;i<k;++i)
                ans[current][i] = ans[before][i-1]+ans[before][i];
        }
        return ans[current];
    }
};
