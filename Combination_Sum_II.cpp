//Attemp #1
//from	2013-09-17 00:30
//to   2013-09-17 00:47
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None

class Solution {
    vector<int> nums,count;
    vector<vector<int> > ans;
    void dfs(int from,int target,vector<int> &now){
        if(target==0) ans.push_back(now);
        else if(from<nums.size()){
            int cc=count[from];
            dfs(from+1,target,now);
            for(int i=1;i<=cc&&target-nums[from]*i>=0;++i){
                now.push_back(nums[from]);   --count[from];
                dfs(from+1,target-nums[from]*i,now);
            }
            while(cc>count[from]){ 
                now.pop_back();
                ++count[from];
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        if(num.size()){
            sort(num.begin(),num.end());
            count.assign(1,1);
            nums.assign(1,num[0]);
            for(int i=1;i<num.size();++i){
                if(num[i]==nums.back()){
                    ++count.back();
                }else{
                    nums.push_back(num[i]);
                    count.push_back(1);
                }
            }
            vector<int> now;
            dfs(0,target,now);
        }
        return ans;
    }
};
