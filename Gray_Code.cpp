//Attemp #1
//from 	2013-7-27 22:05
//to	2013-7-27 22:26
//failed before small AC: CE*0 + RTE*2 + WA*1
//failed before large AC: None


// 0 1 1 0 0 1 1 0
// 0 0 1 1 1 1 0 0
// 0 0 0 0 1 1 1 1




class Solution {
    vector<int> ans;
    inline void set(int& a,int bit){
        a&=(1<<bit);
    }
    void setbits(int k){
        int l=(1<<k),half=l/2;
        for(int i=0;i<half;++i) ans[l-1-i] = ans[i];
        int hehe = 1<<(k-1);
        for(int i=half;i<l;++i) ans[i]+=hehe;
    }
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.resize(1<<n);
        for(int i=0;i<(1<<n);++i) ans[i]=0;
        for(int i=1;i<=n;++i){
            setbits(i);
        }
        return ans;
    }
};

