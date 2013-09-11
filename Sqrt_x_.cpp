//Attemp #1
//from	2013-09-12 00:35
//to   2013-09-12 01:00
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long l=0,r=x;
        while(l<r){
            long long mid=(r+l)/2;
            long long tmp=mid*mid;
            if(tmp==x) return mid;
            else if(tmp>x) r=mid-1;
            else l=mid+1;
        }
        if(l*l>x) --l;
        return l;
    }
};
