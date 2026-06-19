class MinStack {
public:
    vector<int>minst;
    stack<int>st;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minst.empty()) minst.push_back(value);
        else if(value<=minst.back()) minst.push_back(value);
    }
    
    void pop() {
        int val= st.top();
        if(val==minst.back()) minst.pop_back();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.back();
    }
};