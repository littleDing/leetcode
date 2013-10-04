//Attemp #1
//from	2013-10-04 11:42
//to   2013-10-04 12:03
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None

class Solution {
    vector<string> ans;
    string buff;
    int n;
    void dfs(int from,int need){
        if(need==0){
            ans.push_back(buff);
        }else{
            for(int i=from;n-i>=need*2;++i){
                buff[i]='(';
                dfs(i+1,need-1);
                buff[i]=')';
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        buff=string(n*2,')');
        ans.clear();
        this->n=n*2;
        dfs(0,n);
        return ans;
    }
};
