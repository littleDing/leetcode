//Attemp #1
//from	2013-10-04 18:54
//to   2013-10-04 19:54
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None


class Solution {
    typedef pair<int,int> int2;
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=cost.size();
        if(n==1){
            if(gas[0]>=cost[0]) return 0;
            else return -1;
        }
        for(int i=0;i<n;++i)
            gas[i]-=cost[i];
        for(int i=0;i<n;++i)
            gas.push_back(gas[i]);
        for(int i=1;i<gas.size();++i)
            gas[i]+=gas[i-1];
        priority_queue<int2,vector<int2>,greater<int2> > left;
        for(int i=0;i<n;++i) left.push(int2(gas[i],i));
        //if(left.top().first>=0) return 0; 
        for(int i=n;i<gas.size();++i){
            left.push(int2(gas[i],i));
            int bg=i-n+1;
            while(left.top().second<bg) left.pop();
            int mi=left.top().first;
            if(mi>=gas[bg-1]) return bg%n;
        }
        return -1;
    }
};
