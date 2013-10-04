//Attemp #1
//from	2013-09-20 17:19
//to   2013-09-20 17:24
//failed before small AC: CE*1 + RTE* + WA*2
//failed before large AC: None

class Solution {
    map<int,int> idx;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        idx.clear();
        for(int i=numbers.size()-1;i>=0;--i){
            idx[numbers[i]] =i+1;
        }
        vector<int> ans(2,0);
        for(int i=0;i<numbers.size();++i){
            int k=idx[target-numbers[i]];
            if(k!=0&&k!=i+1){
                ans[0]=min(k,i+1);
                ans[1]=max(k,i+1);
            }
        }
        return ans;
    }
};
