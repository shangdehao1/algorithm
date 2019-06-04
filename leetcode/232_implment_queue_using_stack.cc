/*
implement the following operations of a queue using stacks.

  push(x)  -- Push element x to the back of queue.
  pop()    -- Removes the element from in front of queue.
  peek()   -- Get the front element.
  empty()  -- Return whether the queue is empty.

Example:


MyQueue queue = new MyQueue();

  queue.push(1);
  queue.push(2);  
  queue.peek();  // returns 1
  queue.pop();   // returns 1
  queue.empty(); // returns false
  Notes:
  
You must use only standard operations of a stack 
 -- which means only push to top, peek/pop from top, size, and is empty operations are valid.

*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
      input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      peek();    
      int temp = output.top();
      output.pop();
      return temp;
    }
    
    /** Get the front element. */
    int peek() {
      if (output.empty()) {
        while (!input.empty()) {
          output.push(input.top());
          input.pop();
        }
      }    
      return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
      return input.empty() && output.empty();
    }
private:
  stack<int> input;
  stack<int> output;
};


