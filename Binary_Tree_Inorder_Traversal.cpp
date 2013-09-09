//Attemp #1
//from	2013-09-06 01:44
//to   2013-09-06 02:37
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        stack<TreeNode*> sss;
        while(root||!sss.empty()){
            if(root) {
                sss.push(root);
                root=root->left;
            }else{
                root=sss.top(); sss.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};
