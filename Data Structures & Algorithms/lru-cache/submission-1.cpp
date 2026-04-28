class LRUCache {
public:
    struct Node
    {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    int cap;
    unordered_map<int, Node *> cache;
    Node *left; //tail.
    Node *right; //head. they're dummy nodes

    void remove(Node *node)
    {
        Node *prev = node->prev;
        Node *nex = node->next;
        prev->next = nex;
        nex->prev = prev;
    }

    void insert(Node *node) //insertion happens at head. The most recently used node is at right->prev
    {
        Node *prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }


    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.count(key)) //if key exists, it needs to removed, and inserted to the front.
        {
            Node *node = cache[key];
            remove(node);
            insert(node);
            return cache[key]->val; //cache[key] gives pointer to the specific node.
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) remove(cache[key]); //since key already exists, we remove it, and then it gets updated in the next three lines.

        Node *newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;  //i got these three lines right yay

        if(cache.size() > cap)
        {
            Node *lru = left->next; //the least recently used node is given by left->next, since the most recently used nodes get inserted at right
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};









