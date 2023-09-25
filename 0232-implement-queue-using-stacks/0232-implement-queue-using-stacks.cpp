class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while (s.empty()==false)
        {
            tmp.push(s.top());
            s.pop();
        }
        int ret = tmp.top();
        tmp.pop();
        while (tmp.empty() == false)
        {
            s.push(tmp.top());
            tmp.pop();
        }
        return ret;
    }
    
    int peek() {
        while (s.empty()==false)
        {
            tmp.push(s.top());
            s.pop();
        }
        int ret = tmp.top();
        while (tmp.empty() == false)
        {
            s.push(tmp.top());
            tmp.pop();
        }
        return ret;
    }
    
    bool empty() {
        if (s.empty()) return true;
        return false;
    }

public:
    stack<int> s;
    stack<int> tmp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */