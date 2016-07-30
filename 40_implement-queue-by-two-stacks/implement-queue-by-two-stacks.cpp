/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/implement-queue-by-two-stacks
@Language: C++
@Datetime: 16-02-20 02:29
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        int tmp;
        // write your code here
        if( stack2.empty() ){
            while(!stack1.empty()){
                tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

    int top() {
        // write your code here
        int tmp;
        if(stack2.empty()){
            while(!stack1.empty()){
                tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        return stack2.top();
    }
};
