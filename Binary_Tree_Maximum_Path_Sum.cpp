//Attemp #1
//from 	2013-8-19 23:55
//to	2013-8-20 00:13
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
    //return the max path sum ending with root, update ans if necessary
    int solve(TreeNode *root,int& ans){
        if(!root) return 0;
        else{
            //fetch child state
            int maxl = solve(root->left,ans);
            int maxr = solve(root->right,ans);
            //update with a cross pattern
            ans = max(ans,maxl+maxr+root->val);
            
            //update with ending pattern
            int ending = root->val;
            ending = max(ending,maxl+root->val);
            ending = max(ending,maxr+root->val);
            ans = max(ending,ans);
            return ending;
        }
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;
        else{
            int ans = root->val;
            solve(root,ans);
            return ans;
        }
    }
};
