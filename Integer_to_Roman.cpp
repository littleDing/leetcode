//Attemp #1
//from	2013-09-21 16:53
//to   2013-09-21 17:16
//failed before small AC: CE* + RTE* + WA*2
//failed before large AC: None


const int bases[]={1,5,10,50,100,500,1000,5000,10000};
const char reps[]="IVXLCDM0";
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ans="";
        int idx=0;
        while(num){
            int k=num%10;
            string tmp="";
            if(5<=k&&k<=8) 
                tmp=reps[idx+1];
            if(k%5<=3){
                for(int i=0;i<k%5;++i){
                    tmp=tmp+reps[idx];
                }
            }else if(k%5==4){
                tmp=string(1,reps[idx])+string(1,reps[idx+1+(k==9)])+tmp;
            }
            ans=tmp+ans;
            num/=10;
            idx+=2;
        }
        return ans;
    }
};
