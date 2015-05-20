/* **************************
 * 栈的压入、弹出序列
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
 * 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列
 * 1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一
 * 个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 * *************************/
class Solution {
public:
  bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool result = false;
        stack<int> tempStack;
        vector<int>::iterator pushIter=pushV.begin(), popIter=popV.begin();
        //判断入栈序列和出栈序列都为空或一个为空时候的状况
        if(pushV.empty() && popV.empty())
            return true;
        if(pushV.empty() || popV.empty() || pushV.size()!=popV.size())
            return false;
        //如果入栈序列的第一个值和出栈序列的第一个值不一样的时候，
        //将入栈序列的第一个值进入缓存栈，并擦除
        while(!pushV.empty() && !popV.empty()){
            if(*pushIter == *popIter){
                pushV.erase(pushIter);
                popV.erase(popIter);
            } else {
                tempStack.push(*pushIter);
                pushV.erase(pushIter);
            }
        }
        //若缓存堆栈不为空的时候，需要对栈顶元素和出栈序列做比较
        if(tempStack.empty() && pushV.empty() && popV.empty())
            return true;
        popIter = popV.begin();
        while(!tempStack.empty()){
            if(tempStack.top()==*popIter){
                tempStack.pop();
                popV.erase(popIter);
            } else {
                result = false;
                break;
            }
        }
        if(tempStack.empty() && popV.empty())
            result=true;
        return result;
  }
};
