//Attemp #1
//from 	2013-7-27 16:39
//to	2013-8-25 16:56
//failed before small AC: CE* + RTE*1 + WA
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
    //flattened p and return the tail
    TreeNode* dfs(TreeNode *p){
        if(p->left){
            TreeNode *tail=dfs(p->left);
            tail->right=p->right;
            p->right=p->left;
            p->left=NULL;
            if(p->right){
                tail=dfs(p->right);
            }
            return tail;
        }else if(p->right){
            return dfs(p->right);
        }else{
            return p;
        }
    }
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return ;
        dfs(root);
    }
};
