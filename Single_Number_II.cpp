//Attemp #1
//from	2013-10-04 22:23
//to   2013-10-04 22:00
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> bits(32,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<32;++j)
                if(A[i]&(1<<j)) ++bits[j];
        }
        int ans=0;
        for(int i=0;i<32;++i){
            if(bits[i]%3) ans+=(1<<i);
        }
        return ans;
    }
};
