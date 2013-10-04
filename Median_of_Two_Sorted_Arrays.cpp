//Attemp #1
//from	2013-09-21 12:30
//to   2013-09-21 01:02
//failed before small AC: CE* + RTE* + WA*3 + TLE*2
//failed before large AC: None

int findKth(int a[],int m,int b[],int n,int k){
    //assure len(a)>=len(b)
    if(!(m>=n))  return findKth(b,n,a,m,k); //{  swap(a,b); swap(m,n);  }
    if(n==0) return a[k-1];
    if(k==1) return min(a[0],b[0]);
    int db=min(n,k/2),da=k-db;
    if(a[da-1]<b[db-1]) return findKth(a+da,m-da,b,n,k-da);
    else return findKth(a,m,b+db,n-db,k-db);
}

class Solution {
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int need=(m+n)/2,odd=(m+n)%2;
        if(odd) return findKth(A,m,B,n,need+odd);
        else return (findKth(A,m,B,n,need)+findKth(A,m,B,n,need+1))/2.0;
    }
};
