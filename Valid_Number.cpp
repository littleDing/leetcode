//Attemp #1
//from	2013-09-12 02:11
//to   2013-09-12 02:58
//failed before small AC: CE* + RTE* + WA*13
//failed before large AC: None


class Solution {
    int next(const char *s,int from,int to){
        for(int i=from;i<=to;++i)
            if(s[i]=='.'||s[i]=='e')
                return i;
        return to+1;
    }
    bool pureNum(const char *s,int from,int to,bool heading=true){
        if(from>to) return false;
        if(heading&&(s[from]=='+'||s[from]=='-')) ++from;
        if(from>to) return false;
        for(int i=from;i<=to;++i)
            if(s[i]<'0'||'9'<s[i]) return false;
        return true;
    }
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int from=0,to=strlen(s)-1;
        while(from<=to&&s[from]==' ') ++from;
        while(from<=to&&s[to]==' ') --to;
        if(from>to) return false;
        if(s[from]=='+'||s[from]=='-') ++from;
        if(from>to) return false;
        int tag[2];
        tag[0]=next(s,from,to);
        tag[1]=next(s,tag[0]+1,to);
        int cnt=(tag[0]<=to)+(tag[1]<=to);
        if(cnt==0) return pureNum(s,from,to,false);
        else if(cnt==1){
            if(s[tag[0]]=='.'){
                if(tag[0]==from&&tag[0]==to) return false;
                if(tag[0]-from&&!pureNum(s,from,tag[0]-1,false)) return false;
                if(to-tag[0]&&!pureNum(s,tag[0]+1,to,false)) return false;
            }else {
                return pureNum(s,from,tag[0]-1) && pureNum(s,tag[0]+1,to);
            }
        }else if(cnt==2){
            if(!(s[tag[0]]=='.'&&s[tag[1]]=='e')) return false;
            if(tag[0]==from&&tag[0]==tag[1]-1) return false;
            if(tag[0]-from&&!pureNum(s,from,tag[0]-1,false)) return false;
            if(tag[1]-1-tag[0]&&!pureNum(s,tag[0]+1,tag[1]-1,false)) return false;
            return pureNum(s,tag[1]+1,to);
        }
        return true;
    }
};
