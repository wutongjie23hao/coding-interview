/* *************************
 * 链表中倒数第k个结点（代码鲁棒性）
 * 输入一个链表，输出该链表中倒数第k个结点。
 * *************************/
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};

class Solution {
public:
  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //空节点
        if (!pListHead)
            return NULL;
        ListNode *pFront, *pBack;
        pFront=pBack=pListHead;

        unsigned int counter=0;
        //一共不到k个节点
        while(counter<k-1 && pBack!=NULL){
            pBack = pBack->next;
            counter++;
        }
        if(!pBack)
            return NULL;
        //有k或k个以上节点
        while(pBack->next!=NULL){
            pBack = pBack->next;
            pFront = pFront->next;
        }

        return pFront;
  }
};
