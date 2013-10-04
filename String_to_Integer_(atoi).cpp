//Attemp #1
//from	2013-09-21 9:26
//to   2013-09-21 10:14
//failed before small AC: CE* + RTE* + WA*4
//failed before large AC: None


const int int_max=2147483647,int_min=-2147483648;
class Solution {
    enum State{
        heading,
        sign,
        middle,
        numbers,
        tailing,
        overflowed
    };
    bool overflow(int ans,bool neg,int toadd){
        if(neg){
            if(int_max/10<ans) return true;
            else if(int_max/10==ans&&int_max%10<toadd) return true;
        }else{
            if(int_min/-10<ans) return true;
            else if(int_min/-10==ans&&(int_min%10+10)%10<toadd) return true;
        }
        return false;
    }
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        State state=heading;
        bool neg=false;
        for(int i=0;str[i];++i){
            if(state==heading){
                if(str[i]=='-'||str[i]=='+') {
                    state=sign;     --i;
                }else if(('0'<=str[i]&&str[i]<='9')){
                    state=numbers;  --i;
                }else if(str[i]!=' '&&str[i]!='\t')
                    state=tailing;
            }else if(state==sign){
                if(str[i]=='-') neg=true;
                else if(str[i]=='+'){neg=false;}
                else --i;
                state=numbers;
            }else if(state==middle){
                if('0'<=str[i]&&str[i]<='9') {
                    state=numbers;  --i;
                }
            }else if(state==numbers){
                if('0'<=str[i]&&str[i]<='9') {
                    int toadd=str[i]-'0';
                    if(overflow(ans,neg,toadd)) {
                        ans=neg?int_min:int_max;
                        state=overflowed;
                    }
                    else ans=ans*10+(toadd);
                }
                else state=tailing;
            }
        }
        if(state!=overflowed&&neg) ans=-ans;
        return ans;
    }
};
