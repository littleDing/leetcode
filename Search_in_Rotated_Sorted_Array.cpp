//Attemp #1
//from	2013-09-09 07:48
//to   2013-09-09 08:03
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
    int binary_search(int A[],int from,int to,int target){
        return -1;
    }
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return -1;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(A[m]==target) return m;
            if(A[l]<=A[m]){
                if(A[l]<=target&&target<=A[m]) r=m;
                else l=m+1;
            }else{
                if(A[m]<=target&&target<=A[r]) l=m+1;
                else r=m;
            } 
        }
        return -1;
    }
};
