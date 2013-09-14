//Attemp #1
//from	2013-09-14 16:57
//to   2013-09-14 17:17
//failed before small AC: CE* + RTE*4 + WA
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

bool cmp(const Interval &a, const Interval &b){
    return a.start<b.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!intervals.size()) return intervals;
        sort(intervals.begin(),intervals.end(),cmp); 
        int now=0;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start<=intervals[now].end){
                if(intervals[i].end>intervals[now].end)
                    intervals[now].end=intervals[i].end;
                //intervals[now].end=max(intervals[now].end,intervals[i].end);
            }else{
                ++now;
                intervals[now]=intervals[i];
            }
        }
        ++now;
        while(intervals.size()>now) intervals.pop_back();
        return intervals;
    }
};
