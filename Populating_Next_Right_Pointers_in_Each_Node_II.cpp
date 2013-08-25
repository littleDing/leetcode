//Attemp #1
//from 	2013-8-21 1:13
//to	2013-8-21 1:50
//failed before small AC: CE* + RTE*1 + WA*3
//failed before large AC: None

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    inline bool isleaf(TreeLinkNode *root){
        return !root->left && !root->right;
    }
    TreeLinkNode* next(TreeLinkNode* r){
        while(r&&isleaf(r)){
            r=r->next;
        }
        if(r) return (r->left)?r->left:r->right;
        else return r;
    }
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return ;
        connect(root->right);
        TreeLinkNode *l=root->left,*r=root->right;
        if(!r) r=next(root->next);
        while(l&&r){
            l->next=r;
            l=(l->right)?l->right:l->left;
            r=next(r);
        }
        connect(root->left);
    }
};
