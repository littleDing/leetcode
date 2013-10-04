//Attemp #1
//from	2013-09-28 18:19
//to   2013-09-28 19:21
//failed before small AC: CE*3 + RTE*4 + WA
//failed before large AC: None

class Solution {
    map<int,vector<pair<int,int> > > pairs;
    vector<int> values,counts;
    map<int,int> idx;
    vector<vector<int> > ans;
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        if(num.size()>=4){
            //count uniq values
            values.clear(); counts.clear(); idx.clear();
            sort(num.begin(),num.end());
            values.push_back(num[0]); counts.push_back(1); idx[num[0]]=0;
            for(int i=1;i<num.size();++i){
                if(num[i]==values.back()){
                    ++counts.back();
                }else{
                    idx[num[i]]=values.size();
                    values.push_back(num[i]);
                    counts.push_back(1);
                }
            }
            //make value-pairs mapping
            pairs.clear();
            for(int i=0;i<values.size();++i){
                for(int j=i+1;j<values.size();++j){
                    int v=values[i]+values[j];
                    pairs[v].push_back(pair<int,int>(values[i],values[j]));
                }
                if(counts[i]>=2){
                    pairs[values[i]*2].push_back(pair<int,int>(values[i],values[i]));
                }
            }
            //iter values to make target
            for(map<int,vector<pair<int,int> > >::const_iterator it=pairs.begin();it!=pairs.end();++it){
                int v=it->first;
                map<int,vector<pair<int,int> > >::const_iterator fit=pairs.find(target-v);
                if(fit!=pairs.end()){
                    const vector<pair<int,int> > &p1=it->second, &p2=fit->second;
                    for(int i=0;i<p1.size();++i){
                        for(int j=0;j<p2.size();++j){
                            vector<int> tmp(4,0);
                            tmp[0]=p1[i].first; tmp[1]=p1[i].second;
                            tmp[2]=p2[j].first; tmp[3]=p2[j].second;
                            if(tmp[0]<=tmp[1]&&tmp[1]<=tmp[2]&&tmp[2]<=tmp[3]){
                                bool ok=true;
                                for(int k=0;k<4;++k) {
                                    int id=idx[tmp[k]];
                                    --counts[id];
                                    ok=ok&&(counts[id]>=0);
                                }
                                if(ok) ans.push_back(tmp);
                                for(int k=0;k<4;++k) ++counts[idx[tmp[k]]];
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
