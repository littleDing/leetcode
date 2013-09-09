//Attemp #1
//from	2013-09-09 08:50
//to   2013-09-09 08:56
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
    void dfs(vector<int> &s,int from,vector<int>& now,vector<vector<int> >& ans){
        if(from>=s.size()) ans.push_back(now);
        else{
            int cnt=from+1;
            while(cnt<s.size()&&s[cnt]==s[from]) ++cnt;
            cnt-=from;
            for(int i=0;i<=cnt;++i){
                if(i) now.push_back(s[from]);
                dfs(s,from+cnt,now,ans);
            }
            for(int i=1;i<=cnt;++i)
                now.pop_back();
        }
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        vector<vector<int> > ans;
        vector<int> now;
        dfs(S,0,now,ans);
        return ans;
    }
};
