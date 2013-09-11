//Attemp #1
//from	2013-09-12 01:37
//to   2013-09-12 02:01
//failed before small AC: CE*1 + RTE*1 + WA*1 + TLE*2
//failed before large AC: None

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void link(ListNode* &head, ListNode* &end,ListNode* &l){
        if(end){
            end->next=l;
            end = end->next;
        }else{
            head=end=l;
        }
        l=l->next;
    }
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head=NULL,*end=NULL;
        while(l1&&l2){
            if(l1->val<=l2->val){
                link(head,end,l1);
            }else{
                link(head,end,l2);
            }
        }
        while(l1) link(head,end,l1);
        while(l2) link(head,end,l2);
        return head;
    }
};
