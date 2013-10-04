//Attemp #1
//from	2013-10-04 11:38
//to   2013-10-04 11:41
//failed before small AC: CE* + RTE* + WA
//failed before large AC: None


class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<char> lefts;
        for(int i=0;i<s.length();++i){
            char ch=s[i];
            if(ch=='['||ch=='{'||ch=='(')
                lefts.push(ch);
            else if(lefts.empty()) return false;
            else {
                char l=lefts.top(); lefts.pop();
                if(l=='('&&ch!=')') return false;
                if(l=='['&&ch!=']') return false;
                if(l=='{'&&ch!='}') return false;
            }
        }
        return lefts.empty();
    }
};
