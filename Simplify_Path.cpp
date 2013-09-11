//Attemp #1
//from	2013-09-11 23:53
//to   2013-09-12 00:11
//failed before small AC: CE*2 + RTE*1 + WA*1
//failed before large AC: None

class Solution {
    void check(stack<string> &subs,const string &tmp){
        if(tmp.length()==0) return ;
        if(tmp==".."){
            if(!subs.empty())
                subs.pop();
        }else if(tmp!="."){
            subs.push(tmp);
        }
    }
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!path.length()) return "";
        stack<string> subs;
        int from=1;
        for(int i=1;i<path.length();++i){
            if(path[i]=='/'){
                string tmp=path.substr(from,i-from);
                check(subs,tmp);
                from=i+1;
            }
        }
        if(from<path.length())
            check(subs,path.substr(from,path.length()-from));
        string ans="";
        stack<string> qsubs;
        while(!subs.empty()){
            qsubs.push(subs.top());
            subs.pop();
        }
        while(!qsubs.empty()){
            ans=ans+"/"+qsubs.top();
            qsubs.pop();
        }
        if(ans.length()==0) ans="/";
        return ans;
    }
};
