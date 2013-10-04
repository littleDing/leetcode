//Attemp #1
//from	2013-10-04 12:04
//to   2013-10-04 12:05
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int end=0;
        for(int i=0;i<n;++i){
            if(A[i]!=elem) 
                A[end++]=A[i];
        }
        return end;
    }
};
