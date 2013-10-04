//Attemp #1
//from	2013-09-28 23:05
//to   2013-09-28 23:24
//failed before small AC: CE*4 + RTE* + WA*1
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
    typedef pair<int,int> Node;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<Node,vector<Node>,greater<Node>> tops;
        vector<ListNode*> heads=lists;
        //push all heads and make header pointers;
        for(int i=0;i<lists.size();++i){
            if(lists[i]) tops.push(Node(lists[i]->val,i));
        }
        ListNode *head=NULL,**now=&head;
        //while tops is not empty, pop it out and maintain it
        while(!tops.empty()){
            Node node=tops.top(); tops.pop();
            int idx=node.second;
            if(heads[idx]&&node.first==heads[idx]->val){
                *now=heads[idx];
                heads[idx]=heads[idx]->next;
                now=&((*now)->next);
                *now=NULL;
                if(heads[idx]) tops.push(Node(heads[idx]->val,idx));
            }
        }
        return head;
    }
};
