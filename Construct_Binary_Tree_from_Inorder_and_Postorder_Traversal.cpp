//Attemp #1
//from	2013-09-01 10:12:07
//to   2013-09-01 10:35:07
//failed before small AC: CE* + RTE*1 + WA*1
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
    inorder [l]p[r]
    postorder [l][r]p
 */
 
class Solution {
    map<int,int> index;
    void reset(vector<int> &inorder){
        index.clear();
        for(int i=0;i<inorder.size();++i){
            index[inorder[i]]=i+1;
        }
    }
    TreeNode *build(vector<int> &inorder,int ifrom
                    ,vector<int> &postorder,int pfrom,int len){
        if(len<=0) return NULL;
        TreeNode *root = new TreeNode(postorder[pfrom+len-1]);
        int idx=index[root->val]-1;
        int llen=idx-ifrom,rlen=len-llen-1;
        root->left = build(inorder,ifrom,postorder,pfrom,llen);
        root->right = build(inorder,ifrom+1+llen,postorder,pfrom+llen,rlen);
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reset(inorder);
        return build(inorder,0,postorder,0,inorder.size());
    }
};
