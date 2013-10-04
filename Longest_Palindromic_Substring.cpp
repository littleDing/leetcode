//Attemp #1
//from	2013-09-21 01:27
//to   2013-09-21 01:36
//failed before small AC: CE*1 + RTE* + WA
//failed before large AC: None


class Solution {
    bool ok(const string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            ++l; --r;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=-1;
        string ans="";
        for(int l=0;l<s.length();++l){
            for(int r=l+len+1;r<s.length();++r){
                if(ok(s,l,r)&&r-l>len){
                    len=r-l;
                    ans=s.substr(l,len+1);
                }
            }
        }
        return ans;
    }
};
