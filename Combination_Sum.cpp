//Attemp #1
//from	2013-09-16 09:08
//to   2013-09-16 09:12
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
    vector<vector<int> > ans;
    void dfs(vector<int> &candidates,int from,int target,vector<int> now){
        if(target==0) ans.push_back(now);
        else{
            for(int i=from;i<candidates.size()&&candidates[i]<=target;++i){
                now.push_back(candidates[i]);
                dfs(candidates,i,target-candidates[i],now);
                now.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        vector<int> now;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target,now);
        return ans;
    }
};
