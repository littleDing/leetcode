//Attemp #1
//from	2013-09-10 08:37
//to   2013-09-10 09:11
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> cnt(3,0);
        for(int i=0;i<n;++i){
            ++cnt[A[i]];
        }
        int now=0;
        for(int i=0;i<n;++i){
            while(cnt[now]==0) 
                ++now;
            A[i]=now;
            --cnt[now];
        }
    }
};


/*
one scan sulution below
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l=0,r=n-1,now=0;
        while(now<r){
            while(l<r&&A[l]==0) ++l;
            while(l<r&&A[r]==2) --r;
            now=max(l+1,now);
            while(now<r&&A[now]==1) ++now;
            if(now<r&&A[now]==0) swap(A[now],A[l]);
            else if(now<r&&A[now]==2) swap(A[now],A[r]);
        }
        if(A[l]!=0) swap(A[l],A[r]);
    }
};
