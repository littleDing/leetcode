//Attemp #1
//from 	2013-8-21 0:54
//to	2013-8-21 1:11
//failed before small AC: CE*1 + RTE* + WA
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
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root||!root->left) return ;
        TreeLinkNode *l=root->left,*r=root->right;
        do{
            l->next=r;
            l=l->right;
            r=r->left;
        }while(l&&r);
        connect(root->left);
        connect(root->right);
    }
};
