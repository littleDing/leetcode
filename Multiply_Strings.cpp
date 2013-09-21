//Attemp #1
//from	2013-09-15 22:16
//to   2013-09-15 22:31
//failed before small AC: CE*2 + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1=num1.length(),l2=num2.length();
        if(!l1||!l2) return "";
        for(int i=0;i<l1;++i) num1[i]-='0';
        for(int i=0;i<l2;++i) num2[i]-='0';
        vector<int> buff(l1+l2,0);
        for(int i=l1-1;i>=0;--i){
            for(int j=l2-1;j>=0;--j){
                buff[i+j] += num1[l1-1-i]*num2[l2-1-j];
            }
        }
        int extra=0;
        for(int i=0;i<buff.size();++i){
            buff[i]+=extra;
            extra=buff[i]/10;
            buff[i]%=10;
        }
        while(buff.size()>1&&buff[buff.size()-1]==0) buff.pop_back();
        int lans=buff.size();
        string ans(lans,'0');
        for(int i=0;i<lans;++i)
            ans[i]='0'+buff[lans-1-i];
        return ans;
    }
};
