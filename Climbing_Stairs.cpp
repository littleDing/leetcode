//Attemp #1
//from	2013-09-12 00:18
//to   2013-09-12 00:31
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
    vector<int> ans;
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=ans.size();i<=n;++i){
            if(i<3) ans.push_back(i);
            else ans.push_back(ans[i-1]+ans[i-2]);
        }
        return ans[n];
    }
};
