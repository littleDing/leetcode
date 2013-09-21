//Attemp #1
//from	2013-09-20 11:18
//to   2013-09-20 11:25
//failed before small AC: CE*1 + RTE* + WA
//failed before large AC: None

class Solution {
    string say(string tosay){
        char now=tosay[0];
        int cnt =1;
        string ret="";
        for(int i=1;i<tosay.length();++i){
            if(tosay[i]==now) ++cnt;
            else {
                ret+=to_string(cnt)+string(1,now);
                now=tosay[i]; cnt=1;
            }
        }
        ret+=to_string(cnt)+string(1,now);
        return ret;
    }
    vector<string> ans;
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return "";
        for(int i=ans.size();i<=n;++i){
            if(i==0) ans.push_back("");
            else if(i==1) ans.push_back("1");
            else ans.push_back(say(ans[i-1]));
        }
        return ans[n];
    }
};
