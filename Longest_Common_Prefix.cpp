//Attemp #1
//from	2013-09-21 17:17
//to   2013-09-21 17:22
//failed before small AC: CE*1 + RTE* + WA
//failed before large AC: None

bool cmp(const string& a,const string& b){
    return strcmp(a.c_str(),b.c_str())<0;
}

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!strs.size()) return "";
        sort(strs.begin(),strs.end());
        string ans=strs[0];
        for(int i=1;i<strs.size();++i){
            int len=0;
            for(len=0;len<ans.length()&&len<strs[i].length()&&ans[len]==strs[i][len];++len);
            if(len<ans.length()) ans=strs[i].substr(0,len);
        }
        return ans;
    }
};
