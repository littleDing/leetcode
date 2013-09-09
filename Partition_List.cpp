//Attemp #1
//from	2013-09-08 17:46
//to   2013-09-08 17:55
//failed before small AC: CE*1 + RTE* + WA + TLE*1
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *left=NULL,*right=NULL;
        ListNode **leftTail=&(left),**rightTail=&(right);
        for(ListNode* p=head;p;p=p->next){
            if(p->val<x) {
                *leftTail = p;
                leftTail=&(p->next);
            }else{
                *rightTail = p;
                rightTail=&(p->next);
            }
        }
        *leftTail=right;
        *rightTail=NULL;
        return left;
    }
};
