//Attemp #1
//from	2013-09-12 01:32
//to   2013-09-12 01:37
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int extra=1;
        for(int i=digits.size()-1;extra&&i>=0;--i){
            digits[i]+=extra;
            extra=digits[i]/10;
            digits[i]%=10;
        }
        if(extra){
            digits.push_back(0);
            for(int i=digits.size()-1;i>0;--i){
                digits[i]=digits[i-1];
            }
            digits[0]=1;
        }
        return digits;
    }
};
