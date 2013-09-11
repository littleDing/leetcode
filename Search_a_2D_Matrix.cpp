//Attemp #1
//from	2013-09-11 08:11
//to   2013-09-11 08:19
//failed before small AC: CE* + RTE* + WA*1 + TLE*1
//failed before large AC: None

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()&&matrix[0].size()){
            int mod=matrix[0].size();
            int l=0,r=matrix.size()*mod-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int x=mid/mod,y=mid%mod;
                if(matrix[x][y]==target) return true;
                else if(matrix[x][y]<target) l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};
