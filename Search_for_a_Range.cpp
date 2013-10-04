//Attemp #1
//from	2013-09-20 13:31
//to   2013-09-20 13:06
//failed before small AC: CE* + RTE* + WA*4
//failed before large AC: None


class Solution {
    int lower(int A[],int l,int r,int target){
        //return the max l that A[l]<=target
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(A[mid]<=target) l=mid;
            else r=mid-1;
        }
        return l;
    }
    int upper(int A[],int l,int r,int target){
        //return the min r that A[r]>=target
        while(l<r){
            int mid=l+(r-l)/2;
            if(A[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans(2,-1);
        if(n>0&&A[0]<=target&&A[n-1]>=target){
            int r=lower(A,0,n-1,target);
            int l=upper(A,0,n-1,target);
            if(A[l]==A[r]){
                ans[0]=l;
                ans[1]=r;
            }
        }
        return ans;
    }
};
