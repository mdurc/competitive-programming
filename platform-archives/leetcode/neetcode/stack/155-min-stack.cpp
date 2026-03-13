
// with stacks
class MinStack {
private:
    stack<int> m_stack, m_mins;
public:
    MinStack() { }
    
    void push(int val) {
        int new_val = m_mins.empty() ? val : min(val, m_mins.top());
        m_mins.push(new_val);
        m_stack.push(val);
    }
    
    void pop() {
        m_stack.pop();
        m_mins.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_mins.top();
    }
};


// with vectors cause I thought we couldn't use stacks
class MinStack {
private:
    vector<int> m_stack, m_mins;
public:
    MinStack() {}
    
    void push(int val) {
        int new_val = m_mins.empty() ? val : min(val, m_mins.back());
        m_mins.push_back(new_val);
        m_stack.push_back(val);
    }
    
    void pop() {
        m_stack.pop_back();
        m_mins.pop_back();
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return m_mins.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
