//Attemp #1
//from	2013-09-22 00:43
//to   2013-09-22 01:33
//failed before small AC: CE*3 + RTE*4 + WA*5 + TLE*6
//failed before large AC: None


const int max_int=0x7fffffff;
const int min_int=-max_int-1;
class Solution {
    int sign(int k){
        return k>=0?1:-1;
    }
    int searchDown(int &dividend,int upper,int k){
        int ans=0;
        while(k&&dividend){
            while(dividend>=upper) {
                ans+=k;
                dividend-=upper;
            }
            upper>>=1; 
            k>>=1;
        }
        return ans;
    }
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dividend==divisor) return 1;
        if(dividend==-divisor) return -1;
        int ans=0,left=0;
        int s=sign(dividend)==sign(divisor)?1:-1;
        if(divisor==min_int) return 0;
        if(dividend==min_int){
            left=1;
            dividend++;
        }
        dividend=abs(dividend);
        divisor=abs(divisor);
        if(dividend>=divisor){
            int upper=divisor,k=1;
            while((max_int>>1)>=upper&&upper<dividend) { k<<=1; upper<<=1; }
            if(upper>dividend){
                k>>=1; upper>>=1;
            }
            ans=searchDown(dividend,upper,k);
            dividend+=left;
            ans+=searchDown(dividend,upper,k);
        }
        if(s<0) ans=-ans;
        return ans;
    }
};
