//Attemp #1
//from	2013-09-14 22:50
//to   2013-09-14 23:06
//failed before small AC: CE* + RTE* + WA*3 + TLE*3
//failed before large AC: None

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long nn=n;
        bool reverse=false;
        if(nn<0){
            reverse=true;
            nn=-nn;
        }
        double ans=1;
        double now=x;
        while(nn){
            if(nn&1) ans*=now;
            now = now*now;
            nn>>=1;
        }
        if(reverse) ans=1/ans;
        return ans;
    }
};


