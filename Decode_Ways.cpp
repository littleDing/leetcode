//Attemp #1
//from	2013-09-08 10:05
//to   2013-09-08 10:18
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None

class Solution {
    inline bool ok(string &s,int from){
        int decoded=s[from]*10+s[from+1];
        return 10<=decoded&&decoded<=26;
    }
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length()==0) return 0;
        if(s.length()==1) return s[0]!='0';
        vector<int> ans(s.length(),0);
        for(int i=0;i<s.length();++i)
            s[i]-='0';
        ans[0]=(s[0]==0)?0:1;
        ans[1]=(s[1]==0)?0:ans[0];
        if(ok(s,0)) ans[1]+=1;
        for(int i=2;i<s.length();++i){
            if(s[i]!=0) ans[i]+=ans[i-1];
            if(ok(s,i-1)) ans[i]+=ans[i-2];
        }
        return ans[s.length()-1];
    }
};
