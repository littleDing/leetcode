//Attemp #1
//from	2013-09-28 22:57
//to   2013-09-28 22:13
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return head;
        int l=0;
        for(ListNode *p=head;p;p=p->next) ++l;
        l-=n;
        ListNode **p=&head;
        for(int i=0;i<l;++i) p=&((*p)->next);
        *p=(*p)->next;
        return head;
    }
};
