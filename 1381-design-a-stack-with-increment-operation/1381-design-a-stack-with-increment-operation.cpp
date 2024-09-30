class CustomStack {
    int *arr;
    int sz;
    int tos ;
    bool isEmpty(){
        if (tos == -1 ) {
            return true;
        }
        return false;
    }
    bool isFull(){
        if (tos == sz-1 ){
            return true;
        }
        return false;
    }
public:
    CustomStack(int maxSize) {
        this->arr = new int[maxSize];    
        this->sz = maxSize;
        this->tos = -1;
    }
    
    void push(int x) {
        if ( !isFull() ){
            this->arr[++tos] = x;
        }
    }
    
    int pop() {
        if ( isEmpty()) {
            return -1;
        }
        return this->arr[tos--];
    }
    
    void increment(int k, int val) {
        if (k > tos){
            for (int i = 0 ; i<= tos;i++){
                this->arr[i] += val;
            }
        }
        else if (k <= tos){
            for (int i = 0 ; i<k ; i++){
                this->arr[i] += val;
            } 
        }
        return ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */