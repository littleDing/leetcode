//Attemp #1
//from	2013-09-02 08:21:49
//to   2013-09-02 08:29:49
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
    struct Node{
        TreeNode *p;
        int depth;
        Node(TreeNode *_p,int d):p(_p),depth(d){}
    };
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(!root) return ans;
        queue<Node> qqq;
        qqq.push(Node(root,0));
        while(!qqq.empty()){
            Node now = qqq.front(); qqq.pop();
            while(now.depth>=ans.size())
                ans.push_back(vector<int>());
            ans[now.depth].push_back(now.p->val);
            if(now.p->left) qqq.push(Node(now.p->left,now.depth+1));
            if(now.p->right) qqq.push(Node(now.p->right,now.depth+1));
        }
        for(int i=1;i<ans.size();i+=2){
            int n=ans[i].size();
            for(int j=0;j*2<n;++j){
                swap(ans[i][j],ans[i][n-1-j]);
            }    
        }
        return ans;
    }
};
