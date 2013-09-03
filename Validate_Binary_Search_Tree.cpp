//Attemp #1
//from	2013-09-03 17:06
//to   2013-09-03 17:10
//failed before small AC: CE*1 + RTE* + WA*2
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
    bool visit(TreeNode *root,int& mi,int& ma){
        mi=ma=root->val;
        int lma=root->val,rmi=root->val;
        if(root->left&&(!visit(root->left,mi,lma)||root->val<=lma)) return false;
        if(root->right&&(!visit(root->right,rmi,ma)||root->val>=rmi)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        int mi,ma;
        return visit(root,mi,ma);
    }
};
