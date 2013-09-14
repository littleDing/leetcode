//Attemp #1
//from	2013-09-14 23:23
//to   2013-09-15 00:21
//failed before small AC: CE* + RTE* + WA*8
//failed before large AC: None


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // x,y -> y,n-x-1
        // 0,0 -> 0,n-1    0,n-1->n-1,n-1   n-1,n-1->n-1,0   n-1,0->0,0
        // so x,y is from n-y-1,x
        if(!matrix.size()||matrix.size()!=matrix[0].size()) return ;
        int n=matrix.size();
        for(int i=0;i*2+1<n;++i){
            for(int j=i;j+1+i<n;++j){
                int x=i,y=j;
                int tmp=matrix[x][y];
                for(int k=0;k<4;++k){
                    int xx=n-y-1,yy=x;
                    matrix[x][y]=matrix[xx][yy];
                    x=xx; y=yy;
                }
                matrix[y][n-x-1]=tmp;
            }
        }
    }
};
