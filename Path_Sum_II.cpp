//Attemp #1
//from 	2013-8-7 0:39
//to	2013-8-7 0:45
//failed before small AC: CE*1 + RTE*0 + WA*0
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
    void dfs(TreeNode *root, int sum, vector<int> &path,vector<vector<int>> &ans){
        path.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right){
            if(sum==0){
                ans.push_back(path);
            }
        }else{
            if(root->left) dfs(root->left,sum,path,ans);
            if(root->right) dfs(root->right,sum,path,ans);
        }
        path.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ans;
        vector<int> path;
        if(root)
            dfs(root,sum,path,ans);
        return ans;
    }
};
