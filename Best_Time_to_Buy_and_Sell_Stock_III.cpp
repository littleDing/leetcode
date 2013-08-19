//Attemp #1
//from 	2013-8-20 00:32
//to	2013-8-20 00:43
//failed before small AC: CE* + RTE*0 + WA*1
//failed before large AC: None

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=prices.size();
        if(n==0) return 0;
        vector<int> l(n),r(n);
        l[0]=r[n-1]=0;
        int pmi=prices[0];
        for(int i=1;i<n;++i){
            l[i] =max(l[i-1],prices[i]-pmi);
            pmi  =min(pmi,prices[i]);
        }
        
        int pma=prices[n-1];
        for(int i=n-2;i>=0;--i){
            r[i] =max(r[i+1],pma-prices[i]);
            pma  =max(pma,prices[i]);
        }
        
        int ans = l[n-1];
        for(int i=2;i<n;++i){
            ans=max(ans,l[i-1]+r[i]);
        }
        return ans;
    }
};
