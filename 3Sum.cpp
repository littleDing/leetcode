//Attemp #1
//from	2013-09-21 17:23
//to   2013-09-21 17:56
//failed before small AC: CE*1 + RTE*1 + WA*
//failed before large AC: None


class Solution {
    map<int,vector<pair<int,int> > > sum2s;
    map<int,int> sum1s;
    vector<int> uniqs;
    void push(vector<vector<int> > &ans,int a,int b,int c){
        vector<int> tmp(3,0);
        tmp[0]=a; tmp[1]=b; tmp[2]=c;
        ans.push_back(tmp);
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        uniqs.clear(); sum1s.clear(); sum2s.clear();
        vector<vector<int> > ans;
        int cnt=0;
        for(int i=0;i<num.size();++i){
            if(i==0||num[i]!=num[i-1]) cnt=0;
            ++cnt;
            if(cnt==1){
                int target=-num[i];
                vector<pair<int,int> > &s2=sum2s[target];
                for(int j=0;j<s2.size();++j){
                    push(ans,s2[j].first,s2[j].second,num[i]);
                }
                for(int j=0;j<uniqs.size();++j){
                    sum2s[num[i]+uniqs[j]].push_back(pair<int,int>(uniqs[j],num[i]));
                }
                uniqs.push_back(num[i]);
                sum1s[num[i]]=num[i]-1;
            }else if(cnt==2){
                int target=-num[i]*2;
                if(num[i]!=0&&sum1s[target]==target-1) {
                    push(ans,target,num[i],num[i]);
                }
                sum2s[num[i]*2].push_back(pair<int,int>(num[i],num[i])); 
            }else if(cnt==3){
                if(num[i]==0) push(ans,0,0,0);
            }
        }
        return ans;
    }
};
