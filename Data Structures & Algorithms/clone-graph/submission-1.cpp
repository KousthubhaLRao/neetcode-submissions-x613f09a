/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {  //dfs solution works too, but i just wanna try bfs to keep some variety.
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node *, Node *> mp; //this hashmap maps original nodes to their clones.
        queue<Node *> q;
        mp[node] = new Node(node->val); //mapping the first given node to its newly made clone.
        q.push(node); //enqueueing the very first node.

        while(!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            for(Node *x : cur->neighbors) //iterating through all neighbours of the current node
            {
                if(!mp.count(x))  //if a neighbour is being visited for the first time.
                {
                    mp[x] = new Node(x->val);
                    q.push(x);   //add it to the hashmap with its clone, and push it into the bfs queue.
                }
                mp[cur]->neighbors.emplace_back(mp[x]);  //attach the neighbour clones to the current node's clone. (continuing the cloning process basically)
            }
        }
        return mp[node]; //return clone of first node
    }
};
