//Attemp #1
//from 	2013-7-27 10:58
//to	2013-7-27 11:08
//failed before small AC: WA*3 + CE*1
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
    bool dfs(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sum-=root->val;
        if(!root->left&&!root->right) return sum==0;
        else if(root->left && dfs(root->left,sum)) return true;
        else if(root->right) return dfs(root->right,sum);
    }
    
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        return dfs(root,sum);
    }
};

