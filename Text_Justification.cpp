//Attemp #1
//from	2013-09-12 01:01
//to   2013-09-12 01:30
//failed before small AC: CE*1 + RTE* + WA*5
//failed before large AC: None

class Solution {
    string format(vector<string> &words,int from,int to,int s,int L){
        int n=to-from;
        string ans=words[from];
        if(n==0){
            for(int i=words[from].length();i<L;++i){
                ans+=" ";
            }
        }else{
            int extra=L-s,every=extra/n,mod=extra%n;
            string space = " ";
            for(int j=0;j<every;++j)
                space += " ";
            for(int i=1;i<=n;++i){
                ans +=space;
                if(i<=mod) ans+=" ";
                ans += words[from+i];
            }
        }
        return ans;
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        int s=0,from=0;
        for(int i=0;i<words.size();++i){
            int space=(s!=0);
            if(s+space+words[i].length()>L){
                ans.push_back(format(words,from,i-1,s,L));
                s=0; from=i;
                space=0;
            }
            s+=words[i].length()+space;
        }
        if(from<words.size()) {
            string tmp=words[from];
            for(int i=from+1;i<words.size();++i){
                tmp += " " + words[i];
            }
            for(int i=tmp.length();i<L;++i){
                tmp += " ";
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
