//Attemp #1
//from	2013-09-15 01:20
//to   2013-09-15 01:55
//failed before small AC: CE* + RTE*4 + WA*2
//failed before large AC: None




class Solution {
    class Tree{
        struct Node{
            int range[2];
            int mi;
        };
        vector<Node> nodes;
        int ma;
        void reset(int from,int to,int i){
            nodes[i].range[0]=from;
            nodes[i].range[1]=to;
            nodes[i].mi=ma;
            if(from!=to){
                int mid=from+(to-from)/2;
                reset(from,mid,i*2+1);
                reset(mid+1,to,i*2+2);
            }
        }
    public:
        void reset(int n){
            nodes.resize(n*4);
            ma=n+1;
            reset(0,n-1,0);
        }
        int findMin(int from,int to,int i=0){
            if(from<=nodes[i].range[0]&&nodes[i].range[1]<=to)
                return nodes[i].mi;
            else if(to<nodes[i].range[0]||nodes[i].range[1]<from) return ma;
            else return min(findMin(from,to,i*2+1),findMin(from,to,i*2+2));
        }
        void update(int k,int v,int i=0){
            nodes[i].mi = min(nodes[i].mi,v);
            if(nodes[i].range[0]!=nodes[i].range[1]){
                int mid=nodes[i].range[0]+(nodes[i].range[1]-nodes[i].range[0])/2;
                if(k<=mid) update(k,v,i*2+1);
                else update(k,v,i*2+2);
            }
        }
    };
    Tree tree;
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        tree.reset(n);
        tree.update(n-1,0);
        for(int i=n-2;i>=0;--i){
            if(i+A[i]>=n-1) tree.update(i,1);
            else if(A[i]){
                int mi=tree.findMin(i+1,i+A[i]);
                tree.update(i,mi+1);
            }
        }
        return tree.findMin(0,0);
    }
};
