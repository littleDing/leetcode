//Attemp #1
//from	2013-09-14 16:36
//to   2013-09-14 16:56
//failed before small AC: CE* + RTE* + WA*2
//failed before large AC: None

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    int find(vector<Interval> &intervals, Interval target, bool left){
        if(!intervals.size()) return -1;
        if(left&&intervals[0].start>target.start) return -1;
        if(!left&&intervals[intervals.size()-1].end<target.end) return -1;
        int l=0,r=intervals.size()-1;
        while(l<r){
            int mid=l+(r-l+left)/2;
            if(left){
                if(intervals[mid].start<=target.start) l=mid;
                else r=mid-1;
            }else{
                if(intervals[mid].end>=target.end) r=mid;
                else l=mid+1;
            }
        }
        return l;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // find them out, if invalid , may return -1
        int lidx=find(intervals,newInterval,true);
        int ridx=find(intervals,newInterval,false);
        //try merged
        if(lidx!=-1&&intervals[lidx].end>=newInterval.start)
            newInterval.start=intervals[lidx].start;
        if(ridx!=-1&&intervals[ridx].start<=newInterval.end)
            newInterval.end=intervals[ridx].end;
        //generate ans
        bool puted=false;
        vector<Interval> ans;
        for(int i=0;i<intervals.size();++i){
            Interval tmp=intervals[i];
            if(!puted && newInterval.end<tmp.start){
                ans.push_back(newInterval);
                puted=true;
            }
            if(tmp.start<newInterval.start||tmp.end>newInterval.end){
                ans.push_back(tmp);
            }
        }
        if(!puted) ans.push_back(newInterval);
        return ans;
    }
};
