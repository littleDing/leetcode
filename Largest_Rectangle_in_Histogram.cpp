//Attemp #1
//from	2013-09-09 0:27
//to   2013-09-09 01:07
//failed before small AC: CE*1 + RTE* + WA*5
//failed before large AC: TLE*1


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans=0;
        height.push_back(0);
        stack<int> sss;
        for(int i=0;i<height.size();++i){
            while(!sss.empty()&&height[sss.top()]>height[i]){
                int st=sss.top();
                sss.pop();
                int len=(sss.empty()?i:i-sss.top()-1);
                ans=max(ans,len*height[st]);
            }
            sss.push(i);
        }
        return ans;
    }
};
