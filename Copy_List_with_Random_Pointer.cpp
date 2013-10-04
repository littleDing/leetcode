//Attemp #1
//from	2013-10-04 22:24
//to   2013-10-04 22:40
//failed before small AC: CE* + RTE* + WA*1
//failed before large AC: None

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head) return NULL;
        for(RandomListNode *p=head;p;p=p->next->next){
            RandomListNode *np=new RandomListNode(p->label);
            np->next=p->next;
            p->next=np;
        }
        for(RandomListNode *p=head;p;p=p->next->next){
            if(p->random){
                RandomListNode *np=p->next;
                np->random=p->random->next;
            }
        }
        RandomListNode *ret=NULL;
        RandomListNode **pend=&ret;
        for(RandomListNode *p=head;p;p=p->next){
            *pend=p->next;
            p->next=p->next->next;
            pend=&((*pend)->next);
        }
        *pend=NULL;
        return ret;
    }
};
