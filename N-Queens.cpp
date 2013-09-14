//Attemp #1
//from	2013-09-14 22:22
//to   2013-09-14 22:44
//failed before small AC: CE* + RTE*5 + WA
//failed before large AC: None

class Solution {
    vector<int> pos;
    vector<bool> oky,okplus,okminus;
    vector<vector<string> > ans;
    void generate(int n){
        vector<string> ret(n,string(n,'.'));
        for(int i=0;i<n;++i){
            ret[i][pos[i]]='Q';
        }
        ans.push_back(ret);
    }
    void dfs(int k,int n){
        if(k==n){
            generate(n);
        }else{
            for(int i=0;i<n;++i){
                if(oky[i]&&okplus[k+i]&&okminus[k-i+n]){
                    oky[i]=okplus[k+i]=okminus[k-i+n]=false;
                    pos[k]=i;
                    dfs(k+1,n);
                    oky[i]=okplus[k+i]=okminus[k-i+n]=true;
                }
            }
        }
    }
    void init(int n){
        ans.clear();
        pos.assign(n,0);
        oky.assign(n,true);
        okplus.assign(n+n,true);
        okminus.assign(n+n,true);
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init(n);
        dfs(0,n);
        return ans;
    }
};
