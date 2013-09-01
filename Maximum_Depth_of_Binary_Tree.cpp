//Attemp #1
//from	2013-09-01 10:37:56
//to   2013-09-01 10:39:56
//failed before small AC: CE* + RTE* + WA
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
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
