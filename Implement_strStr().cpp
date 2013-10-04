//Attemp #1
//from	2013-10-04 15:03
//to   2013-10-04 14:03
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
    vector<int> next;
    void build(char *pattern){
        int l=strlen(pattern);
        next.assign(l,-1);
        int k=-1;
        for(int i=1;pattern[i];++i){
            while(k>=0&&(pattern[k]!=pattern[i-1])) k=next[k];
            ++k;
            if(pattern[k]==pattern[i]) next[i]=next[k];
            else next[i]=k;
        }
    }
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!haystack[0]&&!needle[0]) return haystack;
        build(needle);
        int i=0,j=0;
        for(;haystack[i]&&needle[j];++i,++j){
            while(j>=0&&haystack[i]!=needle[j]) 
                j=next[j];
        }
        if(!needle[j]) return haystack+i-j;
        return NULL;
    }
};
