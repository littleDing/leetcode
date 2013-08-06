//Attemp #1
//from 	2013-8-7 0:21
//to	2013-8-7 0:37
//failed before small AC: CE* + RTE* + WA*1 + TLE*1
//failed before large AC: None


class Solution {
    bool valid(char ch){
        return (ch>='0'&&ch<='9') || (ch>='a'&&ch<='z');
    }
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return true;
        for(int i=0;i<s.size();++i){
            if(s[i]>='A'&&s[i]<='Z') s[i]-= 'A'-'a';
        }
        int l=-1,r=s.size();
        while(l<=r){
            l++; r--;
            while(l<=r&&!valid(s[l])) l++;
            while(l<=r&&!valid(s[r])) r--;
            if(l<=r&&(s[l]!=s[r]&&s[l])) return false;
        }
        return true;
    }
};
