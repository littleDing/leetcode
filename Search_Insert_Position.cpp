//Attemp #1
//from	2013-09-20 12:24
//to   2013-09-20 12:28
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0||A[0]>=target) return 0;
        if(A[n-1]<target) return n;
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(A[mid]==target) return mid;
            else if(A[mid]<target) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
