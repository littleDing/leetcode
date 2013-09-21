//Attemp #1
//from	2013-09-15 21:50
//to   2013-09-15 22:15
//failed before small AC: CE* + RTE* + WA*20
//failed before large AC: TLE*20 + WA*20

class Solution {
    const char *send;
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        send=s+strlen(s);
        return solve(s,p);
    }
    bool solve(const char *s, const char *p) {
        while(*s){
            if(*p=='*'){
                while(*p=='*') ++p;
                if(!*p) return true;
                int plen=1;
                while(p[plen]&&p[plen]!='*') ++plen;
                int slen=strlen(s);
                while(slen>=plen){
                    int i=0;
                    while(i<plen&&(s[i]==p[i]||p[i]=='?')) ++i;
                    if(i==plen){
                        bool ok=solve(s+plen,p+plen);
                        if(ok||p[plen]=='*') return ok;
                    }
                    ++s; --slen;
                }
                return false;
            }else if(*p!='?'&&*p!=*s)
                return false;
            ++s; ++p;
        }
        while(*p=='*') ++p;
        return !*p;
    }
};
