//Attemp #1
//from	2013-09-03 16:00
//to   2013-09-03 16:40
//failed before small AC: CE* + RTE*2 + WA*3
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
    TreeNode *left,*right;
    TreeNode *visit(TreeNode *root,TreeNode *pre){
        if(root->left) { 
            pre=visit(root->left,pre);
        }
        if(pre&&root->val<pre->val){
            if(!left) left=pre;
            right=root;
        }
        TreeNode *pmin=root;
        if(root->right) pmin=visit(root->right,root);
        return pmin;
    }
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return ;
        left =right =NULL;
        visit(root,NULL);
        if(left && right)
            swap(left->val,right->val);
    }
};
