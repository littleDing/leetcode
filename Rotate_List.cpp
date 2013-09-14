//Attemp #1
//from	2013-09-14 11:54
//to   2013-09-14 12:04
//failed before small AC: CE* + RTE*1 + WA
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
    int len(ListNode *head,ListNode* &end){
        if(!head) return 0;
        int cnt=1;
        for(end=head;end->next;end=end->next)
            cnt++;
        return cnt;
    }
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *end;
        int l=len(head,end);
        if(!l) return head;
        k%=l;
        if(!k) return head;
        ListNode *p=head;
        for(int i=1;i+k<l;++i) p=p->next;
        end->next=head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};
