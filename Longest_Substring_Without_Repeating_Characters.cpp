//Attemp #1
//from	2013-09-21 01:13
//to   2013-09-21 01:27
//failed before small AC: CE*1 + RTE* + WA
//failed before large AC: None

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0, pre=0;
        vector<int> last(128,-1);
        for(int i=0;i<s.length();++i){
            char ch=s[i];
            pre=max(pre,last[ch]+1);
            ans=max(ans,i-pre+1);
            last[ch]=i;
        }
        return ans;
    }
};
