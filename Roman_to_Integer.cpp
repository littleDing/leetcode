//Attemp #1
//from	2013-09-21 17:23
//to   2013-09-21 17:27
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char,int> reps;
        reps['I']=1;
        reps['V']=5;
        reps['X']=10;
        reps['L']=50;
        reps['C']=100;
        reps['D']=500;
        reps['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();++i){
            int base=reps[s[i]];
            if(i+1<s.length()&&reps[s[i+1]]>base) base=-base;
            ans+=base;
        }
        return ans;
    }
};
