//Attemp #1
//from	2013-09-21 01:03
//to   2013-09-21 01:14
//failed before small AC: CE* + RTE* + WA
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
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!l1&&!l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head=NULL;
        ListNode **p=&head;
        int over=0;
        while(l1&&l2){
            int next=l1->val+l2->val+over;
            *p=new ListNode(next%10);
            p=&((*p)->next);
            over=next/10;
            l1=l1->next; l2=l2->next;
        }
        while(l1){
            int next=l1->val+over;
            *p=new ListNode(next%10);
            p=&((*p)->next);
            over=next/10;
            l1=l1->next;
        }
        while(l2){
            int next=l2->val+over;
            *p=new ListNode(next%10);
            p=&((*p)->next);
            over=next/10;
            l2=l2->next;
        }
        while(over){
            int next=over;
            *p=new ListNode(next%10);
            p=&((*p)->next);
            over=next/10;
        }
        return head;
    }
};
