//Attemp #1
//from	2013-09-01 9:38:07
//to   2013-09-01 10:01:07
//failed before small AC: CE*2 + RTE*1 + WA
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
/*
    preorder    p[l][r]
    inprder     [l]p[r]
    postprder   [l][r]p
*/


class Solution {
    map<int,int> index;
    void reset(vector<int> &inorder){
        index.clear();
        for(int i=0;i<inorder.size();++i){
            index[inorder[i]]=i+1;
        }
    }
    TreeNode *build(vector<int> &preorder, int pfrom,
                    vector<int> &inorder, int ifrom, int len){
        if(len<=0) return NULL;
        TreeNode *root=new TreeNode(preorder[pfrom]);
        int idx=index[root->val]-1;
        int llen=idx-ifrom,rlen=len-1-llen;
        root->left = build(preorder,pfrom+1,inorder,ifrom,llen);
        root->right = build(preorder,pfrom+1+llen,inorder,ifrom+1+llen,rlen);
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!preorder.size()&&!inorder.size()&&!preorder.size()==inorder.size())
            return NULL;
        reset(inorder);
        int n=preorder.size();
        return build(preorder,0,inorder,0,n);
    }
};




