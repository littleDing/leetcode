//Attemp #1
//from	2013-10-04 11:21
//to   2013-10-04 11:36
//failed before small AC: CE*1 + RTE* + WA
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
    pair<ListNode*,ListNode*> doReverse(ListNode* from,ListNode* to){
        ListNode *head=from,*end=head;
        while(head!=to){
            ListNode *next=end->next->next;
            end->next->next=head;
            head=end->next;            
            end->next=next;
        }
        return pair<ListNode*,ListNode*>(head,end);        
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(ListNode **phead=&head;*phead;){
            ListNode *end=*phead;
            for(int i=1;i<k&&end;++i,end=end->next);
            if(end){
                pair<ListNode*,ListNode*> newList=doReverse(*phead,end);
                *phead=newList.first;
                phead=&(newList.second->next);    
            }else 
                phead=&end;
        }
        return head;
    }
};
