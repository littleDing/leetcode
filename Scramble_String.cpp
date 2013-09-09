//Attemp #1
//from	2013-09-08 16:18
//to   2013-09-08 17:14
//failed before small AC: CE*2 + RTE* + WA*3
//failed before large AC: None

class Solution {
    bool same(const string &s1,const string& s2){
        for(int i=0;i<s1.length();++i)
            if(s1[i]!=s2[i]) return false;
        return true;
    }
    bool ok(string s1, string s2){
        int len=s1.length();
        if(len==1) return s1[0]==s2[0];
        if(len>=2){
            if(same(s1,s2)) return true;
            vector<int> cnt(128,0);
            for(int i=0;i<len;++i){
                ++cnt[s1[i]];
                --cnt[s2[i]];
            }
            for(int i=0;i<128;++i)
                if(cnt[i]!=0) return false;
            for(int mid=1;mid<len;++mid){
                if(   ok(s1.substr(0,mid),s2.substr(len-mid,mid))
                    &&ok(s1.substr(mid,len-mid),s2.substr(0,len-mid)) )
                    return true;
                if(   ok(s1.substr(0,mid),s2.substr(0,mid))
                    &&ok(s1.substr(mid,len-mid),s2.substr(mid,len-mid)) )
                    return true;
            }
        }
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.length()!=s2.length()) return false;
        if(s1.length()==0) return true;
        return ok(s1,s2);
    }
};
