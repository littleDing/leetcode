//Attemp #1
//from	2013-09-06 00:51
//to   2013-09-06 01:30
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
    vector<vector<TreeNode *> > ans;
    TreeNode* copy(TreeNode* root,int base){
        if(!root) return NULL;
        TreeNode *p = new TreeNode(root->val+base);
        p->left = copy(root->left,base);
        p->right = copy(root->right,base);
        return p;
    }
    void build(int n){
        if(n<ans.size()) return ;
        for(int i=ans.size();i<n;++i) 
            build(i);
        if(n==0) {
            ans.push_back(vector<TreeNode*>(1));
            ans[0][0]=NULL;
        }else if(n==1){
            ans.push_back(vector<TreeNode*>(1,new TreeNode(1)));    
        }else{
            ans.push_back(vector<TreeNode*>());
            for(int i=0;i<n;++i){
                for(int l=0;l<ans[i].size();++l){
                    for(int r=0;r<ans[n-i-1].size();++r){
                        TreeNode *root=new TreeNode(i+1);
                        root->left = copy(ans[i][l],0);
                        root->right = copy(ans[n-i-1][r],i+1);
                        ans[n].push_back(root);
                    }
                }
            }
        }
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        build(n);
        return ans[n];
    }
};
