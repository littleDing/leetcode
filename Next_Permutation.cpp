//Attemp #1
//from	2013-09-26 08:50
//to   2013-09-26 08:58
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
    bool next(vector<int> &num,int from){
        if(from+2==num.size()){
            swap(num[from],num[from+1]);
            return num[from]>num[from+1];
        }else{
            if(!next(num,from+1)){
                int pick=from+1;
                while(pick<num.size()&&num[from]>=num[pick]) ++pick;
                if(pick<num.size()){
                    swap(num[from],num[pick]);
                    return true;
                }else{
                    int now=num[from];
                    for(int i=from+1;i<num.size();++i) num[i-1]=num[i];
                    num.back()=now;
                    return false;
                }
            }else return true;
        }
    }
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()>=2)
            next(num,0);
    }
};
