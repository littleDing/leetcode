//Attemp #1
//from	2013-09-21 18:28
//to   2013-09-21 19:00
//failed before small AC: CE* + RTE* + WA*3
//failed before large AC: None

class Solution {
    vector<int> uniqs,count;
    int lower(vector<int>& a,int target){
        //return max i that a[i]<=target
        int l=0,r=a.size()-1;
        while(l<r){
            int m=l+(r-l+1)/2;
            if(a[m]==target) return m;
            else if(a[m]<target) l=m;
            else r=m-1;
        }
        if(a[l]<=target) return l;
        return -1;
    }
    bool outside(int i){
        return i<0||i>=uniqs.size();
    }
    void update(int target,int &delta,bool& first,int i,int j,int k){
        if(outside(i)||outside(j)||outside(k)) return ;
        int s=uniqs[i]+uniqs[j]+uniqs[k];
        if(first||abs(delta)>abs(target-s)){
            delta=s-target;
            first=false;
        }
    }
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()<3) return target;
        int delta=0;
        bool first=true;
        sort(num.begin(),num.end());
        uniqs.clear(); count.clear();
        uniqs.push_back(num[0]); count.push_back(1);
        for(int i=1;i<num.size();++i){
            if(num[i]==uniqs.back()) ++count.back();
            else {
                uniqs.push_back(num[i]); 
                count.push_back(1);
            }
        }
        for(int i=0;i<uniqs.size();++i){
            for(int j=i+1;j<uniqs.size();++j){
                int s=uniqs[i]+uniqs[j];
                int k=lower(uniqs,target-s);
                if(k!=i&&k!=j) update(target,delta,first,i,j,k);
                if(k+1!=i&&k+1!=j) update(target,delta,first,i,j,k+1);
            }
            if(count[i]>=2){
                int s=uniqs[i]*2;
                int k=lower(uniqs,target-s);
                if(k!=i) update(target,delta,first,i,i,k);
                if(k+1!=i) update(target,delta,first,i,i,k+1);
            }
            if(count[i]>=3){
                update(target,delta,first,i,i,i);
            }
        }
        return target+delta;
    }
};
