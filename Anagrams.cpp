//Attemp #1
//from	2013-09-14 23:09
//to   2013-09-14 23:42
//failed before small AC: CE* + RTE* + WA*7
//failed before large AC: None

bool operator < (const vector<int> &a, const vector<int> &b){
    if(a.size()==b.size()){
        for(int i=0;i<a.size();++i){
            if(a[i]!=b[i]) return a[i]<b[i];
        }
        return false;
    }else return a.size()<b.size();
}
bool operator == (const vector<int> &a, const vector<int> &b){
    if(a.size()==b.size()){
        for(int i=0;i<a.size();++i){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    return false;
}

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        map<vector<int>,int> exists;
        vector<bool> used(strs.size(),false);
        for(int i=0;i<strs.size();++i){
            //if(!strs[i].length()) continue;
            vector<int> hashing(26,0);
            for(int j=0;j<strs[i].length();++j)
                ++hashing[strs[i][j]-'a'];
            if(exists.count(hashing)==0){
                exists[hashing]=i;
            }else{
                int idx=exists[hashing];
                if(!used[idx]) ans.push_back(strs[idx]);
                used[idx]=true;
                ans.push_back(strs[i]);
            }
        }
        return ans;
    }
};
