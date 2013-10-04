//Attemp #1
//from	2013-09-25 01:00
//to   2013-09-25 01:39
//failed before small AC: CE* + RTE*2 + WA*2
//failed before large AC: None

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        vector<int> ends(s.length(),0);
        for(int i=1;i<s.length();++i){
            if(s[i]==')'){
                if(i-ends[i-1]-1>=0&&s[i-ends[i-1]-1]=='(')
                    ends[i]=ends[i-1]+2;
                if(i-ends[i]>=0&&s[i-ends[i]]==')')
                    ends[i]+=ends[i-ends[i]];
            }else ends[i]=0;
            ans=max(ans,ends[i]);
        }
        return ans;
    }
};
