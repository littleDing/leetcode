//Attemp #1
//from 	2013-8-20 00:22
//to	2013-8-20 00:31
//failed before small AC: CE* + RTE*0 + WA*1
//failed before large AC: None


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        if(prices.size()!=0) {
            int in=prices[0],out=prices[0];
            for(int i=1;i<prices.size();++i){
                if(prices[i]>prices[i-1]) {
                    out=prices[i];
                }else if(prices[i]<prices[i-1]){
                    ans+=out-in;
                    in=out=prices[i];
                }
            }
            ans+=out-in;
        }
        return ans;
    }
};
