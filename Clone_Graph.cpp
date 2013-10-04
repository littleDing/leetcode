//Attemp #1
//from	2013-10-04 18:28
//to   2013-10-04 17:33
//failed before small AC: CE*3 + RTE* + WA*2
//failed before large AC: None

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!node) return NULL;
        queue<UndirectedGraphNode*> tovisit;
        map<int,UndirectedGraphNode*> cloned;
        map<int,bool> visited;
        tovisit.push(node); visited[node->label]=true;
        while(!tovisit.empty()){
            UndirectedGraphNode* toclone=tovisit.front(); tovisit.pop();
            UndirectedGraphNode *cld=new UndirectedGraphNode(toclone->label);
            cloned[toclone->label]=cld;
            for(int i=0;i<toclone->neighbors.size();++i){
                UndirectedGraphNode *nb=toclone->neighbors[i];
                if(!visited[nb->label]){
                    tovisit.push(nb);
                    visited[nb->label]=true;
                } 
            }
        }
        visited.clear();
        tovisit.push(node); visited[node->label]=true;
        while(!tovisit.empty()){
            UndirectedGraphNode *toclone=tovisit.front(); tovisit.pop();
            UndirectedGraphNode *cld=cloned[toclone->label];
            for(int i=0;i<toclone->neighbors.size();++i){
                UndirectedGraphNode *nb=toclone->neighbors[i];
                cld->neighbors.push_back(cloned[nb->label]);
                if(!visited[nb->label]){
                    tovisit.push(nb);
                    visited[nb->label]=true;
                } 
            }   
        }
        return cloned[node->label];
    }
};
