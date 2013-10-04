//Attemp #1
//from	2013-09-28 21:27
//to   2013-09-28 21:55
//failed before small AC: CE* + RTE* + WA*2
//failed before large AC: None

const char *mappings[]={
    " ",
    "1",    "abc",  "def",
    "ghi",  "jkl",  "mno",
    "pqrs", "tuv",  "wxyz"
};

class Solution {
    const char* mapping(char ch){
        int c=ch-'0';
        if(c>=0&&c<=9) return mappings[c];
        else if(ch=='*') return "+";
        else return "#";
    }
    vector<string> ans;
    void make(const string& digits,string& buff,int from){
        if(from==digits.length()){
            ans.push_back(buff);
        }else{
            const char* choice=mapping(digits[from]);
            for(int i=0;choice[i];++i){
                buff[from]=choice[i];
                make(digits,buff,from+1);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        if(true||digits.length()){
            string buff(digits.length(),'0');
            make(digits,buff,0);
        }
        return ans;
    }
};
