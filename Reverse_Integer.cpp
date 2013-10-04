//Attemp #1
//from	2013-09-21 01:37
//to   2013-09-21 01:42
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None


class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        bool under=x<0;
        if(under) x=-x;
        while(x){
            ans=ans*10+x%10;
            x/=10;
        }
        if(under) ans=-ans;
        return ans;
    }
};
