//Attemp #1
//from	2013-09-09 09:03
//to   2013-09-09 09:03
//failed before small AC: CE*1 + RTE* + WA
//failed before large AC: None

class Solution {
    
    void dfs(int n,int from,int need,vector<int> &now,vector<vector<int> > &ans){
        if(need==0) ans.push_back(now);
        else{
            for(int i=from;i<=n;++i){
                now.push_back(i);
                dfs(n,i+1,need-1,now,ans);
                now.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> now;
        vector<vector<int> > ans;
        dfs(n,1,k,now,ans);
        return ans;
    }
};
