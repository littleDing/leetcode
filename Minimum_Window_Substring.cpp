//Attemp #1
//from	2013-09-10 08:15
//to   2013-09-10 08:35
//failed before small AC: CE*1 + RTE* + WA*2
//failed before large AC: None

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> covers(128,0);
        int need=0;
        for(int i=0;i<T.length();++i){
            if(covers[T[i]]==0){
                ++need;
            }
            --covers[T[i]];
        }
        int from=0,to=0;
        string ans;
        for(to=0;to<S.length();++to){
            ++covers[S[to]];
            if(covers[S[to]]==0) need--;
            if(!need){
                while(from<=to&&covers[S[from]]!=0){
                    --covers[S[from]];
                    ++from;
                }
                if(ans.length()==0||to-from+1<ans.length()) ans=S.substr(from,to-from+1);
            }
        }
        return ans;
    }
};
