//Attemp #1
//from	2013-09-17 00:48
//to   2013-09-17 01:11
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<n;++i){
            if(A[i]>=1&&A[i]<=n&&A[A[i]-1]!=A[i]){
                swap(A[i],A[A[i]-1]);
                --i;
            }
        }
        for(int i=0;i<n;++i){
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
