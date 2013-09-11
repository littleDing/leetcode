//Attemp #1
//from	2013-09-11 08:20
//to   2013-09-11 08:30
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!matrix.size()||!matrix[0].size()) return ;
        int n=matrix.size(),m=matrix[0].size();
        vector<bool> cols(m,true),rows(n,true);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==0){
                    cols[j]=rows[i]=false;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!cols[j]||!rows[i])
                    matrix[i][j]=0;
            }
        }
    }
};
