//Attemp #1
//from	2013-09-14 17:35
//to   2013-09-14 17:42
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return 0;
        vector<int> sum(n+1,0);
        int ans=A[0],mi=0;
        for(int i=0;i<n;++i){
            sum[i+1]=sum[i]+A[i];
            ans=max(ans,sum[i+1]-sum[mi]);
            if(sum[i+1]<sum[mi]) mi=i+1;
        }
        return ans;
    }
};
