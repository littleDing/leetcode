//Attemp #1
//from	2013-09-08 10:19
//to   2013-09-08 10:25
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a=m-1,b=n-1;
        for(int i=m+n-1;i>=0&&b>=0;--i){
            if(a>=0&&A[a]>B[b]){
                A[i]=A[a];
                --a;
            }else{
                A[i]=B[b];
                --b;
            }
        }
    }
};
