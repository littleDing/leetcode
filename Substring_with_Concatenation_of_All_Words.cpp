//Attemp #1
//from	2013-10-04 15:10
//to   2013-10-04 16:53
//failed before small AC: CE* + RTE*2 + WA*10 + TLE*10
//failed before large AC: None

class Solution {
    
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if(L.size()){
            map<string,int> count;
            for(int i=0;i<L.size();++i)
                ++count[L[i]];
            int l=L[0].length();
            for(int i=0;i+l*L.size()<=S.length();++i){
                map<string,int> need=count;
                bool ok=true;
                for(int j=0;j<L.size()&&ok;++j){
                    string sub=S.substr(i+j*l,l);
                    map<string,int>::iterator it=need.find(sub);
                    if(it==need.end()) ok=false;
                    else{
                        --(it->second);
                        if(it->second<0) ok=false;
                    }
                }
                if(ok) ans.push_back(i);
            }
        }
        return ans;
    }
};
