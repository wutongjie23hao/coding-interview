/* ********************
 * 用两个栈实现队列(栈和队列)
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。
 * 队列中的元素为int类型。
 * ********************/
class Solution
{
public:
  void push(int node) {
        stack1.push(node);

  }

  int pop() {
        int temp;
        if(stack2.empty()){
            while(!stack1.empty()){
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        temp = stack2.top();
        stack2.pop();
        return temp;
  }

private:
  stack<int> stack1;
  stack<int> stack2;
};
