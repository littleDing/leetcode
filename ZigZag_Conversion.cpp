//Attemp #1
//from	2013-09-21 11:00
//to   2013-09-21 12:18
//failed before small AC: CE* + RTE*5 + WA*3
//failed before large AC: None


class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ans(s.length(),' ');
        int len=s.length(),one=nRows+nRows-2;
        if(len<=0) return "";
        if(nRows==1) return s;
        int pre[nRows];
        pre[0]=0; pre[1]=len/one+(len%one>0);
        for(int i=2;i<nRows;++i) pre[i]=(len-1)/one*2+((len-1)%one>=i-1)+((len-1)%one>=nRows*2-i-1)+pre[i-1];
        for(int i=0;i<len;i+=one){
            for(int j=i;j<i+one&&j<len;++j){
                int r=j%one,c=j/one;
                if(r!=0&&r!=nRows-1) c*=2;
                if(r>=nRows){
                    r=nRows-2-(r-nRows);
                    c++;
                } 
                ans[pre[r]+c]=s[j];
            }
        }
        return ans;
    }
};
