//Attemp #1
//from 	2013-8-7 0:39
//to	2013-8-7 0:53
//failed before small AC: CE* + RTE* + WA*2
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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        if(root->left){
            int ret = minDepth(root->left);
            if(root->right) ret = min(ret,minDepth(root->right));
            return ret+1;
        }else return minDepth(root->right)+1;
    }
};
