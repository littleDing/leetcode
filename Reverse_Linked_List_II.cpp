//Attemp #1
//from	2013-09-08 08:37
//to   2013-09-08 09:42
//failed before small AC: CE*1 + RTE* + WA*1+TLE*1
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m<1||m>=n||!head||head->next==NULL) return head;
        ListNode **left=&head;
        for(int i=1;i<m&&*left;++i) left=&((*left)->next);
        if(!(*left)||!(*left)->next) return head;
        ListNode **now=&((*left)->next);
        for(int i=m;i<n&&*now;++i){
            ListNode *next=(*now)->next;
            ListNode *pre=(*left);
            *left=*now;
            (*left)->next =pre;
            *now=next;
        }
        return head;
    }
};
