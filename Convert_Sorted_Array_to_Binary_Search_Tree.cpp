//A
//from	2013-08-25 21:00
//to	2013-08-25 21:23
//failed before small AC: CE* + RTE*2 + WA
//failed before large AC: None


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *solve(vector<int> &num,int from,int to){
        if(from>to) return NULL;
        if(from==to) return new TreeNode(num[from]);
        int mid=from+(to-from+1)/2;
        TreeNode *root=new TreeNode(num[mid]);
        root->left = solve(num,from,mid-1);
        root->right = solve(num,mid+1,to);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return solve(num,0,num.size()-1);
    }
};
