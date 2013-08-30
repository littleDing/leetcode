//Attemp #1
//from	2013-08-30 08:50
//to   2013-08-30 08:58
//failed before small AC: CE*1 + RTE* + WA
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
    struct Node{
        int depth;
        TreeNode *root;
        Node(int d,TreeNode *r):depth(d),root(r){}
    };
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<Node> qqq;
        vector<vector<int> > ans;
        if(!root) return ans;
        Node now(0,root);
        qqq.push(now);
        while(!qqq.empty()){
            now=qqq.front(); qqq.pop();
            while(now.depth>=ans.size())
                ans.push_back(vector<int>());
            ans[now.depth].push_back(now.root->val);
            if(now.root->left) qqq.push(Node(now.depth+1,now.root->left));
            if(now.root->right) qqq.push(Node(now.depth+1,now.root->right));
        }
        for(int i=0;i*2<ans.size();++i){
            swap(ans[i],ans[ans.size()-1-i]);
        }
        return ans;
    }
};
