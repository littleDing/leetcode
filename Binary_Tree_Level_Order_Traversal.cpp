//A
//from	2013-09-02 08:30
//to   2013-09-02 08:36
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
        TreeNode *root;
        int depth;
        Node(TreeNode *r,int d):root(r),depth(d){}
    };
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(root){
            queue<Node> qqq;
            qqq.push(Node(root,0));
            while(!qqq.empty()){
                Node now =qqq.front(); qqq.pop();
                while(now.depth>=ans.size()) 
                    ans.push_back(vector<int>());
                ans[now.depth].push_back(now.root->val);
                if(now.root->left) qqq.push(Node(now.root->left,now.depth+1));
                if(now.root->right) qqq.push(Node(now.root->right,now.depth+1));
            }
        }
        return ans;
    }
};
