/* *********************************
 * 反转链表(代码鲁棒性)
 * 输入一个链表，反转链表后，输出反转链表后头节点
 * **********************************/
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};

class Solution {
public:
  ListNode* ReverseList(ListNode* pHead) {

        if(!pHead)
            return NULL;

        ListNode *pListHead=NULL, *pBack = pHead, *pTemp;
        while(pBack!=NULL){
            pTemp = pBack->next;
            pBack->next = pListHead;
            pListHead = pBack;
            pBack = pTemp;
        }

        return pListHead;
  }
};