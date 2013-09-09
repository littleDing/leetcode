//Attemp #1
//from	2013-09-09 01:09
//to   2013-09-09 01:12
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(ListNode *p=head;p;p=p->next){
            ListNode *next=p->next;
            while(next&&next->val==p->val){
                next=next->next;
            }
            p->next=next;
        }
        return head;
    }
};
