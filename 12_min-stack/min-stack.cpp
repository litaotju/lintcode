/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-02-24 03:42
*/

class MinStack {
public:
    MinStack() {
    }
    void push(int number) {
        data_stack.push(number);
        if(min_stack.empty()){
            min_stack.push(number);
        }else if(number <= min_stack.top() ){
            min_stack.push(number);
        }
        else {
            min_stack.push(min_stack.top());
        }
    }

    int pop() {
        //assert(!data_stack.empty() && ! min_stack.empty() );
        int top = data_stack.top();
        data_stack.pop();
        min_stack.pop();
        return top;
    }

    int min() {
        return min_stack.top();
    }
private:
    stack<int> data_stack;
    stack<int> min_stack;
};
