//Attemp #1
//from	2013-09-09 08:27
//to   2013-09-09 08:31
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return 0;
        int cnt=1;
        bool dup=false;
        for(int i=1;i<n;++i){
            if(A[i]==A[cnt-1]){
                if(!dup) A[cnt++]=A[i];
                dup=true;
            }else{
                dup=false;
                A[cnt++]=A[i];
            }
        }
        return cnt;
    }
};
