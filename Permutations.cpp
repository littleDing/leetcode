//Attemp #1
//from	2013-09-15 00:45
//to   2013-09-15 00:56
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
    vector<bool> used;
    vector<vector<int> > ans;
    void dfs(const vector<int> &num,vector<int> &now){
        if(now.size()==num.size()){
            ans.push_back(now);
        }else{
            for(int i=0;i<num.size();++i){
                if(!used[i]){
                    used[i]=true;   now.push_back(num[i]);
                    dfs(num,now);
                    used[i]=false;  now.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        if(!num.size()) return ans;
        vector<int> now;
        used.assign(num.size(),false);
        dfs(num,now);
        return ans;
    }
};
