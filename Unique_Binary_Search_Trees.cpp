//Attemp #1
//from	2013-09-05 08:47
//to   2013-09-05 08:58
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None


class Solution {
    vector<int> ans;
    void fill(int n){
        for(int i=ans.size();i<n;++i)
            fill(i);
        if(n==0||n==1) ans.push_back(1);
        else{
            int ret = 0;
            for(int i=0;i<n;++i){
                ret += ans[i]*ans[n-i-1];
            }
            ans.push_back(ret);
        }
    }
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        else {
            if(n>=ans.size()) fill(n);
            return ans[n];
        }
    }
};

