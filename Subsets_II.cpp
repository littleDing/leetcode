//Attemp #1
//from	2013-09-08 9:49
//to   2013-09-08 10:01
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None

class Solution {
    void dfs(const vector<int> &S,int from,vector<int> &now,vector<vector<int> > &ans){
        if(from>=S.size()){
            ans.push_back(now);
        }else{
            int l=1;
            for(;from+l<S.size()&&S[from]==S[from+l];++l);
            dfs(S,from+l,now,ans);
            for(int i=1;i<=l;++i){
                now.push_back(S[from]);
                dfs(S,from+l,now,ans);
            }
            for(int i=1;i<=l;++i)
                now.pop_back();
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        vector<vector<int> > ans;
        vector<int> now;
        dfs(S,0,now,ans);
        return ans;
    }
};
