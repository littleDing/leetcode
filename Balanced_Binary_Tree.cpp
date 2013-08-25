//A
//from 	2013-7-27 16:56
//to	2013-8-25 17:05
//failed before small AC: CE*1 + RTE* + WA*1
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
    int visit(TreeNode *root,bool& ans){
        if(!root) return 0;
        int l=0,r=0;
        l=visit(root->left,ans);
        if(ans) r=visit(root->right,ans);
        if(l-r>1||r-l>1) ans=false;
        return max(l,r)+1;
    }
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        bool ans=true;
        visit(root,ans);
        return ans;
    }
};
