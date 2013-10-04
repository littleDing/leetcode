//Attemp #1
//from	2013-09-21 16:20
//to   2013-09-21 16:32
//failed before small AC: CE* + RTE* + WA + TLE*3
//failed before large AC: None

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        vector<int> hs();
        for(int i=height.size()-1;i>=0;--i){
            for(int j=0;j<i&&ans<height[i]*(i-j);++j){
                ans=max(ans,min(height[i],height[j])*(i-j));
            }
        }
        return ans;
    }
};
