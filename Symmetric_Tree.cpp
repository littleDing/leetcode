//Attemp #1
//from 	2013-7-28 10:42
//to	2013-7-28 10:51
//failed before small AC: CE*0 + RTE*0 + WA*1
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
    bool theSame(TreeNode *a,TreeNode* b){
        if(!a||!b) return a==b;
        else return a->val==b->val && theSame(a->left,b->right) && theSame(a->right,b->left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return theSame(root->left,root->right);
    }
};
