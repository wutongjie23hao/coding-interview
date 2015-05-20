/* ********************
 * 从尾到头打印链表(链表)
 * 输入一个链表，从尾到头打印链表每个节点的值。
 * 返回新链表的头结点。
 * *******************/
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
    val(x), next(NULL) {
  }
};

class Solution {
public:
  vector<int> printListFromTailToHead(struct ListNode* head) {
    stack<int> dataStack;
        vector<int> dataVector;

        struct ListNode *tempNode = head;
        while(tempNode!=NULL){
            dataStack.push(tempNode->val);
            tempNode = tempNode->next;
        }

        while(!dataStack.empty()){
            int data = dataStack.top();
            dataStack.pop();
            dataVector.push_back(data);
        }

        return dataVector;
  }
};