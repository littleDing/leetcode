//Attemp #1
//from	2013-10-04 21:35
//to   2013-10-04 21:36
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans=0;
        for(int i=0;i<n;++i) ans^=A[i];
        return ans;
    }
};
