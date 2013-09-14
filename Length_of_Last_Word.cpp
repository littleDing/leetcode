//Attemp #1
//from	2013-09-14 12:53
//to   2013-09-14 12:58
//failed before small AC: CE* + RTE* + WA*1 + TLE*1
//failed before large AC: None

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s) return NULL;
        int ans=0;
        for(int l=0;s[l];){
            while(s[l]&&s[l]==' ') ++l;
            if(!s[l]) break;
            int r=l;
            while(s[r]&&s[r]!=' ') ++r;
            ans=r-l;
            l=r;
        }
        return ans;
    }
};


