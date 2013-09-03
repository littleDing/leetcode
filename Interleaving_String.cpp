//Attemp #1
//from	2013-09-04 01:39
//to   2013-09-04 02:21
//failed before small AC: CE*1 + RTE*2 + WA*3
//failed before large AC: None


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int l1=s1.length(),l2=s2.length(),l3=s3.length();
        if(l1+l2!=l3) return false;
        if(l1>l2){
            swap(l1,l2);
            swap(s1,s2);
        }
        if(l1==0){
            for(int i=0;i<l2;++i){
                if(s2[i]!=s3[i]) return false;
            }
            return true;
        }
        vector<vector<bool> > ok(l3,vector<bool>(l1+1,false));
        vector<bool> ok2(l2,false);
        for(int i=0;i<l2&&s2[i]==s3[i];++i)
            ok[i][0]=true;
        if(s1[0]==s3[0]) ok[0][1]=true;
        for(int l=1;l<l3;++l){
            for(int i=0;i<l1&&i<=l;++i){
                if((s1[i]==s3[l]&&ok[l-1][i])||(s3[l]==s2[l-i-1]&&ok[l-1][i+1]))
                    ok[l][i+1]=true;
            }
        }
        return ok[l3-1][l1];
    }
};
