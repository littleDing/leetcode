//Attemp #1
//from	2013-09-21 15:34
//to   2013-09-21 15:40
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0) return false;
        int tens=1;
        for(int xx=x/10;xx;xx/=10,tens*=10);
        int l=1,r=tens;
        while(l<r){
            if(x/l%10!=x/r%10) return false;
            l*=10; r/=10;
        }
        return true;
    }
};
