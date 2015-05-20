/* **************************
 * 包含min函数的栈（举例让抽象具体化）
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函
 * 数。
 * *************************/
class Solution {
public:
  void push(int value) {
    dataStack.push(value);
        if(minStack.empty())
            minStack.push(value);
        else if(value <= minStack.top())
            minStack.push(value);
  }
  void pop() {
    int temp = dataStack.top();
        if(!dataStack.empty())
          dataStack.pop();
        if(!minStack.empty()){
            if(temp == minStack.top())
              minStack.pop();
        }
  }
  int top() {
    return dataStack.top();
  }
  int min() {
    return minStack.top();
  }
private:
    stack<int> minStack;
    stack<int> dataStack;
};
