//Attemp #1
//from	2013-09-09 01:13
//to   2013-09-09 01:27
//failed before small AC: CE*1 + RTE*1 + WA*1
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(ListNode **p=&head;*p;){
            if((*p)->next&&(*p)->val==(*p)->next->val){
                ListNode **next=&((*p)->next);
                for(;*next&&(*next)->val==(*p)->val;next=&((*next)->next)){            
                }
                *p=*next;
            }else{
                p=&((*p)->next);
            }
        }
        return head;
    }
};
