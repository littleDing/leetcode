//Attemp #1
//from 	2013-7-27 10:05
//to	2013-7-27 10:28
//failed before small AC: CE*3 + RTE*1
//failed before large AC: None

class Solution {
    vector<vector<bool> > ok;
    void make_ok(const string& s){
        const int l = s.size();
        ok.resize(l);
        for(int i=0;i<l;++i){
            ok[i].resize(l);
            ok[i][i]=true;
            for(int j=i+1;j<l;++j) ok[i][j]=false;
            if(i+1<l&&s[i]==s[i+1]) ok[i][i+1] = true;
            
        }
        for(int i=l-3;i>=0;--i){
            for(int j=i+2;j<l;++j){
                if(s[i]==s[j]&&ok[i+1][j-1])
                    ok[i][j]=true;
            }
        }
    }
    void output(vector<int> &parts,const string& s,vector<vector<string>> &ans){
        int from = parts.back()+1;
        if(from==s.size()){
            //do output
            vector<string> out;
            for(int i=1;i<parts.size();++i){
                int f = parts[i-1]+1,t=parts[i];
                out.push_back(s.substr(f,t-f+1));
            }
            ans.push_back(out);
        }else{
            //search 
            for(int to=from;to<s.size();++to){
                if(ok[from][to]){
                    parts.push_back(to);
                    output(parts,s,ans);
                    parts.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        make_ok(s);
        vector<int> parts; parts.push_back(-1);
        vector<vector<string>> ans;
        output(parts,s,ans);
        return ans;
    }
};


