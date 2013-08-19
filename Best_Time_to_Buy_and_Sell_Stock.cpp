//Attemp #1
//from 	2013-8-20 00:15
//to	2013-8-20 00:20
//failed before small AC: CE* + RTE*1 + WA
//failed before large AC: None

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()==0) return 0;
        int ans=0,pmi=prices[0];
        for(int i=1;i<prices.size();++i){
            ans=max(ans,prices[i]-pmi);
            pmi=min(pmi,prices[i]);
        }
        return ans;
    }
};


