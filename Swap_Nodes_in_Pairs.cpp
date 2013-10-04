//Attemp #1
//from	2013-09-28 23:24
//to   2013-09-28 23:36
//failed before small AC: CE* + RTE*3 + WA
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode **p=&head;
        while((*p)&&(*p)->next){
            ListNode *nexts[3]={*p,(*p)->next,(*p)->next->next};
            *p=nexts[1];
            nexts[1]->next=nexts[0];
            nexts[0]->next=nexts[2];
            p=&((*p)->next->next);
        }
        return head;
    }
};
