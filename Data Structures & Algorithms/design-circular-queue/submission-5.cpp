class MyCircularQueue {
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int v, Node *next) : val(v), next(next) {}
    };

    int space;
    Node *front;
    Node *rear;

public:
    MyCircularQueue(int k) {
        space = k;
        front = nullptr;
        rear = nullptr;
    }
    
    bool enQueue(int value) {
        if(!space) return false; //queue is full
        else if(front == nullptr or rear == nullptr) //queue is empty
        {
            Node *temp = new Node(value, nullptr);
            temp->next = temp;
            front = rear = temp;
        }
        else
        {
            rear->next = new Node(value, front);
            rear = rear->next;
        }
        space--;
        return true;
    }
    
    bool deQueue() {
        if(front == nullptr) return false; //queue is empty
        if(front == rear) //queue has only one element
        {
            delete front;
            front = rear = nullptr;
        }
        else
        {
            Node *to_be_freed = front;
            front = front->next;
            rear->next = front;
            delete to_be_freed;
        }
        space++;
        return true;
    }
    
    int Front() {
        return (front == nullptr) ? -1 : front->val;
    }
    
    int Rear() {
        return (front == nullptr) ? -1 : rear->val;
    }
    
    bool isEmpty() {
        return (front == nullptr);
    }
    
    bool isFull() {
        return (space == 0);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */