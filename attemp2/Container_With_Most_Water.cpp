//Attemp #2
//from	2013-09-21 16:40
//to   2013-09-21 16:53
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        int l=0,r=height.size()-1;
        while(l<r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]) ++l;
            else --r;
        }
        return ans;
    }
};
