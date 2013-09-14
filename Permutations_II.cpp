//Attemp #1
//from	2013-09-15 00:57
//to   2013-09-15 01:18
//failed before small AC: CE* + RTE*2 + WA*4
//failed before large AC: None

class Solution {
    vector<int> numbers,count;
    int total;
    vector<vector<int> > ans;
    void dfs(int bad,vector<int> now){
        if(now.size()==total) ans.push_back(now);
        else{
            for(int i=0;i<numbers.size();++i){
                if(count[i]&&bad!=i){
                    int cc=count[i];
                    for(int j=0;j<cc;++j){
                        now.push_back(numbers[i]);
                        --count[i];
                        dfs(i,now);
                    } 
                    for(int j=0;j<cc;++j)
                        now.pop_back();
                    count[i]=cc;
                }
            }
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        if(num.size()){
            sort(num.begin(),num.end());
            numbers.clear(); count.clear();
            numbers.push_back(num[0]);
            count.push_back(1);
            total=num.size();
            int last=0;
            for(int i=1;i<total;++i){
                if(num[i]==numbers[last]){
                    ++count[last];
                }else{
                    numbers.push_back(num[i]);
                    count.push_back(1);
                    ++last;
                }
            }
            vector<int> now;
            dfs(-1,now);
        }
        return ans;
    }
};
