class MyCircularDeque {
public:
    struct Node {
        Node* next ;
        Node* pre ;
        int val ;
    };
    int s = 0 ;
    int ms ;
    Node* front = NULL ;
    Node* back = NULL ;
    MyCircularDeque(int k) {
        ms = k ;
    }
    
    bool insertFront(int value) {
        if(s == ms){
            return false ;
        }
        Node* n = new Node();
        n->val = value ;
        if(front == NULL){
            front = n ;
        }
        else{
            n->next = front ;
            front->pre = n ;
            front = n ;
        }
        if(s == 0){
            back = n ;
        }
        s += 1 ;
        return true ;
    }
    
    bool insertLast(int value) {
        if(s == ms){
            return false ;
        }
        Node* n = new Node();
        n->val = value ;
        if(back == NULL){
            back = n ;
        }
        else{
            back->next = n ;
            n->pre = back ;
            back = n ;
        }
        if(s == 0){
            front = n ;
        }
        s += 1 ;
        return true ;
    }
    
    bool deleteFront() {
        if(s == 0){
            return false ;
        }
        if(front == back){
            front == NULL ;
            back == NULL ;
            s -= 1 ;
            return true ;
        }
        front->next->pre = NULL ;
        Node* n = front->next ;
        front->next = NULL ;
        front = n ;
        s -= 1 ;
        return true ;
    }
    
    bool deleteLast() {
        if(s == 0){
            return false ;
        }
        if(front == back){
            front == NULL ;
            back == NULL ;
            s -= 1 ;
            return true ;
        }
        Node* n = back->pre ;
        back->pre = NULL;
        n->next = NULL ;
        back = n ;
        s -= 1 ;
        return true ;
    }
    
    int getFront() {
        if(s == 0){
            return -1 ;
        }
        return front->val ;
    }
    
    int getRear() {
        if(s == 0){
            return -1 ;
        }
        return back->val ;
    }
    
    bool isEmpty() {
        return s == 0 ;
    }
    
    bool isFull() {
        return s == ms ;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */