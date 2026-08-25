/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;

        queue<pair<Node* , int>>q;
        q.push({root , 1});
        while(!q.empty()){
            auto [a,b]= q.front();
            q.pop();
            vector<Node*>v=a->children;
            for(auto it : v) q.push({it , b+1});

            if(q.empty()) return b;
        }
        return 1;
        
    }
};