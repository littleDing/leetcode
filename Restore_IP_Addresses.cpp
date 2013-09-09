//Attemp #1
//from	2013-09-06 02:45
//to   2013-09-06 03:00
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None

class Solution {
    vector<string> ans;
    int toInt(const string& s){
        int ret=0;
        for(int i=0;i<s.length();++i)
            ret=ret*10+s[i]-'0';
        return ret;
    }
    void dfs(string s,string now,int left){
        int len=s.length();
        if(left*3<len||len<left) return ;
        if(left==1) {
            int num=toInt(s);
            if(num<=255&&!(s[0]=='0'&&len>1)){
                ans.push_back(now+s);
            }
        }else if(s[0]=='0'){
            dfs(s.substr(1),now+"0.",left-1);
        }else{
            for(int i=1;i<=3;++i){
                if(len>i&&toInt(s.substr(0,i))<=255){
                    dfs(s.substr(i),now+s.substr(0,i)+'.',left-1);
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        if(s.length()){
            dfs(s,"",4);
        }
        return ans;
    }
};
