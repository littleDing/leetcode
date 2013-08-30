//Attemp #1
//from 	2013-8-25 19:55
//to	2013-8-25 20:31
//failed before small AC: CE* + RTE*2 + WA*1
//failed before large AC: None



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head,int l) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l==0) return NULL;
        if(l==1) return new TreeNode(head->val);
        ListNode *p=head;
        int i=0;
        for(;(i+1)*2+1<l;++i) p=p->next;
        TreeNode *root=new TreeNode(p->next->val);
        root->left=sortedListToBST(head,i+1);
        root->right=sortedListToBST(p->next->next,l-i-2);
        return root;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        int l=0;
        for(ListNode *p=head;p;p=p->next,++l);
        return sortedListToBST(head,l);
    }
};
