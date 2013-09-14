//Attemp #1
//from	2013-09-14 12:06
//to   2013-09-14 12:42
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None

class Solution {
    vector<int> nums;
    int pickMin(vector<bool> &used,int need){
        for(int j=0;j<used.size();++j){
            if(!used[j]){
                need--;
                if(need==-1){
                    used[j]=true;
                    return j;
                }
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!nums.size()) nums.push_back(1);
        for(int i=nums.size();i<=n;++i)
            nums.push_back(nums[i-1]*i);
        string ans="";
        vector<bool> used(n,false);
        int left=k-1,pick;
        for(int i=1;i<=n;++i){
            int need=left/nums[n-i];
            int pick=pickMin(used,need);
            ans += '1'+pick;
            left %= nums[n-i];
        }
        return ans;
    }
};
