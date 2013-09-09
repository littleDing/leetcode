//Attemp #1
//from	2013-09-09 08:04
//to   2013-09-09 08:21
//failed before small AC: CE*1 + RTE*1 + WA*2
//failed before large AC: None


class Solution {
    bool exists(int a[],int ll,int rr,int target){
        int l=ll,r=rr;
        while(l<r){
            int m=l+(r-l)/2;
            if(a[m]==target) return true;
            if(a[l]<a[m]){
                if(a[l]<=target&&target<=a[m]) r=m;
                else l=m+1;
            }else if(a[m]<a[r]){
                if(a[m]<=target&&target<=a[r]) l=m+1;
                else r=m;
            }else{
                return exists(a,l,m,target)||exists(a,m+1,r,target);
            }
        }
        if(l>=ll&&l<=rr) return a[l]==target;
        return false;
    }
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n&&(A[0]==target||A[n-1]==target)) return true;
        return exists(A,0,n-1,target);
    }
};
