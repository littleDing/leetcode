//Attemp #2
//from	2013-09-20 16:12
//to   2013-09-20 16:37
//failed before small AC: CE* + RTE* + WA*4
//failed before large AC: None

class Solution {
    int solve(int A[],int l,int r,int target){
        if(l>r) return -1;
        if(A[l]<=A[r]){
            while(l<r){
                int mid=l+(r-l)/2;
                if(A[mid]==target) return mid;
                else if(A[mid]<target) l=mid+1;
                else r=mid;
            }
            if(A[l]==target) return l;
        }else{
            int mid=l+(r-l)/2;
            if(A[mid]==target) return mid;
            int fl=solve(A,l,mid-1,target);
            if(fl!=-1) return fl;
            int fr=solve(A,mid+1,r,target);
            return fr;
        }
        return -1;
    }
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return -1;
        int l=0,r=n-1;
        return solve(A,l,r,target);
    }
};
