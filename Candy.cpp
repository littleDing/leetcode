//Attemp #1
//from	2013-10-04 19:54
//to   2013-10-04 20:04
//failed before small AC: CE* + RTE* + WA*4
//failed before large AC: None


class Solution {
    typedef pair<int,int> int2;
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans=0,n=ratings.size();
        vector<int2> idx;
        for(int i=0;i<ratings.size();++i) idx.push_back(int2(ratings[i],i));
        sort(idx.begin(),idx.end());
        vector<int> got(ratings.size(),1);
        for(int i=0;i<idx.size();++i){
            int c=idx[i].second;
            int k=1;
            if(c>0&&ratings[c-1]<ratings[c]) k=max(k,got[c-1]+1);
            if(c+1<n&&ratings[c+1]<ratings[c]) k=max(k,got[c+1]+1);
            ans+=k;
            got[c]=k;
        }
        return ans;
    }
};
