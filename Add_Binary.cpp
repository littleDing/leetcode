//Attemp #1
//from 	2013-7-27 22:28
//to	2013-7-27 22:49
//failed before small AC: CE*0 + RTE*0 + WA*2
//failed before large AC: None

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int current=0,next=0;
        if(a.size()<b.size()) swap(a,b);
        int la=a.size()-1,lb=b.size()-1;  //1,0
        for(int i=0;i<b.size();++i){ // 0
            current = int(b[lb-i]=='1') + int(a[la-i]=='1') + next; //2
            next = current>=2;   //1
            current %= 2;    // 0
            a[la-i] = '0' + current;  // '0'
        }
        for(int i=b.size();next&&i<a.size();++i){
            current = int(a[la-i]=='1') +next;
            next = current>=2;
            current %= 2;
            a[la-i] = '0' + current;
        }
        if(next) return '1'+a;
        else return a;
    }
};
