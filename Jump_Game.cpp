//Attemp #1
//from	2013-09-14 17:18
//to   2013-09-14 17:29
//failed before small AC: CE* + RTE* + WA*0
//failed before large AC: TLE*1 + WA*3


class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return false;
        vector<int> ok(n+1,0);
        ok[n-1]=1;
        for(int i=n-2;i>=0;--i){
            bool yes=false;
            if(i+A[i]>=n) yes=true;
            else {
                if(A[i]&&ok[i+1]-ok[i+A[i]+1]) yes=true;
            }
            ok[i]=ok[i+1]+yes;
        }
        return ok[0]-ok[1]==1;
    }
};
