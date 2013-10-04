//Attemp #1
//from	2013-09-21 15:41
//to   2013-09-21 16:14
//failed before small AC: CE* + RTE* + WA*2 + TLE*2
//failed before large AC: None


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(!s&&!p) return true;
        if(!s||!p) return false;
        if(!*s){
            while(*p&&*(p+1)=='*') p+=2;
            return !*p;
        }
        if(!*p) return false;
        if(*(p+1)=='*'){
            if(isMatch(s,p+2)) return true;
            while(*s&&(*p=='.'||*s==*p)){
                if(isMatch(s+1,p+2)) return true;
                ++s;
            }
            if(!*s) return !*(p+2);
            return false;
        }else{
            if(*p=='.'||*s==*p) return isMatch(s+1,p+1);
            else return false;
        }
    }
};
