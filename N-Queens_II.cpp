//Attemp #1
//from	2013-09-14 22:44
//to   2013-09-14 22:48
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
    int ans;
    vector<bool> oky,okplus,okminus;
    void dfs(int k,int n){
        if(n==k) ++ans;
        else{
            for(int i=0;i<n;++i){
                if(oky[i]&&okplus[i+k]&&okminus[k-i+n]){
                    oky[i]=okplus[i+k]=okminus[k-i+n]=false; 
                    dfs(k+1,n);
                    oky[i]=okplus[i+k]=okminus[k-i+n]=true;
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        oky.assign(n,true);
        okplus.assign(n+n,true);
        okminus.assign(n+n,true);
        ans=0;
        dfs(0,n);
        return ans;
    }
};
