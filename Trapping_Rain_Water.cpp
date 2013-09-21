//Attemp #1
//from	2013-09-20 11:26
//to   2013-09-20 11:53
//failed before small AC: CE* + RTE*1 + WA*1
//failed before large AC: None

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 0;
        int ans=0;
        stack<int> left;
        for(int i=0;i<n;++i){
            int low=0;
            while(!left.empty()){
                int idx=left.top(),h=min(A[idx],A[i]);
                ans+= (h-low)*(i-idx-1);
                low=h;
                if(A[idx]<=A[i]) left.pop();
                if(A[idx]>=A[i]) break;
            }
            left.push(i);
        }
        return ans;
    }
};
