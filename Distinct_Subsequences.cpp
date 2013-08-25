//Attemp #1
//from 	2013-8-25 12:25
//to	2013-8-25 16:33
//failed before small AC: CE*4 + RTE*1 + WA*8 + TLE*1
//failed before large AC: TLE*1

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ns=S.length(),nt=T.length();
        if(ns==0||nt==0) return 0;
        vector<int> f[2];
        f[0].resize(ns); f[1].resize(ns);
        //clear
        for(int i=0;i<ns;++i){
            f[0][i]=f[1][i]=0;
        }
        //first round, L=0
        f[0][ns-1]=(S[ns-1]==T[nt-1]);
        for(int i=ns-2;i>=0;--i){
            f[0][i]=f[0][i+1]+(S[i]==T[nt-1]);
        }
        //lefting rounds
        int current=1;
        for(int l=2;l<=nt;++l,current=1-current){
            f[current][ns-l+1]=0;
            for(int i=ns-l;i>=0;--i){
                f[current][i]=f[current][i+1];
                if(S[i]==T[nt-l]){
                    f[current][i]+=f[1-current][i+1];
                }
            }    
        }
        return f[1-current][0];
    }
};
