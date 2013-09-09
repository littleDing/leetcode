//Attemp #1
//from	2013-09-09 08:22
//to   2013-09-09 08:26
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return 0;
        int cnt=1;
        for(int i=1;i<n;++i){
            if(A[i]!=A[cnt-1])
                A[cnt++]=A[i];
        }
        return cnt;
    }
};
