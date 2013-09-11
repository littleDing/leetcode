//Attemp #1
//from	2013-09-11 08:42
//to   2013-09-11 09:01
//failed before small AC: CE* + RTE*1 + WA*3
//failed before large AC: None

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1=word1.length(),l2=word2.length();
        if(!l1||!l2){
            return max(l1,l2);
        }
        vector<vector<int> > cost(l1+1,vector<int>(l2+1,0));
        for(int i=0;i<l1;++i) cost[i+1][0]=i+1;
        for(int i=0;i<l2;++i) cost[0][i+1]=i+1;
        for(int i=0;i<l1;++i){
            for(int j=0;j<l2;++j){
                cost[i+1][j+1]=min(cost[i][j+1],cost[i+1][j])+1;
                cost[i+1][j+1]=min(cost[i][j]+(word1[i]!=word2[j]),cost[i+1][j+1]);
            }
        }
        return cost[l1][l2];
    }
};
